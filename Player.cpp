#include "Player.h"
#include "GameManager.h"
#include "GameConfig.h"
#include "GameData.h"
#include "BulletManager.h"
#include "DxLib.h"

void Player::movePlayer(BulletManager& bulletManager, GameManager& game)
{

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
		countSpcKey++;

			// 2�b�������ςȂ��Ȃ�A�˃��[�hON
			if (countSpcKey >= GameConfig::RapidModeThreshold) {
				game.getGameData().isRapidMode = true;
			}

			int interval = game.getGameData().isRapidMode
				? GameConfig::RapidFireInterval
				: GameConfig::FireInterval;

			// ���˃^�C�~���O
			if (countSpcKey == 1 || countSpcKey % interval == 0) {
				bulletManager.setBullet(*this, game); // �������u�ԁA����

			}
		}
		else {
			// �������烊�Z�b�g
			countSpcKey = 0;
			game.getGameData().isRapidMode = false;
		}

	int& noDamage = game.getGameData().noDamage;

	if (noDamage > 0)
	{
		// �Q�ƕϐ��𒼐ڏ�����������̂͂悭�Ȃ�
		//noDamage--; // ���G���Ԃ̃J�E���g
		game.getGameData().noDamageCount();// ���G���Ԃ̃J�E���g
	}

	if (noDamage % 4 < 2)
	{	
		auto& drawer = game.getDrawer();
		auto& image = game.getImage();

		drawer.drawImage(image.getFighter(), x, y); // ���@�̕`��
	}
}