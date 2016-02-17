#pragma once
#include "Vector2D.h"
#include <vector>
#include "GameConstants.h"

class SpawnPointController
{
public:
	SpawnPointController();
	Vector2D getSpawnPoint();

private:
	std::vector<Vector2D> spawnPoints;
};
