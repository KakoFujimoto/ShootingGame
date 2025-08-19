#pragma once
#include <string>
#include <memory>
#include "GameManager.h"

class IScene
{
public:
	virtual std::shared_ptr<IScene> run(GameManager& game) =0;
};
