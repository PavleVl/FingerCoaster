#ifndef MAP_H
#define MAP_H

#include "Headers/configuration.h"

class Map
{
public:
    Map();
    ~Map();
    int getWidth()const;
    int getHeight()const;
private:
    int width;
    int height;
};

#endif // MAP_H
