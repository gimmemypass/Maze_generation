#include "hunt_and_hint.h"

Hunt_and_Hint::Hunt_and_Hint(QGraphicsScene *scene, int r, int c) :
    MazeGen (scene, r, c)
{

}

void Hunt_and_Hint::connectWalls(int x, int y){
    std::vector<char> seq = {'l','t','r','b'};
      while(!seq.empty()){
        int r = rand() % seq.size();
        switch (seq[r]){
            case 't':
            if((y-1) >= 0 && grid[y-1][x].used){
                    grid[y][x].top = false;
                    grid[y-1][x].bottom = false;
                    return;
                }
                break;
            case 'r':
                if((x+1) < this->col && grid[y][x + 1].used){
                    grid[y][x].right = false;
                    grid[y][x + 1].left = false;
                    return;
                }
                break;
            case 'b':
                if((y+1) < this->row && grid[y + 1][x].used){
                    grid[y][x].bottom = false;
                    grid[y + 1][x].top = false;
                    return;
                }
                break;
            case 'l':
                if((x - 1) >= 0 && grid[y][x - 1].used){
                    grid[y][x].left = false;
                    grid[y][x - 1].right = false;
                    return;
                }
                break;
        }
        seq.erase(seq.begin() + r);
    }
}

void Hunt_and_Hint::gener(){
    hint(rand() % this->col, rand() % this->row);
    int x, y;
    while(hunt(x, y)){
        connectWalls(x,y);
        hint(x,y);
    }
    drawGrid();
}

bool Hunt_and_Hint::hunt(int &x, int &y){
    x = y = 0;
    for(int ir = 0; ir < this->row; ir++){
        for(int ic = 0; ic < this->col; ic++){
            if(!grid[ir][ic].used && neighbour_is_used(ic, ir)){
                x = ic;
                y = ir;
                return true;
            }
        }
    }
    return false;
}

bool Hunt_and_Hint::neighbour_is_used(const int x, const int y)
{
    return ((y > 0 && grid[y-1][x].used) ||
            (y < (this->row - 1) && grid[y+1][x].used) ||
            (x > 0 && grid[y][x - 1].used) ||
            (x < (this->col - 1) && grid[y][x + 1].used));
}



void Hunt_and_Hint::hint(int x, int y){
    grid[y][x].used = true;
    std::vector<char> seq = {'l','t','r','b'};
      while(!seq.empty()){
        int r = rand() % seq.size();
        switch (seq[r]){
            case 't':
                if((y - 1) >= 0 && !grid[y - 1][x].used){
                    grid[y][x].top = false;
                    grid[y - 1][x].bottom = false;
                    hint(x, y - 1);
                    return;
                }
                break;
            case 'r':
                if((x+1) < this->col && !grid[y][x + 1].used){
                    grid[y][x].right = false;
                    grid[y][x + 1].left = false;
                    hint(x + 1, y);
                    return;
                }
                break;
            case 'b':
                if((y+1) < this->row && !grid[y + 1][x].used){
                    grid[y][x].bottom = false;
                    grid[y + 1][x].top = false;
                    hint(x, y + 1);
                    return;
                }
                break;
            case 'l':
                if((x - 1) >= 0 && !grid[y][x - 1].used){
                    grid[y][x].left = false;
                    grid[y][x - 1].right = false;
                    hint(x - 1, y);
                    return;
                }
                break;
        }
        seq.erase(seq.begin() + r);
    }
}
