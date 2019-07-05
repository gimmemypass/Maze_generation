#include "mazegen.h"

MazeGen::MazeGen(QGraphicsScene *scene, int r, int c)
{
    this->row = r;
    this->col = c;
    Cell::width = 800 / c;
    Cell::height = 600 / r;
    grid = new Cell*[r];
    for(int i = 0; i < r; i++){
        grid[i] = new Cell[c];
        for(int j = 0; j < c; j++){
            grid[i][j].rect =  new QGraphicsRectItem(j*Cell::width + Cell::width*3/8 - 1, i*Cell::height + Cell::height*3/8 - 1,Cell::width/4 + 2,Cell::height/3 + 2);
            grid[i][j].rect->setBrush(QColor(0,3,35));
            grid[i][j].y = i;
            grid[i][j].x = j;
        }
    }
    srand(time(0));
    in.setX(0);
    in.setY(rand() % this->row);
    out.setX(c - 1);
    out.setY(rand() % this->row);
    grid[in.y()][0].left = false;
    grid[out.y()][c - 1].right = false;
    this->scene = scene;
}

MazeGen::~MazeGen(){
    for(int i = 0; i < this->row; i++){
        delete[] grid[i];
    }
    delete[] grid;
}

void MazeGen::drawGrid(){

    scene->clear();
//    scene->removeItem(grid[0][0].rect);
    for (int ir = 0 ; ir < this->row; ir++) {
        for(int ic = 0; ic < this->col; ic++){
            scene->addItem(grid[ir][ic].rect);
            if(grid[ir][ic].top)
                scene->addLine(ic * Cell::width, ir * Cell::height,
                              (ic + 1) * Cell::width, ir * Cell::height,
                               QPen(Qt::white));

            if(grid[ir][ic].right)
                scene->addLine((ic + 1) * Cell::width, ir * Cell::height,
                              (ic + 1) * Cell::width, (ir + 1) * Cell::height,
                               QPen(Qt::white));

            if(grid[ir][ic].bottom)
                scene->addLine((ic + 1) * Cell::width, (ir + 1) * Cell::height,
                                ic * Cell::width, (ir + 1) * Cell::height,
                               QPen(Qt::white));

            if(grid[ir][ic].left)
                scene->addLine(ic * Cell::width, (ir + 1) * Cell::height,
                               ic * Cell::width, ir * Cell::height,
                               QPen(Qt::white));

        }
    }
}

bool MazeGen::solveMaze(int x, int y){
    grid[y][x].used = false; //false в данном случае обозначает, что мы посетили клетку, т к все непосещенные true
    grid[y][x].rect->setBrush(Qt::red);
    if(y == out.y() && x == this->col - 1)
        return true;
    if(!grid[y][x].right && (x+1) < this->col && grid[y][x + 1].used && solveMaze(x+1,y)){
        return true;
    }
    if(!grid[y][x].bottom && (y+1) < this->row && grid[y + 1][x].used && solveMaze(x,y + 1)){
        return true;
    }
    if(!grid[y][x].left && x > 0 && grid[y][x - 1].used && solveMaze(x - 1,y)){
        return true;
    }
    if(!grid[y][x].top && y > 0 && grid[y - 1][x].used && solveMaze(x,y - 1)){
        return true;
    }
    grid[y][x].rect->setBrush(QColor(0,3,35));
    return false;
}

QPoint MazeGen::get_in_point()
{
    return in;
}



