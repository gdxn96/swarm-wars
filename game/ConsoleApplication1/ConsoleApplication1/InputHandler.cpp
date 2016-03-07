#include "stdafx.h"
#include "InputHandler.h"
#define M_PI 3.141592654

InputHandler * InputHandler::instance = nullptr;
InputHandler::InputHandler() : m_maxPlayers(4)
{
	
	vector<t_buttonNum> buttons = {
		DPAD_UP,
		DPAD_DOWN,
		DPAD_LEFT,
		DPAD_RIGHT,
		START,
		BACK,
		LEFT_THUMB,
		RIGHT_THUMB,
		LB,
		RB,
		A,
		B,
		X,
		Y,
		LEFT_TRIGGER,
		RIGHT_TRIGGER,
		LEFT_STICK,
		RIGHT_STICK
	};

	for (int i = 0; i < m_maxPlayers; i++)
	{
		m_buttonsPressed.push_back(vector<std::pair<t_buttonNum, bool>>());
		for (t_buttonNum button : buttons)
		{
			m_buttonsPressed[i].push_back(std::pair<t_buttonNum, bool>(button, false));
		}
	}
	
	
}
void InputHandler::update()
{
	for (int j = 0; j < m_maxPlayers; j++)
	{
		for (int i = 0; i < m_buttonsPressed[j].size(); i++)
		{
			t_buttonNum button = m_buttonsPressed[j][i].first;
			bool isHeldB = isHeld(button, j);
			if (!isHeldB)
			{
				//cout << "kjdsh'vi" << endl;
			}

			m_buttonsPressed[j][i] = std::pair<t_buttonNum, bool>(button, isHeldB);
		}
	}
}
bool InputHandler::isPressed(InputHandler::t_buttonNum button, t_joyNum joyNum)
{
	if (!wasPressed(button, joyNum) && isHeld(button, joyNum))
	{
		return true;
	}
	else
		return false;
}

bool InputHandler::wasPressed(t_buttonNum button, t_joyNum joyNum)
{
	bool wasPressed = true;
	for (int i = 0; i < m_buttonsPressed[joyNum].size(); i++)
	{
		if (m_buttonsPressed[joyNum][i].first == button)
		{
			wasPressed = m_buttonsPressed[joyNum][i].second;
		}
	}
	

	if (wasPressed)
	{
		//cout << "button not found" << endl;
	}
	else
	{
		//cout << "not pressed" << endl;
	}
	return wasPressed;
}


bool InputHandler::isReleased(InputHandler::t_buttonNum button, t_joyNum joyNum)
{
	bool isHeldB = isHeld(button, joyNum);
	return !isHeldB;
}
float InputHandler::getThumbByAngle(t_buttonNum stick, t_joyNum joyNum)
{
	Vector2D ls, rs;
	InputHandler::getSticksPosition(ls, rs, joyNum);
	//180 * radians / 3.14
	float x = 0, y = 0;
	if (stick == LEFT_STICK)
	{
		x = ls.Normalize().x;
		y = ls.Normalize().y;
	}
	else if (stick == RIGHT_STICK)
	{
		x = rs.Normalize().x;
		y = rs.Normalize().y;
	}
	return 180 * (atan2(y, x)) / M_PI;
}

float InputHandler::getThumbByRadian(t_buttonNum stick, t_joyNum joyNum)
{
	Vector2D ls, rs;
	InputHandler::getSticksPosition(ls, rs, joyNum);
	//180 * radians / 3.14
	float x = 0, y = 0, angle = 0;
	if (stick == LEFT_STICK)
	{
		x = ls.Normalize().x;
		y = ls.Normalize().y;
	}
	else if (stick == RIGHT_STICK)
	{
		x = rs.Normalize().x;
		y = rs.Normalize().y;
	}
	return -atan2(y, x);
}

InputHandler * InputHandler::getInstance()
{
	if (instance == nullptr)
	{
		instance = new InputHandler;		
	}
	return instance;
}
// Returns true if the joystick is connected (and is an XBox 360 Controller)
bool InputHandler::isConnected(t_joyNum joyNum)
{
	XINPUT_STATE state;
	ZeroMemory(&state, sizeof(XINPUT_STATE));

	auto result = XInputGetState(joyNum, &state);
	return  (result == ERROR_SUCCESS);

}

