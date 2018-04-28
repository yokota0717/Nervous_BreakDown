#pragma once
#include "DxLib.h"
#include "../Figure/Math.h"


//�L�[�{�[�h����
enum KeyCode {
	LEFT = KEY_INPUT_LEFT,
	RIGHT = KEY_INPUT_RIGHT,
	UP = KEY_INPUT_UP,
	DOWN = KEY_INPUT_DOWN,
	BACK = KEY_INPUT_BACK,
	ENTER = KEY_INPUT_RETURN,
	ESCAPE = KEY_INPUT_ESCAPE,
	SPACE = KEY_INPUT_SPACE,

	A = KEY_INPUT_A,
	B = KEY_INPUT_B,
	C = KEY_INPUT_C,
	D = KEY_INPUT_D,
	E = KEY_INPUT_E,
	F = KEY_INPUT_F,
	G = KEY_INPUT_G,
	H = KEY_INPUT_H,
	I = KEY_INPUT_I,
	J = KEY_INPUT_J,
	K = KEY_INPUT_K,
	L = KEY_INPUT_L,
	M = KEY_INPUT_M,
	N = KEY_INPUT_N,
	O = KEY_INPUT_O,
	P = KEY_INPUT_P,
	Q = KEY_INPUT_Q,
	R = KEY_INPUT_R,
	S = KEY_INPUT_S,
	T = KEY_INPUT_T,
	U = KEY_INPUT_U,
	V = KEY_INPUT_V,
	W = KEY_INPUT_W,
	X = KEY_INPUT_X,
	Y = KEY_INPUT_Y,
	Z = KEY_INPUT_Z,


	//KEY_INPUT_TAB				

	//KEY_INPUT_LSHIFT			
	//KEY_INPUT_RSHIFT			
	//KEY_INPUT_LCONTROL		
	//KEY_INPUT_RCONTROL		
	//KEY_INPUT_PGUP			
	//KEY_INPUT_PGDN			
	//KEY_INPUT_END				
	//KEY_INPUT_HOME			
	//KEY_INPUT_INSERT			
	//KEY_INPUT_DELETE			
	//
	//KEY_INPUT_MINUS			
	//KEY_INPUT_YEN				
	//KEY_INPUT_PREVTRACK		
	//KEY_INPUT_PERIOD			
	//KEY_INPUT_SLASH			
	//KEY_INPUT_LALT			
	//KEY_INPUT_RALT			
	//KEY_INPUT_SCROLL			
	//KEY_INPUT_SEMICOLON		
	//KEY_INPUT_COLON			
	//KEY_INPUT_LBRACKET		
	//KEY_INPUT_RBRACKET		
	//KEY_INPUT_AT				
	//KEY_INPUT_BACKSLASH		
	//KEY_INPUT_COMMA			
	//KEY_INPUT_KANJI			
	//KEY_INPUT_CONVERT			
	//KEY_INPUT_NOCONVERT		
	//KEY_INPUT_KANA			
	//KEY_INPUT_APPS			
	//KEY_INPUT_CAPSLOCK		
	//KEY_INPUT_SYSRQ			
	//KEY_INPUT_PAUSE			
	//KEY_INPUT_LWIN			
	//KEY_INPUT_RWIN			
	//
	//KEY_INPUT_NUMLOCK			
	//KEY_INPUT_NUMPAD0			
	//KEY_INPUT_NUMPAD1			
	//KEY_INPUT_NUMPAD2			
	//KEY_INPUT_NUMPAD3			
	//KEY_INPUT_NUMPAD4			
	//KEY_INPUT_NUMPAD5			
	//KEY_INPUT_NUMPAD6			
	//KEY_INPUT_NUMPAD7			
	//KEY_INPUT_NUMPAD8			
	//KEY_INPUT_NUMPAD9			
	//KEY_INPUT_MULTIPLY		
	//KEY_INPUT_ADD				
	//KEY_INPUT_SUBTRACT		
	//KEY_INPUT_DECIMAL			
	//KEY_INPUT_DIVIDE			
	//KEY_INPUT_NUMPADENTER		
	//
	//KEY_INPUT_F1				
	//KEY_INPUT_F2				
	//KEY_INPUT_F3				
	//KEY_INPUT_F4				
	//KEY_INPUT_F5				
	//KEY_INPUT_F6				
	//KEY_INPUT_F7				
	//KEY_INPUT_F8				
	//KEY_INPUT_F9				
	//KEY_INPUT_F10				
	//KEY_INPUT_F11				
	//KEY_INPUT_F12				
	//
	
	//KEY_INPUT_0 				
	//KEY_INPUT_1				
	//KEY_INPUT_2				
	//KEY_INPUT_3				
	//KEY_INPUT_4				
	//KEY_INPUT_5				
	//KEY_INPUT_6				
	//KEY_INPUT_7				
	//KEY_INPUT_8				
	//KEY_INPUT_9				

};

class Keyboard {
	unsigned int Key[256];		// �L�[�̓��͏�Ԋi�[�p�ϐ�
	unsigned int preKey[256];	//1�t���[���O�̓��͏��
	// KeyCode�̃L�[�̓��͏�Ԃ��擾����
	int getKey(KeyCode KeyCode);
	int getPreKey(KeyCode keycode);

public:
	// �L�[�̓��͏�ԍX�V
	void update();

