#ifndef TILEGUI_H
#define TILEGUI_H

#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>
#include <QObject>
#include "TileState.h"
#include "diskgui.h"

class TileGui : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:

    TileGui(QGraphicsItem *parent = 0);
    ~TileGui();

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    void setColor(QColor color);

    void setLocation(int x, int y);

    void setState(TileState state);

    TileState getState();

    //void flipTile();

    //void setDisk(DiskGui* disk);

signals:
    void tileClicked(int, int);

private:
    QBrush brush;
    int rowLoc;
    int colLoc;
    TileState state;
    //DiskGui* disk;
};

#endif // TILE_H
