#include "GameManager.h"
#include "SceneType.h"

void GameManager::gameLoop()
{
	ClearDrawScreen(); // ��ʂ��N���A����

	// �Q�[���̍��g�݂ƂȂ鏈�����A�����ɋL�q����
	int spd = 1; // �X�N���[���̑���
	if (gameData.scene == SceneType::Play && gameData.distance == 0)
	{
		spd = 0; // �{�X��̓X�N���[����~
	}
	scrollBG(graphic, spd); // �w�i�̃X�N���[��

	//moveEnemy(); 
	//enemies.move(*this, graphic);
	enemies.moveEnemy(*this); // �G�@�̐���

	//moveBullet();
	//bullet.move(player graphic);
	bullets.moveBullet(images, *this); // �e�̐���

	//moveItem();
	//item.move(graphic);
	itemManager.moveItem(*this); // �A�C�e���̐���

	//drawEffect(); // �G�t�F�N�g
	//effetct.draw(graphic);
	effects.drawEffect(*this);


	stageMap(); // �X�e�[�W�}�b�v
	drawer.drawParameter(); // ���@�̃V�[���h�Ȃǂ̃p�����[�^�[��\��

	GameData::timer++; // �^�C�}�[���J�E���g

	sceneManager.run(*this);

	// �X�R�A�A�n�C�X�R�A�A�X�e�[�W���̕\��
	drawer.drawText(10, 10, "SCORE %07d", GameData::score, 0xffffff, 30);
	drawer.drawText(GameConfig::WIDTH - 220, 10, "HI-SC %07d", GameData::hisco, 0xffffff, 30);
	drawer.drawText(GameConfig::WIDTH - 145, GameConfig::HEIGHT - 40, "STAGE %02d", GameData::stage, 0xffffff, 30);

	ScreenFlip(); // ����ʂ̓��e��\��ʂɔ��f������
	WaitTimer(1000 / GameConfig::FPS); // ��莞�ԑ҂�
	if (ProcessMessage() == -1) break; // Windows��������󂯎��G���[���N������I��
	if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break; // ESC�L�[�������ꂽ��I��

}

// �X�e�[�W�}�b�v
void GameManager::stageMap(void)
{
	int mx = GameConfig::WIDTH - 30, my = 60; // �}�b�v�̕\���ʒu
	int wi = 20, he = GameConfig::HEIGHT - 120; // �}�b�v�̕��A����
	int pos = (GameConfig::HEIGHT - 140) * GameData::distance / GameConfig::STAGE_DISTANCE; // ���@�̔�s���Ă���ʒu
	SetDrawBlendMode(DX_BLENDMODE_SUB, 128); // ���Z�ɂ��`��̏d�ˍ��킹
	DrawBox(mx, my, mx + wi, my + he, 0xffffff, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); // �u�����h���[�h������
	DrawBox(mx - 1, my - 1, mx + wi + 1, my + he + 1, 0xffffff, FALSE); // �g��
	DrawBox(mx, my + pos, mx + wi, my + pos + 20, 0x0080ff, TRUE); // ���@�̈ʒu
}