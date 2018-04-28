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

	int receiveMsg(std::weak_ptr<Object> receiver, const std::string& msg) override;	//�^�C�g���ɖ߂鏈��
	int receiveMsg(std::weak_ptr<Object> sender, const int num) override;	//�����`�F�b�N

	Math::Vec table[18];	//�{�[�h�̍��W

	std::vector<std::weak_ptr<Card>> cards;		//�J�[�h�̃|�C���^
	std::vector<std::weak_ptr<Card>> check;		//�����`�F�b�N�̑ΏۂɂȂ�J�[�h
	
	bool checkSameDesign();		//�߂���ꂽ�񖇂̃J�[�h�̊G����������
	bool checkGameClear();		//���ׂẴJ�[�h�𑵂�����

	bool clearGame;
};