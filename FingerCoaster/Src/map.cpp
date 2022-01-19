#include "Headers/map.h"

Map::Map(){
    width = MAP_WIDTH;
    height = MAP_HEIGHT;
}

auto Map::getWidth() const -> int{
    return width;
}
auto Map::getHeight() const -> int{
    return height;
}
