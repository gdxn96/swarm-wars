#include "stdafx.h"
#include "CollisionManager.h"

CollisionManager::CollisionManager(UnitController* unitController)
	:
	m_unitController(unitController)
{
}

void CollisionManager::checkEnemyBullets(vector<Enemy*> enemies, vector<Bullet*> bullets)
{
	for (Bullet * bullet : bullets)
	{
		for (Enemy * enemy : enemies)
		{
				if (Intersects(bullet->getBounds(), enemy->getBounds()))
				{	
					enemy->damage(bullet->getDamage());
					if (!enemy->getAlive())
					{
						m_unitController->getUnitById(bullet->getParentId())->addExperience(GameConstants::EXPERENCE_AMOUNT);
						m_unitController->getUnitById(bullet->getParentId())->addCredits(GameConstants::CREDIT_AMOUNT);
					}
					bullet->kill();
					break;
				}
		}
	}
}

void CollisionManager::updateEnemyNeighbours(vector<Enemy*> enemies)
{
	for (int a = 0; a < enemies.size(); a++)
	{
		enemies[a]->resetNeighbours();
		for (int b = a + 1; b < enemies.size(); b++)
		{
			if (Intersects(enemies[b]->getBounds(), enemies[a]->getNeighbourBounds()))
			{
				enemies[a]->addNeighbour(enemies[b]);
			}
		}
	}
}

void CollisionManager::checkBulletsTower(vector<Bullet*> bullets, Tower& tower)
{
	for (Bullet * bullet : bullets)
	{
		if (Intersects(bullet->getBounds(), tower.getInnerBounds()))
		{
			bullet->kill();
		}
	}
}

void CollisionManager::checkEnemyTower(vector<Enemy*> enemies, Tower& tower)
{
	for (Enemy * enemy : enemies)
	{
		if (Intersects(enemy->getBounds(), tower.getInnerBounds()))
		{
			enemy->kill();
			tower.damage(enemy->getDamage());
		}
	}
}

void CollisionManager::checkEnemyUnitRange(vector<Enemy*> enemies, vector<Unit*> units)
{
	for (Unit * unit : units)
	{
		bool seesEnemy = false;
		for (Enemy * enemy : enemies)
		{
			if (Intersects(enemy->getBounds(), unit->getRangeCone()))
			{
				seesEnemy = true;
				unit->changeState(UNIT_STATE::FIRING);
				break;
			}
			
		}
		if (!seesEnemy && unit->getPreviousState() != UNIT_STATE::FIRING)
		{
			unit->changeState(unit->getPreviousState());
		}
	}
}

void CollisionManager::checkEnemyBunker(vector<Enemy*> enemies, vector<Bunker*> bunkers, float dt)
{
	for (Enemy * enemy : enemies)
	{
		bool collidesBunker = false;
		for (Bunker* bunker : bunkers)
		{
			if (Intersects(enemy->getBounds(), bunker->getBounds()))
			{
				//cout << "collide" << endl;
				enemy->changeState(ENEMY_STATE::ATTACKING);
				bunker->damageBunker(enemy->getDamage() * dt);
				collidesBunker = true;
				break;
			}
		}

		if (!collidesBunker)
		{
			enemy->changeState(ENEMY_STATE::MOVING);
		}
	}
}

float CollisionManager::distFromLineToPoint(Vector2D start, Vector2D end, Vector2D point)
{
	// Return minimum distance between line segment vw and point p
	const float l2 = (start - end).Magnitude() * (start - end).Magnitude();
	if (l2 == 0.0) return (point - start).Magnitude();

	float t = Vector2D::DotProduct(point - start, end - start) / l2;
	if (t < 0.0) return (point - start).Magnitude();
	else if (t > 1.0) return (point- end).Magnitude();
	Vector2D offset = end - start;
	const Vector2D projection = start + ((offset) * t);
	return (point - projection).Magnitude();
}

bool const CollisionManager::Intersects(Circle & circle, Polygon2D& polygon)
{

	//check broad phase
	if (polygon.hasBroadPhaseCircle())
	{
		if (!Intersects(polygon.getBroadPhaseCircle(), circle))
		{
			return false;
		}
	}

	//finds if the centre point of the circle is inside the poly first
	if (polygon.pointInside(circle.getCentre()))
	{
		return true;
	}

	//then checks circle against polygon edges
	vector<std::pair<Vector2D, Vector2D>> polyEdges = polygon.getEdges();

	for (std::pair<Vector2D, Vector2D> edge : polyEdges)
	{
		if (distFromLineToPoint(edge.first, edge.second, circle.getCentre()) < circle.getRadius())
		{
			return true;
		}
	}

	return false;
}

bool const CollisionManager::Intersects(Polygon2D& polygon, Circle & circle)
{
	//check broad phase
	if (polygon.hasBroadPhaseCircle())
	{
		if (!Intersects(polygon.getBroadPhaseCircle(), circle))
		{
			return false;
		}
	}

	//finds if the centre point of the circle is inside the poly first
	if (polygon.pointInside(circle.getCentre()))
	{
		return true;
	}

	//then checks circle against polygon edges
	vector<std::pair<Vector2D, Vector2D>> polyEdges = polygon.getEdges();

	for (std::pair<Vector2D, Vector2D> edge : polyEdges)
	{
		if (distFromLineToPoint(edge.first, edge.second, circle.getCentre()) < circle.getRadius())
		{
			return true;
		}
	}

	return false;
}

bool const CollisionManager::Intersects(Circle& circle1, Circle& circle2)
{
	float distBetween = (circle1.getCentre() - circle2.getCentre()).Magnitude();
	float maxDistBetween = circle1.getRadius() + circle2.getRadius();

	return distBetween < maxDistBetween;
}
