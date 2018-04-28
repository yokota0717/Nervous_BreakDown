#pragma once
#include "./Game.h"
#include "../define.h"
#include "../Easing/Easing.h"
#include <iostream>

class Logo :public Object {
public:
	Logo(std::string name, Object::Status status = Object::Status::run);

	void init() override;
	void update() override;
	void updatePause() override;
	void render() override;
	void renderPause() override;

	int receiveMsg(std::weak_ptr<Object> receiver, const std::string& msg) override;


	Easing ease;
};