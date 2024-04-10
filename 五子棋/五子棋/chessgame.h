#pragma once
#include "man.h"
#include "AI.h"
#include "chess.h"
class chessgame
{public:
	chessgame(man* ma, AI* ai, chess* ch);
	void start();
private:
	man* ma;
	AI* ai;
	chess* ch;

};

