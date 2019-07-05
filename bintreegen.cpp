#include "bintreegen.h"

BinTreeGen::BinTreeGen(QGraphicsScene *scene, int r, int c) :
    MazeGen (scene, r, c)
{
    grid[in.y()][0].left = grid[out.y()][this->col - 1].right = true;
    in.setY(0);
    out.setY(this->row - 1);
    grid[in.y()][0].left = grid[out.y()][this->col - 1].right = false;
}

void BinTreeGen::gener()
{
    int r;
    for(int ir = 0; ir < this->row; ir++){
        for (int ic = 0; ic < this->col ; ic++) {
            grid[ir][ic].used = true;
           if (ir == 0 && ic == 0)
               continue;
           else if(ir == 0)
               r = 0;
           else if(ic == 0)
               r = 1;
           else
               r = rand() % 2; // 0 - left, 1-top

           switch (r){
           case 0:
               grid[ir][ic].left = false;
               grid[ir][ic - 1].right = false;
               break;
           case 1:
               grid[ir][ic].top = false;
               grid[ir - 1][ic].bottom = false;
           }
        }
    }
    drawGrid();
}
