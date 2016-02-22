#pragma once 

#include "Enemy.h"
#include "UnitController.h"
#include "Bullet.h"
#include "Circle.h"
#include "Polygon.h"
#include "Tower.h"
#include "Bunker.h"

class CollisionManager
{
public:
	CollisionManager(UnitController* unitController);

	void updateEnemyNeighbours(vector<Enemy*> enemies);
	void checkBulletsTower(vector<Bullet*> bullets, Tower& tower);
	void checkEnemyBullets(vector<Enemy*> enemies, vector<Bullet*> bullets);
	void checkEnemyTower(vector<Enemy*> enemies, Tower& tower);
	void checkEnemyUnitRange(vector<Enemy*> enemies, vector<Unit*> units);
	void checkEnemyBunker(vector<Enemy*> enemies, vector<Bunker*> bunkers, float dt);
private:
	float distFromLineToPoint(Vector2D start, Vector2D end, Vector2D point);

	bool const Intersects(Circle& circle, Polygon2D& polygon);
	bool const Intersects(Polygon2D& polygon, Circle& circle);
	bool const Intersects(Circle& circle1, Circle& circle2);

	UnitController* m_unitController;
};

