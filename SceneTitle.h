#pragma once
#include <string>
#include "IScene.h"
#include "GameConfig.h"
#include "ScenePlay.h"

class SceneTitle: public IScene
{
public:
	virtual std::shared_ptr<IScene> run(GameManager& game);

	virtual SceneType getType() const override;
};