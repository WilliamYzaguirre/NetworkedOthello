#ifndef DISKGUI_H
#define DISKGUI_H
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QBrush>
#include "TileState.h"

class DiskGui : public QGraphicsRectItem
{

public:
    DiskGui(QGraphicsItem* parent = 0);
    ~DiskGui();

    void setColor(QColor color);

    void flipColor();

private:
    QBrush brush;
    QString color;
};

#endif // OTHELLOPIECE_H
