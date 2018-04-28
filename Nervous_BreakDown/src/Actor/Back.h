#pragma once
#include "DxLib.h"
#include "Game.h"
#include "../Figure/Math.h"
#include "../define.h"

class Back :public Object {
public:
	Back(std::string name, Object::Status status = Object::Status::run);

	void init();
	void update();
	void updatePause();
	void updateSleep();
	void updateDestroy();
	void render();
	void renderPause();
	void renderSleep();
	void renderDestroy();
};