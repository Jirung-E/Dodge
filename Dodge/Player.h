#pragma once

#include "GameObject.h"

class Player : public GameObject {
	int hp;
	int max_hp;

	const char player_shape = '&';

public:
	Player();
	Player(int hp);

	char character() const;	// temp
	Position Pos() const;

	int HP() const;
	int MaxHP() const;
};