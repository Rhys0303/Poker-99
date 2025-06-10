#include"player.h"
#include<iostream>
using namespace std;

player::player(const string&n) :name(n) {};


void player::draw(Deck& deck)
{
	if (!deck.cards.empty())
	{
		hand.push_back(deck.draw());
	}
}
void player::showHand()const
{
	cout << name << "的牌" << endl;
	for (size_t i = 0; i < hand.size(); i++)
	{
		cout << "[" << i + 1 << ":";
		hand[i].print();
		cout << "]";
	}
	cout << endl;
}
card player::play(int index) {
	card c = hand[index];
	hand.erase(hand.begin() + index);
	return c;
}