#pragma once
#include "SFML/Graphics.hpp" 
#include "Command.h"
#include "Vector2D.h"
#define WIN32_LEAN_AND_MEAN // We don't want the extra stuff like MFC and such
#include <XInput.h>     // XInput API
#pragma comment(lib, "XInput.lib")   
class InputHandler
{
	struct GamePadState 
	{
		Vector2D 	left_thumbstick;               // <= I'm using a Vector2 (floats) class but you can replaced it with a float X and Y or whatever your Vector2 class is
		Vector2D	right_thumbstick;
		// Just to clear all values to default
		void reset()
		{
			left_thumbstick = Vector2D(0.0f,0.0f);
			right_thumbstick = Vector2D(0.0f,0.0f);
		}
	};
public:
	InputHandler();
	~InputHandler(void);
	GamePadState State;
	void HandleInput();
	void isButtonPressedOnce(int);
	enum BUTTON {A,B,X,Y,LeftBumper,RightBumper,Select,Start,NONE};
	BUTTON getPressedButton();
	BUTTON getReleasedButton();
	bool debug;
	Vector2D LeftThumbStickDirection,RightThumStickDirection;
	XINPUT_STATE controllerState;
private:
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

