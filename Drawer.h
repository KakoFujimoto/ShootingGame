#pragma once
#include <string>
#include "IDrawable.h"

class Image;
enum class BlendMode;

class Drawer
{
public:
	// 影を付けた文字列と値を表示する
	void drawText(int x, int y, const char* txt, int val, int col, int siz);

	// 文字列をセンタリングして表示する
	void drawTextC(int x, int y, const char* txt, int col, int siz);

	// 中心座標を指定して画像を表示する
	void drawImage(const Image& img, int x, int y);

	// 引数に与えた構造体の画像を描画する
	void drawGraphic(const IDrawable& data);

	// 描画の差異のブレンドモードをセットする
	void setBlendMode(BlendMode mode, int param);
};