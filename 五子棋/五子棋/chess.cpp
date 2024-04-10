#include "chess.h"
#include <mmsystem.h>
#include <math.h>
#include <string.h>
#pragma comment(lib,"winmm.lib")
#include <conio.h>
chess::chess(int size, int marginx, int marginy, float chesssize)
{
	this->size = size;
	this->marginx = marginx;
	this->marginy = marginy;
	this->chesssize = chesssize;
	player = chess_black;
	for (int i = 0; i < size; i++) {
		vector<int>row;
		for (int j = 0; j < size; j++) {
			row.push_back(0);
		}
		chessmap.push_back(row);
	}
}

void chess::init()
{
	initgraph(897*0.8,895*0.8);
	loadimage(0, L"res/����2.jpg", 897 * 0.8, 895 * 0.8,true);
	//mciSendString("play res/ start.wav", 0, 0, 0);
	loadimage(&black,L"res/black.png",chesssize,chesssize,true);
	loadimage(&white,L"res/white2.png",chesssize, chesssize, true);
	for (int i = 0; i <size; i++) {
		for (int j = 0; j < size; j++) {
			chessmap[i][j] = 0;
		}
	}

}

bool chess::clicked(int x, int y, chesspos* pos)
{
	int col=(x - marginx) / chesssize;
	int row = (y - marginy) / chesssize;
	int lefttopx = marginx + col * chesssize;
	int lefttopy = marginy + row * chesssize;
	int offset = chesssize * 0.4;
	bool ret = false;
	int len;
	do {
		//���Ͻ��ж�
		len = sqrt((x - lefttopx) * (x - lefttopx) + (y - lefttopy) * (y - lefttopy));
		if (len < offset) {
			pos->col = col;
			pos->row = row;
			if (chessmap[pos->row][pos->col] == 0) {
				ret = true;
			}
			break;
		}
		//���Ͻ�
		len = sqrt((x - lefttopx - chesssize) * (x - lefttopx - chesssize) + (y - lefttopy) * (y - lefttopy));
		if (len < offset) {
			pos->col = col + 1;
			pos->row = row;
			if (chessmap[pos->row][pos->col] == 0) {
				ret = true;
			}
			break;
		}
		//���½�
		len = sqrt((x - lefttopx) * (x - lefttopx) + (y - lefttopy - chesssize) * (y - lefttopy - chesssize));
		if (len < offset) {
			pos->col = col;
			pos->row = row + 1;
			if (chessmap[pos->row][pos->col] == 0) {
				ret = true;
			}
			break;
		}
		//���½�
		len = sqrt((x - lefttopx - chesssize) * (x - lefttopx - chesssize) + (y - lefttopy - chesssize) * (y - lefttopy - chesssize));
		if (len < offset) {
			pos->col = col + 1;
			pos->row = row + 1;
			if (chessmap[pos->row][pos->col] == 0) {
				ret = true;
			}
			break;
		}
	} while (0);
	return ret;
}

void chess::chess_down(chesspos* pos, chess_kind kind)
{
	mciSendString(L"play res/down7.WAV", 0, 0, 0);
	int x = marginx + chesssize * pos->col - 0.5 * chesssize;
	int y = marginy + chesssize * pos->row - 0.5 * chesssize;
	if (kind == chess_white) {
		putimagePNG(x, y, &white);

	}
	else {
		putimagePNG(x, y, &black);
	}
	updatemap(pos);
}

int chess::getsize()
{
	return size;
}

bool chess::end()
{
	if (checkwin()) {
		Sleep(1000);
		if (player == false) {
			mciSendString(L"play res/����.mp3", 0, 0, 0);
			loadimage(0, L"res/ʤ��.jpg");
		}
		else {
			mciSendString(L"play res/ʧ��.mp3", 0, 0, 0);
			loadimage(0, L"res/ʧ��.jpg");
		}
		_getch();
		return true;
	}
	return false;
}

void chess::updatemap(chesspos* pos)
{
	lastpos = *pos;
	chessmap[pos->row][pos->col] = player ? chess_white : chess_black;
	player = !player;
}

int chess::getChessData(chesspos* pos)
{
	return chessmap[pos->row][pos->col];
}

int chess::getChessData(int row, int col)
{
	return chessmap[row][col];
}

