#include "Game.h"
#include <iostream>
#include <cstdlib>
using namespace std;


Game::Game() : p1("���a1"), p2("���a2"), total(0), currentPlayer(1) {
    for (int i = 0; i < 5; ++i) {
        p1.draw(deck);
        p2.draw(deck);
    }
}

void Game::start() {
    while (true) {
        if (total < 0) {
            total = 0;
        }
       
        player& player = (currentPlayer == 1) ? p1 : p2;
        cout << "-----------------------------------\n";
        cout << "�ثe�`�ơG" << total << std::endl;
        player.showHand();

        cout << player.name << " �п�ܭn�X���P (��J�s�� 1~" << player.hand.size() << "): " << endl;
        int choice;
        cin >> choice;
        while (choice < 1 || choice > static_cast<int>(player.hand.size())) {
            cout << "�L�Ŀ�J�A�Э��s���: ";
            std::cin >> choice;
        }

        card played = player.play(choice - 1);
        cout << player.name << " �X�F�G";
        played.print();
        cout << std::endl;

        int addValue = getCardValue(played);
        total += addValue;

        cout << "�ثe�`�ơG" << total << std::endl;

        if (total > 99) {
            cout << player.name << " �z�F�I�C�������I" << std::endl;
            break;
        }

        player.draw(deck);
        currentPlayer = (currentPlayer == 1) ? 2 : 1;

    }
}

int Game::getCardValue(const card& card) {
    if (card.value == 1) return -total;
    else if (card.value == 10) return -10;
    else if (card.value == 11) return 0;
    else if (card.value == 12) return -20;
    else if (card.value == 13) return (99 - total);
    else return card.value;
}