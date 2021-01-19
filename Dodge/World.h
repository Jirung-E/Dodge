#pragma once

#include "GameObject.h"


namespace World {
	const int Width = 64;
	const int Height = 16;

	const int Min_x = 0;
	const int Min_y = 0;
	const int Max_x = Min_x + Width - 1;
	const int Max_y = Min_y + Height - 1;

	extern GameObject* world[World::Width][World::Height];
}