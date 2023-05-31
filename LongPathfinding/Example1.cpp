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
	std::list<Node*> path = LongestPath(graph, nodes[0], nodes[7]);

	for (auto node : path) {
		std::cout << node->GetID() << " ";
	}

	return 0;
}