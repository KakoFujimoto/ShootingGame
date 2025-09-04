#pragma once
#include <string>
#include "IScene.h"
#include "GameConfig.h"
#include "BulletManager.h"
#include "GameData.h"
#include "EnemyType.h"
#include "SceneType.h"
#include "SceneOver.h"
#include "SceneClear.h"

class GameManager;

class ScenePlay
	: public IScene
{
public:
	std::shared_ptr<IScene> run(GameManager& game);
	SceneType getType() const override;

};
