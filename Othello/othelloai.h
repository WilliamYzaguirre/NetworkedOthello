#ifndef OTHELLOAI_H
#define OTHELLOAI_H

#include "gamestate.h"
#include <utility>
#include <memory>

class OthelloAI
{
    public:
        OthelloAI();

        std::pair<int,int> chooseMove(GameState* state);

        int search(std::unique_ptr<GameState>& s, int depth, bool myTurn, int myColor);

        std::vector<std::pair<int,int>> getMoves(const std::unique_ptr<GameState>& s);

        int evaluateBoard(const std::unique_ptr<GameState>& s, int myColor);
};

#endif // OTHELLOAI_H
