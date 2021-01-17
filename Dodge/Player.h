#pragma once

#include "GameObject.h"

class Player : public GameObject {
	int hp;
	int max_hp;

	const char player_shape = '&';

public:
	Player();
	Player(int hp);


	void Move() = delete;
	void Move(char dir);

	Position Pos() const;

	int HP() const;
	int MaxHP() const;
};