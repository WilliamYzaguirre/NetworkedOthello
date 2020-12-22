#include "diskgui.h"
#include <utility>
#include <QDebug>


DiskGui::DiskGui(QGraphicsItem *parent) : QGraphicsRectItem(parent)
{
    brush.setStyle(Qt::SolidPattern);
    setZValue(-1);
    setColor("None");
}

DiskGui::~DiskGui() {
    delete this;
}

//sets color of disk
void DiskGui::setColor(QColor color) {
    brush.setColor(color);
    setBrush(color);
}

//flips color of disk, white->black, black->white
void DiskGui::flipColor()
{
    if (brush.color() == Qt::white) {
        brush.setColor(Qt::black);
        setBrush(brush);
    }
    else {
        brush.setColor(Qt::white);
        setBrush(brush);
    }
}
