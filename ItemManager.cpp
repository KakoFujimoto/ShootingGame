#include "GameData.h"
#include "GameConfig.h"
#include "GameManager.h"
#include "SceneManager.h"
#include "SoundContainer.h"
#include "SoundPlayer.h"
#include "ItemManager.h"
#include "ItemType.h"
#include "ImageContainer.h"
#include "SceneType.h"
#include "EffectType.h"

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
void ItemManager::moveItem(GameManager& game, SceneManager& scene)
{	
	auto& img = game.getImage();

	if (item.getState() == 0)
	{
		return;
	}
	item.setX(item.getVX());
	item.setY(item.getVY());

	if ((item.getTimer() % 60) < 30)
	{
		item.setVX(item.getVX() - 1);
	}
	else
	{
		item.setVX(item.getVX() + 1);
	}

	if (item.getY() > GameConfig::HEIGHT + 16)
	{
		item.setShield(0);
	}
	int index = (item.getTimer() / 120) % GameConfig::ITEM_TYPE; // 現在、どのアイテムになっているか
	item.setPattern(static_cast<ItemType>(index));

	item.setTimer(item.getTimer() + 1);


	DrawRectGraph
	(
		item.getX() - 20, //int DestX
		item.getY() - 16, //int DestY
		static_cast<int>(item.getPattern()) * 40, // int SrcX
		0, // int SrcY
		40, // int Width
		32, //  int Height
		img.getItem().getId(), // int GraphHandle
		TRUE,
		FALSE,
		FALSE
	);


	if (scene.getCurrentType() == SceneType::Over)
	{
		return; // ゲームオーバー画面では回収できない
	}

	int dis = (item.getX() - game.getPlayer().getX()) * (item.getX() - game.getPlayer().getX())
		+ (item.getY() - game.getPlayer().getY()) * (item.getY() - game.getPlayer().getY());

	if (dis < 60 * 60) // アイテムと自機とのヒットチェック（円による当たり判定）
	{
		item.setState(0);

		if(item.getPattern() == ItemType::SppedUp)
		{
			if (game.getPlayer().getVX() < GameConfig::PLAYER_SPEED_MAX)
			{
				game.getPlayer().setVX(game.getPlayer().getVX() +3);

				game.getPlayer().setVY(game.getPlayer().getVY() + 3);
			}
		}
		if (item.getPattern() == ItemType::ShieldRecovery) // シールド回復
		{
			if (game.getPlayer().getShield() < GameConfig::PLAYER_SHIELD_MAX)
			{
				game.getPlayer().setShield(game.getPlayer().getShield() + 1);

			}

			game.getEffect().setEffect(game.getPlayer().getX(), game.getPlayer().getY(), EffectType::Recover, game.getImage()); // 回復エフェクトを表示
		}
		if (item.getPattern() == ItemType::WeaponLvUp) // 武器レベルアップ
		{
			if (game.getGameData().weaponLv < GameConfig::WEAPON_LV_MAX)
			{
				game.getGameData().weaponLv++;
			}
		}
		game.getSoundPlayer().play(game.getSoundContainer().seItem);
	}
}