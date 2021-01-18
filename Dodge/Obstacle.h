#pragma once

#include "GameObject.h"

#include <chrono>


class Obstacle : public GameObject {
	const char obstacle_shape = '*';
	int move_speed;	// n character / 1 second
	std::chrono::system_clock::time_point last_move;

public:
	Obstacle();

	void randomSpawn();
	void randomMoveSpeed();

	void Move();
};