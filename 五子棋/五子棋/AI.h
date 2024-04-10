#pragma once
#include "chess.h"
class AI
{
public:
	void init(chess *ch);
	void go();
private:
	chess* ch;
	vector<vector<int>> data;
	
	void caculate();
	chesspos think();

};

