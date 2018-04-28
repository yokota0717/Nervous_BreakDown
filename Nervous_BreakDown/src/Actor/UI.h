#pragma once
#include "Game.h"

class UI :public Object {
public:
	enum State {
		Non,
		Correct,
		Miss,
		Clear,
	};
	UI(std::string name, State state);

	void init() override;
	void update() override;
	void updatePause() override;
	void render() override;
	void renderPause() override;

	Easing ease;
	int life;
	int maxLife;
	State state;
};