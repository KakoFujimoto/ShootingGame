#pragma once
#include <string>
#include "GameManager.h"

class Drawer
{
public:
	// 影を付けた文字列と値を表示する関数
	void drawText(int x, int y, const char* txt, int val, int col, int siz);

	// 文字列をセンタリングして表示する関数
	void drawTextC(int x, int y, const char* txt, int col, int siz);

	// 中心座標を指定して画像を表示する関数
	void drawImage(int img, int x, int y);

};