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


// アイテムの処理
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
	GameData::item.pattern = (GameData::item.timer / 120) % GameConfig::ITEM_TYPE; // 現在、どのアイテムになっているか
	GameData::item.timer++;
	DrawRectGraph(GameData::item.x - 20, GameData::item.y - 16, GameData::item.pattern * 40, 0, 40, 32, GameData::imgItem, TRUE, FALSE);
	if (GameData::scene == OVER) return; // ゲームオーバー画面では回収できない
	int dis = (GameData::item.x - GameData::player.x) * (GameData::item.x - GameData::player.x) + (GameData::item.y - GameData::player.y) * (GameData::item.y - GameData::player.y);
	if (dis < 60 * 60) // アイテムと自機とのヒットチェック（円による当たり判定）
	{
		GameData::item.state = 0;
		if (GameData::item.pattern == 0) // スピードアップ
		{
			if (GameData::player.vx < GameConfig::PLAYER_SPEED_MAX)
			{
				GameData::player.vx += 3;
				GameData::player.vy += 3;
			}
		}
		if (GameData::item.pattern == 1) // シールド回復
		{
			if (GameData::player.shield < GameConfig::PLAYER_SHIELD_MAX) GameData::player.shield++;
			setEffect(GameData::player.x, GameData::player.y, EFF_RECOVER); // 回復エフェクトを表示
		}
		if (GameData::item.pattern == 2) // 武器レベルアップ
		{
			if (GameData::weaponLv < GameConfig::WEAPON_LV_MAX) GameData::weaponLv++;
		}
		PlaySoundMem(GameData::seItem, DX_PLAYTYPE_BACK); // 効果音
	}
}