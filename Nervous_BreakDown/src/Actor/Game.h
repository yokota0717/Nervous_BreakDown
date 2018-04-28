#pragma once
#include "../Input/Input.h"
#include "../GraphFactory/GraphFactory.h"
#include "../Object/Object.h"
#include "Back.h"
#include "Logo.h"
#include "Board.h"
//#include "ClearChecker.h"

//ルートクラス
class Root :public Object {
public:
	Root();
	~Root();
	void init(std::shared_ptr<Object> thisptr);
	void update() override;
	void render() override;
	int frame();

private:
	int frame_;
};

//ゲーム管理クラス
class Game {
public:
	Game();
	~Game();
	void fin();

	Keyboard kb;
	std::shared_ptr<Root> root;
	std::unique_ptr<GraphFactory> grafac;
	void doAll();
	bool DebugMode();

private:
	bool debug_;
};

extern std::unique_ptr<Game> game;