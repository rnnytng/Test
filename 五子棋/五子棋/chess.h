#pragma once
#include <graphics.h>
#include <vector>
using namespace std;
class chesspos {
public:
	int row;
	int col;
	chesspos(int i=0, int j=0):row(i),col(j) {
		
	}
};
typedef enum {
	chess_white = 1,
    chess_black = 2
}chess_kind;
class chess
{
public:
	chess(int size, int marginx, int marginy, float chesssize);
	void init();
	bool clicked(int x, int y, chesspos* pos);
	void chess_down(chesspos* pos, chess_kind kind);
	int getsize();
	bool end();
	void updatemap(chesspos* pos);
	int getChessData(chesspos* pos);
	int getChessData(int row, int col);
private:
	IMAGE black;
	IMAGE white;
	int size;
	int marginx;
	int marginy;
	float chesssize;//和小方格大小相等
	vector<vector<int>>chessmap;//棋盘棋子数据
	bool player; //true black,false white
	bool checkwin();
	chesspos lastpos;

	void putimagePNG(int x, int y, IMAGE* picture);
};

