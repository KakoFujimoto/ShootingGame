#include "Drawer.h"
#include "GameConfig.h"
#include "GameData.h"
#include "Image.h"
#include "BlendMode.h"
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

// �����ɗ^�����\���̂̉摜��`�悷��
void Drawer::drawGraphic(const IDrawable& data)
{
	data.drawGraphic();
}

// �`��̍��ق̃u�����h���[�h���Z�b�g����
void Drawer::setBlendMode(BlendMode mode, int param)
{
	constexpr int DxBlendModes[] = {
		DX_BLENDMODE_ADD,
		DX_BLENDMODE_NOBLEND,
		DX_BLENDMODE_SUB
	};

	SetDrawBlendMode(DxBlendModes[static_cast<int>(mode)], param);
}