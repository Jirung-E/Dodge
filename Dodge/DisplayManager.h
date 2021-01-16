#pragma once

#include <Windows.h>

#include "GameObject.h"
#include "Position.h"
#include "Player.h"


namespace DisplayManager {
	void gotoxy(SHORT x, SHORT y);
	void gotoxy(Position pos);

	void GameScreen(Player p);
	void Spawn(GameObject* go);
}