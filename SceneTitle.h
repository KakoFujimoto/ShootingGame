#pragma once
#include <string>
#include "IScene.h"
#include "GameManager.h"
#include "GameConfig.h"

class SceneTitle
	: IScene
{
public:
	virtual std::shared_ptr<IScene> run(GameManager& game)
	{
		auto player = game.getPlayer();

		drawTextC(GameConfig::WIDTH * 0.5, GameConfig::HEIGHT * 0.3, "Shooting Game", 0xffffff, 80);
		drawTextC(GameConfig::WIDTH * 0.5, GameConfig::HEIGHT * 0.7, "Press SPACE to start.", 0xffffff, 30);
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			initVariable();
			return new ScenePlay();
		}
		return nullptr;
	}
};