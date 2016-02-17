#pragma once 

#include "Enemy.h"
#include "Unit.h"
#include "Bullet.h"
#include "Circle.h"
#include "Polygon.h"
#include "Tower.h"
#include "Bunker.h"

class CollisionManager
{
public:
	CollisionManager();

	void checkEnemyBullets(vector<Enemy*> enemies, vector<Bullet*> bullets);
	void checkEnemyTower(vector<Enemy*> enemies, Tower& tower);
	void checkEnemyUnitRange(vector<Enemy*> enemies, vector<Unit*> units);
	void checkEnemyBunker(vector<Enemy*> enemies, vector<Bunker*> bunkers, float dt);

private:
	float distFromLineToPoint(Vector2D start, Vector2D end, Vector2D point);

	bool const Intersects(Circle& circle, Polygon2D& polygon);
	bool const Intersects(Polygon2D& polygon, Circle& circle);
	bool const Intersects(Circle& circle1, Circle& circle2);
};

