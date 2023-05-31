#include <iostream>
#include <vector>

#include "Graph.h"
#include "Pathfinding.h"

int main()
{
	using namespace Graphs;
	using namespace Pathfinding;

	Graph graph(4);
	std::vector<Node*> nodes = graph.GetNodes();

	graph.AddEdge(nodes[0], nodes[1], 1);
	graph.AddEdge(nodes[0], nodes[2], 1);
	graph.AddEdge(nodes[1], nodes[3], 1);
	graph.AddEdge(nodes[2], nodes[3], 2);

	graph.RemoveNode(nodes[2]);
	nodes = graph.AddNode();

	graph.AddEdge(nodes[0], nodes[2], 1);
	graph.AddEdge(nodes[2], nodes[3], 2);

	graph.AddEdge(nodes[1], nodes[3], 100); //This edge will not be added

	std::list<Node*> path = LongestPath(graph, nodes[0], nodes[3]);

	for (auto node : path) {
		std::cout << node->GetID() << " ";
	}

	return 0;
}