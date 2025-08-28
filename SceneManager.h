#pragma once
#include "SceneTitle.h"

class SceneManager
{
public:
	SceneManager()
	{
		scene = std::make_shared<SceneTitle>();
	}

	void run(GameManager& game)
	{
		auto nextScene = scene->run(game);

		if (nextScene != nullptr) {
			scene = nextScene;
		}
	}

private:
	std::shared_ptr<IScene> scene;
};
