#pragma once
#include <string>
#include <memory>
#include "SceneType.h"

class GameManager;

class IScene
{
public:
	virtual std::shared_ptr<IScene> run(GameManager& game) =0;

	virtual SceneType getType() const = 0;
};
