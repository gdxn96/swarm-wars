#pragma once 
#include <vector>
#include "Vector2D.h"

class Polygon2D
{
public:
	Polygon2D();
	std::vector<std::pair<Vector2D, Vector2D>> const getEdges();
	std::vector<Vector2D> const getPoints();
	void clearPoints();
	void addPoint(Vector2D point);
	bool pointInside(Vector2D point);
	void draw(sf::RenderWindow & window, sf::Color color);
	

private:
	void updateEdges();

	std::vector<Vector2D> m_vertices;
	std::vector<std::pair<Vector2D, Vector2D>> m_edges;
};


