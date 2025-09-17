#pragma once
#include <string>
#include "IDrawable.h"

class Image;
enum class BlendMode;

class Drawer
{
public:
	// �e��t����������ƒl��\������
	void drawText(int x, int y, const char* txt, int val, int col, int siz);

	// ��������Z���^�����O���ĕ\������
	void drawTextC(int x, int y, const char* txt, int col, int siz);

	// ���S���W���w�肵�ĉ摜��\������
	void drawImage(const Image& img, int x, int y);

	// �����ɗ^�����\���̂̉摜��`�悷��
	void drawGraphic(const IDrawable& data);

	// �`��̍��ق̃u�����h���[�h���Z�b�g����
	void setBlendMode(BlendMode mode, int param);
};