#include "stdafx.h"
#include "CollisionManager.h"

CollisionManager::CollisionManager()
{
}

void CollisionManager::checkEnemyBullets()
{

}

void CollisionManager::checkEnemyTower()
{

}

void CollisionManager::checkEnemyUnitRange(vector<Enemy*> enemies, vector<Unit*> units)
{
	for (Enemy * enemy : enemies)
	{
		for (Unit * unit : units)
		{
			bool intersects = circleIntersectsPolygon(enemy->getBounds(), unit->getRangeCone());
			if (intersects)
			{
				printf("collide\n");
			}
			else
			{
				printf("not collide\n");
			}
		}
	}
}

void CollisionManager::checkEnemyBunker()
{

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

bool const CollisionManager::circleIntersectsPolygon(Circle & circle, Polygon2D& polygon)
{
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

bool const CollisionManager::circleIntersectsCircle(Circle& circle1, Circle& circle2)
{
	float distBetween = (circle1.getCentre() - circle2.getCentre()).Magnitude();
	float maxDistBetween = circle1.getRadius() + circle2.getRadius();

	return distBetween < maxDistBetween;
}
