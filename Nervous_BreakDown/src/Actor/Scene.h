#pragma once
#include "DxLib.h"
#include "../Object/Object.h"


class Scene :public Object {
public:
	enum class Task {
		Title,
		Game,
	};

	Scene(Object::Status s, Task t);

	void update();
	void updatePause();

private:
	Task task;
	bool active;		//óvÇÈÇ©ÅH
};