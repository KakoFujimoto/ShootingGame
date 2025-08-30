#pragma once
#include <string>

class Drawer
{
public:
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

    //void drawImage(int x, int y, int img, const DrawerManager::ImageStyle& style);

};