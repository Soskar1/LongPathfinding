#include <iostream>
#include <vector>

#include "Graph.h"
#include "Pathfinding.h"

int main()
{
	using namespace Graphs;
	using namespace Pathfinding;

	//"Unweighted" Directed Acyclic Graph
	Graph graph({
		{0, 1, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 0, 0, 0}
		});

	std::vector<Node*> nodes = graph.GetNodes();
	auto path = LongestPath(graph, nodes[0], nodes[7]);

	for (auto node : path.first) {
		std::cout << node->GetID() << " ";
	}

<<<<<<< Updated upstream
	std::cout << "\nlength: " << path.second;
=======
	std::cout << "length: " << path.second;
>>>>>>> Stashed changes

	return 0;
}