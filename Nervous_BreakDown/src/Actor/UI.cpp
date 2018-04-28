#include "UI.h"

UI::UI(std::string name, UI::State state) :
	Object(name),
	state(state)
{
	maxLife = (state == Clear) ? 80 : 40;
}

void UI::init() {
	image = game->grafac->GetGraph("./resource/image/system.png");
	pos = Math::Vec(SCREEN_WIDTH / 2.0f - 120.0f, SCREEN_HEIGHT / 2.0f + 100.0f);
	ease.init();
	life = maxLife;
}
void UI::update() {
	pos.y = ease.quint.Out(ease.Time(8), SCREEN_HEIGHT / 2.0f + 100.0f, -200.0f, 8);
	life--;
	if (life <= 0) {
		postMsg(getParentPtr(), "Clear");
		kill();
	}
}
void UI::updatePause() {
	kill();		//UI表示中にタイトル→ゲームに移行したときに残らないようにポーズに入ったら死ぬ
}
void UI::render() {
	if (life <= 0) { return; }
	switch (state) {
	case Correct:
		draw = Math::Box2D(pos.x, pos.y, 240, 120);
		src = Math::Box2D(0, 0, 240, 120);
		break;
	case Miss:
		draw = Math::Box2D(pos.x, pos.y, 240, 120);
		src = Math::Box2D(0, 120, 240, 120);
		break;
	case Clear:
		draw = Math::Box2D(pos.x - 120, pos.y - 60, 480, 240);
		src = Math::Box2D(0, 240, 240, 120);
		break;
	default:
		src = Math::Box2D(0, 240, 240, 120);
		break;
	}
 	 DrawImage(draw, src, image);
}
void UI::renderPause() {}

