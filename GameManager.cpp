#include "GameManager.h"
#include "BlendMode.h"
#include "DxLib.h"

void GameManager::gameLoop()
{
	ClearDrawScreen(); // ��ʂ��N���A����

	// �Q�[���̍��g�݂ƂȂ鏈�����A�����ɋL�q����
	int spd = 1; // �X�N���[���̑���
	if (sceneManager.getCurrentType() == SceneType::Play && gameData.distance == 0)
	{
		spd = 0; // �{�X��̓X�N���[����~
	}

	scrollBG(spd); 
	enemies.moveEnemy(*this); // �G�@�̐���
	bullets.moveBullet(images, *this); // �e�̈ړ�
	itemManager.moveItem(*this, sceneManager); // �A�C�e���̐���
	effects.drawEffect(*this);


	stageMap(); // �X�e�[�W�}�b�v
	drawParameter(*this); // ���@�̃V�[���h�Ȃǂ̃p�����[�^�[��\��
	gameData.timer++; // �^�C�}�[���J�E���g

	sceneManager.run(*this);

	// �X�R�A�A�n�C�X�R�A�A�X�e�[�W���̕\��
	drawer.drawText(10, 10, "SCORE %07d", gameData.score, 0xffffff, 30);
	drawer.drawText(GameConfig::WIDTH - 220, 10, "HI-SC %07d", gameData.hisco, 0xffffff, 30);
	drawer.drawText(GameConfig::WIDTH - 145, GameConfig::HEIGHT - 40, "STAGE %02d", gameData.stage, 0xffffff, 30);

	ScreenFlip(); // ����ʂ̓��e��\��ʂɔ��f������
	WaitTimer(1000 / GameConfig::FPS); // ��莞�ԑ҂�
	if (ProcessMessage() == -1)
	{
		return; // Windows��������󂯎��G���[���N������I��
	}
	if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
	{
		getGameData().isRunning = false; // ESC�L�[�������ꂽ��I��
	}
}

// �X�e�[�W�}�b�v
void GameManager::stageMap(void)
{
	int mx = GameConfig::WIDTH - 30, my = 60; // �}�b�v�̕\���ʒu
	int wi = 20, he = GameConfig::HEIGHT - 120; // �}�b�v�̕��A����
	int pos = (GameConfig::HEIGHT - 140) * gameData.distance / GameConfig::STAGE_DISTANCE; // ���@�̔�s���Ă���ʒu

	// �C���idrawer.�`�`�ƂȂ��Ă����OK�j
	//SetDrawBlendMode(DX_BLENDMODE_SUB, 128); // ���Z�ɂ��`��̏d�ˍ��킹
	drawer.setBlendMode(BlendMode::Sub, 128);// ���Z�ɂ��`��̏d�ˍ��킹

	BoxData box{ mx, my, mx + wi, my + he, 0xffffff, TRUE };
	drawer.drawGraphic(box);

	// �C��
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); // �u�����h���[�h������

	BoxData frame{ mx - 1, my - 1, mx + wi + 1, my + he + 1, 0xffffff, FALSE }; // �g��
	drawer.drawGraphic(frame);

	BoxData position{ mx, my + pos, mx + wi, my + pos + 20, 0x0080ff, TRUE }; // ���@�̈ʒu
	drawer.drawGraphic(position);
}

// �w�i�̃X�N���[��
void GameManager::scrollBG(int spd)
{	
	// �����������O���[�o���ϐ��Ȃ̂ŗǂ��Ȃ�
	static int galaxyY, floorY, wallY; // �X�N���[���ʒu���Ǘ�����ϐ��i�ÓI�L���̈�ɕێ������j
	galaxyY = (galaxyY + spd) % GameConfig::HEIGHT; // ����i�F���j

	ImageData image{ 0, galaxyY - GameConfig::HEIGHT, images.getGalaxy(), FALSE };
	drawer.drawGraphic(image);

	ImageData gfc{ 0, galaxyY, images.getGalaxy().getId(), FALSE };
	drawer.drawGraphic(gfc);


	floorY = (floorY + spd * 2) % 120;  // ��
	for (int i = -1; i < 6; i++) DrawGraph(240, floorY + i * 120, images.getFloor().getId(), TRUE);

	wallY = (wallY + spd * 4) % 240;    // ���E�̕�

	ImageData wallL{ 0, wallY - 240, images.getWallL().getId(), TRUE };
	drawer.drawGraphic(wallL);

	ImageData wallR{ GameConfig::WIDTH - 300, wallY - 240, images.getWallR().getId(), TRUE };
	drawer.drawGraphic(wallR);
}

// �Q�[���J�n���̏����l��������֐�
void GameManager::initVariable(void)
{
	player.setX(GameConfig::WIDTH / 2);
	player.setVX(5);
	player.setVY(5);

	player.setY(GameConfig::HEIGHT / 2);
	player.setShield(GameConfig::PLAYER_SHIELD_MAX);

	// ���@�̉摜�̕��ƍ�������
	player.setWidth(images.getFighter().getWidth());
	player.setHeight(images.getFighter().getHeight());

	enemies.resetAllEnemies();

	gameData.score = 0;
	gameData.stage = 1;
	gameData.noDamage = 0;
	gameData.weaponLv = 1;
	gameData.distance = GameConfig::STAGE_DISTANCE;
}

// ���@�Ɋւ���p�����[�^�[��\��
void GameManager::drawParameter(GameManager& game)
{
	int x = 10, y = GameConfig::HEIGHT - 30; // �\���ʒu
	// �C��
	DrawBox(x, y, x + GameConfig::PLAYER_SHIELD_MAX * 30, y + 20, 0x000000, TRUE);

	for (int i = 0; i < game.getPlayer().getShield(); i++) // �V�[���h�̃��[�^�[
	{
		int r = 128 * (GameConfig::PLAYER_SHIELD_MAX - i) / GameConfig::PLAYER_SHIELD_MAX; // RGB�l���v�Z
		int g = 255 * i / GameConfig::PLAYER_SHIELD_MAX;
		int b = 160 + 96 * i / GameConfig::PLAYER_SHIELD_MAX;
		// �C��
		DrawBox(x + 2 + i * 30, y + 2, x + 28 + i * 30, y + 18, GetColor(r, g, b), TRUE);
	}
	game.getDrawer().drawText(x, y - 25, "SHIELD Lv %02d", game.getPlayer().getShield(), 0xffffff, 20); // �V�[���h�l
	drawer.drawText(x, y - 50, "WEAPON Lv %02d", game.getGameData().weaponLv, 0xffffff, 20); // ���탌�x��
	drawer.drawText(x, y - 75, "SPEED %02d", game.getPlayer().getVX(), 0xffffff, 20); // �ړ����x
}

// �������p�̊֐�
void GameManager::initGame(void)
{	
	// �Q�[���X�^�[�g���ɕK�v�ȉ摜��ǂݍ���
	images.load();

	// �T�E���h�̓ǂݍ��݂Ɖ��ʐݒ�
	soundLoader.loadAll(soundContainer);

	soundPlayer.setVolume(soundContainer.bgm, 128);
	soundPlayer.setVolume(soundContainer.jinOver, 128);
	soundPlayer.setVolume(soundContainer.jinClear, 128);
}