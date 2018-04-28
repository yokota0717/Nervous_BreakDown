#include "Scene.h"

Scene::Scene(Object::Status s, Scene::Task t):
	Object("Scene", s),
	task(t)
{}

void Scene::update() {
	//キーが押されたらシーン切り替え
}
void Scene::updatePause() {
	//停止中
}