#include "card.h"
#include <iostream>
using namespace std;

card::card(int v) :value(v) {}
void card::print()const
{
	if (value == 1)
	{
		cout << "A";
	}

	else if (value == 11)
	{
		cout << "J";
	}

	else if (value == 12)
	{
		cout << "Q";
	}

	else if (value == 13)
	{
		cout << "K";
	}
	else cout << value;
}