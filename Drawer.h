#pragma once
#include <string>
#include "IDrawable.h"

class Image;

class Drawer
{
public:
	// 影を付けた文字列と値を表示する
	void drawText(int x, int y, const char* txt, int val, int col, int siz);

	// 文字列をセンタリングして表示する
	void drawTextC(int x, int y, const char* txt, int col, int siz);

	// 中心座標を指定して画像を表示する
	void drawImage(const Image& img, int x, int y);

	void drawGraphic(const IDrawable& data);


	//// 通常のDrawGraph()を実行する
	//void drawGraphic(const ImageData& data);

	//// 指定矩形部分のみを描画する(rawRectGraph)を実行する
	//void drawGraphic(const RectData& data);

	//// 円の描画(DrawCircle)を実行する
	//void drawGraphic(const CircleData& data);

	//// 四角形の描画(DrawBox)を実行する
	//void drawGraphic(const BoxData& data);

};