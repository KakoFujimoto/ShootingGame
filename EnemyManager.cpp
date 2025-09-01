#include "Bullet.h"
#include "GameData.h"
#include "EnemyManager.h"
#include "DxLib.h"
#include "Image.h"
#include "EnemyType.h"

	// �G�@�𓮂���
	void EnemyManager::moveEnemy(GameManager& game)
	{
		for (int i = 0; i < GameConfig::ENEMY_MAX; i++) {
			auto& enemy = enemies[i];

			if (enemy.getState() == 0)
			{
				continue; // �󂢂Ă���z��Ȃ珈�����Ȃ�
			}
			if (enemy.getPattern() == EnemyType::Zako3) // �U�R�@3
			{
				if (enemy.getVY() > 1) // ����
				{
					enemy.setVY(enemy.getVY() * 0.9);
				}
				else if (enemy.getVY()y > 0) // �e���ˁA��ы���
				{
					setEnemy(enemy.getX(), enemy.getY(), 0, 6, ENE_BULLET, GameData::imgEnemy[ENE_BULLET], 0); // �e

					//GameData::enemy[i].vx = 8;
					enemy.setVX(8);
					//GameData::enemy[i].vy = -4;
					enemy.setVY(-4);
				}
			}
			if (enemy.getPattern() == EnemyType::Boss) // �{�X�@
			{
				if (enemy.getY() > GameConfig::HEIGHT - 120)
				{
					//GameData::enemy[i].vy = -2;
					enemy.setVY(-2);
				}
				if (enemy.getY() < 120) // ��ʏ�[
				{
					if (enemy.getY() < 0) // �e����
					{
						for (int bx = -2; bx <= 2; bx++) // ��d���[�v��for
							for (int by = 0; by <= 3; by++)
							{
								if (bx == 0 && by == 0) continue;
								setEnemy(enemy.getX(), enemy.getY(), bx * 2, by * 3, ENE_BULLET, GameData::imgEnemy[ENE_BULLET], 0);
							}
					}
					enemy.setVY(2);
				}
			}
			enemy.setX(enemy.getX() + enemy.getVX()); //���G�@�̈ړ�
			enemy.setY(enemy.getY() + enemy.getVY()); //��


			drawImage(GameData::enemy[i].image, enemy.getX(), enemy.getY()); // �G�@�̕`��
			// ��ʊO�ɏo�����H
			if (enemy.getX() < -200 || GameConfig::WIDTH + 200 < enemy.getX()
				|| enemy.getY() < -200 || GameConfig::HEIGHT + 200 < enemy.getY())
			{
				enemy.setState(0); // ��ʊO�ɏo����A���݂��Ȃ���Ԃɂ���
			}
			// �����蔻��̃A���S���Y��
			if (enemy.getShield() > 0) // �q�b�g�`�F�b�N���s���G�@�i�e�ȊO�j
			{
				for (int j = 0; j < GameConfig::BULLET_MAX; j++) { // ���@�̒e�ƃq�b�g�`�F�b�N
					auto& bullet = game.getBullet();
					if (bullet.getState() == 0)
					{
						continue;
					}
					int dx = abs((int)(enemy.getX() - bullet.getX())); //�����S���W�Ԃ̃s�N�Z����
					int dy = abs((int)(enemy.getY() - bullet.getY())); //��
					if (dx < enemy.getWidth() / 2 && dy < enemy.getHeight() / 2) // �ڐG���Ă��邩
					{
						bullet.setState(0); // �e������
						damageEnemy(i, 1); // �G�Ƀ_���[�W
					}
				}
			}
			if (GameData::noDamage == 0) // ���G��ԂłȂ����A���@�ƃq�b�g�`�F�b�N
			{	
				auto& player = game.getPlayer();

				int dx = abs(enemy.getX() - player.getX()); //�����S���W�Ԃ̃s�N�Z����
				int dy = abs(enemy.getY() - player.getY()); //��
				if (dx < enemy.getWidth() / 2 + player.getWidth() / 2 && dy < enemy.getHeight() / 2 + player.getHeight() / 2)
				{
					if (player.getShield() > 0)
					{
						player.setShield(player.getShield() - 1); // �V�[���h�����炷
					}
					GameData::noDamage = GameConfig::FPS; // ���G��Ԃ��Z�b�g
					damageEnemy(i, 1); // �G�Ƀ_���[�W
				}
			}
		}
	}

	// �G�@���Z�b�g����
	int EnemyManager::setEnemy(int x, int y, int vx, int vy, EnemyType ptn, Image img, int sld)
	{
		for (int i = 0; i < GameConfig::ENEMY_MAX; i++) {
			if (GameData::enemy[i].state == 0) {
				GameData::enemy[i].x = x;
				GameData::enemy[i].y = y;
				GameData::enemy[i].vx = vx;
				GameData::enemy[i].vy = vy;
				GameData::enemy[i].state = 1;
				GameData::enemy[i].pattern = ptn;
				GameData::enemy[i].image = img;
				GameData::enemy[i].shield = sld * GameData::stage; // �X�e�[�W���i�ނقǓG���ł��Ȃ�
				GetGraphSize(img, &GameData::enemy[i].wid, &GameData::enemy[i].hei); // �摜�̕��ƍ�������
				return i;
			}
		}
		return -1;
	}
