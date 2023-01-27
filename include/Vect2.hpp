#pragma once

struct Vect2{
    int x;
    int y;
    bool est_egal(Vect2 v)
    {
        return (this->x == v.x) && (this->y == v.y);
    }
};