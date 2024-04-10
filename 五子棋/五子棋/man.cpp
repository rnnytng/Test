#include "man.h"
#include <iostream>
void man::init(chess* ch)
{
	this->ch = ch;
}

void man::go()
{
	MOUSEMSG msg;
	chesspos pos;
	msg = GetMouseMsg();
	while (1) {
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN && ch->clicked(msg.x, msg.y, &pos)) {
			break;
		}
	}
	//std::cout << pos.row << " " << pos.col<<endl;
	ch->chess_down(&pos, chess_black);
}
