#include "DxLib.h" //DX���C�u�����̃C���N���[�h
//#include "shootingGame.h" // �w�b�_�[�t�@�C�����C���N���[�h
#include "GameManager.h"
#include <cstdlib>
//#include <array>
#include <string>


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("�V���[�e�B���O�Q�[��"); // �E�B���h�E�̃^�C�g��
	SetGraphMode(GameConfig::WIDTH, GameConfig::HEIGHT, 32); // �E�B���h�E�̑傫���ƃJ���[�r�b�g���̎w��
	ChangeWindowMode(TRUE); // �E�B���h�E���[�h�ŋN��

	if (DxLib_Init() == -1)return -1; // ���C�u���������� �G���[���N������I��
	GameManager game;


	SetBackgroundColor(0, 0, 0); // �w�i�F�̎w��
	SetDrawScreen(DX_SCREEN_BACK); // �`��ʂ𗠉�ʂɂ���

	game.initGame(); // �������p�̊֐����Ăяo��

	game.initVariable(); // �y���z�Q�[��������������ۂɌĂяo���ʒu��ς���
	game.getGameData().distance = GameConfig::STAGE_DISTANCE; // �y�L�q�ʒu�͉��z�X�e�[�W�̒�������


	while (game.getGameData().isRunning) // ���C�����[�v
	{
		game.gameLoop();
	}
	DxLib_End(); // �c�w���C�u�����g�p�̏I������
	return 0; // �\�t�g�̏I��
}

