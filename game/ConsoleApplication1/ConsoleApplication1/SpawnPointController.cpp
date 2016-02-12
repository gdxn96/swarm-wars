#include "stdafx.h"
#include "SpawnPointController.h"


SpawnPointController::SpawnPointController()
{
	spawnPoints.push_back(Vector2D(GameConstants::WINDOW_CENTRE.x, -50));
}

Vector2D SpawnPointController::getSpawnPoint()
{
	int index = rand() % spawnPoints.size();
	return spawnPoints[index];
}


