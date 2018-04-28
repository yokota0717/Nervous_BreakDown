#include "DxLib.h"
#include ".\define.h"
#include "Input\Input.h"
#include "Object\Object.h"
#include "Actor\Game.h"
#include "Console\Console.h"

//-------------------------------------------------------------------------------------------------------------------
//メインループの処理をまとめる
int ProcessLoop() {
	if (ScreenFlip() != 0) return -1;
	if (ProcessMessage() != 0) return -1;
	if (ClearDrawScreen() != 0) return -1;
	return 0;
}
//-------------------------------------------------------------------------------------------------------------------
//初期化関連をまとめる
void DXinit() {
	SetOutApplicationLogValidFlag(FALSE);			//ログ消し
	SetMainWindowText("Nervous_BreakDown");						//ウインドウタイトルを変更
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);						//画面解像度、色深度バッファ？変更
	SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);		//画面サイズ変更
	ChangeWindowMode(TRUE);							//ウィンドウモード変更
	SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);		//初期化
	DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);	//裏画面設定
	SetUseTransColor(FALSE);
}
//-------------------------------------------------------------------------------------------------------------------


int Object::uid_ = 0;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ShowConsole();
	DXinit();
	
	while (ProcessLoop() == 0) {
		game->doAll();
		if (game->kb.Down(ESCAPE)) { break; }
	};

	DxLib_End(); // DXライブラリ終了処理
	return 0;
}