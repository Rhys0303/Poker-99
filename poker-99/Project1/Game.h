#include "Deck.h"
#include "player.h"

class Game {
private:
    Deck deck;
    player p1, p2;
     int total;
    int currentPlayer; 

public:
    Game();
    void start();
    int getCardValue(const card& card);
    void clearScreen();
};