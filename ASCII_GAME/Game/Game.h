#ifndef _GAME_H_
#define _GAME_H

#include "GameStates.h"
#include "GameObjects\PlayerShip.h"
#include "GameObjects\EnemyArmy.h"
#include "GameObjects\Missile.h"
#include "../Core/Renderer/Sprite.h"
#include "GameObjects\ScoreDisplay.h"
#include "GameObjects\LifeDisplay.h"
#include <vector>

class ASCIIRenderer;

class Game
{
public:
	Game();
	~Game();

	void Initialise();

	void Run();

	void AddEnemyMissile(Missile* pMissile);

private:

	void InitialiseRenderer();
	void Update();
	void Render();
	void UpdateScoreDisplay();
	void UpdateLifeDisplay();


	void InitialiseMainMenu();
	void InitialiseGame();
	void InitialiseEndScreens();

	void UpdateMainMenu();
	void UpdateGame();

	void UpdatePlayerMissiles();
	void UpdateEnemyMissiles();

	void CheckWinConditions();

	void FireMissile();

	void UpdateEndGameScreens();

	void UpdateNextRound();

	void RenderMainMenu();
	void RenderGame();
	void RenderWinScreen();
	void RenderLoseScreen();
	void RenderNextRoundScreen();

	void RenderEnemyMissiles();
	void RenderScore();
	void RenderLives();

	ASCIIRenderer* m_pRenderer;

	E_GAME_STATE m_GameState;

	bool m_bInitialised;
	bool m_bExitApp;

	int m_Score;
	int m_PlayerLives = 3;
	

	PlayerShip m_PlayerShip;
	EnemyArmy m_EnemyArmy;

	
	Missile m_Missile; //player missile
	std::vector<Missile*> m_EnemyMissiles;

	ScoreDisplay m_ScoreDigit[4];
	LifeDisplay m_LifeDigit[1];


	Sprite m_GameTitle;
	int m_MainMenuCounter;

	Sprite m_NextRoundTitle;
	int m_NextRoundCounter;

	Sprite m_GameOverTitle;
	int m_EndScreenCounter;

	Sprite m_YouWinTitle;


};


#endif
