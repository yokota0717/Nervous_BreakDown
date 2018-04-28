#pragma once
#include "Game.h"

class Board;

class Cursor :public Object {
public:
	Cursor(const std::string& name, Object::Status status = Object::Status::pause);

	void init() override;
	void update() override;
	void updatePause() override;
	void updateSleep() override;
	void render() override;
	void renderPause() override;

	int nowpos;
	std::shared_ptr<Board> board;

	int postMsg(std::weak_ptr<Object> reciever, const int num) override;
};