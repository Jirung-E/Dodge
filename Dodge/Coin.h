#pragma once

#include "Obstacle.h"


class Coin : public Obstacle {
	const char coin_shape = 'c';

public:
	Coin();
};