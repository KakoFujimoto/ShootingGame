#include "Drawer.h"
#include "GameConfig.h"
#include "GameData.h"
#include "Image.h"
#include <DxLib.h>

// �e��t����������ƒl��\������
void Drawer::drawText(int x, int y, const char* txt, int val, int col, int siz)
{
	SetFontSize(siz); // �t�H���g�̑傫�����w��
	DrawFormatString(x + 1, y + 1, 0x000000, txt, val); // ���ŕ������\��
	DrawFormatString(x, y, col, txt, val); // �����̐F�ŕ������\��
}

// ��������Z���^�����O���ĕ\������
void Drawer::drawTextC(int x, int y, const char* txt, int col, int siz)
{
	SetFontSize(siz);
	int strWidth = GetDrawStringWidth(txt, strlen(txt));
	x -= strWidth / 2;
	y -= siz / 2;
	DrawString(x + 1, y + 1, txt, 0x000000);
	DrawString(x, y, txt, col);
}

// ���S���W���w�肵�ĉ摜��\������
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
//// �ʏ��DrawGraph()�����s����
//void Drawer::drawGraphic(const ImageData& data)
//{
//	DrawGraph(data.x, data.y, data.img.getId(), data.isTransParent);
//}
//
//// �w���`�����݂̂�`�悷��(rawRectGraph)�����s����
//void Drawer::drawGraphic(const RectData& data)
//{	
//	DrawRectGraph(data.x, data.y, data.srcX, data.srcY, data.w, data.h, data.img.getId(), TRUE, FALSE);
//}
//
//// �~�̕`��(DrawCircle)�����s����
//void Drawer::drawGraphic(const CircleData& data)
//{
//	DrawCircle(data.x, data.y, data.r, data.color, data.isFilled);
//}
//
//// �l�p�`�̕`��(DrawBox)�����s����
//void Drawer::drawGraphic(const BoxData& data)
//{
//	DrawBox(data.left, data.top, data.right, data.bottom, data.color, data.isFilled);
//}