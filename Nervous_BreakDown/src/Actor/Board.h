#pragma once
#include "Game.h"
#include "Card.h"
#include "Cursor.h"
#include "UI.h"
#include <random>
#include <time.h>

class Card;

class Board :public Object {
public:
	Board(std::string name, Object::Status status = Object::Status::pause);

	void init() override;
	void update() override;
	void updatePause() override;
	void render() override;
	void renderPause() override;

	int receiveMsg(std::weak_ptr<Object> receiver, const std::string& msg) override;	//タイトルに戻る処理
	int receiveMsg(std::weak_ptr<Object> sender, const int num) override;	//正解チェック

	Math::Vec table[18];	//ボードの座標

	std::vector<std::weak_ptr<Card>> cards;		//カードのポインタ
	std::vector<std::weak_ptr<Card>> check;		//正解チェックの対象になるカード
	
	bool checkSameDesign();		//めくられた二枚のカードの絵柄が同じか
	bool checkGameClear();		//すべてのカードを揃えたか

	bool clearGame;
};