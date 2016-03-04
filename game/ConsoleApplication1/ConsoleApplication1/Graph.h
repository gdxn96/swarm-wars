#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <queue>

using namespace std;

template <class NodeType, class ArcType> class GraphArc;
template <class NodeType, class ArcType> class GraphNode;

// ----------------------------------------------------------------
//  Name:           Graph
//  Description:    This is the graph class, it contains all the
//                  nodes.
// ----------------------------------------------------------------
template<class NodeType, class ArcType>
class Graph {
private:

	// typedef the classes to make our lives easier.
	typedef GraphArc<NodeType, ArcType> Arc;
	typedef GraphNode<NodeType, ArcType> Node;

	// ----------------------------------------------------------------
	//  Description:    An array of all the nodes in the graph.
	// ----------------------------------------------------------------
	Node** m_pNodes;

	// ----------------------------------------------------------------
	//  Description:    The maximum number of nodes in the graph.
	// ----------------------------------------------------------------
	int m_maxNodes;


	// ----------------------------------------------------------------
	//  Description:    The actual number of nodes in the graph.
	// ----------------------------------------------------------------



public:
	int m_count;
	// Constructor and destructor functions
	Graph(int size);
	~Graph();

	// Accessors
	Node** nodeArray() const {
		return m_pNodes;
	}

	// Public member functions.
	bool addNode(NodeType data, float x, float y, int index);
	void removeNode(int index);
	bool addArc(int from, int to, ArcType weight);
	void removeArc(int from, int to);
	Arc* getArc(int from, int to);
	void clearMarks();
	void depthFirst(Node* pNode, void(*pProcess)(Node*));
	void breadthFirst(Node* pNode, void(*pProcess)(Node*));
	void breadthFirstSearch(Node* pNode, Node* pLastNode, void(*pProcess)(Node*));

	void aStar(Node* pStart, Node* pDest, void(*pProcess)(Node*), std::vector<Node *>& path);

	void ucs(Node* pNode, Node* pLastNode, void(*pVisitFunc)(Node*), std::vector<Node *>& path);
	struct NodeSearchConstCompare
	{
	public:
		bool operator()(Node *n1, Node * n2){
			return n1->getSearchDistance() > n2->getSearchDistance();
		}
	};

	struct AStarConstCompare
	{
	public:
		bool operator()(Node *n1, Node * n2){
			return n1->getSearchDistance() + n1->getHeuristic() > n2->getSearchDistance() + n2->getHeuristic();
		}
	};

	void draw(sf::RenderWindow & window, sf::Font font);
};

// ----------------------------------------------------------------
//  Name:           Graph
//  Description:    Constructor, this constructs an empty graph
//  Arguments:      The maximum number of nodes.
//  Return Value:   None.
// ----------------------------------------------------------------
template<class NodeType, class ArcType>
Graph<NodeType, ArcType>::Graph(int size) : m_maxNodes(size) {
	int i;
	m_pNodes = new Node *[m_maxNodes];
	// go through every index and clear it to null (0)
	for (i = 0; i < m_maxNodes; i++) {
		m_pNodes[i] = 0;
	}

	// set the node count to 0.
	m_count = 0;
}

// ----------------------------------------------------------------
//  Name:           ~Graph
//  Description:    destructor, This deletes every node
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
template<class NodeType, class ArcType>
Graph<NodeType, ArcType>::~Graph() {
	int index;
	for (index = 0; index < m_maxNodes; index++) {
		if (m_pNodes[index] != 0) {
			delete m_pNodes[index];
		}
	}
	// Delete the actual array
	delete m_pNodes;
}

template<class NodeType, class ArcType>
void Graph<NodeType, ArcType>::draw(sf::RenderWindow & window, sf::Font font)
{

	for (int i = 0; i < 19; ++i)
	{

		m_pNodes[i]->draw(window, font);
	}
}

