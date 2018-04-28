#include "Card.h"

Card::Card(std::string name, int n, Object::Status status):
	Object(name, status),
	num(n)
{}

void Card::init() {
	board = std::dynamic_pointer_cast<Board>(getParentPtr().lock());
	image = game->grafac->GetGraph("./resource/image/card.png");
	pos = board->table[num];
	draw = Math::Box2D(pos.x, pos.y, 150, 200);
	src = Math::Box2D(300.0f * 6, 0.0f, 300.0f, 400.0f);
	state = Back;
	ease.init();
}
void Card::setDesign(int des) {
	design = des;
}
void Card::update() {
	switch (state) {
	case Back:
		break;
	case Front:
		break;
	case TurnStart:
		//ひっくり返し始めアニメーション
		draw.x = ease.quint.Out(ease.Time(5), pos.x, 75.0f, 5);
		draw.w = ease.quint.Out(ease.Time(5), 150.0f, -150.0f, 5);
		if (draw.w == 0) {
			src = Math::Box2D(300.0f * (design - 1), 0.0f, 300.0f, 400.0f);
			state = TurnEnd;
			ease.init();
		}
		break;
	case TurnEnd:
		draw.x = ease.circ.Out(ease.Time(3), pos.x + 75.0f, -75.0f, 3);
		draw.w = ease.circ.Out(ease.Time(3), 0.0f, 150.0f, 3);
		if (draw.w == 150.0f) {
			state = Front;
			ease.init();
			postMsg(board, selfPtr());
		}
		break;
	case BackStart:
		draw.x = ease.circ.Out(ease.Time(2), pos.x, 75.0f, 2);
		draw.w = ease.circ.Out(ease.Time(2), 150.0f, -150.0f, 2);
		if (draw.w == 0) {
			src = Math::Box2D(300.0f * 6, 0.0f, 300.0f, 400.0f);
			state = BackEnd;
			ease.init();
		}
		break;
	case BackEnd:
		draw.x = ease.circ.Out(ease.Time(2), pos.x + 75.0f, -75.0f, 2);
		draw.w = ease.circ.Out(ease.Time(2), 0.0f, 150.0f, 2);
		if (draw.w == 150.0f) {
			state = Back;
			ease.init();
		}
		break;
	default:
		break;
	}

}
void Card::updatePause() {}
void Card::render() {
	DrawImage(draw, src, image);
}
void Card::renderPause(){}

int Card::receiveMsg(std::weak_ptr<Object> receiver, const std::string& msg) {
	if (msg == "TurnStart") {
		if (state != Back) { return 0; }
		state = TurnStart;
	}
	else if (msg == "Back") {
		state = BackStart;
	}
	return 0;
}
int Card::postMsg(std::weak_ptr<Object> receiver, std::weak_ptr<Object> sender) {
	return receiver.lock()->receiveMsg(selfPtr(), num);
}
