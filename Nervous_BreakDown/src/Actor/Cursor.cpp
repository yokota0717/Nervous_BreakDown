#include "Cursor.h"

Cursor::Cursor(const std::string& name, Object::Status status):
	Object(name, status)
{}

void Cursor::init() {
	image = game->grafac->GetGraph("./resource/image/card.png");
	board = std::dynamic_pointer_cast<Board>(getParentPtr().lock());
	nowpos = 0;
	pos = board->table[nowpos];
	src = Math::Box2D(300.0f*6.0f, 400.0f, 300.0f, 400.0f);
}
void Cursor::update() {
	if (board->clearGame) { return; }

	int prepos = nowpos;
	//移動
	if (game->kb.Down(LEFT)) {
		nowpos -= 1;
	}
	if (game->kb.Down(RIGHT)) {
		nowpos += 1;
	}
	if (game->kb.Down(UP)) {
		nowpos -= 6;
	}
	if (game->kb.Down(DOWN)) {
		nowpos += 6;
	}
	//はみ出し防止
	if (nowpos < 0 || nowpos >= 18) {
		nowpos = prepos;
	}
	//座標更新
	pos = board->table[nowpos];

	//カードをめくる処理	
	if (game->kb.Down(ENTER)) {
		postMsg(std::weak_ptr<Object>(board), nowpos);	//ボードに座標を知らせる
	}
}
void Cursor::updatePause() {}
void Cursor::updateSleep() {}
void Cursor::render() {
	draw = Math::Box2D(pos.x, pos.y, 150.0f, 200.0f);
	DrawImage(draw, src, image);
}
void Cursor::renderPause() {}

int Cursor::postMsg(std::weak_ptr<Object> reciever, int num) {
	return reciever.lock()->receiveMsg(selfPtr(), num);
}
