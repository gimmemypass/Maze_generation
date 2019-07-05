#ifndef MAZEGEN_H
#define MAZEGEN_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <ctime>
#include <QThread>
#include <QDebug>

#include "cell.h"

class MazeGen
{
public:
    MazeGen(QGraphicsScene *scene, int r = 10, int c = 10);
    virtual ~MazeGen();
    virtual void drawGrid();
    virtual void gener() = 0;
    virtual bool solveMaze(int x, int y);
    QPoint get_in_point();
protected:
    int row,
        col;
    QPoint in,
           out;
    Cell **grid;
    QGraphicsScene *scene;
};

#endif // MAZEGEN_H
