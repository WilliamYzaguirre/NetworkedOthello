#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "othelloboard.h"
//#include "gameengine.h"


class GameState
{
public:
    GameState(int blackScore, int whiteScore, int turnCount, OthelloBoard board);

    const OthelloBoard& board() const noexcept;

    int getBlackScore() const noexcept;

    int getWhiteScore() const noexcept;

    bool isGameOver() const noexcept;

    bool isBlackTurn() const noexcept;

    bool isWhiteTurn() const noexcept;

    bool isValidMove(int x, int y) const noexcept;

    void makeMove(int x, int y);

    std::unique_ptr<GameState> clone() const;

    TileState getEndOfLine(int x, int y, int xFac, int yFac) const;

private:
    int blackScore;
    int whiteScore;
    int turnCount;

    OthelloBoard gameBoard;
};

#endif // GAMESTATE_H

