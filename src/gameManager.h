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
	void Start();
	void endOfGame();
	// Création de la map brique
	// Ajouter une bille
	// Supprimer une bille
	void variationScore(int var);
	void variationVie(int var);


	SDL_Renderer* renderer;
private:

	Platform* plateforme = nullptr;
	std::vector<Bille> billes;
	int vie;
	int score;
	bool jeuEnCours = false;


};


#endif