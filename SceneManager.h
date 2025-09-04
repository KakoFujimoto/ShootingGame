#pragma once
#include "SceneTitle.h"
#include "SceneType.h"
#include "GameManager.h"

class IScene;

class SceneManager
{
public:
	SceneManager();
	void run(GameManager& game);
	SceneType getCurrentType() const;

private:
	std::shared_ptr<IScene> scene;
};
