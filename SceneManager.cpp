#include "SceneTitle.h"

class SceneManager
{
public:
	SceneManager()
	{
		scene = new SceneTitle();
	}

	void run(GameManager& game)
	{
		auto nextScene = scene->run(game);

		if (nextScene != std::nullptr_t) {
			scene = nextScene;
		}
	}

private:
	std::shared_ptr<IScene> scene;
};