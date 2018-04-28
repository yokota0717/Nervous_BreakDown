#include "Logo.h"

Logo::Logo(std::string name, Object::Status status) :
	Object(name, status)
{}

void Logo::init() {
	image = game->grafac->GetGraph("./resource/image/title.png");
	pos = Math::Vec(float(SCREEN_WIDTH / 2 - 720 / 2), -180.0f);
	ease.init();
}

void Logo::update() {
	pos.y = ease.bounce.Out(ease.Time(10), -180.0f, SCREEN_HEIGHT / 2.0f - 110.0f + 180.0f, 10);
	if (game->kb.Down(SPACE)) {
		pause();
		postMsg(game->root->getObjectFromChildren("Board"), "GameStart");
	}
}
void Logo::updatePause() {}
void Logo::render() {
	draw = Math::Box2D(pos.x, pos.y, 720, 180);
	src = Math::Box2D(0, 0, 240, 120);
	DrawImage(draw, src, image);
}
void Logo::renderPause() {}

int Logo::receiveMsg(std::weak_ptr<Object> receiver, const std::string& msg) {
	//他にメッセージ送ってくるオブジェクトがないので分岐はなし
	run();
	init();
	return 0;
}
