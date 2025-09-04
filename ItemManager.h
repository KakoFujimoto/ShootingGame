#pragma once
#include "Item.h"
#include "GameManager.h"

class SceneManager;

class ItemManager {
public:
	// �A�C�e�����Z�b�g
	void setItem(void);
	// �A�C�e���̏���
	void moveItem(GameManager& game, SceneManager& scene);

private:
	Item item;
};