#pragma once

#include <Windows.h>

#include "GameObject.h"
#include "Position.h"
#include "Player.h"


namespace DisplayManager {
	void gotoxy(SHORT x, SHORT y);
	void gotoxy(Position pos);

	namespace GameScreen {
		void Start(Player p);
		void Update(Player p);
	}

	void Spawn(GameObject* go);		// temp
}