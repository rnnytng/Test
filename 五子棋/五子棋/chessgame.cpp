#include "chessgame.h"

chessgame::chessgame(man* ma, AI* ai, chess* ch)
{
	this->ma = ma;
	this->ai = ai;
	this->ch = ch;

	ma->init(ch);
	ai->init(ch);
}

void chessgame::start()
{
	ch->init();
	while (1) {
		
		ma->go();
		if (ch->end()) {
			ch->init();
			continue;
		}

		
		ai->go();
		if (ch->end()) {
			ch->init();
			continue;
		}
	}
}
