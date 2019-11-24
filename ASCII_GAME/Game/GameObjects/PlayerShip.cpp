#include "PlayerShip.h"
#include "../../Core/Maths/Vector2.h"
#include "../../Core/Renderer/ConsoleColours.h"
#include <Windows.h>

const int MOVEMENT_SPEED = 2;

CHAR_INFO ShipSprite[]=
{
	{ 95, FOREGROUND_WHITE }, { 95 ,FOREGROUND_WHITE }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK },
	{ 124 ,FOREGROUND_WHITE }, { 0 ,BACKGROUND_BLACK }, { 92 ,FOREGROUND_WHITE }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK },
	{ 61 ,FOREGROUND_WHITE }, { 91 ,FOREGROUND_WHITE }, { 95 ,FOREGROUND_WHITE }, { 124 ,FOREGROUND_WHITE }, { 72 ,FOREGROUND_WHITE }, { 41 ,FOREGROUND_WHITE }, { 45 ,FOREGROUND_WHITE }, { 45 ,FOREGROUND_WHITE }, { 46 ,FOREGROUND_WHITE }, { 95 ,FOREGROUND_WHITE }, { 95 ,FOREGROUND_WHITE }, { 95 ,FOREGROUND_WHITE },
	{ 61 ,FOREGROUND_WHITE }, { 91 ,FOREGROUND_WHITE }, { 43 ,FOREGROUND_WHITE }, { 45 ,FOREGROUND_WHITE }, { 45 ,FOREGROUND_WHITE }, { 44 ,FOREGROUND_WHITE }, { 45 ,FOREGROUND_WHITE }, { 45 ,FOREGROUND_WHITE }, { 45 ,FOREGROUND_WHITE }, { 45 ,FOREGROUND_WHITE }, { 45 ,FOREGROUND_WHITE }, { 45 ,FOREGROUND_WHITE },
	{ 0 ,BACKGROUND_BLACK }, { 61 ,FOREGROUND_WHITE }, { 124 ,FOREGROUND_WHITE }, { 95 ,FOREGROUND_WHITE }, { 47 ,FOREGROUND_WHITE }, { 34 ,FOREGROUND_WHITE }, { 34 ,FOREGROUND_WHITE }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK },
	{ 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK },
	{ 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK },
	{ 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK }, { 0 ,BACKGROUND_BLACK },
};

PlayerShip::PlayerShip()
:m_LeftKey(0)
,m_RightKey(0)
,m_UpKey(0)
,m_DownKey(0)

, m_bInitialised(false)
{
}

PlayerShip::~PlayerShip()
{
}

void PlayerShip::Initialise(Vector2& position, int leftKey, int rightKey, int upKey, int downKey)
{
	m_LeftKey = leftKey;
	m_RightKey = rightKey;
	m_UpKey = upKey;
	m_DownKey = downKey;

	Sprite::Initialise(ShipSprite, Vector2(12, 8));

	Vector2 startPosition(0,45);
	SetPosition(startPosition);

	m_bInitialised = true;
}

void PlayerShip::Update()
{
	if (!m_bInitialised)
		return;

	if (LeftKeyPressed())
	{
		MoveLeft();
	}

	if (RightKeyPressed())
	{
		MoveRight();
	}

	if (UpKeyPressed())
	{
		MoveUp();
	}

	if (DownKeyPressed())
	{
		MoveDown();
	}
}

void PlayerShip::Render(ASCIIRenderer* pRenderer)
{
	if (!m_bInitialised)
		return;

	Sprite::Render(pRenderer);
}


void PlayerShip::MoveLeft()
{
	SetPosition(Vector2(GetPosition().x - MOVEMENT_SPEED, GetPosition().y));

	if (GetPosition().x < 0)
	{
		MoveRight();
	}
}

void PlayerShip::MoveRight()
{
	SetPosition(Vector2(GetPosition().x + MOVEMENT_SPEED, GetPosition().y));

	if (GetPosition().x + GetSize().x > SCREEN_WIDTH)
	{
		MoveLeft();
	}
}

void PlayerShip::MoveUp()
{
	SetPosition(Vector2(GetPosition().x, GetPosition().y - MOVEMENT_SPEED));

	if (GetPosition().y + GetSize().y <= 0)
	{
		MoveDown();
	}
}

void PlayerShip::MoveDown()
{
	SetPosition(Vector2(GetPosition().x, GetPosition().y + MOVEMENT_SPEED));

	if (GetPosition().y + GetSize().y >= SCREEN_HEIGHT)
	{
		MoveUp();
	}
}

bool PlayerShip::LeftKeyPressed()
{
	return (GetKeyState(m_LeftKey) < 0);
}

bool PlayerShip::RightKeyPressed()
{
	return (GetKeyState(m_RightKey) < 0);
}

bool PlayerShip::UpKeyPressed()
{
	return (GetKeyState(m_UpKey) < 0);
}

bool PlayerShip::DownKeyPressed()
{
	return (GetKeyState(m_DownKey) < 0);
}