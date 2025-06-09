#include "Game.h"
#include <iostream>
using namespace std;

Game::Game() : p1("玩家1"), p2("玩家2"), total(0), currentPlayer(1) {
    for (int i = 0; i < 3; ++i) {
        p1.draw(deck);
        p2.draw(deck);
    }
}

void Game::start() {
    while (true) {
        player& player = (currentPlayer == 1) ? p1 : p2;
        cout << "-----------------------------------\n";
        cout << "目前總數：" << total << std::endl;
        player.showHand();

        cout << player.name << " 請選擇要出的牌 (輸入編號 1~" << player.hand.size() << "): ";
        int choice;
        cin >> choice;
        while (choice < 1 || choice > static_cast<int>(player.hand.size())) {
            cout << "無效輸入，請重新選擇: ";
            std::cin >> choice;
        }

        card played = player.play(choice - 1);
        cout << player.name << " 出了：";
        played.print();
        cout << std::endl;

        int addValue = getCardValue(played);
        total += addValue;

        cout << "目前總數：" << total << std::endl;

        if (total > 99) {
            cout << player.name << " 爆了！遊戲結束！" << std::endl;
            break;
        }

        player.draw(deck);
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }
}

int Game::getCardValue(const card& card) {
    if (card.value == 10) return -10;
    else if (card.value == 13) return (99 - total); 
    else return card.value;
}
