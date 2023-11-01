#ifndef MANAGER_H
#define MANAGER_H

#include <vector>

#include "sprite.h"
#include "vector2.h"
#include "platform.h"
#include "bille.h"



class GameManager
{
public:
	GameManager(SDL_Renderer* renderer);
	~GameManager();
	void Update();
	// Début de la partie
	// Ajouter une bille
	// Supprimer une bille
	// Augmenter le score
	// Gestion vie


	SDL_Renderer* renderer;
private:

	Platform* plateforme = nullptr;
	std::vector<Bille> billes;
	int vie;


};


#endif