// ----------------------------------------------------------------
//  Name:           addNode
//  Description:    This adds a node at a given index in the graph.
//  Arguments:      The first parameter is the data to store in the node.
//                  The second parameter is the index to store the node.
//  Return Value:   true if successful
// ----------------------------------------------------------------
template<class NodeType, class ArcType>
bool Graph<NodeType, ArcType>::addNode(NodeType data, float x, float y, int index) {
	bool nodeNotPresent = false;
	// find out if a node does not exist at that index.
	if (m_pNodes[index] == 0) {
		nodeNotPresent = true;
		// create a new node, put the data in it, and unmark it.
		m_pNodes[index] = new Node;
		m_pNodes[index]->setData(data);
		m_pNodes[index]->setPosition(Vector2D(x, y));
		m_pNodes[index]->setMarked(false);
		// increase the count and return success.
		m_count++;
	}

	return nodeNotPresent;
}

// ----------------------------------------------------------------
//  Name:           removeNode
//  Description:    This removes a node from the graph
//  Arguments:      The index of the node to return.
//  Return Value:   None.
// ----------------------------------------------------------------
template<class NodeType, class ArcType>
void Graph<NodeType, ArcType>::removeNode(int index) {
	// Only proceed if node does exist.
	if (m_pNodes[index] != 0) {
		// now find every arc that points to the node that
		// is being removed and remove it.
		int node;
		Arc* arc;

		// loop through every node
		for (node = 0; node < m_maxNodes; node++) {
			// if the node is valid...
			if (m_pNodes[node] != 0) {
				// see if the node has an arc pointing to the current node.
				arc = m_pNodes[node]->getArc(m_pNodes[index]);
			}
			// if it has an arc pointing to the current node, then
			// remove the arc.
			if (arc != 0) {
				removeArc(node, index);
			}
		}


		// now that every arc pointing to the current node has been removed,
		// the node can be deleted.
		delete m_pNodes[index];
		m_pNodes[index] = 0;
		m_count--;
	}
}

// ----------------------------------------------------------------
//  Name:           addArd
//  Description:    Adds an arc from the first index to the 
//                  second index with the specified weight.
//  Arguments:      The first argument is the originating node index
//                  The second argument is the ending node index
//                  The third argument is the weight of the arc
//  Return Value:   true on success.
// ----------------------------------------------------------------
template<class NodeType, class ArcType>
bool Graph<NodeType, ArcType>::addArc(int from, int to, ArcType weight) {
	bool proceed = true;
	// make sure both nodes exist.
	if (m_pNodes[from] == 0 || m_pNodes[to] == 0) {
		proceed = false;
	}

	// if an arc already exists we should not proceed
	if (m_pNodes[from]->getArc(m_pNodes[to]) != 0) {
		proceed = false;
	}

	if (proceed == true) {
		// add the arc to the "from" node.
		m_pNodes[from]->addArc(m_pNodes[to], weight);
	}

	return proceed;
}

// ----------------------------------------------------------------
//  Name:           removeArc
//  Description:    This removes the arc from the first index to the second index
//  Arguments:      The first parameter is the originating node index.
//                  The second parameter is the ending node index.
//  Return Value:   None.
// ----------------------------------------------------------------
template<class NodeType, class ArcType>
void Graph<NodeType, ArcType>::removeArc(int from, int to) {
	// Make sure that the node exists before trying to remove
	// an arc from it.
	bool nodeExists = true;
	if (m_pNodes[from] == 0 || m_pNodes[to] == 0) {
		nodeExists = false;
	}

	if (nodeExists == true) {
		// remove the arc.
		m_pNodes[from]->removeArc(m_pNodes[to]);
	}
}


// ----------------------------------------------------------------
//  Name:           getArc
//  Description:    Gets a pointer to an arc from the first index
//                  to the second index.
//  Arguments:      The first parameter is the originating node index.
//                  The second parameter is the ending node index.
//  Return Value:   pointer to the arc, or 0 if it doesn't exist.
// ----------------------------------------------------------------
template<class NodeType, class ArcType>
// Dev-CPP doesn't like Arc* as the (typedef'd) return type?
GraphArc<NodeType, ArcType>* Graph<NodeType, ArcType>::getArc(int from, int to) {
	Arc* pArc = 0;
	// make sure the to and from nodes exist
	if (m_pNodes[from] != 0 && m_pNodes[to] != 0) {
		pArc = m_pNodes[from]->getArc(m_pNodes[to]);
	}

	return pArc;
}


