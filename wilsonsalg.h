#ifndef WILSONSALG_H
#define WILSONSALG_H

#include "mazegen.h"

#include <vector>
#include <QPoint>

class WilsonsAlg : public MazeGen
{
public:
    WilsonsAlg(QGraphicsScene *scene, int r, int c);
    void gener() override;
    bool hunt(int &x, int &y);
    void connectWalls(QPoint first, QPoint second);
    void searchBranch(int x, int y);
    void createBranch();
    void removeCycle();
private:
    std::vector<Cell*> stack;
};

#endif // WILSONSALG_H
