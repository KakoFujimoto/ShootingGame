#include "DxLib.h" //DX���C�u�����̃C���N���[�h
#include "shootingGame.h" // �w�b�_�[�t�@�C�����C���N���[�h
#include <cstdlib>
#include <array>
#include <string>

// �萔�̒�`
namespace GameConfig {
	constexpr int WIDTH = 1200; // �E�B���h�E�̕�
	constexpr int HEIGHT = 720; // �E�B���h�E�̍���
	constexpr int FPS = 60; // �t���[�����[�g
	constexpr int IMG_ENEMY_MAX = 5; // �G�̉摜�̖����i��ށj
	constexpr int BULLET_MAX = 100; // ���@�����˂���e�̍ő吔
	constexpr int ENEMY_MAX = 100; // �G�@�̐��̍ő�l
	constexpr int STAGE_DISTANCE = FPS * 60; // �X�e�[�W�̒���
	constexpr int PLAYER_SHIELD_MAX = 8; // ���@�̃V�[���h�̍ő�l
	constexpr int EFFECT_MAX = 100; // �G�t�F�N�g�̍ő吔
	constexpr int ITEM_TYPE = 3; // �A�C�e���̎��
	constexpr int WEAPON_LV_MAX = 10; // ���탌�x���̍ő�l
	constexpr int PLAYER_SPEED_MAX = 20; // ���@�̑����̍ő�l
}

// �G�@�̎��
enum EnemyType {
	ENE_BULLET,
	ENE_ZAKO1,
	ENE_ZAKO2,
	ENE_ZAKO3,
	ENE_BOSS
};

// �G�t�F�N�g�̎��
enum EffectType {
	EFF_EXPLODE,
	EFF_RECOVER
};

// �V�[���̎��
enum SceneType {
	TITLE,
	PLAY,
	OVER,
	CLEAR
};



// �O���[�o���ϐ�
// �����ŃQ�[���ɗp����ϐ���z����`����
namespace GameData {
	// --- �摜 ---
	int imgGalaxy, imgFloor, imgWallL, imgWallR; // �w�i�摜
	int imgFighter, imgBullet; // ���@�Ǝ��@�̒e�̉摜
	int imgEnemy[GameConfig::IMG_ENEMY_MAX]; // �G�@�̉摜
	int imgExplosion; // �������o�̉摜
	int imgItem; // �A�C�e���̉摜

	// --- �� ---
	int bgm, jinOver, jinClear, seExpl, seItem, seShot; // ���̓ǂݍ��ݗp

	// --- �Q�[����� ---
	int distance = 0; // �X�e�[�W�I�[�܂ł̋���
	int bossIdx = 0; // �{�X���������z��̃C���f�b�N�X
	int stage = 1; // �X�e�[�W
	int score = 0; // �X�R�A
	int hisco = 10000; // �n�C�X�R�A
	int noDamage = 0; // ���G���
	int weaponLv = 1; // ���@�̕���̃��x���i�����ɔ��˂����e���j
	int scene = TITLE; // �V�[�����Ǘ�
	int timer = 0; // ���Ԃ̐i�s���Ǘ�

	// --- �I�u�W�F�N�g ---
	OBJECT player; // ���@�p�̍\���̕ϐ�
	OBJECT bullet[GameConfig::BULLET_MAX]; // �e�p�̍\���̂̔z��
	OBJECT enemy[GameConfig::ENEMY_MAX]; // �G�@�p�̍\���̂̔z��
	OBJECT effect[GameConfig::EFFECT_MAX]; // �G�t�F�N�g�p�̍\���̂̔z��
	OBJECT item; // �A�C�e���p�̍\���̕ϐ�
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("�V���[�e�B���O�Q�[��"); // �E�B���h�E�̃^�C�g��
	SetGraphMode(GameConfig::WIDTH, GameConfig::HEIGHT, 32); // �E�B���h�E�̑傫���ƃJ���[�r�b�g���̎w��
	ChangeWindowMode(TRUE); // �E�B���h�E���[�h�ŋN��

	if (DxLib_Init() == -1)return -1; // ���C�u���������� �G���[���N������I��

	GameManager game;
	
