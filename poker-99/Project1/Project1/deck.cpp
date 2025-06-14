#include"Deck.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

Deck::Deck()
{
	for (int i = 1; i <= 4; i++)
	{
		for (int i = 1; i <= 13; i++)
		{
			cards.push_back(card(i));
		}
	}

	shuffle();
}

void Deck::shuffle()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	std::random_shuffle(cards.begin(), cards.end());
}

card Deck::draw()
{
	card c = cards.back();
	cards.pop_back();
	return c;
}