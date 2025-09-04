#include "SceneClear.h"
#include "GameManager.h"

std::shared_ptr<IScene> SceneClear::run(GameManager& game)
{
	auto& player = game.getPlayer();
	auto& bulletManager = game.getBulletManager();
	auto& effect = game.getEffect();
	auto& enemy = game.getEnemy();
	auto& image = game.getImage();
	auto& soundContainer = game.getSoundContainer();
	auto& soundPlayer = game.getSoundPlayer();
	auto& drawer = game.getDrawer();


	player.movePlayer(bulletManager, game); // 自機の処理
	int& timer = game.getGameData().timer;
	int& bossIdx = game.getGameData().bossIdx;
	int& stage = game.getGameData().stage;
	int& distance = game.getGameData().distance;



	if (timer < GameConfig::FPS * 3) // ボスが爆発する演出
	{
		if (timer % 7 == 0)
		{
			effect.setEffect
			(
				enemy.getEnemy(bossIdx).getX() + rand() % 201 - 100,
				enemy.getEnemy(bossIdx).getY() + rand() % 201 - 100,

				EffectType::Explode,
				image
			);
		}
	}
	else if (timer == GameConfig::FPS * 3)
	{
		soundPlayer.play(soundContainer.jinClear); // ジングル出力
	}
	else
	{
		drawer.drawTextC(GameConfig::WIDTH * 0.5, GameConfig::HEIGHT * 0.3, "STAGE CLEAR!", 0x00ffff, 80);
	}
	if (timer > GameConfig::FPS * 10) // ゲームプレイへ遷移
	{
		stage++;
		distance = GameConfig::STAGE_DISTANCE;
		return std::make_shared<ScenePlay>();

	}
	return nullptr;
}

SceneType SceneClear::getType() const
{
	return SceneType::Clear;
}