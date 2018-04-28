#pragma once
#include "DxLib.h"
#include "Figure\Math.h"

namespace {
	const int SCREEN_WIDTH = 1280,
		SCREEN_HEIGHT = 720;

	//DX���C�u�����̕`��֐������b�s���O
	inline void DrawImage(Math::Box2D draw, Math::Box2D src, int handle) {
		DrawRectExtendGraphF(draw.x, draw.y, draw.x + draw.w, draw.y + draw.h, (int)src.x, (int)src.y, (int)src.w, (int)src.h, handle, true);
	}
}