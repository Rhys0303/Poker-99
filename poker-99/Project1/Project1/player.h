#ifndef PLAYER_H
#define PLAYER_H
#include<string>
#include<vector>
#include"Deck.h"
using namespace std;

class player
{
public:
	vector<card> hand;
	string name;

	player(const string& n);
	void draw(Deck& deck);
	void showHand()const;
	card play(int index);

};
#endif 
