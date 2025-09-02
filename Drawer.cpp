#include "Drawer.h"
#include "GameConfig.h"
#include "GameData.h"
#include <DxLib.h>

// 影を付けた文字列と値を表示する関数
void drawText(int x, int y, const char* txt, int val, int col, int siz)
{
	SetFontSize(siz); // フォントの大きさを指定
	DrawFormatString(x + 1, y + 1, 0x000000, txt, val); // 黒で文字列を表示
	DrawFormatString(x, y, col, txt, val); // 引数の色で文字列を表示
}

// 文字列をセンタリングして表示する関数
void drawTextC(int x, int y, const char* txt, int col, int siz)
{
	SetFontSize(siz);
	int strWidth = GetDrawStringWidth(txt, strlen(txt));
	x -= strWidth / 2;
	y -= siz / 2;
	DrawString(x + 1, y + 1, txt, 0x000000);
	DrawString(x, y, txt, col);
}

// 中心座標を指定して画像を表示する関数
void drawImage(int img, int x, int y)
{
	int w, h;
	GetGraphSize(img, &w, &h);
	DrawGraph(x - w / 2, y - h / 2, img, TRUE);
}

// 自機に関するパラメーターを表示
void drawParameter(GameManager& game)
{
	int x = 10, y = GameConfig::HEIGHT - 30; // 表示位置
	DrawBox(x, y, x + GameConfig::PLAYER_SHIELD_MAX * 30, y + 20, 0x000000, TRUE);

	for (int i = 0; i < game.getPlayer().getShield(); i++) // シールドのメーター
	{
		int r = 128 * (GameConfig::PLAYER_SHIELD_MAX - i) / GameConfig::PLAYER_SHIELD_MAX; // RGB値を計算
		int g = 255 * i / GameConfig::PLAYER_SHIELD_MAX;
		int b = 160 + 96 * i / GameConfig::PLAYER_SHIELD_MAX;
		DrawBox(x + 2 + i * 30, y + 2, x + 28 + i * 30, y + 18, GetColor(r, g, b), TRUE);
	}
	drawText(x, y - 25, "SHIELD Lv %02d", game.getPlayer().getShield(), 0xffffff, 20); // シールド値
	drawText(x, y - 50, "WEAPON Lv %02d", game.getGameData().weaponLv, 0xffffff, 20); // 武器レベル
	drawText(x, y - 75, "SPEED %02d", game.getPlayer().getVX(), 0xffffff, 20); // 移動速度
}



//void Drawer::drawText(int x, int y, const std::string& text, const DrawerManager::TextStyle& style)
//{
//
//	SetFontSize(style.size);
//
//	int drawX = x;
//	int drawY = y;
//
//    if (style.center) {
//        int strWidth = GetDrawStringWidth(text.c_str(), text.size());
//        drawX -= strWidth / 2;
//        drawY -= style.size / 2;
//    }
//
//    if (style.shadow) {
//        DrawString(drawX + 1, drawY + 1, text.c_str(), GetColor(0, 0, 0));
//    }
//    DrawString(drawX, drawY, text.c_str(), style.color);
//}

//使用イメージ
//Drawer drawer;
//DrawerManager::TextStyle style = DrawerManager::DefaultTextStyle();
//style.size = 20;
//style.color = GetColor(255, 0, 0);
//style.shadow = true;
//drawer.drawText(400, 300, "Hello, World!", style);

//void Drawer::drawImage(int x, int y, int img, const DrawerManager::ImageStyle& style) {
//    int w, h;
//    GetGraphSize(img, &w, &h);
//
//    int drawX = x;
//    int drawY = y;
//
//    if (style.center) {
//        drawX -= w / 2;
//        drawY -= h / 2;
//    }
//
//    DrawGraph(drawX, drawY, img, TRUE);
//}

//DrawerManager::TextStyle DrawerManager::DefaultTextStyle() {
//	return TextStyle();
//}