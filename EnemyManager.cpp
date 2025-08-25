#include "Bullet.h"
#include "GameData.h"
#include "EnemyManager.h"
#include "DxLib.h"

	// �G�@�𓮂���
	void EnemyManager::moveEnemy(void)
	{
		for (int i = 0; i < GameConfig::ENEMY_MAX; i++) {
			if (GameData::enemy[i].state == 0) continue; // �󂢂Ă���z��Ȃ珈�����Ȃ�
			if (GameData::enemy[i].pattern == ENE_ZAKO3) // �U�R�@3
			{
				if (GameData::enemy[i].vy > 1) // ����
				{
					GameData::enemy[i].vy *= 0.9;
				}
				else if (GameData::enemy[i].vy > 0) // �e���ˁA��ы���
				{
					setEnemy(GameData::enemy[i].x, GameData::enemy[i].y, 0, 6, ENE_BULLET, GameData::imgEnemy[ENE_BULLET], 0); // �e
					GameData::enemy[i].vx = 8;
					GameData::enemy[i].vy = -4;
				}
			}
			if (GameData::enemy[i].pattern == ENE_BOSS) // �{�X�@
			{
				if (GameData::enemy[i].y > GameConfig::HEIGHT - 120) GameData::enemy[i].vy = -2;
				if (GameData::enemy[i].y < 120) // ��ʏ�[
				{
					if (GameData::enemy[i].vy < 0) // �e����
					{
						for (int bx = -2; bx <= 2; bx++) // ��d���[�v��for
							for (int by = 0; by <= 3; by++)
							{
								if (bx == 0 && by == 0) continue;
								setEnemy(GameData::enemy[i].x, GameData::enemy[i].y, bx * 2, by * 3, ENE_BULLET, GameData::imgEnemy[ENE_BULLET], 0);
							}
					}
					GameData::enemy[i].vy = 2;
				}
			}
			GameData::enemy[i].x += GameData::enemy[i].vx; //���G�@�̈ړ�
			GameData::enemy[i].y += GameData::enemy[i].vy; //��
			drawImage(GameData::enemy[i].image, GameData::enemy[i].x, GameData::enemy[i].y); // �G�@�̕`��
			// ��ʊO�ɏo�����H
			if (GameData::enemy[i].x < -200 || GameConfig::WIDTH + 200 < GameData::enemy[i].x || GameData::enemy[i].y < -200 || GameConfig::HEIGHT + 200 < GameData::enemy[i].y) GameData::enemy[i].state = 0;
			// �����蔻��̃A���S���Y��
			if (GameData::enemy[i].shield > 0) // �q�b�g�`�F�b�N���s���G�@�i�e�ȊO�j
			{
				for (int j = 0; j < GameConfig::BULLET_MAX; j++) { // ���@�̒e�ƃq�b�g�`�F�b�N
					if (GameData::bullet[j].state == 0) continue;
					int dx = abs((int)(GameData::enemy[i].x - GameData::bullet[j].x)); //�����S���W�Ԃ̃s�N�Z����
					int dy = abs((int)(GameData::enemy[i].y - GameData::bullet[j].y)); //��
					if (dx < GameData::enemy[i].wid / 2 && dy < GameData::enemy[i].hei / 2) // �ڐG���Ă��邩
					{
						GameData::bullet[j].state = 0; // �e������
						damageEnemy(i, 1); // �G�Ƀ_���[�W
					}
				}
			}
			if (GameData::noDamage == 0) // ���G��ԂłȂ����A���@�ƃq�b�g�`�F�b�N
			{
				int dx = abs(GameData::enemy[i].x - GameData::player.x); //�����S���W�Ԃ̃s�N�Z����
				int dy = abs(GameData::enemy[i].y - GameData::player.y); //��
				if (dx < GameData::enemy[i].wid / 2 + GameData::player.wid / 2 && dy < GameData::enemy[i].hei / 2 + GameData::player.hei / 2)
				{
					if (GameData::player.shield > 0) GameData::player.shield--; // �V�[���h�����炷
					GameData::noDamage = GameConfig::FPS; // ���G��Ԃ��Z�b�g
					damageEnemy(i, 1); // �G�Ƀ_���[�W
				}
			}
		}
	}

	// �G�@���Z�b�g����
	int EnemyManager::setEnemy(int x, int y, int vx, int vy, int ptn, int img, int sld)
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
