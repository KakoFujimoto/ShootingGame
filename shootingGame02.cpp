#include "DxLib.h" //DX���C�u�����̃C���N���[�h
#include "shootingGame.h" // �w�b�_�[�t�@�C�����C���N���[�h
#include <cstdlib>

namespace GameConfig {
	constexpr int WIDTH = 1200; // �E�B���h�E�̕�
	constexpr int HEIGHT = 720; // �E�B���h�E�̍���
	constexpr int FPS = 60; // �t���[�����[�g
	constexpr int IMG_ENEMY_MAX = 5; // �G�̉摜�̖����i��ށj
	constexpr int BULLET_MAX = 100; // ���@�����˂���e�̍ő吔
	constexpr int ENEMY_MAX = 100; // �G�@�̐��̍ő�l
	constexpr int STAGE_DISTANCE = FPS * 60; // �X�e�[�W�̒���
	constexpr int PLAYER_SHIELD_MAX = 8; // ���@�̃V�[���h�̍ő�l
	constexpr int EFFECT_MAX = 100; // �G�t�F�N�g�̍ő吔
	constexpr int ITEM_TYPE = 3; // �A�C�e���̎��
	constexpr int WEAPON_LV_MAX = 10; // ���탌�x���̍ő�l
	constexpr int PLAYER_SPEED_MAX = 20; // ���@�̑����̍ő�l
}

// �G�@�̎��
enum EnemyType {
	ENE_BULLET,
	ENE_ZAKO1,
	ENE_ZAKO2,
	ENE_ZAKO03,
	ENE_BOSS
};

// �G�t�F�N�g�̎��
enum EffectType {
	EFF_EXPLODE,
	EFF_RECOVER
};

// �V�[���̎��
enum SceneType {
	TITLE,
	PLAY,
	OVER,
	CLEAR
};