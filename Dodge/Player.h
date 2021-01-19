#pragma once

#include "GameObject.h"

class Player : public GameObject {
	int hp;
	int max_hp;
	int coin;

	const char player_shape = '&';

	void getDmg(int dmg);

public:
	Player();
	Player(int hp);


	void Move() = delete;
	void Move(char dir);

	Position Pos() const;

	int HP() const;
	int MaxHP() const;
	int Coins() const;

	void Interaction(GameObject* go);
};