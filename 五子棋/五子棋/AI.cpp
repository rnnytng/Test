#include "AI.h"

void AI::init(chess* ch)
{
	this->ch = ch;
	int size = ch->getsize();
	for (int i = 0; i < size; i++) {
		vector<int>row;
		for (int j = 0; j < size; j++) {
			row.push_back(0);
		}
		data.push_back(row);
	}

}

void AI::go()
{
	chesspos pos = think();
	Sleep(1000);
	ch->chess_down(&pos, chess_white);

}

void AI::caculate()
{
	int playernum=0;
	int ainum=0;
	int emptynum=0;
	for (int i = 0; i < data.size(); i++) {
		for (int j = 0; j < data[i].size(); j++) {
			data[i][j] = 0;
		}
	}
	for (int row = 0; row < data.size(); row++) {
		for (int col = 0; col < data[row].size(); col++) {
			
			if (ch->getChessData(row,col))continue;

			
			for (int y = -1; y <= 0; y++) {
				for (int x = -1; x <= 1; x++) {
					if (y == 0 && x == 0)continue;	
					if (y == 0 && x != 1)continue;
					playernum = 0;
					ainum = 0;
					emptynum = 0;
					//ºÚÆåÂä×ÓºóµÄ½á¹û
					for (int i = 1; i <= 4; i++) {
						int currow = row + i * y;
						int curcol = col + i * x;
						if (currow >= 0 && currow < data.size() && curcol >= 0 && curcol < data.size() &&ch->getChessData(currow,curcol) == 2) {
							playernum++;
						}
						else if (currow >= 0 && currow < data.size() && curcol >= 0 && curcol < data.size() && ch->getChessData(currow, curcol) == 0) {
							emptynum++;
							break;
						}
						else {//Óöµ½°×Æå
							break;
						}
					}
					for (int i = 1; i <= 4; i++) {
						int currow = row - i * y;
						int curcol = col - i * x;
						if (currow >= 0 && currow < data.size() && curcol >= 0 && curcol < data.size() && ch->getChessData(currow, curcol) == 2) {
							playernum++;
						}
						else if (currow >= 0 && currow < data.size() && curcol >= 0 && curcol < data.size() && ch->getChessData(currow, curcol) == 0) {
							emptynum++;
							break;
						}
						else {//Óöµ½°×Æå
							break;
						}
					}
					if (playernum == 1) {
						data[row][col] += 10;
					}
					else if (playernum == 2) {
						if (emptynum == 1) {
							data[row][col] += 30;
						}
						if (emptynum == 2) {
							data[row][col] += 40;
						}
					}
					else if (playernum == 3) {
						if (emptynum == 1) {
							data[row][col] = 60;
						}
						if (emptynum == 2) {
							data[row][col] = 200;
						}
					}
					else if (playernum == 4) {
						data[row][col] = 20000;
					}
/*----------------------------------------------------------------------------------------------------------------------------------------*/

					//°×
					emptynum = 0;
					for (int i = 1; i <= 4; i++) {
						int currow = row + i * y;
						int curcol = col + i * x;
						if (currow >= 0 && currow < data.size() && curcol >= 0 && curcol < data.size() && ch->getChessData(currow, curcol) == 1) {
							ainum++;
						}
						else if (currow >= 0 && currow < data.size() && curcol >= 0 && curcol < data.size() && ch->getChessData(currow, curcol) == 0) {
							emptynum++;
							break;
						}
						else {//Óöµ½ºÚÆå
							break;
						}
					}
					for (int i = 1; i <= 4; i++) {
						int currow = row - i * y;
						int curcol = col - i * x;
						if (currow >= 0 && currow < data.size() && curcol >= 0 && curcol < data.size() && ch->getChessData(currow, curcol) == 1) {
							ainum++;
						}
						else if (currow >= 0 && currow < data.size() && curcol >= 0 && curcol < data.size() && ch->getChessData(currow, curcol) == 0) {
							emptynum++;
							break;
						}
						else {//Óöµ½ºÚÆå
							break;
						}
					}
					if (ainum==0) {
						data[row][col] += 5;
					}
					else if (ainum == 1) {
						data[row][col] += 10;
					}
					else if (ainum== 2) {
						if (emptynum == 1) {
							data[row][col] += 25;
						}
						if (emptynum == 2) {
							data[row][col] += 50;
						}
					}
					else if (playernum == 3) {
						if (emptynum == 1) {
							data[row][col] += 55;
						}
						if (emptynum == 2) {
							data[row][col] +=10000;
						}
					}
					else if (playernum == 4) {
						data[row][col] += 30000;
					}

				}
			}
		}
	}
}

chesspos AI::think()
{
	vector<chesspos>points;
	
	caculate();
	int max = 0;
	int size = ch->getsize();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (ch->getChessData(i, j) == 0) {
				{
					if (data[i][j] > max) {
						max = data[i][j];
						points.clear();
						points.push_back(chesspos(i, j));
					}
				}
				
			}
			else if (data[i][j] == max) {
			
				points.push_back(chesspos(i,j));
			}

		}
	}
	int index = rand() % points.size();
	return points[index];
}
