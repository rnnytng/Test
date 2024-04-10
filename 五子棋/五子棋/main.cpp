#include <iostream>
#include <graphics.h>
#include "chessgame.h"
using namespace std;
int main() {
	man ma;
	chess ch(13,43*0.8,41*0.8,67*0.8);
	AI ai;
	chessgame game(&ma, &ai, &ch);
	game.start();
	return 0;
}