// ----------------------------------------------------------------
//  Name:           clearMarks
//  Description:    This clears every mark on every node.
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
template<class NodeType, class ArcType>
void Graph<NodeType, ArcType>::clearMarks() {
	int index;
	for (index = 0; index < m_maxNodes; index++) {
		if (m_pNodes[index] != 0) {
			m_pNodes[index]->setMarked(false);
			m_pNodes[index]->setColour(sf::Color::Red);
		}
	}
}


// ----------------------------------------------------------------
//  Name:           depthFirst
//  Description:    Performs a depth-first traversal on the specified 
//                  node.
//  Arguments:      The first argument is the starting node
//                  The second argument is the processing function.
//  Return Value:   None.
// ----------------------------------------------------------------
template<class NodeType, class ArcType>
void Graph<NodeType, ArcType>::depthFirst(Node* pNode, void(*pProcess)(Node*)) {
	if (pNode != 0) {
		// process the current node and mark it
		pProcess(pNode);
		pNode->setMarked(true);

		// go through each connecting node
		list<Arc>::iterator iter = pNode->arcList().begin();
		list<Arc>::iterator endIter = pNode->arcList().end();

		for (; iter != endIter; ++iter) {
			// process the linked node if it isn't already marked.
			if ((*iter).node()->marked() == false) {
				depthFirst((*iter).node(), pProcess);
			}
		}
	}
}


// ----------------------------------------------------------------
//  Name:           breadthFirst
//  Description:    Performs a depth-first traversal the starting node
//                  specified as an input parameter.
//  Arguments:      The first parameter is the starting node
//                  The second parameter is the processing function.
//  Return Value:   None.
// ----------------------------------------------------------------
template<class NodeType, class ArcType>
void Graph<NodeType, ArcType>::breadthFirst(Node* pNode, void(*pProcess)(Node*)) {
	if (pNode != 0) {
		queue<Node*> nodeQueue;
		// place the first node on the queue, and mark it.
		nodeQueue.push(pNode);
		pNode->setMarked(true);

		// loop through the queue while there are nodes in it.
		while (nodeQueue.size() != 0) {
			// process the node at the front of the queue.
			pProcess(nodeQueue.front());

			// add all of the child nodes that have not been 
			// marked into the queue
			list<Arc>::const_iterator iter = nodeQueue.front()->arcList().begin();
			list<Arc>::const_iterator endIter = nodeQueue.front()->arcList().end();

			for (; iter != endIter; iter++) {
				if ((*iter).node()->marked() == false) {
					// mark the node and add it to the queue.
					(*iter).node()->setMarked(true);
					nodeQueue.push((*iter).node());
				}
			}

			// dequeue the current node.
			nodeQueue.pop();
		}
	}
}

template<class NodeType, class ArcType>
void Graph<NodeType, ArcType>::breadthFirstSearch(Node* pNode, Node* pLastNode, void(*pProcess)(Node*)) {
	if (pNode != 0)
	{
		v

			// loop through the queue while there are nodes in it.
			while (nodeQueue.size() != 0 && goalReached == false)
			{
				// process the node at the front of the queue.
				//pProcess(nodeQueue.front());

				// add all of the child nodes that have not been 
				// marked into the queue
				list<Arc>::const_iterator iter = nodeQueue.front()->arcList().begin();
				list<Arc>::const_iterator endIter = nodeQueue.front()->arcList().end();

				for (; iter != endIter && goalReached == false; iter++)
				{
					if ((*iter).node() == pLastNode)
					{
						goalReached = true;
						pLastNode->setPreviousNode(nodeQueue.front());
						pLastNode->printPrevious(pProcess);
					}

					if ((*iter).node()->marked() == false)
					{
						(*iter).node()->setPreviousNode(nodeQueue.front());
						// mark the node and add it to the queue.
						(*iter).node()->setMarked(true);
						nodeQueue.push((*iter).node());
					}
				}

				// dequeue the current node.
				nodeQueue.pop();
			}
	}
}

