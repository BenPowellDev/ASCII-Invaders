#include "LifeDisplay.h"
#include "../../Core/Renderer/ConsoleColours.h"
#include "EnemyArmy.h"
#include "PlayerShip.h"
#include "../Game/Game.h"

CHAR_INFO LifeDigitSprite[10][8 * 10] =
{
	{
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },
	},
	{
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },
	},
	{
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
	},
	{
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },
	},
	{
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },
	},
	{
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },
	},
	{
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },
	},
	{
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
	},
	{
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },
	},
	{
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },
		{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE } ,{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_WHITE },{ ' ' ,BACKGROUND_BLACK },
	},
};

LifeDisplay::LifeDisplay()
	:m_bInitialised(false)
{
}

LifeDisplay::~LifeDisplay()
{
}

void LifeDisplay::Initialise(Vector2& position)
{
	AnimatedSprite::Initialise(&LifeDigitSprite[0][0], Vector3(8, 10, 10));

	Vector2 startPosition(position.x - (AnimatedSprite::GetSize().x / 2), position.y - (AnimatedSprite::GetSize().y / 2));
	SetPosition(startPosition);

	SetAnimationFrame(3);

	m_bInitialised = true;
}

void LifeDisplay::Update(float deltaTime)
{
	if (!m_bInitialised)
		return;
}

void LifeDisplay::SetLifeValue(int m_PlayerLives)
{	

	if (m_PlayerLives >= 0 && m_PlayerLives < 3)
	{
		SetAnimationFrame(m_PlayerLives);
	}
	else
	{
		SetAnimationFrame(3);
	}
}

void LifeDisplay::Render(ASCIIRenderer* pRenderer)
{
	if (!m_bInitialised)
		return;

	AnimatedSprite::Render(pRenderer);
}
