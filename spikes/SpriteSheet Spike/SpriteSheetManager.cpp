#include "stdafx.h"
#include "SpriteSheetManager.h"
#include <iostream>
using namespace std;


SpriteSheetManager::SpriteSheetManager()
{
}
SpriteSheetManager::SpriteSheetManager(const sf::Texture & _texture,int _columnAmount,int _rowAmount,Vector2D &_position, Vector2D _scale)
{
	debug = false;
	texture = _texture;
	width = texture.getSize().x;
	height = texture.getSize().y;
	cellWidth = width/_columnAmount;
	cellHeight = height/_rowAmount;
	selectedRow = 0;
	selectedColumn = 0;
	columnAmount = _columnAmount;
	rowAmount = _rowAmount;
	position = _position;
	isLooping = false;
	isDead = false;
	willDie = false;
	cellOrigin = Vector2D(cellWidth/2,cellHeight/2);
	for(int i = 0; i < rowAmount;i ++)
	{
		animation temp;
		temp.index = i;
		for(int j = 0 ; j < columnAmount; j++)
		{
			temp.RectangleList.push_back(sf::IntRect(cellWidth * j,cellHeight * i,cellWidth,cellHeight));
		}
		animationList.push_back(temp);
	}
	texture.setSmooth(true);
	sf::Sprite t(texture);
	outputSprite.setOrigin(cellOrigin.toSFMLVector());
	outputSprite.setTexture(texture,true);
	outputSprite.setPosition(position.toSFMLVector());
	outputSprite.setScale(_scale.toSFMLVector());
}

void SpriteSheetManager::Update()
{

	sf::Time elapsedTime = clock.getElapsedTime();
	if(elapsedTime > sf::seconds(0.1f))
	{
		if(selectedColumn < columnAmount-1)
		{
			selectedColumn++;

		}
		else
		{
			if(isLooping || willDie == false)
			{
				selectedColumn = 0;
			}
			if(willDie)
			{
				isDead = true;
			}
		}
		if(debug)
		{
			cout << "col "<<selectedColumn<< endl;
			cout << "row "<<selectedRow<< endl;
		}
		clock.restart();
	}

	outputSprite.setRotation(rotation);
	outputSprite.setScale(scale.toSFMLVector());
	outputSprite.setTextureRect(animationList[selectedRow].RectangleList[selectedColumn]);
	outputSprite.setPosition(position.toSFMLVector());
}

void SpriteSheetManager::setPosition(Vector2D & _position)
{
	position = _position;
}
void SpriteSheetManager::Draw(sf::RenderWindow & window)
{
	if(!isDead)
	window.draw(outputSprite);
}
void SpriteSheetManager::setRunningAnimation(std::string name)
{
	for(int i = 0; i < animationIndixList.size();i++)
	{
		if(animationIndixList[i].name == name)
		{
			selectedRow = i;
		}
		else
		{
			selectedRow = 0;
		}
	}
}
void SpriteSheetManager::setRotation(float _rotate)
{
	rotation = _rotate;
}
void SpriteSheetManager::setAnimationNameToIndex(int index,std::string name)
{
	animationIndex temp;
	temp.index = index;
	temp.name = name;
	animationIndixList.push_back(temp);
}
void SpriteSheetManager::setScale(Vector2D _scale)
{
	scale = _scale;
}
void SpriteSheetManager::setIsLooping(bool _isLooping)
{
	isLooping = _isLooping;
}
bool SpriteSheetManager::getIfDead()
{
	return isDead;
}
SpriteSheetManager::~SpriteSheetManager(void)
{
}
