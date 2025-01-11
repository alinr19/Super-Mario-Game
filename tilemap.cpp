#include "tilemap.h"
#include "tilesetbitmap.h"
#include "lvl.h"

TileMap::TileMap() 
    : _tileMapWidth(1), _tileMapHeight(1), _tileWidth(8), _tileHeight(8), _tileMapID(nullptr) {}
void TileMap::getTileIndexByPos(int coordx, int coordy, int *pickedTile) {
    pickedTile[0] = coordx / _tileWidth;
    pickedTile[1] = coordy / _tileHeight;
}
void TileMap::getPosByTileIndex(int tilex, int tiley, int *result) {
    result[0] = tilex * _tileWidth;
    result[1] = tiley * _tileHeight;
}
unsigned int TileMap::getMapWidth() {
    return _tileMapWidth;
}
unsigned int TileMap::getMapHeight() {
    return _tileMapHeight;
}
unsigned int TileMap::getTileWidth() {
    return _tileWidth;
}
unsigned int TileMap::getTileHeight() {
    return _tileHeight;
}
void TileMap::setDisplayPointer(Adafruit_PCD8544 *disp) {
    _display = disp;
}
void TileMap::setTileSize(unsigned int width, unsigned int height) {
    _tileWidth = width;
    _tileHeight = height;
}
void TileMap::setMapSize(unsigned int width, unsigned int height) {
    _tileMapWidth = width;
    _tileMapHeight = height;
}
void TileMap::setTileMap(TILEMAPSET *tilemapArray) {
    _tileMapID = tilemapArray;
}
void TileMap::drawTile(const unsigned int id, int x, int y) {
    BMP *tileToDraw = nullptr;
    switch (id) {
        case 2: tileToDraw = tileset002; break;
        case 3: tileToDraw = tileset003; break;
        case 4: tileToDraw = tileset004; break;
        case 11: tileToDraw = tileset011; break;
        case 14: tileToDraw = tileset014; break;
        case 55: tileToDraw = tileset055; break;
        case 56: tileToDraw = tileset056; break;
        case 71: tileToDraw = tileset071; break;
        case 72: tileToDraw = tileset072; break;
        case 76: tileToDraw = tileset076; break;
        case 77: tileToDraw = tileset077; break;
        case 78: tileToDraw = tileset078; break;
        case 79: tileToDraw = tileset079; break;
        case 80: tileToDraw = tileset080; break;
        case 102: tileToDraw = tileset102; break;
        case 103: tileToDraw = tileset103; break;
        case 118: tileToDraw = tileset118; break;
        case 119: tileToDraw = tileset119; break;
        case 145: tileToDraw = tileset145; break;
        case 146: tileToDraw = tileset146; break;
        case 161: tileToDraw = tileset080; break;
        case 162: tileToDraw = tileset162; break;
        case 163: tileToDraw = tileset163; break;
        default: break;
    }
    if (tileToDraw != nullptr) {
        _display->drawBitmap(x, y, tileToDraw, _tileWidth, _tileHeight, 1);
    }
}
void TileMap::drawMap(int xCamera, int yCamera) {
    int tileStart[2] = {0, 0};
    int tileEnd[2] = {1, 1};
    getTileIndexByPos(xCamera, yCamera, tileStart);
    getTileIndexByPos(xCamera + _display->width() + _tileWidth, 
                      yCamera + _display->height(), tileEnd);
    xCamera *= -1;
    for (int y = tileStart[1]; y < tileEnd[1]; ++y) {
        for (int x = tileStart[0]; x < tileEnd[0]; ++x) {
            unsigned int tileIndex = x + (y * _tileMapWidth);
            tileIndex = pgm_read_word_near(&_tileMapID[tileIndex]);
            if (tileIndex > 0) {
                drawTile(tileIndex, xCamera + (x * _tileWidth), yCamera + (y * _tileHeight));
            }
        }
    }
}