	//SetBackgroundColor(0, 0, 0); // �w�i�F�̎w��
	//SetDrawScreen(DX_SCREEN_BACK); // �`��ʂ𗠉�ʂɂ���

	//initGame(); // �������p�̊֐����Ăяo��
	//initVariable(); // �y���z�Q�[��������������ۂɌĂяo���ʒu��ς���
	//GameData::distance = GameConfig::STAGE_DISTANCE; // �y�L�q�ʒu�͉��z�X�e�[�W�̒�������

	game.init();

	while (1) // ���C�����[�v
	{
		game.gameLoop();

		//ClearDrawScreen(); // ��ʂ��N���A����

		//// �Q�[���̍��g�݂ƂȂ鏈�����A�����ɋL�q����
		//int spd = 1; // �X�N���[���̑���
		//if (GameData::scene == PLAY && GameData::distance == 0) spd = 0; // �{�X��̓X�N���[����~
		//scrollBG(spd); // �w�i�̃X�N���[��
		//moveEnemy(); // �G�@�̐���
		//moveBullet(); // �e�̐���
		//moveItem(); // �A�C�e���̐���
		//drawEffect(); // �G�t�F�N�g
		//stageMap(); // �X�e�[�W�}�b�v
		//drawParameter(); // ���@�̃V�[���h�Ȃǂ̃p�����[�^�[��\��

		//GameData::timer++; // �^�C�}�[���J�E���g
		//switch (GameData::scene) // �V�[�����Ƃɏ����𕪊�
		//{
		//case TITLE: // �^�C�g�����
		//	drawTextC(GameConfig::WIDTH * 0.5, GameConfig::HEIGHT * 0.3, "Shooting Game", 0xffffff, 80);
		//	drawTextC(GameConfig::WIDTH * 0.5, GameConfig::HEIGHT * 0.7, "Press SPACE to start.", 0xffffff, 30);
		//	if (CheckHitKey(KEY_INPUT_SPACE))
		//	{
		//		initVariable();
		//		GameData::scene = PLAY;
		//	}
		//	break;

		//case PLAY: // �Q�[���v���C���
		//	movePlayer(); // ���@�̑���
		//	if (GameData::distance == GameConfig::STAGE_DISTANCE)
		//	{
		//		srand(GameData::stage); // �X�e�[�W�̃p�^�[�������߂�
		//		PlaySoundMem(GameData::bgm, DX_PLAYTYPE_LOOP); // �a�f�l���[�v�o��
		//	}
		//	if (GameData::distance > 0) GameData::distance--;
		//	if (300 < GameData::distance && GameData::distance % 20 == 0) // �U�R1��2�̏o��
		//	{
		//		int x = 100 + rand() % (GameConfig::WIDTH - 200);
		//		int y = -50;
		//		int e = 1 + rand() % 2;
		//		if (e == ENE_ZAKO1) setEnemy(x, y, 0, 3, ENE_ZAKO1, GameData::imgEnemy[ENE_ZAKO1], 1);
		//		if (e == ENE_ZAKO2) {
		//			int vx = 0;
		//			if (GameData::player.x < x - 50) vx = -3;
		//			if (GameData::player.x > x + 50) vx = 3;
		//			setEnemy(x, -100, vx, 5, ENE_ZAKO2, GameData::imgEnemy[ENE_ZAKO2], 3);
		//		}
		//	}
		//	if (300 < GameData::distance && GameData::distance < 900 && GameData::distance % 30 == 0) // �U�R3�̏o��
		//	{
		//		int x = 100 + rand() % (GameConfig::WIDTH - 200);
		//		int y = -50;
		//		int vy = 40 + rand() % 20;
		//		setEnemy(x, -100, 0, vy, ENE_ZAKO3, GameData::imgEnemy[ENE_ZAKO3], 5);
		//	}
		//		if (GameData::distance == 1) GameData::bossIdx = setEnemy(GameConfig::WIDTH / 2, -120, 0, 1, ENE_BOSS, GameData::imgEnemy[ENE_BOSS], 200); // �{�X�o��
		//		if (GameData::distance % 800 == 1) setItem(); // �A�C�e���̏o��
		//		if (GameData::player.shield == 0)
		//		{
		//			StopSoundMem(GameData::bgm); // �a�f�l��~
		//			GameData::scene = OVER;
		//			GameData::timer = 0;
		//			break;
		//		}
		//		break;

		//case OVER: // �Q�[���I�[�o�[
		//	if (GameData::timer < GameConfig::FPS * 3) // ���@���������鉉�o
		//	{
		//		if (GameData::timer % 7 == 0) setEffect(GameData::player.x + rand() % 81 - 40, GameData::player.y + rand() % 81 - 40, EFF_EXPLODE);
		//	}
		//	else if (GameData::timer == GameConfig::FPS * 3)
		//	{
		//		PlaySoundMem(GameData::jinOver, DX_PLAYTYPE_BACK); // �W���O���o��
		//	}
		//	else
		//	{
		//		drawTextC(GameConfig::WIDTH * 0.5, GameConfig::HEIGHT * 0.3, "GAME OVER", 0xff0000, 80);
		//	}
		//	if (GameData::timer > GameConfig::FPS * 10) GameData::scene = TITLE; // �^�C�g���֑J��
		//	break;

		//case CLEAR: // �X�e�[�W�N���A
		//	movePlayer(); // ���@�̏���
		//	if (GameData::timer < GameConfig::FPS * 3) // �{�X���������鉉�o
		//	{
		//		if (GameData::timer % 7 == 0) setEffect(GameData::enemy[GameData::bossIdx].x + rand() % 201 - 100, GameData::enemy[GameData::bossIdx].y + rand() % 201 - 100, EFF_EXPLODE);
		//	}
		//	else if (GameData::timer == GameConfig::FPS * 3)
		//	{
		//		PlaySoundMem(GameData::jinClear, DX_PLAYTYPE_BACK); // �W���O���o��
		//	}
		//	else
		//	{
		//		drawTextC(GameConfig::WIDTH * 0.5, GameConfig::HEIGHT * 0.3, "STAGE CLEAR!", 0x00ffff, 80);
		//	}
		//	if (GameData::timer > GameConfig::FPS * 10) // �Q�[���v���C�֑J��
		//	{
		//		GameData::stage++;
		//		GameData::distance = GameConfig::STAGE_DISTANCE;
		//		GameData::scene = PLAY;
		//	}
		//	break;
		//	}

		//	// �X�R�A�A�n�C�X�R�A�A�X�e�[�W���̕\��
		//	drawText(10, 10, "SCORE %07d", GameData::score, 0xffffff, 30);
		//	drawText(GameConfig::WIDTH - 220, 10, "HI-SC %07d", GameData::hisco, 0xffffff, 30);
		//	drawText(GameConfig::WIDTH - 145, GameConfig::HEIGHT - 40, "STAGE %02d", GameData::stage, 0xffffff, 30);

		//	ScreenFlip(); // ����ʂ̓��e��\��ʂɔ��f������
		//	WaitTimer(1000 / GameConfig::FPS); // ��莞�ԑ҂�
		//	if (ProcessMessage() == -1) break; // Windows��������󂯎��G���[���N������I��
		//	if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break; // ESC�L�[�������ꂽ��I��
		}

