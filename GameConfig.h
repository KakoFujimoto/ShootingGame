#pragma once

class GameConfig
{
public:
	static constexpr int WIDTH = 1200;				// �E�B���h�E�̕�
	static constexpr int HEIGHT = 720;				// �E�B���h�E�̍���
	static constexpr int FPS = 60;					// �t���[�����[�g
	static constexpr int IMG_ENEMY_MAX = 5;			// �G�̉摜�̖����i��ށj
	static constexpr int BULLET_MAX = 100;			// ���@�����˂���e�̍ő吔
	static constexpr int ENEMY_MAX = 100;			// �G�@�̐��̍ő�l
	//static constexpr int STAGE_DISTANCE = FPS * 60; // �X�e�[�W�̒���
	static constexpr int STAGE_DISTANCE = FPS * 30; // �X�e�[�W�̒���

	//static constexpr int PLAYER_SHIELD_MAX = 10;		// ���@�̃V�[���h�̍ő�l
	static constexpr int PLAYER_SHIELD_MAX = 100;		// ���@�̃V�[���h�̍ő�l

	static constexpr int EFFECT_MAX = 100;			// �G�t�F�N�g�̍ő吔
	static constexpr int ITEM_TYPE = 3;				// �A�C�e���̎��
	static constexpr int WEAPON_LV_MAX = 10;		// ���탌�x���̍ő�l
	//static constexpr int PLAYER_SPEED_MAX = 20;		// ���@�̑����̍ő�l
	static constexpr int PLAYER_SPEED_MAX = 30;		// ���@�̑����̍ő�l

	// --- �e�̔��ˊԊu ---
	static constexpr int FireInterval = 20;       // �ʏ탂�[�h
	static constexpr int FireIntervalHidden = 3; // �B���v�f���[�h
	static constexpr int RapidModeThreshold = 120; // �B���v�f���[�h�܂ł̑ҋ@����

};