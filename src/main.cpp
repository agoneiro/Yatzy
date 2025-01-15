#include "game/Game.h"
#include <iostream>
#include <conio.h>

int main() {
    while(true) {
        std::system("cls");
        Game();

        std::cout << "Q aby zakonczyc, dowolny inny przycisk aby kontynuowac ...";
        char c = _getch();
        if(c == 'q' || c == 'Q') break;
    }
    return 0;
}