#pragma once
#include <string>
#include "DxLib.h"
#include "IScene.h"
#include "GameConfig.h"
#include "GameData.h"
#include "SceneType.h"
#include "ScenePlay.h"
#include "EffectType.h"

class GameManager;

class SceneClear
	: public IScene
{
public:
	virtual std::shared_ptr<IScene> run(GameManager& game);
	
};