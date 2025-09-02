#include "Drawer.h"
#include "GameConfig.h"
#include "GameData.h"
#include <DxLib.h>

// �e��t����������ƒl��\������֐�
void Drawer::drawText(int x, int y, const char* txt, int val, int col, int siz)
{
	SetFontSize(siz); // �t�H���g�̑傫�����w��
	DrawFormatString(x + 1, y + 1, 0x000000, txt, val); // ���ŕ������\��
	DrawFormatString(x, y, col, txt, val); // �����̐F�ŕ������\��
}

// ��������Z���^�����O���ĕ\������֐�
void Drawer::drawTextC(int x, int y, const char* txt, int col, int siz)
{
	SetFontSize(siz);
	int strWidth = GetDrawStringWidth(txt, strlen(txt));
	x -= strWidth / 2;
	y -= siz / 2;
	DrawString(x + 1, y + 1, txt, 0x000000);
	DrawString(x, y, txt, col);
}

// ���S���W���w�肵�ĉ摜��\������֐�
void Drawer::drawImage(int img, int x, int y)
{
	int w, h;
	GetGraphSize(img, &w, &h);
	DrawGraph(x - w / 2, y - h / 2, img, TRUE);
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

//�g�p�C���[�W
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