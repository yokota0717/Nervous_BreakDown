#include "Scene.h"

Scene::Scene(Object::Status s, Scene::Task t):
	Object("Scene", s),
	task(t)
{}

void Scene::update() {
	//�L�[�������ꂽ��V�[���؂�ւ�
}
void Scene::updatePause() {
	//��~��
}