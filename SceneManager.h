#pragma once
#include "SceneTitle.h"
#include "SceneType.h"

class IScene;
class GameManager;

class SceneManager
{
public:
	SceneManager();
	void run(GameManager& game);
	SceneType getCurrentType() const;

private:
	std::shared_ptr<IScene> scene;
};
