#ifndef HUNT_AND_HINT_H
#define HUNT_AND_HINT_H

#include "mazegen.h"

class Hunt_and_Hint : public MazeGen
{
public:
    Hunt_and_Hint(QGraphicsScene *scene, int r = 10, int c = 10);
    void hint(int x, int y);
    bool hunt(int &x, int &y);
    bool neighbour_is_used(const int x, const int y); //Функция для hunt. Проверяет, имеет ли найденная клетка посещенных соседей
    void connectWalls(int x, int y); //Соединяет найденную "жертву" с уже использованной клеткой поблизости
    void gener() override;
};

#endif // HUNT_AND_HINT_H
