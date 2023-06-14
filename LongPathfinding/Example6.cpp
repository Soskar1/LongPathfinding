#include <iostream>
#include <vector>

#include "Graph.h"
#include "Pathfinding.h"

int main()
{
	using namespace Graphs;
	using namespace Pathfinding;

	Graph graph({
		{0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},
		{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0},
		{1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
		{1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0},
		{0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0},
		{0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1},
		{0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0},
		{0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1},
		{0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
		});

	std::vector<Node*> nodes = graph.GetNodes();
<<<<<<< Updated upstream
	auto path = LongestPathHeuristic(graph, nodes[0], nodes[10]);
=======
	auto pathInfo = LongestPath(graph, nodes[0], nodes[10]);
	std::list<Node*> path = pathInfo.first;
>>>>>>> Stashed changes

	for (auto node : path.first) {
		std::cout << node->GetID() << " ";
	}

	std::cout << "\nlength: " << path.second;

	return 0;
}