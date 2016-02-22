#pragma once
#include "Vector2D.h"
#include "GameConstants.h"

class SpawnPoint
{
private:
	std::vector<Vector2D> m_points;

public:
	SpawnPoint(float angle, float distFromCentre);
	Vector2D getPoint();
	void draw(sf::RenderWindow & window);
};