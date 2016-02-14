// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h" 
#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include <iostream> 
#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include "LightManager.h"
#include "Vector2D.h"
//#include "LightManager.h"
#include "InputHandler.h"
#include <ctime>
#include <cstdlib>
using namespace std;
sf::Vector2f position ;
sf::Texture bloodText;
bool hasController = false;
Vector2D zero = Vector2D(0,0);
InputHandler inputHandler;
int main()
{
	srand (static_cast <unsigned> (time(0)));
	Vector2D move;
	LightManager lights2 = LightManager(position,sf::Vector2f(0.9f, 0.9f),sf::Color(255,180,130,255));
	// Create a window for the game
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Application");
	sf::Texture texture;
	texture.loadFromFile("background.png");
	// Load the center sprite
	sf::Sprite center_sprite(texture);
	center_sprite.setOrigin(256, 256);
	center_sprite.setPosition(400, 300);

	inputHandler.debug = false;


	//center_sprite.setTextureRect(sf::IntRect(105,0,50,50));
	lights2.AddLight(sf::Vector2f(300,500), sf::Vector2f(0.9f, 0.9f),  sf::Color(255,0,0,255),sf::Vector2f(0.5f,0));
	lights2.AddLight(sf::Vector2f(200,200), sf::Vector2f(0.9f, 0.9f),  sf::Color(255,180,130,255),sf::Vector2f(0,0));

	for (;;)// main update
	{

		inputHandler.HandleInput();
		if (inputHandler.getReleasedButton() == InputHandler::BUTTON::B)
		{
			lights2.AddLight(sf::Vector2f(500,500), sf::Vector2f(0.9f, 0.9f), 
				sf::Color(255,130,130,255),inputHandler.getLeftThumbStick().toSFMLVector());
		}
		if (inputHandler.getReleasedButton() == InputHandler::BUTTON::X)
		{
			lights2.AddLight(sf::Vector2f(500,500), sf::Vector2f(0.9f, 0.9f),
				sf::Color(144,56,255,255),inputHandler.getRightThumbStick().toSFMLVector());
		}
		position = sf::Vector2f(sf::Mouse::getPosition().x,sf::Mouse::getPosition().y);
		// ---------- Handle Events -----------
		lights2.Update(window,position);

		sf::Event event;
		while (window.pollEvent(event))
		{
			// Handle events
			if (event.type == sf::Event::Closed
				|| event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				return 0;
		}
		window.draw(center_sprite);

	}
}