#include "stdafx.h"
#include "SpawnPointController.h"


SpawnPointController::SpawnPointController()
{
	float spawnRadius = GameConstants::WINDOW_SIZE.x;
	int numSpawnPoints = 12;

	for (int i = 0; i < numSpawnPoints; i++)
	{
		spawnPoints.push_back(Vector2D(2 * GameConstants::PI / numSpawnPoints * i) * spawnRadius + GameConstants::WINDOW_CENTRE);
	}
}

Vector2D SpawnPointController::getSpawnPoint()
{
	int index = rand() % spawnPoints.size();
	return spawnPoints[index];
}


