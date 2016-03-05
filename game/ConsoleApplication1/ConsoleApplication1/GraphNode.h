#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include <list>
#include "Vector2D.h"
#include "AABB.h"
using namespace sf;

// Forward references
template <typename NodeType, typename ArcType> class GraphArc;

// -------------------------------------------------------
// Name:        GraphNode
// Description: This is the node class. The node class 
//              contains data, and has a linked list of 
//              arcs.
// -------------------------------------------------------
template<class NodeType, class ArcType>
class GraphNode {
private:
	// typedef the classes to make our lives easier.
	typedef GraphArc<NodeType, ArcType> Arc;
	typedef GraphNode<NodeType, ArcType> Node;
	// -------------------------------------------------------
	// Description: data inside the node
	// -------------------------------------------------------
	NodeType m_data;

	// -------------------------------------------------------
	// Description: list of arcs that the node has.
	// -------------------------------------------------------
	list<Arc> m_arcList;

	// -------------------------------------------------------
	// Description: This remembers if the node is marked.
	// -------------------------------------------------------
	bool m_marked;

	// -------------------------------------------------------
	// Description: This stores the previous node.				////Q2
	// -------------------------------------------------------
	Node* m_previousNode;


	int searchDistance;
	int heuristic = 0;
	Vector2D m_position;
	float m_radius = 10;
	sf::Color myColour = sf::Color::Red;
	

public:
	AABB bounds;
	//Q2
	Node *getPreviousNode(){ return m_previousNode; }
	void setPreviousNode(Node* prev){ m_previousNode = prev; }
	
	// Accessor functions
	list<Arc> const & arcList() const {
		return m_arcList;
	}

	bool marked() const {
		return m_marked;
	}

	void draw(sf::RenderWindow & window, sf::Font font)
	{

		//bounds = AABB(Vector2D(m_position - Vector2D(40, 40)), 80, 80);
		//sf::Text name;
		//name.setFont(font);
		//name.setString(m_data);
		//name.setPosition(Vector2D(m_position - Vector2D(m_radius, m_radius)).toSFMLVector());
		//name.setCharacterSize(20);

		sf::CircleShape c;
		c.setRadius(m_radius);
		c.setOrigin(Vector2f(m_radius, m_radius));
		c.setPosition(m_position.toSFMLVector());
		c.setFillColor(myColour);
		window.draw(c);
		//window.draw(name);
		//bounds.Draw(window);
		list<Arc>::iterator iter = m_arcList.begin();
		list<Arc>::iterator endIter = m_arcList.end();
		int i = 0;
		for (; iter != endIter; ++iter) 
		{
			Vector2D pos = iter->node()->getPosition();
			i++;

			Vector2D dir = pos - m_position;
			float mag = sqrt(dir.x * dir.x + dir.y * dir.y);
			dir = Vector2D(dir.x / mag, dir.y / mag);
			Vector2D offset = Vector2D(dir.x * (mag / 2), dir.y * (mag / 2));

			/*sf::Text ci = name;
			ci.setOrigin(Vector2f(5, 5));
			ci.setPosition(Vector2D(m_position + offset).toSFMLVector());
			ci.setString(to_string(iter->weight()));
			ci.setCharacterSize(12.5f);
			window.draw(ci);*/
			


			sf::Vertex line[] = { sf::Vertex(m_position.toSFMLVector()), sf::Vertex(iter->node()->getPosition().toSFMLVector()) };
			window.draw(line, 2, sf::Lines);
		}
		
	}

	NodeType const & data() const {
		return m_data;
	}
	// Manipulator functions
	void setData(NodeType data) {
		m_data = data;
	}

	void setPosition(Vector2D pos) {
		m_position = pos;
	}

	Vector2D getPosition() {
		return m_position;// -Vector2f(50, 50);
	}

	void setColour(sf::Color col) {
		myColour = col;
	}

	sf::Color getColour() {
		return myColour;
	}

	void setMarked(bool mark) {
		m_marked = mark;
	}

	Arc* getArc(Node* pNode);
	void addArc(Node* pNode, ArcType pWeight);
	void removeArc(Node* pNode);

	void printPrevious(void(*pProcess)(Node*));

	int const & getSearchDistance() const {
		return searchDistance;
	}

	void setSearchDistance(int val) {
		searchDistance = val;
	}

	int const & getHeuristic() const {
		return heuristic;
	}

	void setHeuristic(int val) {
		heuristic = val;
	}


};

// ----------------------------------------------------------------
//  Name:           getArc
//  Description:    This finds the arc in the current node that
//                  points to the node in the parameter.
//  Arguments:      The node that the arc connects to.
//  Return Value:   A pointer to the arc, or 0 if an arc doesn't
//                  exist from this to the specified input node.
// ----------------------------------------------------------------
template<typename NodeType, typename ArcType>
GraphArc<NodeType, ArcType>* GraphNode<NodeType, ArcType>::getArc(Node* pNode) {

	list<Arc>::iterator iter = m_arcList.begin();
	list<Arc>::iterator endIter = m_arcList.end();
	Arc* pArc = 0;

	// find the arc that matches the node
	for (; iter != endIter && pArc == 0; ++iter) {
		if ((*iter).node() == pNode) {
			pArc = &((*iter));
		}
	}

	// returns null if not found
	return pArc;
}


// ----------------------------------------------------------------
//  Name:           addArc
//  Description:    This adds an arc from the current node pointing
//                  to the first parameter, with the second parameter 
//                  as the weight.
//  Arguments:      First argument is the node to connect the arc to.
//                  Second argument is the weight of the arc.
//  Return Value:   None.
// ----------------------------------------------------------------
template<typename NodeType, typename ArcType>
void GraphNode<NodeType, ArcType>::addArc(Node* pNode, ArcType weight) {
	// Create a new arc.
	Arc a;
	a.setNode(pNode);
	a.setWeight(weight);
	// Add it to the arc list.
	m_arcList.push_back(a);
}


// ----------------------------------------------------------------
//  Name:           removeArc
//  Description:    This finds an arc from this node to input node 
//                  and removes it.
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
template<typename NodeType, typename ArcType>
void GraphNode<NodeType, ArcType>::removeArc(Node* pNode) {
	list<Arc>::iterator iter = m_arcList.begin();
	list<Arc>::iterator endIter = m_arcList.end();

	int size = m_arcList.size();
	// find the arc that matches the node
	for (; iter != endIter && m_arcList.size() == size;
		++iter) {
		if ((*iter).node() == pNode) {
			m_arcList.remove((*iter));
		}
	}
}

template<typename NodeType, typename ArcType>
void GraphNode<NodeType, ArcType>::printPrevious(void(*pProcess)(Node*)) 
{
	if (m_previousNode != nullptr) 
	{
		m_previousNode->printPrevious(pProcess);
	}
	pProcess(this);
}

#include "GraphArc.h"

#endif