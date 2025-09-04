#pragma once
#include <string>
#include "IScene.h"
#include "GameConfig.h"

class GameManager;

class SceneOver
	: public IScene
{
public:
	virtual std::shared_ptr<IScene> run(GameManager& game);
	SceneType getType() const override;

};