#include "Headers/map.h"

Map::Map(){
    width = MAP_WIDTH;
    height = MAP_HEIGHT;
}

int Map::getWidth() const{
    return width;
}
int Map::getHeight() const{
    return height;
}