		DxLib_End(); // �c�w���C�u�����g�p�̏I������
		return 0; // �\�t�g�̏I��
	}

	// �������牺�Ɏ��삵���֐����L�q����
	// �������p�̊֐�
	void initGame(void)
	{
		// �w�i�p�̉摜�̓ǂݍ���
		GameData::imgGalaxy = LoadGraph("image/bg0.png");
		GameData::imgFloor = LoadGraph("image/bg1.png");
		GameData::imgWallL = LoadGraph("image/bg2.png");
		GameData::imgWallR = LoadGraph("image/bg3.png");
		// ���@�Ǝ��@�̒e�̉摜�̓ǂݍ���
		GameData::imgFighter = LoadGraph("image/fighter.png");
		GameData::imgBullet = LoadGraph("image/bullet.png");
		// �G�@�̉摜�̓ǂݍ���
		for (int i = 0; i < GameConfig::IMG_ENEMY_MAX; i++) {
			std::string file = "image/enemy" + std::to_string(i) + ".png";
			GameData::imgEnemy[i] = LoadGraph(file.c_str());
		}
		// ���̑��̉摜�̓ǂݍ���
		GameData::imgExplosion = LoadGraph("image/explosion.png"); // �������o
		GameData::imgItem = LoadGraph("image/item.png"); // �A�C�e��

		// �T�E���h�̓ǂݍ��݂Ɖ��ʐݒ�
		GameData::bgm = LoadSoundMem("sound/bgm.mp3");
		GameData::jinOver = LoadSoundMem("sound/gameover.mp3");
		GameData::jinClear = LoadSoundMem("sound/stageclear.mp3");
		GameData::seExpl = LoadSoundMem("sound/explosion.mp3");
		GameData::seItem = LoadSoundMem("sound/item.mp3");
		GameData::seShot = LoadSoundMem("sound/shot.mp3");
		ChangeVolumeSoundMem(128, GameData::bgm);
		ChangeVolumeSoundMem(128, GameData::jinOver);
		ChangeVolumeSoundMem(128, GameData::jinClear);
	}

	// �w�i�̃X�N���[��
	void scrollBG(int spd)
	{
		static int galaxyY, floorY, wallY; // �X�N���[���ʒu���Ǘ�����ϐ��i�ÓI�L���̈�ɕێ������j
		galaxyY = (galaxyY + spd) % GameConfig::HEIGHT; // ����i�F���j
		DrawGraph(0, galaxyY - GameConfig::HEIGHT, GameData::imgGalaxy, FALSE);
		DrawGraph(0, galaxyY, GameData::imgGalaxy, FALSE);
		floorY = (floorY + spd * 2) % 120;  // ��
		for (int i = -1; i < 6; i++) DrawGraph(240, floorY + i * 120, GameData::imgFloor, TRUE);
		wallY = (wallY + spd * 4) % 240;    // ���E�̕�
		DrawGraph(0, wallY - 240, GameData::imgWallL, TRUE);
		DrawGraph(GameConfig::WIDTH - 300, wallY - 240, GameData::imgWallR, TRUE);
	}

	// �Q�[���J�n���̏����l��������֐�
	void initVariable(void)
	{
		GameData::player.x = GameConfig::WIDTH / 2;
		GameData::player.vx = 5;
		GameData::player.vy = 5;
		GameData::player.y = GameConfig::HEIGHT / 2;
		GameData::player.shield = GameConfig::PLAYER_SHIELD_MAX;
		GetGraphSize(GameData::imgFighter, &GameData::player.wid, &GameData::player.hei); // ���@�̉摜�̕��ƍ�������
		for (int i = 0; i < GameConfig::ENEMY_MAX; i++) GameData::enemy[i].state = 0; // �S�Ă̓G�@�𑶍݂��Ȃ���Ԃ�
		GameData::score = 0;
		GameData::stage = 1;
		GameData::noDamage = 0;
		GameData::weaponLv = 1;
		GameData::distance = GameConfig::STAGE_DISTANCE;
	}

	// ���S���W���w�肵�ĉ摜��\������֐�
	void drawImage(int img, int x, int y)
	{
		int w, h;
		GetGraphSize(img, &w, &h);
		DrawGraph(x - w / 2, y - h / 2, img, TRUE);
	}

	// ���@�𓮂����֐�
	void movePlayer(void)
	{
		static char oldSpcKey; // 1�O�̃X�y�[�X�L�[�̏�Ԃ�ێ�����ϐ�
		static int countSpcKey; // �X�y�[�X�L�[�����������Ă���ԁA�J�E���g�A�b�v����ϐ�
		if (CheckHitKey(KEY_INPUT_UP)) { // ��L�[
			GameData::player.y -= GameData::player.vy;
			if (GameData::player.y < 30) GameData::player.y = 30;
		}
		if (CheckHitKey(KEY_INPUT_DOWN)) { // ���L�[
			GameData::player.y += GameData::player.vy;
			if (GameData::player.y > GameConfig::HEIGHT - 30) GameData::player.y = GameConfig::HEIGHT - 30;
		}
		if (CheckHitKey(KEY_INPUT_LEFT)) { // ���L�[
			GameData::player.x -= GameData::player.vx;
			if (GameData::player.x < 30) GameData::player.x = 30;
		}
		if (CheckHitKey(KEY_INPUT_RIGHT)) { // �E�L�[
			GameData::player.x += GameData::player.vx;
			if (GameData::player.x > GameConfig::WIDTH - 30) GameData::player.x = GameConfig::WIDTH - 30;
		}
		if (CheckHitKey(KEY_INPUT_SPACE)) { // �X�y�[�X�L�[
			if (oldSpcKey == 0) setBullet(); // �������u�ԁA����
			else if (countSpcKey % 20 == 0) setBullet(); // ���Ԋu�Ŕ���
			countSpcKey++;
		}
		oldSpcKey = CheckHitKey(KEY_INPUT_SPACE); // �X�y�[�X�L�[�̏�Ԃ�ێ�
		if (GameData::noDamage > 0) GameData::noDamage--; // ���G���Ԃ̃J�E���g
		if (GameData::noDamage % 4 < 2) drawImage(GameData::imgFighter, GameData::player.x, GameData::player.y); // ���@�̕`��
	}

	// �e�̃Z�b�g�i���ˁj
	void setBullet(void)
	{
		for (int n = 0; n < GameData::weaponLv; n++) {
			int x = GameData::player.x - (GameData::weaponLv - 1) * 5 + n * 10;
			int y = GameData::player.y - 20;
			for (int i = 0; i < GameConfig::BULLET_MAX; i++) {
				if (GameData::bullet[i].state == 0) {
					GameData::bullet[i].x = x;
					GameData::bullet[i].y = y;
					GameData::bullet[i].vx = 0;
					GameData::bullet[i].vy = -40;
					GameData::bullet[i].state = 1;
					break;
				}
			}
		}
		PlaySoundMem(GameData::seShot, DX_PLAYTYPE_BACK); // ���ʉ�
	}

	// �e�̈ړ�
	void moveBullet(void)
	{
		for (int i = 0; i < GameConfig::BULLET_MAX; i++) {
			if (GameData::bullet[i].state == 0) continue; // �󂢂Ă���z��Ȃ珈�����Ȃ�
			GameData::bullet[i].x += GameData::bullet[i].vx; // �� ���W��ω�������
			GameData::bullet[i].y += GameData::bullet[i].vy; // ��
			drawImage(GameData::imgBullet, GameData::bullet[i].x, GameData::bullet[i].y); // �e�̕`��
			if (GameData::bullet[i].y < -100) GameData::bullet[i].state = 0; // ��ʊO�ɏo����A���݂��Ȃ���Ԃɂ���
		}
	}

	// �G�@���Z�b�g����
	//int setEnemy(int x, int y, int vx, int vy, int ptn, int img, int sld)
	//{
	//	for (int i = 0; i < GameConfig::ENEMY_MAX; i++) {
	//		if (GameData::enemy[i].state == 0) {
	//			GameData::enemy[i].x = x;
	//			GameData::enemy[i].y = y;
	//			GameData::enemy[i].vx = vx;
	//			GameData::enemy[i].vy = vy;
	//			GameData::enemy[i].state = 1;
	//			GameData::enemy[i].pattern = ptn;
	//			GameData::enemy[i].image = img;
	//			GameData::enemy[i].shield = sld * GameData::stage; // �X�e�[�W���i�ނقǓG���ł��Ȃ�
	//			GetGraphSize(img, &GameData::enemy[i].wid, &GameData::enemy[i].hei); // �摜�̕��ƍ�������
	//			return i;
	//		}
	//	}
	//	return -1;
	//}

	// �G�@�𓮂���
	//void moveEnemy(void)
	//{
	//	for (int i = 0; i < GameConfig::ENEMY_MAX; i++) {
	//		if (GameData::enemy[i].state == 0) continue; // �󂢂Ă���z��Ȃ珈�����Ȃ�
	//		if (GameData::enemy[i].pattern == ENE_ZAKO3) // �U�R�@3
	//		{
	//			if (GameData::enemy[i].vy > 1) // ����
	//			{
	//				GameData::enemy[i].vy *= 0.9;
	//			}
	//			else if (GameData::enemy[i].vy > 0) // �e���ˁA��ы���
	//			{
	//				setEnemy(GameData::enemy[i].x, GameData::enemy[i].y, 0, 6, ENE_BULLET, GameData::imgEnemy[ENE_BULLET], 0); // �e
	//				GameData::enemy[i].vx = 8;
	//				GameData::enemy[i].vy = -4;
	//			}
	//		}
	//		if (GameData::enemy[i].pattern == ENE_BOSS) // �{�X�@
	//		{
	//			if (GameData::enemy[i].y > GameConfig::HEIGHT - 120) GameData::enemy[i].vy = -2;
	//			if (GameData::enemy[i].y < 120) // ��ʏ�[
	//			{
	//				if (GameData::enemy[i].vy < 0) // �e����
	//				{
	//					for (int bx = -2; bx <= 2; bx++) // ��d���[�v��for
	//						for (int by = 0; by <= 3; by++)
	//						{
	//							if (bx == 0 && by == 0) continue;
	//							setEnemy(GameData::enemy[i].x, GameData::enemy[i].y, bx * 2, by * 3, ENE_BULLET, GameData::imgEnemy[ENE_BULLET], 0);
	//						}
	//				}
	//				GameData::enemy[i].vy = 2;
	//			}
	//		}
	//		GameData::enemy[i].x += GameData::enemy[i].vx; //���G�@�̈ړ�
	//		GameData::enemy[i].y += GameData::enemy[i].vy; //��
	//		drawImage(GameData::enemy[i].image, GameData::enemy[i].x, GameData::enemy[i].y); // �G�@�̕`��
	//		// ��ʊO�ɏo�����H
	//		if (GameData::enemy[i].x < -200 || GameConfig::WIDTH + 200 < GameData::enemy[i].x || GameData::enemy[i].y < -200 || GameConfig::HEIGHT + 200 < GameData::enemy[i].y) GameData::enemy[i].state = 0;
	//		// �����蔻��̃A���S���Y��
	//		if (GameData::enemy[i].shield > 0) // �q�b�g�`�F�b�N���s���G�@�i�e�ȊO�j
	//		{
	//			for (int j = 0; j < GameConfig::BULLET_MAX; j++) { // ���@�̒e�ƃq�b�g�`�F�b�N
	//				if (GameData::bullet[j].state == 0) continue;
	//				int dx = abs((int)(GameData::enemy[i].x - GameData::bullet[j].x)); //�����S���W�Ԃ̃s�N�Z����
	//				int dy = abs((int)(GameData::enemy[i].y - GameData::bullet[j].y)); //��
	//				if (dx < GameData::enemy[i].wid / 2 && dy < GameData::enemy[i].hei / 2) // �ڐG���Ă��邩
	//				{
	//					GameData::bullet[j].state = 0; // �e������
	//					damageEnemy(i, 1); // �G�Ƀ_���[�W
	//				}
	//			}
	//		}
	//		if (GameData::noDamage == 0) // ���G��ԂłȂ����A���@�ƃq�b�g�`�F�b�N
	//		{
	//			int dx = abs(GameData::enemy[i].x - GameData::player.x); //�����S���W�Ԃ̃s�N�Z����
	//			int dy = abs(GameData::enemy[i].y - GameData::player.y); //��
	//			if (dx < GameData::enemy[i].wid / 2 + GameData::player.wid / 2 && dy < GameData::enemy[i].hei / 2 + GameData::player.hei / 2)
	//			{
	//				if (GameData::player.shield > 0) GameData::player.shield--; // �V�[���h�����炷
	//				GameData::noDamage = GameConfig::FPS; // ���G��Ԃ��Z�b�g
	//				damageEnemy(i, 1); // �G�Ƀ_���[�W
	//			}
	//		}
	//	}
	//}

	// �X�e�[�W�}�b�v
	void stageMap(void)
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

	// �G�@�̃V�[���h�����炷�i�_���[�W��^����j
	void damageEnemy(int n, int dmg)
	{
		SetDrawBlendMode(DX_BLENDMODE_ADD, 192); // ���Z�ɂ��`��̏d�ˍ��킹
		DrawCircle(GameData::enemy[n].x, GameData::enemy[n].y, (GameData::enemy[n].wid + GameData::enemy[n].hei) / 4, 0xff0000, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); // �u�����h���[�h������
		GameData::score += 100; // �X�R�A�̉��Z
		if (GameData::score > GameData::hisco) GameData::hisco = GameData::score; // �n�C�X�R�A�̍X�V
		GameData::enemy[n].shield -= dmg; // �V�[���h�����炷
		if (GameData::enemy[n].shield <= 0)
		{
			GameData::enemy[n].state = 0; // �V�[���h0�ȉ��ŏ���
			setEffect(GameData::enemy[n].x, GameData::enemy[n].y, EFF_EXPLODE); // �������o
			if (GameData::enemy[n].pattern == ENE_BOSS) // �{�X��|����
			{
				StopSoundMem(GameData::bgm); // �a�f�l��~
				GameData::scene = CLEAR;
				GameData::timer = 0;
			}
		}
	}

	// �e��t����������ƒl��\������֐�
	void drawText(int x, int y, const char* txt, int val, int col, int siz)
	{
		SetFontSize(siz); // �t�H���g�̑傫�����w��
		DrawFormatString(x + 1, y + 1, 0x000000, txt, val); // ���ŕ������\��
		DrawFormatString(x, y, col, txt, val); // �����̐F�ŕ������\��
	}

	// ���@�Ɋւ���p�����[�^�[��\��
	void drawParameter(void)
	{
		int x = 10, y = GameConfig::HEIGHT - 30; // �\���ʒu
		DrawBox(x, y, x + GameConfig::PLAYER_SHIELD_MAX * 30, y + 20, 0x000000, TRUE);
		for (int i = 0; i < GameData::player.shield; i++) // �V�[���h�̃��[�^�[
		{
			int r = 128 * (GameConfig::PLAYER_SHIELD_MAX - i) / GameConfig::PLAYER_SHIELD_MAX; // RGB�l���v�Z
			int g = 255 * i / GameConfig::PLAYER_SHIELD_MAX;
			int b = 160 + 96 * i / GameConfig::PLAYER_SHIELD_MAX;
			DrawBox(x + 2 + i * 30, y + 2, x + 28 + i * 30, y + 18, GetColor(r, g, b), TRUE);
		}
		drawText(x, y - 25, "SHIELD Lv %02d", GameData::player.shield, 0xffffff, 20); // �V�[���h�l
		drawText(x, y - 50, "WEAPON Lv %02d", GameData::weaponLv, 0xffffff, 20); // ���탌�x��
		drawText(x, y - 75, "SPEED %02d", GameData::player.vx, 0xffffff, 20); // �ړ����x
	}

	// �G�t�F�N�g�̃Z�b�g
	//void setEffect(int x, int y, int ptn)
	//{
	//	static int eff_num;
	//	GameData::effect[eff_num].x = x;
	//	GameData::effect[eff_num].y = y;
	//	GameData::effect[eff_num].state = 1;
	//	GameData::effect[eff_num].pattern = ptn;
	//	GameData::effect[eff_num].timer = 0;
	//	eff_num = (eff_num + 1) % GameConfig::EFFECT_MAX;
	//	if (ptn == EFF_EXPLODE) PlaySoundMem(GameData::seExpl, DX_PLAYTYPE_BACK); // ���ʉ�
	//}

	// �G�t�F�N�g�̕`��
	//void drawEffect(void)
	//{
	//	int ix;
	//	for (int i = 0; i < GameConfig::EFFECT_MAX; i++)
	//	{
	//		if (GameData::effect[i].state == 0) continue;

	//		GameData::effect[i].draw(drawer):

	//		//switch (GameData::effect[i].pattern) // �G�t�F�N�g���Ƃɏ����𕪂���
	//		//{
	//		//case EFF_EXPLODE: // �������o
	//		//	ix = GameData::effect[i].timer * 128; // �摜�̐؂�o���ʒu
	//		//	DrawRectGraph(GameData::effect[i].x - 64, GameData::effect[i].y - 64, ix, 0, 128, 128, GameData::imgExplosion, TRUE, FALSE);
	//		//	GameData::effect[i].timer++;
	//		//	if (GameData::effect[i].timer == 7) GameData::effect[i].state = 0;
	//		//	break;

	//		//case EFF_RECOVER: // �񕜉��o
	//		//	if (GameData::effect[i].timer < 30) // ���Z�ɂ��`��̏d�ˍ��킹
	//		//		SetDrawBlendMode(DX_BLENDMODE_ADD, GameData::effect[i].timer * 8);
	//		//	else
	//		//		SetDrawBlendMode(DX_BLENDMODE_ADD, (60 - GameData::effect[i].timer) * 8);
	//		//	for (int i = 3; i < 8; i++) DrawCircle(GameData::player.x, GameData::player.y, (GameData::player.wid + GameData::player.hei) / i, 0x2040c0, TRUE);
	//		//	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); // �u�����h���[�h������
	//		//	GameData::effect[i].timer++;
	//		//	if (GameData::effect[i].timer == 60) GameData::effect[i].state = 0;
	//		//	break;
	//		//}
	//	}
	//}

	// �A�C�e�����Z�b�g
	void setItem(void)
	{
		GameData::item.x = (GameConfig::WIDTH / 4) * (1 + rand() % 3);
		GameData::item.y = -16;
		GameData::item.vx = 15;
		GameData::item.vy = 1;
		GameData::item.state = 1;
		GameData::item.timer = 0;
	}

	// �A�C�e���̏���
	void moveItem(void)
	{
		if (GameData::item.state == 0) return;
		GameData::item.x += GameData::item.vx;
		GameData::item.y += GameData::item.vy;
		if (GameData::item.timer % 60 < 30)
			GameData::item.vx -= 1;
		else
			GameData::item.vx += 1;
		if (GameData::item.y > GameConfig::HEIGHT + 16) GameData::item.state = 0;
		GameData::item.pattern = (GameData::item.timer / 120) % GameConfig::ITEM_TYPE; // ���݁A�ǂ̃A�C�e���ɂȂ��Ă��邩
		GameData::item.timer++;
		DrawRectGraph(GameData::item.x - 20, GameData::item.y - 16, GameData::item.pattern * 40, 0, 40, 32, GameData::imgItem, TRUE, FALSE);
		if (GameData::scene == OVER) return; // �Q�[���I�[�o�[��ʂł͉���ł��Ȃ�
		int dis = (GameData::item.x - GameData::player.x) * (GameData::item.x - GameData::player.x) + (GameData::item.y - GameData::player.y) * (GameData::item.y - GameData::player.y);
		if (dis < 60 * 60) // �A�C�e���Ǝ��@�Ƃ̃q�b�g�`�F�b�N�i�~�ɂ�铖���蔻��j
		{
			GameData::item.state = 0;
			if (GameData::item.pattern == 0) // �X�s�[�h�A�b�v
			{
				if (GameData::player.vx < GameConfig::PLAYER_SPEED_MAX)
				{
					GameData::player.vx += 3;
					GameData::player.vy += 3;
				}
			}
			if (GameData::item.pattern == 1) // �V�[���h��
			{
				if (GameData::player.shield < GameConfig::PLAYER_SHIELD_MAX) GameData::player.shield++;
				setEffect(GameData::player.x, GameData::player.y, EFF_RECOVER); // �񕜃G�t�F�N�g��\��
			}
			if (GameData::item.pattern == 2) // ���탌�x���A�b�v
			{
				if (GameData::weaponLv < GameConfig::WEAPON_LV_MAX) GameData::weaponLv++;
			}
			PlaySoundMem(GameData::seItem, DX_PLAYTYPE_BACK); // ���ʉ�
		}
	}

	// ��������Z���^�����O���ĕ\������֐�
	void drawTextC(int x, int y, const char* txt, int col, int siz)
	{
		SetFontSize(siz);
		int strWidth = GetDrawStringWidth(txt, strlen(txt));
		x -= strWidth / 2;
		y -= siz / 2;
		DrawString(x + 1, y + 1, txt, 0x000000);
		DrawString(x, y, txt, col);
	}