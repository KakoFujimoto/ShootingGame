#include "Drawer.h"
#include "GameConfig.h"
#include "GameData.h"
#include "Image.h"
#include <DxLib.h>

// 影を付けた文字列と値を表示する
void Drawer::drawText(int x, int y, const char* txt, int val, int col, int siz)
{
	SetFontSize(siz); // フォントの大きさを指定
	DrawFormatString(x + 1, y + 1, 0x000000, txt, val); // 黒で文字列を表示
	DrawFormatString(x, y, col, txt, val); // 引数の色で文字列を表示
}

// 文字列をセンタリングして表示する
void Drawer::drawTextC(int x, int y, const char* txt, int col, int siz)
{
	SetFontSize(siz);
	int strWidth = GetDrawStringWidth(txt, strlen(txt));
	x -= strWidth / 2;
	y -= siz / 2;
	DrawString(x + 1, y + 1, txt, 0x000000);
	DrawString(x, y, txt, col);
}

// 中心座標を指定して画像を表示する
void Drawer::drawImage(const Image& img, int x, int y)
{	
	int imgId = img.getId();
	int w, h;
	GetGraphSize(imgId, &w, &h);
	DrawGraph(x - w / 2, y - h / 2, imgId, TRUE);
}

void Drawer::drawGraphic(const IDrawable& data)
{
	data.drawGraphic();
}
//// 通常のDrawGraph()を実行する
//void Drawer::drawGraphic(const ImageData& data)
//{
//	DrawGraph(data.x, data.y, data.img.getId(), data.isTransParent);
//}
//
//// 指定矩形部分のみを描画する(rawRectGraph)を実行する
//void Drawer::drawGraphic(const RectData& data)
//{	
//	DrawRectGraph(data.x, data.y, data.srcX, data.srcY, data.w, data.h, data.img.getId(), TRUE, FALSE);
//}
//
//// 円の描画(DrawCircle)を実行する
//void Drawer::drawGraphic(const CircleData& data)
//{
//	DrawCircle(data.x, data.y, data.r, data.color, data.isFilled);
//}
//
//// 四角形の描画(DrawBox)を実行する
//void Drawer::drawGraphic(const BoxData& data)
//{
//	DrawBox(data.left, data.top, data.right, data.bottom, data.color, data.isFilled);
//}