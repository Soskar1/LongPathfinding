#include <iostream>
#include <vector>

#include "Graph.h"
#include "Pathfinding.h"

int main()
{
	using namespace Graphs;
	using namespace Pathfinding;

	Graph graph({
		{0, 1, 2, 0},
		{0, 0, 4, 5},
		{1, 0, 0, 2},
		{0, 0, 0, 0},
		});

	std::vector<Node*> nodes = graph.GetNodes();
	auto path = LongestPath(graph, nodes[0], nodes[3]);

	for (auto node : path.first) {
		std::cout << node->GetID() << " ";
	}

	std::cout << "\nlength: " << path.second;

	return 0;
}