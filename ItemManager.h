#pragma once
#include "Item.h"
#include "GameManager.h"

class SceneManager;

class ItemManager {
public:
	// アイテムをセット
	void setItem(void);
	// アイテムの処理
	void moveItem(GameManager& game, SceneManager& scene);

private:
	Item item;
};