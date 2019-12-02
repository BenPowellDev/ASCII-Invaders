#ifndef _LifeDisplay_H_
#define _LifeDisplay_H_

#include "../../Core/Renderer/AnimatedSprite.h"

class ASCIIRenderer;

extern const int SCREEN_WIDTH;


class LifeDisplay : public AnimatedSprite
{
public:

	LifeDisplay();
	~LifeDisplay();

	void Initialise(Vector2& position);
	void Update(float deltaTime);
	void Render(ASCIIRenderer* pRenderer);

	void SetLifeValue(int value);

private:

	bool m_bInitialised;

};

#endif
