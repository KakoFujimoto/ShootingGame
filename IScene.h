#pragma once
#include <string>
#include <memory>
#include "GameManager.h"
#include "SceneType.h"

class IScene
{
public:
	virtual std::shared_ptr<IScene> run(GameManager& game) =0;

	virtual SceneType getType() const = 0;
};