template<class NodeType, class ArcType>
void Graph<NodeType, ArcType>::ucs(Node* pNode, Node* pLastNode, void(*pVisitFunc)(Node*), std::vector<Node *>& path)
{
	if (pNode != 0)
	{
		priority_queue<Node *, vector<Node*>, NodeSearchConstCompare> nodeQueue;
		pNode->setSearchDistance(0);
		for (int i = 0; i < m_count; i++)
		{
			if (m_pNodes[i] != pNode)
			{
				m_pNodes[i]->setSearchDistance(1000000);
			}

			m_pNodes[i]->setPreviousNode(nullptr);
		}

		nodeQueue.push(pNode);
		pNode->setMarked(true);

		while (!nodeQueue.empty() && nodeQueue.top() != pLastNode)
		{
			pVisitFunc(nodeQueue.top());

			list<Arc>::const_iterator iter = nodeQueue.top()->arcList().begin();
			list<Arc>::const_iterator endIter = nodeQueue.top()->arcList().end();

			for (; iter != endIter; iter++)
			{
				if ((*iter).node() != nodeQueue.top()->getPreviousNode())
				{
					int dist = (*iter).weight() + nodeQueue.top()->getSearchDistance();

					if (dist < (*iter).node()->getSearchDistance())
					{
						(*iter).node()->setSearchDistance(dist);


						//iter->node()->setHeuristic(dist * 0.9f);

						(*iter).node()->setPreviousNode(nodeQueue.top());
					}

					if ((*iter).node()->marked() == false)
					{
						nodeQueue.push((*iter).node());
						(*iter).node()->setMarked(true);
					}
				}
			}

			// dequeue the current node.
			nodeQueue.pop();
		}
	}

	Node* currentNode = pLastNode;
	while (currentNode != nullptr)
	{
		path.push_back(currentNode);
		currentNode = currentNode->getPreviousNode();
	}
}

