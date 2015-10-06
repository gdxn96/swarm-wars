#include "stdafx.h"
#include "InputHandler.h"
using namespace std;
//this class handles the inputs of the controller to be used outside this class cleanly

//if (inputHandler.getReleasedButton() == InputHandler::BUTTON::A)  <-- use the method to get the key pressed in your class outside this one
//{}
InputHandler::InputHandler()
{
	wasButtonAPressed = false;
	wasButtonBPressed = false;
	wasButtonXPressed = false;
	wasButtonYPressed = false;
	wasButtonLeftBumpPressed = false;
	wasButtonRightBumpPressed = false;
	wasButtonStartPressed = false;
	wasButtonSelectPressed = false;
	debug = true;
}
void InputHandler::HandleInput()
{
	isButtonPressedOnce(PlayerOne);
}
void InputHandler::isButtonPressedOnce(int player)
{
	bool isButtonAPressed = sf::Joystick::isButtonPressed(player,buttonA);
	bool isButtonBPressed = sf::Joystick::isButtonPressed(player,buttonB);
	bool isButtonXPressed = sf::Joystick::isButtonPressed(player,buttonX);
	bool isButtonYPressed = sf::Joystick::isButtonPressed(player,buttonY);
	bool isButtonLeftBumpPressed = sf::Joystick::isButtonPressed(player,buttonLeftBumper);
	bool isButtonRightBumpPressed = sf::Joystick::isButtonPressed(player,buttonRightBumper);
	bool isButtonSelectPressed = sf::Joystick::isButtonPressed(player,buttonSelect);
	bool isButtonStartPressed = sf::Joystick::isButtonPressed(player,buttonStart);
#pragma region Joystic buttom press and release check
	// doo all the button pressed checks
	if(isButtonAPressed && !wasButtonAPressed)
	{	
		if(debug)
		{
			printf("button A : \n");
		}
		pressedButton = BUTTON::A;
	}
	else if(isButtonBPressed && !wasButtonBPressed)
	{	
		if(debug)
		{
			printf("button B : \n");
		}
		pressedButton = BUTTON::B;
	}
	else if(isButtonXPressed && !wasButtonXPressed)
	{	
		if(debug)
		{
			printf("button X : \n");
		}
		pressedButton = BUTTON::X;
	}
	else if(isButtonYPressed && !wasButtonYPressed)
	{	
		if(debug)
		{
			printf("button Y : \n");
		}
		pressedButton = BUTTON::Y;
	}
	else if(isButtonLeftBumpPressed && !wasButtonLeftBumpPressed)
	{	
		if(debug)
		{
			printf("button Left Bump : \n");
		}
		pressedButton = BUTTON::LeftBumper;
	}
	else if(isButtonRightBumpPressed && !wasButtonRightBumpPressed)
	{	
		if(debug)
		{
			printf("button Right Bump : \n");
		}
		pressedButton = BUTTON::RightBumper;
	}
	else if(isButtonSelectPressed && !wasButtonSelectPressed)
	{	
		if(debug)
		{
			printf("button Select : \n");
		}
		pressedButton = BUTTON::Select;
	}
	else if(isButtonStartPressed && !wasButtonStartPressed)
	{	
		if(debug)
		{
			printf("button Start : \n");
		}
		pressedButton = BUTTON::Start;
	}
	else
	{
		pressedButton = BUTTON::NONE;
	}
	// do all the button release checks
	if(!isButtonAPressed && wasButtonAPressed)
	{	
		if(debug)
		{
			printf("button released A : \n");
		}
		releasedButton = BUTTON::A;
	}
	else if(!isButtonBPressed && wasButtonBPressed)
	{	
		if(debug)
		{
			printf("button released B : \n");
		}
		releasedButton = BUTTON::B;
	}
	else if(!isButtonXPressed && wasButtonXPressed)
	{	
		if(debug)
		{
			printf("button released X : \n");
		}
		releasedButton = BUTTON::X;
	}
	else if(!isButtonYPressed && wasButtonYPressed)
	{	
		if(debug)
		{
			printf("button released Y : \n");
		}
		releasedButton = BUTTON::Y;
	}
	else if(!isButtonLeftBumpPressed && wasButtonLeftBumpPressed)
	{	
		if(debug)
		{
			printf("button released Left Bump : \n");
		}
		releasedButton = BUTTON::LeftBumper;
	}
	else if(!isButtonRightBumpPressed && wasButtonRightBumpPressed)
	{	
		if(debug)
		{
			printf("button released Right Bump : \n");
		}
		releasedButton = BUTTON::RightBumper;
	}
	else if(!isButtonSelectPressed && wasButtonSelectPressed)
	{	
		if(debug)
		{
			printf("button released Select : \n");
		}
		releasedButton = BUTTON::Select;
	}

	else if(!isButtonStartPressed && wasButtonStartPressed)
	{	
		if(debug)
		{
			printf("button released Start : \n");
		}
		releasedButton = BUTTON::Start;
	}
	else
	{
		releasedButton = BUTTON::NONE;
	}  
#pragma endregion
	float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
	float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
	//thumbStickDirection = Vector2D(x,y);
	//LeftThumbStickDirection  = -Vector2D::DirectionVectorBetweenTwoPoints(thumbStickDirection,zero)
	// Check left thumbStick

	float leftThumbY = controllerState.Gamepad.sThumbLY;
	if(leftThumbY)
	{
		State.left_thumbstick.y = leftThumbY;
	}
	float leftThumbX = controllerState.Gamepad.sThumbLX;
	if(leftThumbX)
	{
		State.left_thumbstick.x = leftThumbX;
	}    
	wasButtonAPressed = isButtonAPressed;
	wasButtonBPressed = isButtonBPressed;
	wasButtonXPressed = isButtonXPressed;
	wasButtonYPressed = isButtonYPressed;
	wasButtonLeftBumpPressed = isButtonLeftBumpPressed;
	wasButtonRightBumpPressed = isButtonRightBumpPressed;
	wasButtonSelectPressed = isButtonSelectPressed;
	wasButtonStartPressed = isButtonStartPressed;
}

InputHandler::BUTTON InputHandler::getPressedButton()
{
	return pressedButton;
}
InputHandler::BUTTON InputHandler::getReleasedButton()
{
	return releasedButton;
}
InputHandler::~InputHandler(void)
{
}
