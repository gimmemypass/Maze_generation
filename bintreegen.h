#ifndef BINTREEGEN_H
#define BINTREEGEN_H

#include "mazegen.h"

class BinTreeGen : public MazeGen
{
public:
    BinTreeGen(QGraphicsScene *scene, int r, int c);
    void gener() override;
};

#endif // BITTREEGEN_H
