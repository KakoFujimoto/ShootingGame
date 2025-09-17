#include "Drawer.h"
#include "GameConfig.h"
#include "GameData.h"
#include "Image.h"
#include "BlendMode.h"
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

// 引数に与えた構造体の画像を描画する
void Drawer::drawGraphic(const IDrawable& data)
{
	data.drawGraphic();
}

// 描画の差異のブレンドモードをセットする
void Drawer::setBlendMode(BlendMode mode, int param)
{
	constexpr int DxBlendModes[] = {
		DX_BLENDMODE_ADD,
		DX_BLENDMODE_NOBLEND,
		DX_BLENDMODE_SUB
	};

	SetDrawBlendMode(DxBlendModes[static_cast<int>(mode)], param);
}