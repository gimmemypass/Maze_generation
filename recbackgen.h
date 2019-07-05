#ifndef RECBACKGEN_H
#define RECBACKGEN_H

#include "mazegen.h"
#include <QTimer>

class RecBackGen : public MazeGen
{
public:
    RecBackGen(QGraphicsScene *scene, int r = 10, int c = 10);
    void rec(int x, int y);
    void gener() override;
//    ~RecBackGen()override;
};

#endif // RECBACKGEN_H
