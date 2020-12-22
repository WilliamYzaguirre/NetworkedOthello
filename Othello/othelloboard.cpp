#include "othelloboard.h"
#include "tilegui.h"
#include "diskgui.h"
#include <utility>


OthelloBoard::OthelloBoard()
{
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            if ((x == 3 && y == 4) || (x == 4 && y == 3)) {
                board[x][y] = black;
            }
            else if ((x == 3 && y == 3) || (x == 4 && y == 4)) {
                board[x][y] = white;

            }
            else {
                board[x][y] = empty;
            }
        }
    }
}

OthelloBoard::OthelloBoard(const OthelloBoard& b)
{
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            board[x][y] = b.board[x][y];
        }
    }
}

OthelloBoard::~OthelloBoard()
{

}

//Sets tile at x,y to state (black, white, empty)
void OthelloBoard::setTile(TileState state, int x, int y) {
    board[x][y] = state;
}

//Returns tile state (black, white, empty) at x,y
TileState OthelloBoard::getTile(int x, int y) const
{
    return board[x][y];
}

//Flips tile at x,x
void OthelloBoard::flipTile(int x, int y)
{
    if (board[x][y] != empty) {
        if (board[x][y] == white) {
            board[x][y] = black;
        }
        else {
            board[x][y] = white;
        }
    }
}

bool OthelloBoard::isValidTile(int x, int y) const
{
    if (x < 8 && x > -1 && y < 8 && y > -1) {
        return true;
    }
    else {
        return false;
    }
}





