#include "SceneTitle.h"
#include "GameManager.h"

std::shared_ptr<IScene> SceneTitle::run(GameManager& game)
{
	auto player = game.getPlayer();

	game.getDrawer().drawTextC(GameConfig::WIDTH * 0.5, GameConfig::HEIGHT * 0.3, "Shooting Game", 0xffffff, 80);

	game.getDrawer().drawTextC(GameConfig::WIDTH * 0.5, GameConfig::HEIGHT * 0.7, "Press SPACE to start.", 0xffffff, 30);

	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		game.initVariable();
		return std::make_shared<ScenePlay>();
	}
	return nullptr;
}

SceneType SceneTitle::getType() const
{
	return SceneType::Title;
}
