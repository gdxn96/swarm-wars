#pragma once 

#include "Enemy.h"
#include "Unit.h"
#include "Bullet.h"
#include "Circle.h"
#include "Polygon.h"

class CollisionManager
{
public:
	CollisionManager();

	void checkEnemyBullets();
	void checkEnemyTower();
	void checkEnemyUnitRange(vector<Enemy*> enemies, vector<Unit*> units);
	void checkEnemyBunker();

private:
	float distFromLineToPoint(Vector2D start, Vector2D end, Vector2D point);

	bool const circleIntersectsPolygon(Circle& circle, Polygon2D& polygon);
	bool const circleIntersectsCircle(Circle& circle1, Circle& circle2);
};

