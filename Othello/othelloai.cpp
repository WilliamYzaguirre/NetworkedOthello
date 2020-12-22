#include "othelloai.h"
#include "TileState.h"
//#include "gamestate.h"

OthelloAI::OthelloAI()
{

}

std::pair<int, int> OthelloAI::chooseMove(GameState* state)
{
    int myColor;
        if (state->isBlackTurn()) {
            myColor = 1; //i am black
        }
        else {
            myColor = 0; //i am white
        }

        //make vector of possible moves. x, y. width, height
        std::vector<std::pair<int, int>> possibleMoves = getMoves(state->clone());
        std::vector<int> highestMoveScore;


        //go through all possible moves and find best move by finding which gives the highest score
        for (unsigned int i = 0; i < possibleMoves.size(); ++i) {
            std::unique_ptr<GameState> moved = state->clone();
            moved->makeMove(possibleMoves[i].first, possibleMoves[i].second);
            highestMoveScore.push_back(search(moved, 2, false, myColor));
        }

        //go through all possible score and save the index of the best
        int pos = 0;
        int currentHigh = highestMoveScore[0];
        for (unsigned int i = 1; i < highestMoveScore.size(); ++i) {
            if (currentHigh > highestMoveScore[i]) {
                pos = i;
            }
        }

        return possibleMoves[pos];
}

int OthelloAI::search(std::unique_ptr<GameState> &s, int depth, bool myTurn, int myColor)
{
    if (depth == 0) {
            //if my turn
            return evaluateBoard(s, myColor);
        }
        else {
            //find all moves
            std::vector<std::pair<int, int>> possibleMoves = getMoves(s);
            if (possibleMoves.size() == 0) {
                return evaluateBoard(s, myColor);
            }
            std::vector<int> moveScores;
            //if its my turn,
            if (myTurn) {
                for (unsigned int i = 0; i < possibleMoves.size(); ++i) {
                    std::unique_ptr<GameState> moved = s->clone();
                    moved->makeMove(possibleMoves[i].first, possibleMoves[i].second);
                    moveScores.push_back(search(moved, depth - 1, false, myColor));
                }
                int loc = 0;
                int start = moveScores[0];
                for (unsigned int i = 0; i < moveScores.size(); i++) {
                    if (start > moveScores[i]) {
                        loc = i;
                    }
                }
                return moveScores[loc];
            }
            //not my turn
            else {
                for (unsigned int i = 0; i < possibleMoves.size(); ++i) {
                    std::unique_ptr<GameState> moved = s->clone();
                    moved->makeMove(possibleMoves[i].first, possibleMoves[i].second);
                    moveScores.push_back(search(moved, depth - 1, true, myColor));
                }
                int loc = 0;
                int start = moveScores[0];
                for (unsigned int i = 0; i < moveScores.size(); i++) {
                    if (start > moveScores[i]) {
                        loc = i;
                    }
                }
                return moveScores[loc];
            }
        }
}

std::vector<std::pair<int, int> > OthelloAI::getMoves(const std::unique_ptr<GameState> &s)
{
    std::vector<std::pair<int, int>> possibleMoves;
        //go through whole board to find all possible move locations
        for (int x = 0; x < 8; ++x) {
            for (int y = 0; y < 8; ++y) {
                if (s->isValidMove(x, y) == true) {
                    possibleMoves.push_back(std::make_pair(x, y));
                }
            }
        }
        return possibleMoves;
}

int OthelloAI::evaluateBoard(const std::unique_ptr<GameState> &s, int myColor)
{
    ///////////////make vectors of tiles and assign points based on tile importance/////////////////
        std::vector<std::pair<int, int>> corners = {std::make_pair(0,0), std::make_pair(7,7), std::make_pair(0,7), std::make_pair(7,0)};
        std::vector<std::pair<int, int>> cornAdj = {std::make_pair(1,0), std::make_pair(0,1), std::make_pair(1,1), std::make_pair(6,0), std::make_pair(6,1), std::make_pair(7,0), std::make_pair(0,6), std::make_pair(1,6), std::make_pair(1,7), std::make_pair(6,7), std::make_pair(7,6), std::make_pair(6,6)};
        std::vector<std::pair<int, int>> centerNine;
        for (int i = 2; i < 6; ++i) {
            for (int j = 2; j < 6; ++j) {
                centerNine.push_back(std::make_pair(i,j));
            }
        }
        std::vector<std::pair<int, int>> edges = {std::make_pair(0,2), std::make_pair(0,3), std::make_pair(0,4), std::make_pair(0,5), std::make_pair(7,2), std::make_pair(7,3), std::make_pair(7,4), std::make_pair(7,5), std::make_pair(2,0), std::make_pair(3, 0), std::make_pair(4, 0), std::make_pair(5, 0), std::make_pair(2,7), std::make_pair(3, 7), std::make_pair(4, 7), std::make_pair(5, 7)};
    ///////////////////////////////////////////////////////////////////////////////////////////////

        //figure out where my current pieces are
        int totalPoints = 0;
        if (s->isGameOver()) {
            //if i'm black
            if (myColor == 1) {
                //if I win, choose this move
                if (s->getBlackScore() > s->getWhiteScore()) {
                    totalPoints -= 100;
                }
                //if I lose, don't choose this move
                else if (s->getWhiteScore() > s->getBlackScore()) {
                    totalPoints += 100;
                }
            }
            //if I'm white
            else if (myColor == 0) {
                //if i win, choose this move
                if (s->getWhiteScore() > s->getBlackScore()) {
                    totalPoints -= 100;
                }
                //if i lose, don't choose this move
                else if (s->getBlackScore() > s->getWhiteScore()) {
                    totalPoints += 100;
                }
            }
        }
        std::vector<std::pair<int, int>> pieceLocation;
        if (s->isBlackTurn()) {
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
                    if (s->board().getTile(i, j) == TileState::black) {
                        pieceLocation.push_back(std::make_pair(i,j));
                    }
                }
            }
            int totalPieces = pieceLocation.size();
            int piecePoints = 0;
            for (std::pair<int, int> piece : pieceLocation) {
                for (std::pair<int, int> corner : corners) {
                    if (piece == corner) {
                        piecePoints -= 2;
                    }
                }
                for (std::pair<int, int> adj : cornAdj) {
                    if (piece == adj) {
                        piecePoints += 4;
                    }
                }
                for (std::pair<int, int> center : centerNine) {
                    if (piece == center) {
                        piecePoints += 0;
                    }
                }
                for (std::pair<int, int> edge : edges) {
                    if (piece == edge) {
                        piecePoints -= 1;
                    }
                }
            }
            totalPoints += totalPieces + piecePoints;
            return totalPoints;
        }
        else {
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
                    if (s->board().getTile(i, j) == TileState::white) {
                        pieceLocation.push_back(std::make_pair(i,j));
                    }
                }
            }
            int totalPieces = pieceLocation.size();
            int piecePoints = 0;
            for (std::pair<int, int> piece : pieceLocation) {
                for (std::pair<int, int> corner : corners) {
                    if (piece == corner) {
                        piecePoints -= 2;
                    }
                }
                for (std::pair<int, int> adj : cornAdj) {
                    if (piece == adj) {
                        piecePoints += 4;
                    }
                }
                for (std::pair<int, int> center : centerNine) {
                    if (piece == center) {
                        piecePoints += 0;
                    }
                }
                for (std::pair<int, int> edge : edges) {
                    if (piece == edge) {
                        piecePoints -= 1;
                    }
                }
            }
            totalPoints += totalPieces + piecePoints;
            return totalPoints;
        }
}