bool chess::checkwin()
{
	int row = lastpos.row;
	int col = lastpos.col;
	//ˮƽ
	for (int i = 0; i < 5; i++) {
		if (col-i>=0&&col-i+4<size&&
			chessmap[row][col - i] == chessmap[row][col - i + 1]&&
			chessmap[row][col - i] == chessmap[row][col - i + 2] &&
			chessmap[row][col - i] == chessmap[row][col - i + 3] &&
			chessmap[row][col - i] == chessmap[row][col - i + 4] ){
			return true;
			}
	}
	//��ֱ
	for (int i = 0; i < 5; i++) {
		if (row - i >= 0 && row - i + 4 < size &&
			chessmap[row-i][col] == chessmap[row-i+1][col] &&
			chessmap[row - i][col] == chessmap[row - i + 2][col] &&
			chessmap[row - i][col] == chessmap[row - i + 3][col] &&
			chessmap[row - i][col] == chessmap[row - i + 4][col]) {
			return true;
		}
	}
	//��б
	for (int i = 0; i < 5; i++) {
		if (row + i< size && row + i - 4 >= 0 && col + i-4 >= 0 && col + i < size &&
			chessmap[row + i][col + i] == chessmap[row + i - 1][col + i - 1] &&
			chessmap[row + i][col + i] == chessmap[row + i - 2][col +i - 2] &&
			chessmap[row + i][col + i] == chessmap[row + i - 3][col + i - 3] &&
			chessmap[row + i][col + i] == chessmap[row + i - 4][col + i - 4]) {
			return true;
		}
	}
	//��xie
	for (int i = 0; i < 5; i++) {
		if (row+i<size&&row+i-4>=0&&col-i>=0&&col-i+4<size&&
			chessmap[row +i][col-i] == chessmap[row+i -1][col-i+1] &&
			chessmap[row + i][col - i] == chessmap[row + i - 2][col - i + 2] &&
			chessmap[row + i][col - i] == chessmap[row + i - 3][col - i + 3] &&
			chessmap[row + i][col - i] == chessmap[row + i - 4][col - i + 4]) {
			return true;
		}
	}
	return false;
}

void chess::putimagePNG(int x, int y, IMAGE* picture)
{
	// ������ʼ��
	DWORD* dst = GetImageBuffer();    // GetImageBuffer()���������ڻ�ȡ��ͼ�豸���Դ�ָ�룬EASYX�Դ�
	DWORD* draw = GetImageBuffer();
	DWORD* src = GetImageBuffer(picture); //��ȡpicture���Դ�ָ��
	int picture_width = picture->getwidth(); //��ȡpicture�Ŀ�ȣ�EASYX�Դ�
	int picture_height = picture->getheight(); //��ȡpicture�ĸ߶ȣ�EASYX�Դ�
	int graphWidth = getwidth();       //��ȡ��ͼ���Ŀ�ȣ�EASYX�Դ�
	int graphHeight = getheight();     //��ȡ��ͼ���ĸ߶ȣ�EASYX�Դ�
	int dstX = 0;    //���Դ������صĽǱ�

	// ʵ��͸����ͼ ��ʽ�� Cp=��p*FP+(1-��p)*BP �� ��Ҷ˹���������е���ɫ�ĸ��ʼ���
	for (int iy = 0; iy < picture_height; iy++)
	{
		for (int ix = 0; ix < picture_width; ix++)
		{
			int srcX = ix + iy * picture_width; //���Դ������صĽǱ�
			int sa = ((src[srcX] & 0xff000000) >> 24); //0xAArrggbb;AA��͸����
			int sr = ((src[srcX] & 0xff0000) >> 16); //��ȡRGB���R
			int sg = ((src[srcX] & 0xff00) >> 8);   //G
			int sb = src[srcX] & 0xff;              //B
			if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
			{
				dstX = (ix + x) + (iy + y) * graphWidth; //���Դ������صĽǱ�
				int dr = ((dst[dstX] & 0xff0000) >> 16);
				int dg = ((dst[dstX] & 0xff00) >> 8);
				int db = dst[dstX] & 0xff;
				draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)  //��ʽ�� Cp=��p*FP+(1-��p)*BP  �� ��p=sa/255 , FP=sr , BP=dr
					| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)         //��p=sa/255 , FP=sg , BP=dg
					| (sb * sa / 255 + db * (255 - sa) / 255);              //��p=sa/255 , FP=sb , BP=db
			}
		}
	}
}



