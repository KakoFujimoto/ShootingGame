#pragma once
#include <string>

class Sound
{
public:

	//// �Q�[���J�n���̃T�E���h���[�h����
	//void load();

	//// Bullet���˃T�E���h�̃��[�h����
	//void loadShotSound(const std::string& filePath);

	//// Bullet���˃T�E���h�̍Đ�
	//void playShot() const;

	// �Q�[�����Ŏg�p����鉹
	int bgm;
	int jinOver;
	int jinClear;
	int seExpl;
	int seItem;
	int seShot;

private:
	int seShotHandle = -1;
};