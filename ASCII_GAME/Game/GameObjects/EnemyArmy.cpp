#include "EnemyArmy.h"
#include "../Game.h"
#include <random>

float deltaTime = 1.0f / 30.0f;

const int ENEMY_SPACING_X = 10;
const int ENEMY_SPACING_Y = 12;

int RandomArmy(int low, int high)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> Distribution(low,high);

	return Distribution(rng);
}


EnemyArmy::EnemyArmy()
:m_UpdateTimer(0.0f)
,m_pGame(NULL)
,m_ScoreEarned(0)
{

}

EnemyArmy::~EnemyArmy()
{

}

void EnemyArmy::Initialise(Game* pGame)
{
	m_pGame = pGame;
	deltaTime = 1.5f / 10.0f;

	m_MovingRight = true;

	for (int i = 0; i < NUM_ROWS_OF_INVADERS; i++)
	{
		for (int j = 0; j < NUM_INVADERS_PER_ROW; j++)
		{
			m_EnemyShip[i][j].Initialise(Vector2(SCREEN_WIDTH + RandomArmy(1, 150), RandomArmy(5, (SCREEN_HEIGHT - m_EnemyShip[i][j].GetSize().y - 5))), 5, i, 200);
		}
	}
}

void EnemyArmy::Update()
{
	m_UpdateTimer += deltaTime;

	if (m_UpdateTimer >= 1.0f)
	{
		m_UpdateTimer -= 1.0f;

		if (ShouldChangeDirection())
		{
			//change direction
			m_MovingRight = !m_MovingRight;

			//increase speed!
			deltaTime += 0.01f;

			for (int i = 0; i < NUM_ROWS_OF_INVADERS; i++)
			{
				for (int j = 0; j < NUM_INVADERS_PER_ROW; j++)
				{
					m_EnemyShip[i][j].MoveLeft();
				}
			}
		}
		else
		{
			for (int i = 0; i < NUM_ROWS_OF_INVADERS; i++)
			{
				for (int j = 0; j < NUM_INVADERS_PER_ROW; j++)
				{
					m_EnemyShip[i][j].MoveLeft();
				}
			}
		}

	}

	//update enemy animations
	for (int i = 0; i < NUM_ROWS_OF_INVADERS; i++)
	{
		for (int j = 0; j < NUM_INVADERS_PER_ROW; j++)
		{
			if (m_EnemyShip[i][j].Update(deltaTime))
			{
				Missile* pMissile = new Missile;
				pMissile->Initialise(Vector2(m_EnemyShip[i][j].GetPosition().x - 2, m_EnemyShip[i][j].GetPosition().y + (m_EnemyShip[i][j].GetSize().y * 0.5f)), Vector2(-MISSILE_SPEED, 0));
				m_pGame->AddEnemyMissile(pMissile);
			}
		}
	}
}

bool EnemyArmy::ShouldChangeDirection()
{
	bool changeDirection = false;

	if (m_MovingRight)
	{
		for (int i = 0; i < NUM_ROWS_OF_INVADERS; i++)
		{
			for (int j = NUM_INVADERS_PER_ROW -1; j >= 0; j--)
			{
				//check the right most ship in this row
				if (m_EnemyShip[i][j].Active())
				{
					if ((m_EnemyShip[i][j].GetPosition().x + (m_EnemyShip[i][j].GetSize().x)) >= SCREEN_WIDTH)
					{
						changeDirection = true;
						break;
					}
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < NUM_ROWS_OF_INVADERS; i++)
		{
			for (int j = 0; j < NUM_INVADERS_PER_ROW; j++)
			{
				//check the left most ship in this row
				if (m_EnemyShip[i][j].Active())
				{
					if ((m_EnemyShip[i][j].GetPosition().x) <= 0)
					{
						changeDirection = true;
						break;
					}
				}
			}
		}
	}

	return changeDirection;
}

bool EnemyArmy::HasLanded()
{
	for (int i = 0; i < NUM_ROWS_OF_INVADERS; i++)
	{
		for (int j = NUM_INVADERS_PER_ROW - 1; j >= 0; j--)
		{
			//check the right most ship in this row
			if (m_EnemyShip[i][j].Active())
			{
				if ((m_EnemyShip[i][j].GetPosition().y + (m_EnemyShip[i][j].GetSize().y)) >= SCREEN_WIDTH)
				{
					return true;
				}
			}
		}
	}

	return false;
}

void EnemyArmy::Render(ASCIIRenderer* pRenderer)
{
	for (int i = 0; i < NUM_ROWS_OF_INVADERS; i++)
	{
		for (int j = 0; j < NUM_INVADERS_PER_ROW; j++)
		{
			m_EnemyShip[i][j].Render(pRenderer);
		}
	}
}


bool EnemyArmy::Collides(Sprite& otherSprite)
{
	bool collision = false;
	for (int i = 0; i < NUM_ROWS_OF_INVADERS; i++)
	{
		for (int j = 0; j < NUM_INVADERS_PER_ROW; j++)
		{
			if (m_EnemyShip[i][j].Active() && otherSprite.Collides(m_EnemyShip[i][j].GetCurrentSprite()))
			{
				collision = true;
				m_ScoreEarned += m_EnemyShip[i][j].GetScoreValue();
				m_EnemyShip[i][j].Explode();
			}
		}
	}

	return collision;
}

int EnemyArmy::GetNumActiveEnemies()
{
	int activeEnemies = 0;
	for (int i = 0; i < NUM_ROWS_OF_INVADERS; i++)
	{
		for (int j = 0; j < NUM_INVADERS_PER_ROW; j++)
		{
			if (m_EnemyShip[i][j].Active())
			{
				activeEnemies++;
			}
		}
	}

	return activeEnemies;
}
