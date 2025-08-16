class GameManger
{
public:
	void gameLoop();

	Player& getPlayer()
	{
		return player;
	}

private:
	SceneManger sceneManager;
	Graphic  graphic;

	Player player;
	EnemyManager enemies;
	BulletManager bullets;
};


void GameManger::gameLoop()
{
	ClearDrawScreen(); // ��ʂ��N���A����

	// �Q�[���̍��g�݂ƂȂ鏈�����A�����ɋL�q����
	int spd = 1; // �X�N���[���̑���
	if (GameData::scene == PLAY && GameData::distance == 0) spd = 0; // �{�X��̓X�N���[����~
	scrollBG(graphic, spd); // �w�i�̃X�N���[��

	enemies.move(*this, graphic); // �G�@�̐���
	bullet.move(player graphic); // �e�̐���
	item.move(graphic); // �A�C�e���̐���
	effetct.draw(graphic); // �G�t�F�N�g

	stageMap(graphic); // �X�e�[�W�}�b�v
	drawParameter(graphic); // ���@�̃V�[���h�Ȃǂ̃p�����[�^�[��\��

	GameData::timer++; // �^�C�}�[���J�E���g

	sceneManager.run(*this);

	// �X�R�A�A�n�C�X�R�A�A�X�e�[�W���̕\��
	drawText(10, 10, "SCORE %07d", GameData::score, 0xffffff, 30);
	drawText(GameConfig::WIDTH - 220, 10, "HI-SC %07d", GameData::hisco, 0xffffff, 30);
	drawText(GameConfig::WIDTH - 145, GameConfig::HEIGHT - 40, "STAGE %02d", GameData::stage, 0xffffff, 30);

	ScreenFlip(); // ����ʂ̓��e��\��ʂɔ��f������
	WaitTimer(1000 / GameConfig::FPS); // ��莞�ԑ҂�
	if (ProcessMessage() == -1) break; // Windows��������󂯎��G���[���N������I��
	if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break; // ESC�L�[�������ꂽ��I��

}