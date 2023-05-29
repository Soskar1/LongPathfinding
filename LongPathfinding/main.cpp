#include <iostream>
#include <vector>

#include "Graph.h"
#include "Pathfinding.h"

void PrintNodes(const std::vector<Graphs::Node*>& nodes) {
	for (auto node : nodes) {
		int id = node->GetID();
		auto outEdges = node->GetOutEdges();
		auto inEdges = node->GetInEdges();

		std::cout << id << ":\n";
		std::cout << "  outEdges:\n";
		for (auto edge : outEdges) {
			std::cout << "\t" << id << " -> " << edge.first->GetID() << ": " << edge.second << std::endl;
		}

		std::cout << "  inEdges:\n";
		for (auto edge : inEdges) {
			std::cout << "\t" << edge->GetID() << " -> " << id << std::endl;
		}
	}
}

void PrintGraph(const Graphs::Graph& graph) {
	auto nodes = graph.GetNodes();

	PrintNodes(nodes);
}

int main()
{
	using namespace Graphs;
	using namespace Pathfinding;

	Graph graph({
		{0, 6, 5, 3, 0},
		{0, 0, -8, 1, 2},
		{7, 0, 0, 4, 0},
		{0, 5, 0, 0, 8},
		{0, 5, 0, -2, 0}
		});

	std::vector<Node*> nodes = graph.GetNodes();
	std::vector<int> path = LongestPath(graph, nodes[0], nodes[4]);

	for (auto step : path) {
		std::cout << step << " ";
	}

	return 0;
}