#pragma once
#include <string>
#include "GameManager.h"

class Drawer
{
public:
	// �e��t����������ƒl��\������֐�
	void drawText(int x, int y, const char* txt, int val, int col, int siz);

	// ��������Z���^�����O���ĕ\������֐�
	void drawTextC(int x, int y, const char* txt, int col, int siz);

	// ���S���W���w�肵�ĉ摜��\������֐�
	void drawImage(int img, int x, int y);

};