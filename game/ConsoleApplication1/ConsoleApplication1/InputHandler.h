#pragma once
#include "Vector2D.h"
#include <iostream> 
#include <sstream>
#include <unordered_map>
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <XInput.h>
using namespace std;
class InputHandler
{
public:
	static InputHandler * getInstance();
	// Typedefs
	typedef unsigned int    t_joyNum;
	typedef unsigned short  t_buttonNum;

	// Enums
	enum {
		Count = 4       // Player 0-3
	};

	enum {
		DPAD_UP = 0x0001,
		DPAD_DOWN = 0x0002,
		DPAD_LEFT = 0x0004,
		DPAD_RIGHT = 0x0008,
		START = 0x0010,
		BACK = 0x0020,
		LEFT_THUMB = 0x0040,
		RIGHT_THUMB = 0x0080,
		LB = 0x0100,
		RB = 0x0200,
		A = 0x1000,
		B = 0x2000,
		X = 0x4000,
		Y = 0x8000,
		NONE = NULL,
		LEFT_TRIGGER,
		RIGHT_TRIGGER,
		LEFT_STICK,
		RIGHT_STICK,
	};

	enum DPadState { LEFT, RIGHT, UP, DOWN, CENTER };
	vector<t_joyNum> listOfButtons;
	// Functions (similar to SFML API)
	static bool isConnected(t_joyNum joyNum = 0);
	unsigned int getButtonCount(t_joyNum joyNum = 0) { return 14; }
	
	// X360 specific functions
	static bool isAnyXBox360ControllerConnected();

	static void getSticksPosition(Vector2D &left, Vector2D &right, t_joyNum joyNum = 0);

	void update();

	bool wasPressed(t_buttonNum, t_joyNum joyNum = 0);

	bool isPressed(t_buttonNum, t_joyNum joyNum = 0);

	bool isReleased(t_buttonNum, t_joyNum joyNum = 0);

	bool isHeld(t_buttonNum buttonNum, t_joyNum joyNum = 0);

	bool getTriggerPressed(t_buttonNum, float &, t_joyNum joyNum = 0);

	static void setVibration(float leftMotor = 0.0f, float rightMotor = 0.0f, t_joyNum joyNum = 0);

	static float getThumbByAngle(t_buttonNum, t_joyNum joyNum = 0);

	static float getThumbByRadian(t_buttonNum, t_joyNum joyNum = 0);


	~InputHandler();
protected:
	InputHandler();
	static InputHandler * instance;
	
private:
	int m_maxPlayers;

	vector<vector<std::pair<t_buttonNum, bool>>> m_buttonsPressed;
	
	void getTriggers(float &left, float &right, t_joyNum joyNum);
};

