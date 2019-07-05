#include "wilsonsalg.h"

WilsonsAlg::WilsonsAlg(QGraphicsScene *scene, int r, int c):
    MazeGen (scene, r, c)
{}

void WilsonsAlg::gener(){
    int xr = rand() % this->col;
    int yr = rand() % this->row;
    grid[yr][xr].used = true;
    while(hunt(xr, yr)){
        stack.push_back(&grid[yr][xr]);
        grid[yr][xr].rect->setBrush(Qt::green);
        searchBranch(xr, yr);
    }
    drawGrid();
}

bool WilsonsAlg::hunt(int &x, int &y)
{
    x = y = 0;
    int yr = rand() % this->row,
        xr = rand() % this->col;
    int count = this->row * this->col;
    for(int ir = yr, second = 0; ir < ((ir >= yr)? this->row:yr); (ir != this->row - 1)? (ir++):(ir=0, second++)){
        for(int ic = (!second && ir == yr)? xr:0; ic < ((second && ir == yr)? xr:this->col);ic++, count--){
            if(!grid[ir][ic].used){
                x = ic;
                y = ir;
                return true;
            }
            if(count == 1){
                return false;
            }
        }
    }
}

void WilsonsAlg::connectWalls(QPoint first, QPoint second){
    switch((first.x()-second.x())){
        case -1:
            grid[first.y()][first.x()].right = false;
            grid[second.y()][second.x()].left = false;
            break;
        case 1:
            grid[first.y()][first.x()].left = false;
            grid[second.y()][second.x()].right = false;
            break;
    }
    switch(first.y() - second.y()){
        case -1:
            grid[first.y()][first.x()].bottom = false;
            grid[second.y()][second.x()].top = false;
            break;
        case 1:
            grid[first.y()][first.x()].top = false;
            grid[second.y()][second.x()].bottom = false;
            break;
    }
}

void WilsonsAlg::searchBranch(int x, int y)
{
    while(true){
        char dir[4] = {'t','r','b','l'};
        switch (dir[rand() % 4]){
            case 't':
                if(y > 0){
                    stack.push_back(&grid[y - 1][x]);
                    if(stack.back()->used){
                        createBranch();
                        return;
                    }
                    if(stack.back()->rect->brush().color() != Qt::green){
                        stack.back()->rect->setBrush(Qt::green);
                        searchBranch(x, y - 1);
                        return;
                    }
                    else {
                        stack.back()->rect->setBrush(QColor(Qt::blue));
                        stack.pop_back();
                        removeCycle();
                        searchBranch(x, y - 1);
                        return;
                    }
                }
                break;
            case 'r':
                if(x + 1 < this->col){
                    stack.push_back(&grid[y][x + 1]);
                    if(stack.back()->used){
                        createBranch();
                        return;
                    }
                    if(stack.back()->rect->brush().color() != Qt::green){
                        stack.back()->rect->setBrush(Qt::green);
                        searchBranch(x + 1, y);
                        return;
                    }
                    else {
                        stack.back()->rect->setBrush(QColor(Qt::blue));
                        stack.pop_back();
                        removeCycle();
                        searchBranch(x + 1, y);
                        return;
                    }
                }
                break;
            case 'b':
                if(y + 1 < this->row){
                    stack.push_back(&grid[y + 1][x]);
                    if(stack.back()->used){
                        createBranch();
                        return;
                    }
                    if(stack.back()->rect->brush().color() != Qt::green){
                        stack.back()->rect->setBrush(Qt::green);
                        searchBranch(x, y + 1);
                        return;
                    }
                    else {
                        stack.back()->rect->setBrush(QColor(Qt::blue));
                        stack.pop_back();
                        removeCycle();
                        searchBranch(x, y + 1);
                        return;
                    }
                }
                break;
            case 'l':
                if(x > 0){
                    stack.push_back(&grid[y][x - 1]);
                    if(stack.back()->used){
                        createBranch();
                        return;
                    }
                    if(stack.back()->rect->brush().color() != Qt::green){
                        stack.back()->rect->setBrush(Qt::green);
                        searchBranch(x - 1, y);
                        return;
                    }
                    else {
                        stack.back()->rect->setBrush(QColor(Qt::blue));
                        stack.pop_back();
                        removeCycle();
                        searchBranch(x - 1, y);
                        return;
                    }
                }
                break;
        }
    }
}

void WilsonsAlg::removeCycle()
{
    while(stack.back()->rect->brush().color() == Qt::green){
        stack.back()->rect->setBrush(QColor(0,3,35));
        stack.pop_back();
    }
    stack.back()->rect->setBrush(Qt::green);
}

void WilsonsAlg::createBranch(){
    while(stack.size() > 1){
        QPoint first, second;
        first.setX(stack.back()->x);
        first.setY(stack.back()->y);
        stack.pop_back();
        stack.back()->rect->setBrush(QColor(0,3,35));
        stack.back()->used = true;
        second.setX(stack.back()->x);
        second.setY(stack.back()->y);
        connectWalls(first, second);
    }
    stack.pop_back();
}
