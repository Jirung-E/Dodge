#pragma once

#include "GameObject.h"

class Obstacle : public GameObject {
	const char obstacle_shape = '*';

public:
	Obstacle();

	void randomSpawn();
};