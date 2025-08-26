#include "Drawer.h"
#include <DxLib.h>

void Drawer::drawText(int x, int y, const std::string& text, const DrawerManager::TextStyle& style)
{
	SetFontSize(style.size);

	int drawX = x;
	int drawY = y;

    if (style.center) {
        int strWidth = GetDrawStringWidth(text.c_str(), text.size());
        drawX -= strWidth / 2;
        drawY -= style.size / 2;
    }

    if (style.shadow) {
        DrawString(drawX + 1, drawY + 1, text.c_str(), GetColor(0, 0, 0));
    }
    DrawString(drawX, drawY, text.c_str(), style.color);
}

//使用イメージ
//Drawer drawer;
//DrawerManager::TextStyle style = DrawerManager::DefaultTextStyle();
//style.size = 20;
//style.color = GetColor(255, 0, 0);
//style.shadow = true;
//drawer.drawText(400, 300, "Hello, World!", style);

void Drawer::drawImage(int x, int y, int img, const DrawerManager::ImageStyle& style) {
    int w, h;
    GetGraphSize(img, &w, &h);

    int drawX = x;
    int drawY = y;

    if (style.center) {
        drawX -= w / 2;
        drawY -= h / 2;
    }

    DrawGraph(drawX, drawY, img, TRUE);
}