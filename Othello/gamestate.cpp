#include "gamestate.h"
#include "OthelloException.h"
#include "TileState.h"
#include <memory>

GameState::GameState(int blackScore, int whiteScore, int turnCount, OthelloBoard board)
    :blackScore{blackScore}, whiteScore{whiteScore}, turnCount{turnCount}, gameBoard{board}
{
}


const OthelloBoard& GameState::board() const noexcept
{
    return gameBoard;
}

int GameState::getBlackScore() const noexcept
{
    return blackScore;
}

int GameState::getWhiteScore() const noexcept
{
    return blackScore;
}

bool GameState::isGameOver() const noexcept
{
    return false;
}

bool GameState::isBlackTurn() const noexcept
{
    if (turnCount % 2 == 1) {
        return true;
    }
    else {
        return false;
    }
}

bool GameState::isWhiteTurn() const noexcept
{
    if (turnCount % 2 == 0) {
        return true;
    }
    else {
        return false;
    }
}

std::unique_ptr<GameState> GameState::clone() const
{
    return std::make_unique<GameState>(blackScore, whiteScore, turnCount, gameBoard);
}

void GameState::makeMove(int x, int y)
{
    if (isValidMove(x,y)) {
        if (turnCount % 2 == 0) {
            gameBoard.setTile(white, x, y);
            whiteScore++;
            //upper left: col-1, row-1
            if (gameBoard.getTile(x-1,y-1) == black) {
                int i = x-1;
                int j = y-1;
                while (gameBoard.getTile(i,j) == black && gameBoard.isValidTile(i,j)) {
                    i -= 1;
                    j -= 1;
                }
                if (gameBoard.getTile(i,j) == white) {
                    i++;
                    j++;
                    while(i > x && j > y) {
                        gameBoard.flipTile(i,j);
                        whiteScore++;
                        blackScore--;
                        i++;
                        j++;
                    }
                }
            }

            //upper left: col-1, row-1
            if (gameBoard.getTile(x-1,y-1) == black) {
                int i = x-1;
                int j = y-1;
                while (gameBoard.getTile(i,j) == black && gameBoard.isValidTile(i,j)) {
                    i -= 1;
                    j -= 1;
                }
                if (gameBoard.getTile(i,j) == white) {
                    i++;
                    j++;
                    while(i < x && j < y) {
                        gameBoard.flipTile(i,j);
                        whiteScore++;
                        blackScore--;
                        i++;
                        j++;
                    }
                }
            }

            //up: col, row-1
            if (gameBoard.getTile(x,y-1) == black) {
                int i = x;
                int j = y-1;
                while (gameBoard.getTile(i,j) == black && gameBoard.isValidTile(i,j)) {
                    j -= 1;
                }
                if (gameBoard.getTile(i,j) == white) {
                    j++;
                    while(j < y) {
                        gameBoard.flipTile(i,j);
                        whiteScore++;
                        blackScore--;
                        j++;
                    }
                }
            }

            //upper right: col+1, row-1
            if (gameBoard.getTile(x+1,y-1) == black) {
                int i = x+1;
                int j = y-1;
                while (gameBoard.getTile(i,j) == black && gameBoard.isValidTile(i,j)) {
                    i += 1;
                    j -= 1;
                }
                if (gameBoard.getTile(i,j) == white) {
                    i--;
                    j++;
                    while(i > x && j < y) {
                        gameBoard.flipTile(i,j);
                        whiteScore++;
                        blackScore--;
                        i--;
                        j++;
                    }
                }
            }

            //left: col-1, row
            if (gameBoard.getTile(x-1,y) == black) {
                int i = x-1;
                int j = y;
                while (gameBoard.getTile(i,j) == black && gameBoard.isValidTile(i,j)) {
                    i -= 1;
                }
                if (gameBoard.getTile(i,j) == white) {
                    i++;
                    while(i < x) {
                        gameBoard.flipTile(i,j);
                        whiteScore++;
                        blackScore--;
                        i++;
                    }
                }
            }

            //right: col+1, row
            if (gameBoard.getTile(x+1,y) == black) {
                int i = x+1;
                int j = y;
                while (gameBoard.getTile(i,j) == black && gameBoard.isValidTile(i,j)) {
                    i += 1;
                }
                if (gameBoard.getTile(i,j) == white) {
                    i--;
                    while(i > x) {
                        gameBoard.flipTile(i,j);
                        whiteScore++;
                        blackScore--;
                        i--;
                    }
                }
            }

            //bottom left: col-1, row+1
            if (gameBoard.getTile(x-1,y+1) == black) {
                int i = x-1;
                int j = y+1;
                while (gameBoard.getTile(i,j) == black && gameBoard.isValidTile(i,j)) {
                    i -= 1;
                    j += 1;
                }
                if (gameBoard.getTile(i,j) == white) {
                        i++;
                        j--;
                    while(i < x && j > y) {
                        gameBoard.flipTile(i,j);
                        whiteScore++;
                        blackScore--;
                        i++;
                        j--;
                    }
                }
            }

            //down: col, row+1
            if (gameBoard.getTile(x,y+1) == black) {
                int i = x;
                int j = y+1;
                while (gameBoard.getTile(i,j) == black && gameBoard.isValidTile(i,j)) {
                    j += 1;
                }
                if (gameBoard.getTile(i,j) == white) {
                        j--;
                    while(j > y) {
                        gameBoard.flipTile(i,j);
                        whiteScore++;
                        blackScore--;
                        j--;
                    }
                }
            }

            //bottom right: col+1, row+1
            if (gameBoard.getTile(x+1,y+1) == black) {
                int i = x+1;
                int j = y+1;
                while (gameBoard.getTile(i,j) == black && gameBoard.isValidTile(i,j)) {
                    i += 1;
                    j += 1;
                }
                if (gameBoard.getTile(i,j) == white) {
                        i--;
                        j--;
                    while(i > x && j > y) {
                        gameBoard.flipTile(i,j);
                        whiteScore--;
                        blackScore++;
                        i--;
                        j--;
                    }
                }
            }

        }
        else {
            gameBoard.setTile(black, x, y);
            blackScore++;

            //upper left: col-1, row-1
            if (gameBoard.getTile(x-1,y-1) == white) {
                int i = x-1;
                int j = y-1;
                while (gameBoard.getTile(i,j) == white && gameBoard.isValidTile(i,j)) {
                    i -= 1;
                    j -= 1;
                }
                if (gameBoard.getTile(i,j) == black) {
                    i++;
                    j++;
                    while(i < x && j < y) {
                        gameBoard.flipTile(i,j);
                        whiteScore--;
                        blackScore++;
                        i++;
                        j++;
                    }
                }
            }

            //up: col, row-1
            if (gameBoard.getTile(x,y-1) == white) {
                int i = x;
                int j = y-1;
                while (gameBoard.getTile(i,j) == white && gameBoard.isValidTile(i,j)) {
                    j -= 1;
                }
                if (gameBoard.getTile(i,j) == black) {
                    j++;
                    while(j < y) {
                        gameBoard.flipTile(i,j);
                        whiteScore--;
                        blackScore++;
                        j++;
                    }
                }
            }

            //upper right: col+1, row-1
            if (gameBoard.getTile(x+1,y-1) == white) {
                int i = x+1;
                int j = y-1;
                while (gameBoard.getTile(i,j) == white && gameBoard.isValidTile(i,j)) {
                    i += 1;
                    j -= 1;
                }
                if (gameBoard.getTile(i,j) == black) {
                    i--;
                    j++;
                    while(i > x && j < y) {
                        gameBoard.flipTile(i,j);
                        whiteScore--;
                        blackScore++;
                        i--;
                        j++;
                    }
                }
            }

            //left: col-1, row
            if (gameBoard.getTile(x-1,y) == white) {
                int i = x-1;
                int j = y;
                while (gameBoard.getTile(i,j) == white && gameBoard.isValidTile(i,j)) {
                    i -= 1;
                }
                if (gameBoard.getTile(i,j) == black) {
                    i++;
                    while(i < x) {
                        gameBoard.flipTile(i,j);
                        whiteScore--;
                        blackScore++;
                        i++;
                    }
                }
            }

            //right: col+1, row
            if (gameBoard.getTile(x+1,y) == white) {
                qDebug("rightttt");
                int i = x+1;
                int j = y;
                while (gameBoard.getTile(i,j) == white && gameBoard.isValidTile(i,j)) {
                    i += 1;
                }
                if (gameBoard.getTile(i,j) == black) {
                    i--;
                    while(i > x) {
                        gameBoard.flipTile(i,j);
                        whiteScore--;
                        blackScore++;
                        i--;
                    }
                }
            }

            //bottom left: col-1, row+1
            if (gameBoard.getTile(x-1,y+1) == white) {
                int i = x-1;
                int j = y+1;
                while (gameBoard.getTile(i,j) == white && gameBoard.isValidTile(i,j)) {
                    i -= 1;
                    j += 1;
                }
                if (gameBoard.getTile(i,j) == black) {
                    i++;
                    j--;
                    while(i < x && j > y) {
                        gameBoard.flipTile(i,j);
                        whiteScore--;
                        blackScore++;
                        i++;
                        j--;
                    }
                }
            }

            //down: col, row+1
            if (gameBoard.getTile(x,y+1) == white) {
                int i = x;
                int j = y+1;
                while (gameBoard.getTile(i,j) == white && gameBoard.isValidTile(i,j)) {
                    j += 1;
                }
                if (gameBoard.getTile(i,j) == black) {
                    j--;
                    while(j > y) {
                        gameBoard.flipTile(i,j);
                        whiteScore--;
                        blackScore++;
                        j--;
                    }
                }
            }

            //bottom right: col+1, row+1
            if (gameBoard.getTile(x+1,y+1) == white) {
                int i = x+1;
                int j = y+1;
                while (gameBoard.getTile(i,j) == white && gameBoard.isValidTile(i,j)) {
                    i += 1;
                    j += 1;
                }
                if (gameBoard.getTile(i,j) == black) {
                    i--;
                    j++;
                    while(i > x && j > y) {
                        gameBoard.flipTile(i,j);
                        whiteScore--;
                        blackScore++;
                        i--;
                        j--;
                    }
                }
            }
        }
    }
}

