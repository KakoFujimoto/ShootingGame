#pragma once

// �\���̂̐錾
struct OBJECT // ���@��G�@�p
{
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

// �֐��v���g�^�C�v�錾
// �����Ƀv���g�^�C�v�錾���L�q����
void initGame(void);
void scrollBG(int spd);
void initVariable(void);
void drawImage(int img, int x, int y);
void movePlayer(void);
void setBullet(void);
void moveBullet(void);
int setEnemy(int x, int y, int vx, int vy, int ptn, int img, int sld);
void moveEnemy(void);
void stageMap(void);
void damageEnemy(int n, int dmg);
void drawText(int x, int y, const char* txt, int val, int col, int siz);
void drawParameter(void);
void setEffect(int x, int y, int ptn);
void drawEffect(void);
void setItem(void);
void moveItem(void);
void drawTextC(int x, int y, const char* txt, int col, int siz);
