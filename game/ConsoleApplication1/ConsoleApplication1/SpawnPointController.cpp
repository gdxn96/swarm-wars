#include "stdafx.h"
#include "SpawnPointController.h"


SpawnPointController::SpawnPointController()
{
	float spawnRadius = GameConstants::WINDOW_SIZE.x;
	int numSpawnPoints = 3;

	for (int i = 0; i < numSpawnPoints; i++)
	{
		spawnPoints.push_back(Vector2D((2 * GameConstants::PI / numSpawnPoints * i) + 2 * GameConstants::PI / 90) * spawnRadius + GameConstants::WINDOW_CENTRE);
		spawnPoints.push_back(Vector2D(2 * GameConstants::PI / numSpawnPoints * i) * spawnRadius + GameConstants::WINDOW_CENTRE);
		spawnPoints.push_back(Vector2D(2 * GameConstants::PI / numSpawnPoints * i - 2 * GameConstants::PI / 90) * spawnRadius + GameConstants::WINDOW_CENTRE);
	}
}

int SpawnPointController::getNumDeadPylons()
{
	return spawnPoints.size() / 3;
}

Vector2D SpawnPointController::getSpawnPoint()
{
	int index = rand() % spawnPoints.size();
	return spawnPoints[index];
}


