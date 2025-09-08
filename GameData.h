#pragma once
#include "SceneType.h"

class GameData
{
public:
	int distance = 0; // �X�e�[�W�I�[�܂ł̋���
	int bossIdx = 0; // �{�X���������z��̃C���f�b�N�X
	int stage = 1; // �X�e�[�W
	int score = 0; // �X�R�A
	int hisco = 10000; // �n�C�X�R�A
	int noDamage = 0; // ���G���
	int weaponLv = 1; // ���@�̕���̃��x���i�����ɔ��˂����e���j
	SceneType scene = SceneType::Title; // �V�[�����Ǘ�
	int timer = 0; // ���Ԃ̐i�s���Ǘ�
	bool isRapidMode = false; // �A�˃��[�h�̃t���O
	bool isRunning = true;
};