bool GameState::isValidMove(int x, int y) const noexcept
{
    if (isWhiteTurn()) {
        if (gameBoard.getTile(x,y) == empty) {
            //up left: x-1, y-1
            if (gameBoard.getTile(x-1,y-1) == black) {
                if (getEndOfLine(x-1,y-1,-1,-1) == white) {
                    return true;
                }
            }

            //up: x, y-1
            if (gameBoard.getTile(x,y-1) == black) {
                if (getEndOfLine(x,y-1,0,-1) == white) {
                    return true;
                }
            }

            //up right: x+1, y-1
            if (gameBoard.getTile(x+1,y-1) == black) {
                if (getEndOfLine(x+1,y-1,1,-1) == white) {
                    return true;
                }
            }

            //left: x-1, y
            if (gameBoard.getTile(x-1,y) == black) {
                if (getEndOfLine(x-1,y,-1,0) == white) {
                    return true;
                }
            }

            //right: x+1, y
            if (gameBoard.getTile(x+1,y) == black) {
                if (getEndOfLine(x+1,y,1,0) == white) {
                    return true;
                }
            }

            //down left: x-1, y+1
            if (gameBoard.getTile(x-1,y+1) == black) {
                if (getEndOfLine(x-1,y+1,-1,+1) == white) {
                    return true;
                }
            }

            //down: x, y+1
            if (gameBoard.getTile(x,y+1) == black) {
                if (getEndOfLine(x,y+1,0,1) == white) {
                    return true;
                }
            }

            //down right: x+1, y+1
            if (gameBoard.getTile(x+1,y+1) == black) {
                if (getEndOfLine(x+1,y+1,1,1) == white) {
                    return true;
                }
            }

            else {
                return false;
            }
        }
    }
    else {
        if (gameBoard.getTile(x,y) == empty) {
            //up left: x-1, y-1
            if (gameBoard.getTile(x-1,y-1) == white) {
                if (getEndOfLine(x-1,y-1,-1,-1) == black) {
                    return true;
                }
            }

            //up: x, y-1
            if (gameBoard.getTile(x,y-1) == white) {
                if (getEndOfLine(x,y-1,0,-1) == black) {
                    return true;
                }
            }

            //up right: x+1, y-1
            if (gameBoard.getTile(x+1,y-1) == white) {
                if (getEndOfLine(x+1,y-1,1,-1) == black) {
                    return true;
                }
            }

            //left: x-1, y
            if (gameBoard.getTile(x-1,y) == white) {
                if (getEndOfLine(x-1,y,-1,0) == black) {
                    return true;
                }
            }

            //right: x+1, y
            if (gameBoard.getTile(x+1,y) == white) {
                if (getEndOfLine(x+1,y,1,0) == black) {
                    return true;
                }
            }

            //down left: x-1, y+1
            if (gameBoard.getTile(x-1,y+1) == white) {
                if (getEndOfLine(x-1,y+1,-1,+1) == black) {
                    return true;
                }
            }

            //down: x, y+1
            if (gameBoard.getTile(x,y+1) == white) {
                if (getEndOfLine(x,y+1,0,1) == black) {
                    return true;
                }
            }

            //down right: x+1, y+1
            if (gameBoard.getTile(x+1,y+1) == white) {
                if (getEndOfLine(x+1,y+1,1,1) == black) {
                    return true;
                }
            }

            else {
                return false;
            }
        }
    }
}

TileState GameState::getEndOfLine(int x, int y, int xFac, int yFac) const
{
    if (gameBoard.getTile(x,y) == white) {
        while(gameBoard.getTile(x,y) == white && gameBoard.isValidTile(x,y)) {
            x += xFac;
            y += yFac;
        }
        return gameBoard.getTile(x,y);
    }
    else {
        while(gameBoard.getTile(x,y) == black && gameBoard.isValidTile(x,y)) {
            x += xFac;
            y += yFac;
        }
        return gameBoard.getTile(x,y);
    }
}
