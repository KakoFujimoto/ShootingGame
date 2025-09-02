#pragma once
#include <string>
#include "IScene.h"
#include "GameManager.h"
#include "GameConfig.h"
#include "DxLib.h"

class SceneTitle: public IScene
{
public:
	virtual std::shared_ptr<IScene> run(GameManager& game)
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

	virtual SceneType getType() const override
	{
		return SceneType::Title;
	}
};