	bool On(KeyCode keycode);
	bool Down(KeyCode keycode);
	bool Up(KeyCode keycode);
	bool Off(KeyCode keycode);
};
/*
PAD_INPUT_DOWN�@	// ���`�F�b�N�}�X�N(���L�[ or �e���L�[�̂Q�L�[)
PAD_INPUT_LEFT�@	// ���`�F�b�N�}�X�N(���L�[ or �e���L�[�̂S�L�[)
PAD_INPUT_RIGHT	// ���`�F�b�N�}�X�N(�E�L�[ or �e���L�[�̂U�L�[)
PAD_INPUT_UP�@	// ���`�F�b�N�}�X�N(��L�[ or �e���L�[�̂W�L�[)
PAD_INPUT_1�@	// 1�{�^���`�F�b�N�}�X�N(�y�L�[)
PAD_INPUT_2�@	// 2�{�^���`�F�b�N�}�X�N(�w�L�[)
PAD_INPUT_3�@	// 3�{�^���`�F�b�N�}�X�N(�b�L�[)
PAD_INPUT_4�@	// 4�{�^���`�F�b�N�}�X�N(�`�L�[)
PAD_INPUT_5�@	// 5�{�^���`�F�b�N�}�X�N(�r�L�[)
PAD_INPUT_6�@	// 6�{�^���`�F�b�N�}�X�N(�c�L�[)
PAD_INPUT_7�@	// 7�{�^���`�F�b�N�}�X�N(�p�L�[)
PAD_INPUT_8�@	// 8�{�^���`�F�b�N�}�X�N(�v�L�[)
PAD_INPUT_9�@	// 9�{�^���`�F�b�N�}�X�N(�d�r�b�L�[)
PAD_INPUT_10�@	// 10�{�^���`�F�b�N�}�X�N(�X�y�[�X�L�[)

#define PAD_INPUT_DOWN								(0x00000001)	// ���`�F�b�N�}�X�N
#define PAD_INPUT_LEFT								(0x00000002)	// ���`�F�b�N�}�X�N
#define PAD_INPUT_RIGHT								(0x00000004)	// ���`�F�b�N�}�X�N
#define PAD_INPUT_UP								(0x00000008)	// ���`�F�b�N�}�X�N
#define PAD_INPUT_A									(0x00000010)	// �`�{�^���`�F�b�N�}�X�N
#define PAD_INPUT_B									(0x00000020)	// �a�{�^���`�F�b�N�}�X�N
#define PAD_INPUT_C									(0x00000040)	// �b�{�^���`�F�b�N�}�X�N
#define PAD_INPUT_X									(0x00000080)	// �w�{�^���`�F�b�N�}�X�N
#define PAD_INPUT_Y									(0x00000100)	// �x�{�^���`�F�b�N�}�X�N
#define PAD_INPUT_Z									(0x00000200)	// �y�{�^���`�F�b�N�}�X�N
#define PAD_INPUT_L									(0x00000400)	// �k�{�^���`�F�b�N�}�X�N
#define PAD_INPUT_R									(0x00000800)	// �q�{�^���`�F�b�N�}�X�N
#define PAD_INPUT_START								(0x00001000)	// �r�s�`�q�s�{�^���`�F�b�N�}�X�N
#define PAD_INPUT_M									(0x00002000)	// �l�{�^���`�F�b�N�}�X�N


typedef struct tagDINPUT_JOYSTATE
{
int						X ;								// �X�e�B�b�N�̂w���p�����[�^( -1000�`1000 )
int						Y ;								// �X�e�B�b�N�̂x���p�����[�^( -1000�`1000 )
int						Z ;								// �X�e�B�b�N�̂y���p�����[�^( -1000�`1000 )
int						Rx ;							// �X�e�B�b�N�̂w����]�p�����[�^( -1000�`1000 )
int						Ry ;							// �X�e�B�b�N�̂x����]�p�����[�^( -1000�`1000 )
int						Rz ;							// �X�e�B�b�N�̂y����]�p�����[�^( -1000�`1000 )
int						Slider[ 2 ] ;					// �X���C�_�[���
unsigned int			POV[ 4 ] ;						// �n�b�g�X�C�b�`�S��( 0xffffffff:���͂Ȃ� 0:�� 4500:�E�� 9000:�E 13500:�E�� 18000:�� 22500:���� 27000:�� 31500:���� )
unsigned char			Buttons[ 32 ] ;					// �{�^���R�Q��( �����ꂽ�{�^���� 128 �ɂȂ� )
} DINPUT_JOYSTATE ;

*/
//�p�b�h����
class GPad {
	enum PadType {
		one,
		two,
		three,
		four,
	};
	DINPUT_JOYSTATE input;		//���͏��
	unsigned int padNum;		//�ڑ�����Ă���p�b�h�̐�

	GPad(int);
	void update();
	unsigned int getPadNum();

private:
	unsigned int padID;
};


//�}�E�X����
class Mouse {
public:
	int x, y;				//���W
	int wheel;				//�z�C�[���̏��
	unsigned int button[3];	//�{�^���̏��
	bool visible;			//�}�E�X�|�C���^�̕\���̗L��

	void update();			//�X�V����
};