#pragma once
#include "Game.h"
#include "../Easing/Easing.h"

class Board;
class ClearChecker;

class Card :public Object {
public:
	Card(std::string name, int n, Object::Status status = Object::Status::pause);

	void init() override;
	void setDesign(int des);
	void update() override;
	void updatePause() override;
	void render() override;
	void renderPause() override;
	
	int receiveMsg(std::weak_ptr<Object> receiver, const std::string& msg) override;
	int postMsg(std::weak_ptr<Object> receiver, std::weak_ptr<Object> sender);

	std::shared_ptr<Board> board;
	int num;		//カード毎に固有の通し番号
	int design;		//表の絵柄(1～6)

	enum State {
		Non,
		Front,
		Back,
		TurnStart,
		TurnEnd,
		BackStart,
		BackEnd,
	};
	State state;
	
	Easing ease;
};