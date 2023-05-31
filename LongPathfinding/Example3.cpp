#include <iostream>
#include <vector>

#include "Graph.h"
#include "Pathfinding.h"

int main()
{
	using namespace Graphs;
	using namespace Pathfinding;

	Graph graph({
		{0, 1, 1, 0},
		{0, 0, 0, 1},
		{0, 0, 0, 1},
		{0, 0, 0, 0},
		});

	std::vector<Node*> nodes = graph.GetNodes();
	std::list<Node*> path = LongestPath(graph, nodes[3], nodes[1]);

	for (auto node : path) {
		std::cout << node->GetID() << " ";
	}

	return 0;
}