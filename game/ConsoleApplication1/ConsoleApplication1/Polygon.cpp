#include "stdafx.h"
#include "Polygon.h"
#include "AssetLoader.h"
Polygon2D::Polygon2D() : m_hasBroudPhaseCircle(false)
{
}

void Polygon2D::setBroadPhaseCircle(Vector2D centre, float radius)
{
	m_hasBroudPhaseCircle = true;
	m_broadPhaseCircle = Circle(centre, radius);
}

Circle& Polygon2D::getBroadPhaseCircle()
{
	return m_broadPhaseCircle;
}

bool Polygon2D::hasBroadPhaseCircle()
{
	return m_hasBroudPhaseCircle;
}

bool Polygon2D::pointInside(Vector2D point)
{
	int i, j;
	bool inside = 0;
	for (i = 0, j = m_vertices.size() - 1; i < m_vertices.size(); j = i++) {
		if (((m_vertices[i].y > point.y) != (m_vertices[j].y >point.y)) &&
			(point.x < (m_vertices[j].x - m_vertices[i].x) * (point.y - m_vertices[i].y) / (m_vertices[j].y - m_vertices[i].y) + m_vertices[i].x))
			inside = !inside;
	}
	return inside;
}

std::vector<std::pair<Vector2D, Vector2D>> const Polygon2D::getEdges()
{
	return m_edges;
}

void Polygon2D::draw(sf::RenderWindow & window, sf::Color color)
{
	sf::ConvexShape polygon;
	polygon.setPointCount(m_vertices.size());
	
	for (int i = 0; i < m_vertices.size(); i++)
	{
		polygon.setPoint(i, m_vertices[i].toSFMLVector());
	}
	polygon.setFillColor(color);
	polygon.setOutlineColor(sf::Color(135, 206, 250, 255));
	polygon.setOutlineThickness(2);
	window.draw(polygon);
}

std::vector<Vector2D> const Polygon2D::getPoints()
{
	return m_vertices;
}

void Polygon2D::clearPoints()
{
	m_vertices.clear();
	updateEdges();
}

void Polygon2D::addPoint(Vector2D point)
{
	m_vertices.push_back(point); 
	updateEdges();
}

void Polygon2D::updateEdges()
{
	m_edges.clear();
	int numEdges = m_vertices.size();
	Vector2D lastPoint, firstPoint;
	
	for (int i = 0; i < numEdges - 1; i++)
	{
		m_edges.push_back(std::pair<Vector2D, Vector2D>(m_vertices[i], m_vertices[i + 1]));
	}
	if (numEdges > 0)
	{	//get last edge
		firstPoint = m_vertices[0];
		lastPoint = m_vertices[numEdges - 1];
		m_edges.push_back(std::pair<Vector2D, Vector2D>( lastPoint, firstPoint));
	}
}