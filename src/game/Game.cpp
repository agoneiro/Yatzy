#include "Game.h"
#include <windows.h>
#include <random>
#include <algorithm>

void Game::initGame() {
    int playersNumber = 0;
    std::cout << "Podaj liczbe graczy: ";
    std::cin >> playersNumber;
    if(playersNumber <= 0) {
        exit(1);
    }

    for(int i = 0; i < playersNumber; i++) {
        std::string playerName;
        std::cout << "Podaj nazwe " << i+1 << "-ego gracza: ";
        std::cin >> playerName;
        players.push_back(new Player(playerName));
    }

    srand(time(nullptr));
    int firstPlayer = rand() % playersNumber;

    for(int i = 0; i < firstPlayer; i++) {
        Player* first = players.front();
        players.erase(players.begin());
        players.push_back(first);
    }
}

void Game::newRound() {
    for(Player* player : players) {
        std::system("cls");
        printTable();
        std::cout << "Runda " << roundNumber << ", tura gracza " << player->getPlayerName() << ": " << std::endl;
        
        std::vector<int> dices;
        std::cout << "Wczytaj kostki: ";
    
        for(int i = 0; i < 5; i++) {
            int dice = 0;
            while(!(dice > 0 && dice <= 6)) {
                std::cin >> dice;
            }
            dices.push_back(dice);
        }
        

        bool nameCorrect = false;
        while(!nameCorrect) {
            std::cout << "Podaj pole: ";
            std::string scoreboxName;
            std::cin >> scoreboxName;

            int sbRandom;
            if (stringToLower(scoreboxName) == "losowo") {
                do {
                    sbRandom = rand() % 13; 
                } while(player->getScoreboxes()[sbRandom]->isUsed());
                player->getScoreboxes()[sbRandom]->setValue(dices);
                break;
            }
        
            for(Scorebox* scorebox : player->getScoreboxes()) {
                if(stringToLower(scoreboxName) == stringToLower(scorebox->getScoreboxName()) && !scorebox->isUsed()) {
                    scorebox->setValue(dices);
                    nameCorrect = true;
                }
                else if(stringToLower(scoreboxName) == stringToLower(scorebox->getScoreboxName())) {
                    std::cout << "Pole juz wykorzystane!" << std::endl;
                }
            }
        }
    }
    roundNumber++;

    if(roundNumber > players[0]->getScoreboxes().size()) {
        finished = true;
        std::system("cls");
        printTable();
        std::cout << "Zwyciezca: ";

        std::string winner = " ";
        int maxTotal = 0;
        for(Player* player : players) {
            if(player->countTotal() > maxTotal) {
                winner = player->getPlayerName();
                maxTotal = player->countTotal();
            }
            else if(player->countTotal() == maxTotal) {
                winner += ", " + player->getPlayerName();
            }
        }
        std::cout << winner << std::endl;
    }
}

void Game::drawEmptyLine(int columnWidth) const {
    for(int i = 0; i <= players.size(); i++) {
        if(i == 0) {
            for(int j = 0; j < columnWidth; j++) std::cout << "-";
        }
        else {
            std::cout << "-|-";
            for(int j = 0; j < columnWidth; j++) std::cout << "-";
        }
    }
    std::cout << std::endl;
}

void Game::printTable() const {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int columnWidth = getColumnWidth();

    for(int i = 0; i <= players.size(); i++) {
        if(i == 0) {
            std::string yatzy_str = "YATZY";
            std::cout << yatzy_str;
            for(int j = 0; j < columnWidth - yatzy_str.length(); j++) std::cout << " ";
        }
        else {
            std::cout << " | " << players[i - 1]->getPlayerName();
            for(int j = 0; j < columnWidth - players[i-1]->getPlayerName().length(); j++) std::cout << " ";
        }
    }
    std::cout << std::endl;

    int scoreboxNo = 0;
    for(Scorebox* scorebox : players[0]->getScoreboxes()) { 
        if(scoreboxNo == 6) {
            drawEmptyLine(columnWidth);
            for(int i = 0; i <= players.size(); i++) {
                if(i == 0) {
                    std::string sum_str = "===";
                    std::cout << sum_str;
                    for(int j = 0; j < columnWidth - sum_str.length(); j++) std::cout << " ";
                }
                else {
                    std::cout << " | ";
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    std::cout << players[i - 1]->countTotalUpper();
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
                    for(int j = 0; j < columnWidth - std::to_string(players[i-1]->countTotalUpper()).length(); j++) std::cout << " ";
                }
            }
            std::cout << std::endl;
        }

        drawEmptyLine(columnWidth);

        for(int i = 0; i <= players.size(); i++) {
            if(i == 0) {
                std::cout << scorebox->getScoreboxName();
                for(int j = 0; j < columnWidth - scorebox->getScoreboxName().length(); j++) std::cout << " ";
            }
            else {
                std::cout << " | ";
                if(players[i-1]->getScoreboxes()[scoreboxNo]->isUsed()) {
                    std::cout << players[i - 1]->getScoreboxes()[scoreboxNo]->getValue();
                    for(int j = 0; j < columnWidth - std::to_string(players[i - 1]->getScoreboxes()[scoreboxNo]->getValue()).length() ; j++) {
                        std::cout << " ";
                    }
                }
                else {
                    for(int j = 0; j < columnWidth ; j++) {
                        std::cout << " ";
                    }
                }
            }
        } 

        scoreboxNo++;
        std::cout << std::endl;
    }

    drawEmptyLine(columnWidth);
    for(int i = 0; i <= players.size(); i++) {
        if(i == 0) {
            std::string total_str = "Total";
            std::cout << total_str;
            for(int j = 0; j < columnWidth - total_str.length(); j++) std::cout << " ";
        }
        else {
            int total = players[i - 1]->countTotal();
            std::cout << " | ";
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            std::cout << total;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
            for(int j = 0; j < columnWidth - std::to_string(total).length(); j++) std::cout << " ";
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

int Game::getColumnWidth() const {
    int columnWidth = 5;
    for(Player* player : players) {
        if(player->getPlayerName().length() > columnWidth) {
            columnWidth = player->getPlayerName().length();
        }
    }
    for(Scorebox* scorebox : players[0]->getScoreboxes()) {
        if(scorebox->getScoreboxName().length() > columnWidth) {
            columnWidth = scorebox->getScoreboxName().length();
        }
    }
    return columnWidth;
}

std::string Game::stringToLower(std::string str) const {
    std::string result;
    result.reserve(str.length());

    for(char c : str) {
        result += std::tolower(c);
    }

    return result;
}

Game::Game() {
    initGame();
    while(!finished) newRound();
}

Game::~Game() {
    for(Player* player : players) {
        delete player;
    }
}