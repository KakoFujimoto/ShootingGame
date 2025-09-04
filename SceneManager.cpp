#include "SceneManager.h"

SceneManager::SceneManager()
{
	scene = std::make_shared<SceneTitle>();
}

void SceneManager::run(GameManager& game)
{
	auto nextScene = scene->run(game);

	if (nextScene != nullptr) {
		scene = nextScene;
	}
}

SceneType SceneManager::getCurrentType() const
{
	return scene->getType();
}