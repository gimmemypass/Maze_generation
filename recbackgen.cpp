#include "recbackgen.h"


RecBackGen::RecBackGen(QGraphicsScene *scene, int r, int c) :
    MazeGen (scene,r, c)
{

}

void RecBackGen::gener(){
    rec(0,0);
    drawGrid();
}

void RecBackGen::rec(int x, int y){
    grid[y][x].used = true;
    std::vector<char> seq = {'l','t','r','b'};
      while(!seq.empty()){
        int r = rand() % seq.size();
        switch (seq[r]){
            case 't':
                if((y - 1) >= 0 && !grid[y - 1][x].used){
                    grid[y][x].top = false;
                    grid[y - 1][x].bottom = false;
                    rec(x, y - 1);
                }
                break;
            case 'r':
                if((x+1) < this->col && !grid[y][x + 1].used){
                    grid[y][x].right = false;
                    grid[y][x + 1].left = false;
                    rec(x + 1, y);
                }
                break;
            case 'b':
                if((y+1) < this->row && !grid[y + 1][x].used){
                    grid[y][x].bottom = false;
                    grid[y + 1][x].top = false;
                    rec(x, y + 1);
                }
                break;
            case 'l':
                if((x - 1) >= 0 && !grid[y][x - 1].used){
                    grid[y][x].left = false;
                    grid[y][x - 1].right = false;
                    rec(x - 1, y);
                }
                break;

        }
        seq.erase(seq.begin() + r);
    }
}
