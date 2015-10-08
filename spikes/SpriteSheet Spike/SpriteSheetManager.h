#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2D.h"
class SpriteSheetManager
{
public:
	struct animation
	{
		int index;
		std::vector<sf::IntRect> RectangleList;
	};
	struct animationIndex
	{
		int index;
		std::string name;
	};
	SpriteSheetManager();
	SpriteSheetManager(const sf::Texture & texture,int columeAmount,int rowAmount, Vector2D position);
	~SpriteSheetManager(void);
	void Draw(sf::RenderWindow & window);
	void Update();
	void setAnimationNameToIndex(int index,std::string name);
	void setRunningAnimation(std::string name);
	sf::Sprite getOutputImage();
	void setPosition(Vector2D position);
	void setRotation(float _rotation);
private:
	sf::Clock clock;
	std::vector<animation> animationList;
	std::vector<animationIndex> animationIndixList;
	sf::Texture texture;
	sf::Image image;
	float rotation;
	float width,height,cellWidth,cellHeight,timeElapsed;
	bool isLooping;
	Vector2D position,cellOrigin;
	sf::Sprite outputSprite;
	int selectedRow,columnAmount,rowAmount,selectedColumn;
};

