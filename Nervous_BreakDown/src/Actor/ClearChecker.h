#pragma once
#include "Game.h"

class Card;

class ClearChecker:public Object {
public:
	ClearChecker(const std::string& name, Object::Status status = Object::Status::pause);

	bool checkClear();

	std::vector<std::weak_ptr<Card>> check;
	int receiveMsg(std::weak_ptr<Object> sender, std::weak_ptr<Object> front);
};