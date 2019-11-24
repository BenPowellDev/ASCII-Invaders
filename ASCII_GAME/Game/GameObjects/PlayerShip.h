#ifndef _PlayerShip_H_
#define _PlayerShip_H_

#include "../../Core/Renderer/Sprite.h"

class ASCIIRenderer;

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

class PlayerShip : public Sprite
{
public:

	PlayerShip();
	~PlayerShip();

	void Initialise(Vector2& position, int leftKey, int rightKey, int upKey, int downKey);
	void Update();
	void Render(ASCIIRenderer* pRenderer);
	
private:

	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	void Lives();

	int m_LeftKey;
	int m_RightKey;
	int m_UpKey;
	int m_DownKey;

	bool LeftKeyPressed();
	bool RightKeyPressed();
	bool UpKeyPressed();
	bool DownKeyPressed();

	bool m_bInitialised;

};

#endif
