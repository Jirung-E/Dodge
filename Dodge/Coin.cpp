#include "Coin.h"

#include "Player.h"


Coin::Coin() : Obstacle() {
	shape = coin_shape;
}


void Coin::Interaction(GameObject* go) {
	//if(is_sleep) {
	//	return;
	//}

	//if(dynamic_cast<Player*>(go)) {
	//	dynamic_cast<Player*>(go)->Interaction(this);
	//	Sleep();
	//}

	Obstacle::Interaction(go);
}