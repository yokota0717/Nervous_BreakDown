#include "Back.h"

Back::Back(std::string name, Object::Status status) :
	Object(name, status)
{}

void Back::init(){
	draw = Math::Box2D(0, 0, 1280, 720);
	src = Math::Box2D(0, 0, 620, 439);
	image = game->grafac->GetGraph("./resource/image/back.jpg");
}
void Back::update(){}
void Back::updatePause(){}
void Back::updateSleep(){}
void Back::updateDestroy(){}

void Back::render() {
	DrawImage(draw, src, image);
}
void Back::renderPause(){
	render();
}
void Back::renderSleep(){}
void Back::renderDestroy(){}