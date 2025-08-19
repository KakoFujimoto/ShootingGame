#include "Player.h"
#include "GameConfig.h"
#include "DxLib.h" //DX���C�u�����̃C���N���[�h

void Player::movePlayer()
{
	static char oldSpcKey; // 1�O�̃X�y�[�X�L�[�̏�Ԃ�ێ�����ϐ�
	static int countSpcKey; // �X�y�[�X�L�[�����������Ă���ԁA�J�E���g�A�b�v����ϐ�

	if (CheckHitKey(KEY_INPUT_UP)) { // ��L�[
		y -= vy;
		if (y < 30)
		{
			y = 30;
		}
	}
	if (CheckHitKey(KEY_INPUT_DOWN)) { // ���L�[
		y += vy;
		if (y > GameConfig::HEIGHT - 30)
		{
			y = GameConfig::HEIGHT - 30;
		}
	}
	if (CheckHitKey(KEY_INPUT_LEFT)) { // ���L�[
		x -= vx;
		if (x < 30)
		{
			x = 30;
		}
	}
	if (CheckHitKey(KEY_INPUT_RIGHT)) { // �E�L�[
		x += vx;
		if (x > GameConfig::WIDTH - 30)
		{
			x = GameConfig::WIDTH - 30;
		}
	}
	if (CheckHitKey(KEY_INPUT_SPACE)) { // �X�y�[�X�L�[
		if (oldSpcKey == 0)
		{
			setBullet(); // �������u�ԁA����
		}
		else if (countSpcKey % 20 == 0)
		{
			setBullet(); // ���Ԋu�Ŕ���
		}
		countSpcKey++;
	}
	oldSpcKey = CheckHitKey(KEY_INPUT_SPACE); // �X�y�[�X�L�[�̏�Ԃ�ێ�

	if (GameData::noDamage > 0)
	{
		GameData::noDamage--; // ���G���Ԃ̃J�E���g
	}

	if (GameData::noDamage % 4 < 2)
	{
		drawImage(GameData::imgFighter, GameData::player.x, GameData::player.y); // ���@�̕`��
	}
}