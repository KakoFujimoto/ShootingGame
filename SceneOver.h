#pragma once
#include <string>
#include "IScene.h"
#include "GameManager.h"
#include "GameConfig.h"

class SceneOver
	: IScene
{
public:
	virtual std::shared_ptr<IScene> run(GameManager& game);
};