#include "Board.h"

Board::Board(std::string name, Object::Status status) :
	Object(name, status)
{}

void Board::init() {
	cout << clearGame << endl;
	for (int i = 0; i < 6 * 3; ++i) {
		table[i] = Math::Vec(float(10 + 160 * (i % 6)), float(10 + 200 * (i / 6)));
		insertAsChild(new Card("Card" + to_string(i), i));
	}
	for (int i = 0; i < 18; ++i) {
		cards.push_back(std::dynamic_pointer_cast<Card>(getObjectFromChildren(i + 5).lock()));
	}
	insertAsChild(new Cursor("Cursor"));
}
void Board::update() {
	if (game->kb.Down(SPACE)) {
		if (preStatus == Object::Status::pause) { return; }
		killFromChildren(std::vector<std::string>({ "UI" }));
		pauseAll();
		postMsg(game->root->getObjectFromChildren("Logo"), "BackToTitle");
	}
	preStatus = status();
}
void Board::updatePause() {
	preStatus = status();
}
void Board::render() {}
void Board::renderPause() {}

int Board::receiveMsg(std::weak_ptr<Object> receiver, const std::string& msg) {
	if (receiver.lock()->name() == "UIClear" && msg == "Clear") {
		postMsg(game->root->getObjectFromChildren("Logo"), "BackToTitle");
		pauseAll();
	}
	else if(receiver.lock()->name() == "Logo"){
		runAll();
		clearGame = false;
		for (auto c : getChildren()) {
			c.lock()->init();
		}
		std::mt19937_64 get_rand_mt(unsigned int(time(0)));
		std::vector<int> design = { 1,1,1,1,2,2,2,2,3,3,3,3,4,4,5,5,6,6 };
		if (!game->DebugMode()) {		//タイトル画面でQを推すとシャッフルされなくなるよ
			std::shuffle(design.begin(), design.end(), get_rand_mt);
		}
		int i = 0;
		for (auto card : cards) {
			card.lock()->setDesign(design[i]);
			++i;
		}
	}
	return 0;
}
int Board::receiveMsg(std::weak_ptr<Object> sender, const int num) {
	if (sender.lock()->ID() >= 5 && sender.lock()->ID() < (5 + 18)) {
		auto turncard = getObjectFromChildren(std::string("Card" + to_string(num)));	//めくられたカード
		check.push_back(std::dynamic_pointer_cast<Card>(turncard.lock()));
		if (check.size() == 2) {
			if (checkSameDesign()) {
				if (clearGame = checkGameClear()) {
					insertAsChild(new UI("UIClear", UI::State::Clear));
				}
				else {
					insertAsChild(new UI("UI", UI::State::Correct));
				}
			}
			else {
				insertAsChild(new UI("UI", UI::State::Miss));
				for (auto c : check) {
					postMsg(c, "Back");

				}
			}
			check.clear();
		}
	}
	else if (sender.lock()->name() == "Cursor") {
		postMsg(getObjectFromChildren(std::string("Card" + to_string(num))), "TurnStart");
	}
	return 0;
}
bool Board::checkSameDesign() {
	return check[0].lock()->design == check[1].lock()->design;
}
bool Board::checkGameClear() {
	for (auto card : cards) {
		//表になっていないカードがあったら終了
		if (card.lock()->state != Card::State::Front) {
			return false;
		}
	}
	return true;
}
