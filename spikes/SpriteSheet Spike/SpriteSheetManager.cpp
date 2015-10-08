#include "stdafx.h"
#include "SpriteSheetManager.h"
#include <iostream>
using namespace std;
SpriteSheetManager::SpriteSheetManager()
{
}
SpriteSheetManager::SpriteSheetManager(const sf::Texture & _texture,int _columnAmount,int _rowAmount,Vector2D _position)
{
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
	//outputSprite.setOrigin(256, 256);
	outputSprite.setTexture(texture,true);
	outputSprite.setPosition(position.toSFMLVector());
	outputSprite.setScale(.5f,0.5f);
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
			selectedColumn = 0;
		}
		cout << "col "<<selectedColumn<< endl;
		cout << "row "<<selectedRow<< endl;
		clock.restart();
	}
	
	outputSprite.setTextureRect(animationList[selectedRow].RectangleList[selectedColumn]);
	outputSprite.setPosition(position.toSFMLVector());
}
void SpriteSheetManager::setPosition(Vector2D _position)
{
	position = _position;
}
void SpriteSheetManager::Draw(sf::RenderWindow & window)
{
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
sf::Sprite SpriteSheetManager::getOutputImage()
{
	return outputSprite;
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
SpriteSheetManager::~SpriteSheetManager(void)
{
}
