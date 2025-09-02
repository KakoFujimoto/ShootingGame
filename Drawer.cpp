#include "Drawer.h"
#include "GameConfig.h"
#include "GameData.h"
#include <DxLib.h>

// �e��t����������ƒl��\������֐�
void drawText(int x, int y, const char* txt, int val, int col, int siz)
{
	SetFontSize(siz); // �t�H���g�̑傫�����w��
	DrawFormatString(x + 1, y + 1, 0x000000, txt, val); // ���ŕ������\��
	DrawFormatString(x, y, col, txt, val); // �����̐F�ŕ������\��
}

// ��������Z���^�����O���ĕ\������֐�
void drawTextC(int x, int y, const char* txt, int col, int siz)
{
	SetFontSize(siz);
	int strWidth = GetDrawStringWidth(txt, strlen(txt));
	x -= strWidth / 2;
	y -= siz / 2;
	DrawString(x + 1, y + 1, txt, 0x000000);
	DrawString(x, y, txt, col);
}

// ���S���W���w�肵�ĉ摜��\������֐�
void drawImage(int img, int x, int y)
{
	int w, h;
	GetGraphSize(img, &w, &h);
	DrawGraph(x - w / 2, y - h / 2, img, TRUE);
}

// ���@�Ɋւ���p�����[�^�[��\��
void drawParameter(GameManager& game)
{
	int x = 10, y = GameConfig::HEIGHT - 30; // �\���ʒu
	DrawBox(x, y, x + GameConfig::PLAYER_SHIELD_MAX * 30, y + 20, 0x000000, TRUE);

	for (int i = 0; i < game.getPlayer().getShield(); i++) // �V�[���h�̃��[�^�[
	{
		int r = 128 * (GameConfig::PLAYER_SHIELD_MAX - i) / GameConfig::PLAYER_SHIELD_MAX; // RGB�l���v�Z
		int g = 255 * i / GameConfig::PLAYER_SHIELD_MAX;
		int b = 160 + 96 * i / GameConfig::PLAYER_SHIELD_MAX;
		DrawBox(x + 2 + i * 30, y + 2, x + 28 + i * 30, y + 18, GetColor(r, g, b), TRUE);
	}
	drawText(x, y - 25, "SHIELD Lv %02d", game.getPlayer().getShield(), 0xffffff, 20); // �V�[���h�l
	drawText(x, y - 50, "WEAPON Lv %02d", game.getGameData().weaponLv, 0xffffff, 20); // ���탌�x��
	drawText(x, y - 75, "SPEED %02d", game.getPlayer().getVX(), 0xffffff, 20); // �ړ����x
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