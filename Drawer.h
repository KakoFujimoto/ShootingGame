#pragma once
#include <string>
#include "DrawerManager.h"

class Drawer
{
public:
    void drawText(int x, int y, const std::string& text, const DrawerManager::TextStyle& style = DrawerManager::DefaultTextStyle());
    void drawImage(int x, int y, int img, const DrawerManager::ImageStyle& style);

};