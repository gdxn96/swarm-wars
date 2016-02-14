#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2D.h"
/*
*@author Aaron Keating
* Here is an example in how to use the class
*
* sf::Texture texture;
* texture.loadFromFile("blood.png");
* 
* SpriteSheetManager Animation = SpriteSheetManager(texture,8,1,Vector2D(150,150));
* Animation.setAnimationNameToIndex(0,"blood pop");
* Animation.setRunningAnimation("blood pop");
* Animation.setIsLooping(true);
* Animation.setRotation(70);
* Animation.setScale(Vector2D(2,2));
* Animation.willDie = true;
* Animation.Update();
* 
* Animation.Draw(window);
*/
class AnimationManager
{
public:
	//if true debuging will output on the prompt
	bool debug;
	//setting this to true will kill the object 
	//after it runs through the animation once
	bool willDie;
	//A structor to hold an index and a list of Int Rectangles
	struct animation
	{
		int index;
		std::vector<sf::IntRect> RectangleList;
	};
	//A struct to hold and index and string name 
	//to tie the name to the index
	//used for setting a name to an animation
	struct animationIndex
	{
		int index;
		std::string name;
	};
	//default empty constructor
	AnimationManager();
	//default constructor that need a texture 
	//column and row Ammount plus a starting pos
	AnimationManager(const sf::Texture & texture,int columeAmount,int rowAmount, Vector2D & position, Vector2D _scale);
	//destructor method
	~AnimationManager(void);
	//the draw method for the spritesheet
	//draws the calucutated output sprite
	//takes a refrence to window to draw
	void Draw(sf::RenderWindow & window);
	//Update used sf::Clock to track the time
	//this time is used to run through the list
	//of rectangls that the final sprite will use
	void Update();
	//***Very IMPORTANT ***
	//This sets a name to a Row,
	//I.E row 0 = running animation
	//I.E row 0 = jumping animation
	void setAnimationNameToIndex(int index,std::string name);
	//*** very IMPORTANT ***
	//sets the running animation ie what row
	// by the asigned name value
	//
	void setRunningAnimation(std::string name);
	/**
	* sets the position
	* position sets a refrence to the value 
	*/
	void setPosition(Vector2D & position);
	//sets the rotation from the input
	//to the sprite rotation
	void setRotation(float _rotation);
	//method to set if the animation is looping or not
	void setIsLooping(bool _isLooping);
	//set the scale of the sprite
	//using Vector2D
	void setScale(Vector2D _scale);
	//gets if the object is still alive
	//true == is dead
	//false == is Alive
	bool getIfDead();
private:
	//private clock used to find the elasped time
	//used to loop through the int rects
	sf::Clock clock;
	//list of a struct that stores an index 
	//and another list or rectangles
	std::vector<animation> animationList;
	//list of an index and a string name
	//used to to tie a name to a row
	std::vector<animationIndex> animationRowList;
	//texture of the entire spriteSheet used
	sf::Texture texture;
	//rotation of the sprite
	float rotation;
	//values used to calculate the cell size 
	float width,height,cellWidth,cellHeight,timeElapsed;
	//set if you want the animation to loop or not
	bool isLooping;
	//position and origin of the sprite
	Vector2D position,cellOrigin;
	//the drawn output sprite;
	sf::Sprite outputSprite;
	//used to find the right row and column for the animation
	int selectedRow,columnAmount,rowAmount,selectedColumn;
	//vector to store the scale
	Vector2D scale;
	//set if the object is destroyed at the end of the animation
	bool isDead;
};

