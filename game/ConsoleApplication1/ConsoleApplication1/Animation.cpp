#include "stdafx.h"
#include "Animation.h"
#include "AssetLoader.h"
Animation::Animation(){}
Animation::Animation(string _animationName, Vector2D _position)
{
	texture = AssetLoader::getInstance()->findAnimationByKey(_animationName).first;
	animationList = AssetLoader::getInstance()->findAnimationByKey(_animationName).second;
	position = _position;
	for (int i = 0; i < animationList.size(); i++)
	{
		animationNames.push_back(animationList[i].first);
	}
	for (int i = 0; i < animationList[selectedAnimationIndex].second.size(); i++)
	{
		if (animationList[selectedAnimationIndex].second[i].width > maxCellWidth)
		{
			maxCellWidth = animationList[selectedAnimationIndex].second[i].width;
		}
		if (animationList[selectedAnimationIndex].second[i].height > maxCellHeight)
		{
			maxCellHeight = animationList[selectedAnimationIndex].second[i].height;
		}
	}
	FPS = 0.1f;
	outputSprite.setOrigin(maxCellWidth / 2, maxCellHeight / 2);
	outputSprite.setTexture(*texture, true);
	outputSprite.setPosition(position.toSFMLVector());
	outputSprite.setScale(Vector2f(1, 1));
	
}

void Animation::update()
{
	int max;
	sf::Time elapsedTime = clock.getElapsedTime();
	if (animationList[selectedAnimationIndex].second.size() != 0)
	{
		max = animationList[selectedAnimationIndex].second.size();
	}
	else
		max = 0;
	
	if (elapsedTime > sf::seconds(FPS) && isLooping)
	{
		if (selectedColumn < max - 1 )
		{
			selectedColumn++;
		}
		else
		{
			if (!doOnce)
			selectedColumn = 0;
		}
		
		clock.restart();
	}
	outputSprite.setRotation(rotation);
	if (selectedColumn < animationList[selectedAnimationIndex].second.size() - 1)
	{
		outputSprite.setTextureRect(animationList[selectedAnimationIndex].second[selectedColumn]);
	}
	outputSprite.setPosition(position.toSFMLVector());
}
void Animation::changeAnimation(string _animationName)
{
	texture = AssetLoader::getInstance()->findAnimationByKey(_animationName).first;
	animationList = AssetLoader::getInstance()->findAnimationByKey(_animationName).second;
	outputSprite.setTexture(*texture);
}
void Animation::SetLooping(bool _isLooping)
{
	isLooping = _isLooping;
}
void Animation::setFramesPerSecond(float _framesPerSecond)
{
	FPS = 1 / _framesPerSecond;
}
void Animation::setRotation(float _rotationInDegrees)
{
	rotation = _rotationInDegrees-90;
}

void Animation::setPosition(Vector2D _pos)
{
	position = _pos;
}
void Animation::reset()
{
	selectedColumn = 0;
}

void Animation::setDoOnce(bool _d)
{
	doOnce = _d;
}

void Animation::draw(RenderWindow & _window)
{
	if (isAlive)
	{
		_window.draw(outputSprite);
	}
}
void Animation::translate(Vector2D _translationAmount)
{
	position += _translationAmount;
}

void Animation::setIsAlive(bool _isAlive)
{
	isAlive = _isAlive;
}

void Animation::setRadius(float _radius)
{
	float width, height;
	width = _radius / maxCellWidth;
	height = _radius / maxCellHeight;
	outputSprite.setScale(width, height);
}
Animation::~Animation()
{
}
