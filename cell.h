#ifndef CELL_H
#define CELL_H

#include <QGraphicsRectItem>
#include <QDebug>

class Cell
{
public:
    Cell();
    ~Cell();
    bool left,
         right,
         top,
         bottom;
    static int width,
               height;
    bool used;
    QGraphicsRectItem *rect;
    int x,
        y;
};

#endif // CELL_H
