#pragma once

// �����N���X�����ʂŎ��v���p�e�B�̒�`
class GameObject
{
public:
    int x;     // x���W
    int y;     // y���W
    int vx;    // x�������̑���
    int vy;    // y�������̑���
    int state;   // ���݂��邩
    int pattern; // �G�@�̓����̃p�^�[��
    int image;   // �摜
    int wid;     // �摜�̕��i�s�N�Z�����j
    int hei;     // �摜�̍���
    int shield;  // �V�[���h�i�ϋv�́j
    int timer;   // �^�C�}�[
};