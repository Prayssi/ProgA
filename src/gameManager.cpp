
#include <vector>

#include "sprite.h"
#include "vector2.h"
#include "platform.h"
#include "bille.h"

#include "gameManager.h"

#define max(a,b)(a>=b?a:b)

GameManager::GameManager(SDL_Renderer* renderer) : renderer(renderer)
{

}

GameManager::~GameManager()
{
	delete plateforme;
	plateforme = nullptr;
	billes.clear();
}

void GameManager::Start()
{
	plateforme = new Platform(250,300,renderer);
	billes.push_back(Bille(250, 250,renderer,plateforme));
	this->jeuEnCours = true;	
}


void GameManager::Update()
{
	if(this->jeuEnCours == true) 
	 {for (auto& bille : billes) {
	         bille.Update();
	         SDL_Rect dstBille = bille.sprite.getRectPos(bille.pos.getx(),bille.pos.gety());
	         bille.sprite.displayText(renderer,dstBille);
	     }
	 
	     plateforme->Update();
	     SDL_Rect dstPlateforme = plateforme->sprite.getRectPos(plateforme->pos.getx(),plateforme->pos.gety());
	 	plateforme->sprite.displayText(renderer,dstPlateforme);}
}

void GameManager::endOfGame()
{
	
}

void GameManager::variationVie(int var)
{
	if(this->jeuEnCours == true){this->vie = max(0,this->vie + var);
		if(vie <= 0) endOfGame();}
}

void GameManager::variationScore(int var)
{
	if(this->jeuEnCours == true)this->score = this->score + var;
}