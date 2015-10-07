#pragma once
#include "SFML/Graphics.hpp" 
#include "Command.h"
#include "Vector2D.h"
#define WIN32_LEAN_AND_MEAN // We don't want the extra stuff like MFC and such
#include <XInput.h>     // XInput API
//
// Constants for gamepad buttons
//

class InputHandler
{
	
public:
	enum DPadState {LEFT,RIGHT,UP,DOWN,CENTER};
	InputHandler();
	~InputHandler(void);
	void HandleInput();
	void isButtonPressedOnce(int);
	enum BUTTON {A,B,X,Y,LeftBumper,RightBumper,Select,Start,NONE};
	BUTTON getPressedButton();
	BUTTON getReleasedButton();
	bool debug;
	Vector2D getLeftThumbStick();
	Vector2D getRightThumbStick();
	Vector2D getDPadDirection();
	DPadState dpadState,lastDpadState;
private:
	Vector2D LeftThumbStickDirection,RightThumStickDirection,DPadDirection;
	BUTTON pressedButton;
	BUTTON releasedButton;
	static const int buttonA = 0;
	static const int buttonB = 1;
	static const int buttonX = 2;
	static const int buttonY = 3;
	static const int buttonLeftBumper = 4;
	static const int buttonRightBumper = 5;
	static const int buttonSelect = 6;
	static const int buttonStart = 7;
	static const int PlayerOne = 0;
	sf::RenderWindow window;
	bool wasButtonAPressed;
	bool wasButtonBPressed;
	bool wasButtonXPressed;
	bool wasButtonYPressed;
	bool wasButtonLeftBumpPressed;
	bool wasButtonRightBumpPressed;
	bool wasButtonStartPressed;
	bool wasButtonSelectPressed;
};