// Convenience function: Returns true if there is at least one X360 controller connected
bool InputHandler::isAnyXBox360ControllerConnected()
{
	return  (isConnected(0) || isConnected(1) || isConnected(2) || isConnected(3));

}

// Returns true if the specified button is pressed
// Note that the triggers are NOT recognized as buttons.. You must use
// the getTriggers function for reading the triggers state
bool InputHandler::isHeld(  t_buttonNum buttonNum, t_joyNum joyNum)
{

	XINPUT_STATE state;
	ZeroMemory(&state, sizeof(XINPUT_STATE));

	XInputGetState(joyNum, &state);
	return  (state.Gamepad.wButtons & buttonNum);

}

// This function returns nothing
// It fills the variables left and right with the current state of the triggers (LT and RT)
// The values will always be in the range 0..1
// TODO: TAKE CARE OF THE DEAD ZONE ??????????????????????????????????
void InputHandler::getTriggers(float &left, float &right, t_joyNum joyNum)
{

	XINPUT_STATE state;
	ZeroMemory(&state, sizeof(XINPUT_STATE));

	XInputGetState(joyNum, &state);

	// Normalize and take care of the Dead Zone
	left = static_cast <float> (state.Gamepad.bLeftTrigger) / 255;
	right = static_cast <float> (state.Gamepad.bRightTrigger) / 255;

}
bool InputHandler::getTriggerPressed(  t_buttonNum buttonNum, float & amount, t_joyNum joyNum)
{
	XINPUT_STATE state;
	ZeroMemory(&state, sizeof(XINPUT_STATE));

	XInputGetState(joyNum, &state);
	if (buttonNum == LEFT_TRIGGER)
	{
		amount = static_cast <float> (state.Gamepad.bLeftTrigger) / 255;
		return true;
	}
	else if (buttonNum == RIGHT_TRIGGER)
	{
		amount = static_cast <float> (state.Gamepad.bRightTrigger) / 255;
		return true;
	}
	else
		amount= 0;
	return false;
}
// This function returns nothing
// It fills the vectors left and right with the stick positions,
// wich are in the range -100..100, similar to the SFML function
// getAxisPosition
void InputHandler::getSticksPosition(  Vector2D &left, Vector2D &right, t_joyNum joyNum)
{

	XINPUT_STATE state;
	ZeroMemory(&state, sizeof(XINPUT_STATE));

	XInputGetState(joyNum, &state);

	// Check for the "DEAD ZONE"
	// Left Stick
	if ((state.Gamepad.sThumbLX < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE &&
		state.Gamepad.sThumbLX > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) &&
		(state.Gamepad.sThumbLY < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE &&
		state.Gamepad.sThumbLY > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)) {

		state.Gamepad.sThumbLX = 0;
		state.Gamepad.sThumbLY = 0;

	}

	// Right Stick
	if ((state.Gamepad.sThumbRX < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE &&
		state.Gamepad.sThumbRX > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) &&
		(state.Gamepad.sThumbRY < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE &&
		state.Gamepad.sThumbRY > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)) {

		state.Gamepad.sThumbRX = 0;
		state.Gamepad.sThumbRY = 0;

	}

	// Convert values to SFML style (-100..100)
	left.x = static_cast <float> (state.Gamepad.sThumbLX / 327);
	left.y = static_cast <float> (state.Gamepad.sThumbLY / 327);
	right.x = static_cast <float> (state.Gamepad.sThumbRX / 327);
	right.y = static_cast <float> (state.Gamepad.sThumbRY / 327);

}

// Set vibration (0.0 to 1.0)
// 0 stops the vibration
void InputHandler::setVibration(  float leftMotor, float rightMotor, t_joyNum joyNum)
{

	XINPUT_VIBRATION vib;
	ZeroMemory(&vib, sizeof(XINPUT_VIBRATION));

	vib.wLeftMotorSpeed = static_cast <WORD> (leftMotor  * 65535.0f);
	vib.wRightMotorSpeed = static_cast <WORD> (rightMotor * 65535.0f);

	XInputSetState(joyNum, &vib);

}

InputHandler::~InputHandler()
{
}
