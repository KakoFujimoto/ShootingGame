#pragma once
#include <string>

class Drawer
{
public:
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

    //void drawImage(int x, int y, int img, const DrawerManager::ImageStyle& style);

};