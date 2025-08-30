#include "GameData.h"
#include "GameConfig.h"
#include "SoundContainer.h"
#include "SoundPlayer.h"
#include "ItemManager.h"


void ItemManager::setItem(void)
{
	item.setX((GameConfig::WIDTH / 4) * (1 + rand() % 3));
	item.setY(-16);
	item.setVX(15);
	item.setVY(1);
	item.setState(1);
	item.setTimer(0);
}


// �A�C�e���̏���
void moveItem(void)
{
	if (GameData::item.state == 0) return;
	GameData::item.x += GameData::item.vx;
	GameData::item.y += GameData::item.vy;
	if (GameData::item.timer % 60 < 30)
		GameData::item.vx -= 1;
	else
		GameData::item.vx += 1;
	if (GameData::item.y > GameConfig::HEIGHT + 16) GameData::item.state = 0;
	GameData::item.pattern = (GameData::item.timer / 120) % GameConfig::ITEM_TYPE; // ���݁A�ǂ̃A�C�e���ɂȂ��Ă��邩
	GameData::item.timer++;
	DrawRectGraph(GameData::item.x - 20, GameData::item.y - 16, GameData::item.pattern * 40, 0, 40, 32, GameData::imgItem, TRUE, FALSE);
	if (GameData::scene == OVER) return; // �Q�[���I�[�o�[��ʂł͉���ł��Ȃ�
	int dis = (GameData::item.x - GameData::player.x) * (GameData::item.x - GameData::player.x) + (GameData::item.y - GameData::player.y) * (GameData::item.y - GameData::player.y);
	if (dis < 60 * 60) // �A�C�e���Ǝ��@�Ƃ̃q�b�g�`�F�b�N�i�~�ɂ�铖���蔻��j
	{
		GameData::item.state = 0;
		if (GameData::item.pattern == 0) // �X�s�[�h�A�b�v
		{
			if (GameData::player.vx < GameConfig::PLAYER_SPEED_MAX)
			{
				GameData::player.vx += 3;
				GameData::player.vy += 3;
			}
		}
		if (GameData::item.pattern == 1) // �V�[���h��
		{
			if (GameData::player.shield < GameConfig::PLAYER_SHIELD_MAX) GameData::player.shield++;
			setEffect(GameData::player.x, GameData::player.y, EFF_RECOVER); // �񕜃G�t�F�N�g��\��
		}
		if (GameData::item.pattern == 2) // ���탌�x���A�b�v
		{
			if (GameData::weaponLv < GameConfig::WEAPON_LV_MAX) GameData::weaponLv++;
		}
		PlaySoundMem(GameData::seItem, DX_PLAYTYPE_BACK); // ���ʉ�
	}
}