#ifndef DECK_H
#define DECK_H
#include"card.h"
#include<vector>
using namespace std;
class Deck
{
public:
	vector<card> cards;
	Deck();
	void shuffle();
	card draw();
};
#endif 