template<class NodeType, class ArcType>
void Graph<NodeType, ArcType>::aStar(Node* pStart, Node* pDest, void(*pProcess)(Node*), std::vector<Node *>& path)
{
	//---------------------------------------how a* works --------------------------------------
	/*a star is a shortest distance algorythem it uses a weight and a heurstic to calculate the best path
	for this the heuristic is the distance from the tested node to the end point(straigh line)
	to explan this further is simple imagine we have 1 node(the start node) connected to 3 other nodes 
	
	        [2]
	        /
	       /weight(200)
	      /
	     /  
        /
	   /
	  /             weight(140)
	[0]------------[1]                                [destination node]
	  \
	   \
	    \weight(100)
		 \
		  [3]
	
	we are at node 0 now, the formula to decide what node to go to next is F = W + H
	W = weight , H = heuristic(distance);

	the F value at node 3 is F = 100 + 300(distace to dest)
	so [3] = 400;

	the F value at node 2 is F = 200 +320(dist)
	so [2] = 520;

	the value at node 1 is F = 140 + 200(dist)
	so [1] = 340;
	
	we want the shortest distance to clearly node 1 is the best choice because 340 < 400,520;
	
	so now we store node [1] into our path list and node [1] becomes or new start, so we loop this process

	         [2]
	        /
	       /weight(200)
	      /
	     /             [5]
        /              /
	   /              /    
	  /              /
	[0]------------[1]                                [destination node]
	 \               \
   	  \               \
	   \weight(100)    \
	    \               \
	    [3]              \
		                  \
		                   \
                           [4]

	as you can see node [1] is connected to node [4] and node [5].

	we keep looping until we get to the destination or run out of node,
	adding each node we move to to the path list
	if we dont get to the destination and run out of nodes then the destination is unreacable 

	gg astar explained like a boos ;)
	*/
	if (pStart != 0)
	{
		/*Priority queues are a type of container adaptors,
		specifically designed such that its first element is always the greatest of the elements it contains,
		according to some strict weak ordering criterion.
		This context is similar to a heap, where elements can be inserted at any moment,
		and only the max heap element can be retrieved (the one at the top in the priority queue).*/
		priority_queue<Node *, vector<Node*>, AStarConstCompare> nodeQueue;
		//AStarConstCompare will find out if node 1's dist+heuristic is greater than node 2; returns a bool
		pStart->setSearchDistance(0);

		//loop through all the nodes on the graph ans set the serchdistance / weight to a rediculious high
		//value and setting previous Node to null ptr. this ensures the algorythem has cleared values to work
		for (int i = 0; i < m_count; i++)
		{
			if (m_pNodes[i] != pStart)
			{
				//dont set start node serch dist or error out
				m_pNodes[i]->setSearchDistance(1000000);
			}

			//set previous node to null
			// the previous node is used to make sure the a* doesnt go back wards onitself when searching
			//
			m_pNodes[i]->setPreviousNode(nullptr);
		}

		//set start node and push it into the prority_queue
		nodeQueue.push(pStart);
		//then mark the start node as true
		pStart->setMarked(true);
		//set the the magnitude of the distance as the Heuristic
		Vector2D dir = pStart->getPosition() - pDest->getPosition();
		pStart->setHeuristic(dir.Magnitude());
		// So now we have a priority queue of one. just the start node with the heuristic set and,
		// the dist of all other node set really hight

		//loop through queue until empty or destination reached
		while (!nodeQueue.empty() && nodeQueue.top() != pDest)
		{
			//print new base node
			//pProcess(nodeQueue.top());

			// make the iterators start and end of arc list
			//arc list is a list of what nodes are a single node conected to,
			//for examle the first node[0] is connected to node[6], node[7] and node[1]
			//the nodes are labbled as node[0] = 1, node[6] = i,node[7] = m, node[1] = 4;	
			list<Arc>::const_iterator iter = nodeQueue.top()->arcList().begin();
			list<Arc>::const_iterator endIter = nodeQueue.top()->arcList().end();

			//loop through base node arcs
			//the search starts here, where all the pretty a* happens
			for (; iter != endIter; iter++)
			{
				//dont count previous node, prevent going backwards
				// only iterate through if current node != top of the queue's previous node
				if ((*iter).node() != nodeQueue.top()->getPreviousNode())
				{
					//get weight and set the distance and heuristic
					int dist = (*iter).weight() + nodeQueue.top()->getSearchDistance();
					int heuristic = nodeQueue.top()->getHeuristic();


					//if queue node weight is less than currentNodeWeight
					if (dist + heuristic < (*iter).node()->getSearchDistance() + (*iter).node()->getHeuristic())
					{
						//set the current node's distance
						(*iter).node()->setSearchDistance(dist);

						//set A* heuristic
						dir = iter->node()->getPosition() - pDest->getPosition();
						// set the heuristic to the magnitude of the distance between,
						//the current node to the destination
						iter->node()->setHeuristic(dir.Magnitude());
						//then set the previous node
						(*iter).node()->setPreviousNode(nodeQueue.top());
					}
					//return if the current node is marked
					if ((*iter).node()->marked() == false)
					{
						//if not marked then push to priority queue
						nodeQueue.push((*iter).node());
						//then set it to marked
						(*iter).node()->setMarked(true);
					}
				}
			}

			// dequeue the current node.
			nodeQueue.pop();
		}
	}
	//create a node pointer set it to the destination node
	Node* currentNode = pDest;
	while (currentNode != nullptr)
	{
		//while the destination node is not null
		//push current node into path list and loop back using the pointer to previous
		path.push_back(currentNode);
		//the loop will stop when it hits the start node as its previous pointer will be null
		currentNode = currentNode->getPreviousNode();
	}
}

#include "GraphNode.h"
#include "GraphArc.h"


#endif
