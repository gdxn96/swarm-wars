#pragma once
#include "rapidjson\document.h"
#include "rapidjson\reader.h"
#include "rapidjson\filereadstream.h"
#include "Vector2D.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace rapidjson;
using namespace sf;
class Animation
{
public:
	Animation();
	~Animation();
	void update();
	void draw(RenderWindow & _window);
	void setFramesPerSecond(float _framesPerSecond);
	void setRotation(float _rotationInDegrees);
	void translate(Vector2D);
	void setRadius(float _radius);
	Animation(string _animationName, Vector2D _position);
	void changeAnimation(string _animation);
	void SetLooping(bool _islooping);
	void setPosition(Vector2D);
	void setIsAlive(bool);
	void reset();
	void setDoOnce(bool doOnce);
private:
	vector<pair <string, vector<sf::IntRect>>>  animationList;
	Texture *texture;
	Vector2D position;
	vector<string> animationNames;
	string selectedAnimation;
	int selectedAnimationIndex = 0;
	sf::Clock clock;
	sf::Sprite outputSprite;
	float FPS,rotation = 0,maxCellWidth=0,maxCellHeight=0;
	int selectedColumn = 0;
	bool isLooping = true;
	bool isAlive = true;
	
	bool doOnce = false;
};

