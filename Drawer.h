#pragma once
#include <string>
#include "IDrawable.h"

class Image;

class Drawer
{
public:
	// �e��t����������ƒl��\������
	void drawText(int x, int y, const char* txt, int val, int col, int siz);

	// ��������Z���^�����O���ĕ\������
	void drawTextC(int x, int y, const char* txt, int col, int siz);

	// ���S���W���w�肵�ĉ摜��\������
	void drawImage(const Image& img, int x, int y);

	void drawGraphic(const IDrawable& data);


	//// �ʏ��DrawGraph()�����s����
	//void drawGraphic(const ImageData& data);

	//// �w���`�����݂̂�`�悷��(rawRectGraph)�����s����
	//void drawGraphic(const RectData& data);

	//// �~�̕`��(DrawCircle)�����s����
	//void drawGraphic(const CircleData& data);

	//// �l�p�`�̕`��(DrawBox)�����s����
	//void drawGraphic(const BoxData& data);

};