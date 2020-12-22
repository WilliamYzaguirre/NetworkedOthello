#ifndef OTHELLOBOARD_H
#define OTHELLOBOARD_H
#include <QGraphicsRectItem>
#include "tilegui.h"
#include <QObject>


class OthelloBoard : public QObject
{
    Q_OBJECT
public:
    OthelloBoard();
    OthelloBoard(const OthelloBoard& b);
    ~OthelloBoard();

    void setTile(TileState state, int x, int y);
    TileState getTile(int x, int y) const;
    void flipTile(int x, int y);

    bool isValidTile(int x, int y) const;

signals:
    void tileFlipped(int, int);
    void tileSet(int, int, TileState);

private:
    TileState board[8][8];

};

#endif // OTHELLOBOARD_H

