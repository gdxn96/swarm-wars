#include "stdafx.h"
#include "Bolt.h"


Bolt::Bolt(Pylon* left, Pylon* right) : 
m_alive(true), 
m_nodeLeft(left), 
m_nodeRight(right),
TIME_UNTIL_CHANGE(0.005f)
{
	timeUntillChange = TIME_UNTIL_CHANGE;
	if (m_alive)
	//listOfLines = CreateArk(m_nodeLeft->getPosition(), m_nodeRight->getPosition(), thickness);
	alpha = 0;
	
}

void Bolt::update(float dt)
{
	timeUntillChange -= dt;
	if (m_alive)
	{
		if (m_nodeLeft->getAlive() && m_nodeRight->getAlive())
		{

		}
		else
		{
			kill();
		}

		if (timeUntillChange <= 0)
		{
			alpha -= 12;
			for (int i = 0; i < listOfLines.size(); i++)
			{
				listOfLines[i]->setAlpha(alpha);
			}
			timeUntillChange = TIME_UNTIL_CHANGE;
		}
		if (alpha <= 0)
		{
			alpha = 255;	
			for (auto & li : listOfLines)
			{
				li->setAlive(false);
			}
		}

		if (listOfLines.size() == 0)
		{
			listOfLines = CreateArk(m_nodeLeft->getPosition(), m_nodeRight->getPosition(), thickness);
		}

		for (int i = 0; i < listOfLines.size(); i++)
		{
			if (listOfLines[i]->getAlive())
			{
				listOfLines[i]->Update();
			}
			else
			{
				delete listOfLines[i];
				listOfLines[i] = nullptr;
				listOfLines.erase(listOfLines.begin() + i);
			}
		}
	}
	
}

void Bolt::draw(sf::RenderWindow& window)
{
	if (m_alive)
	{
		for (int i = 0; i < listOfLines.size(); i++)
		{
			listOfLines[i]->Draw(window);
		}
	}
	
}
bool my_compare(float a, float b){
	return a < b;
}
std::vector<Line *> Bolt::CreateArk(Vector2D & start, Vector2D & end, float thickness)
{
	std::vector<Line *> results;
	Vector2D tangent = end - start;
	Vector2D normal = Vector2D::Normalize(Vector2D(tangent.y, -tangent.x));
	float length = tangent.Magnitude();

	std::vector<float> points;
	points.push_back(0);

	for (int i = 0; i < length / 6; i++)
	{
		double r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		points.push_back(r);
	}

	std::sort(points.begin(), points.end(), my_compare);

	const float sway = 80;
	const float jag = 1 / sway;

	Vector2D previousPoint = start;
	float previousDisplacment = 0;

	for (int i = 1; i < points.size(); i++)
	{
		float point = points[i];
		//used to prevent sharp angles 
		float scale = (length * jag) * (point - points[i - 1]);
		//defines an envelope
		float envelope = point > 0.95f ? 20 * (1 - point) : 1;

		float displacment = -sway + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (sway - (-sway))));

		displacment -= (displacment - previousDisplacment) * (1 - scale);
		displacment *= envelope;

		sf::Vector2f pos = start.toSFMLVector() + point * tangent.toSFMLVector() + displacment * normal.toSFMLVector();
		Vector2D p;
		p.x = pos.x;
		p.y = pos.y;

		results.push_back(new Line(previousPoint, p, thickness));

		previousPoint = p;
		previousDisplacment = displacment;
	}
	
	results.push_back(new Line(previousPoint, end, thickness));
	return results;
}

void Bolt::kill()
{
	m_alive = false;
	for (auto & li : listOfLines)
	{
		li->setAlive(m_alive);
	}

	for (int i = 0; i < listOfLines.size(); i++)
	{

			delete listOfLines[i];
			listOfLines[i] = nullptr;
			listOfLines.erase(listOfLines.begin() + i);
	}
}

bool Bolt::containsPylon(Pylon * node)
{
	return m_nodeLeft == node || m_nodeRight == node;
}
