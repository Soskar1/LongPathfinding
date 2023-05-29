#include <iostream>
#include <vector>

#include "Graph.h"

void PrintGraph(const Graphs::Graph& graph) {
	auto nodes = graph.GetNodes();

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

int main()
{
	using namespace Graphs;

	Graph graph(5);

	std::vector<Node*> nodes = graph.GetNodes();
	graph.AddEdge(nodes[0], nodes[1], 2);
	graph.AddEdge(nodes[1], nodes[0], 4);
	graph.AddEdge(nodes[1], nodes[2], 1);
	graph.AddEdge(nodes[1], nodes[3], 3);
	graph.AddEdge(nodes[0], nodes[4], 0);
	graph.AddEdge(nodes[3], nodes[4], 0);

	graph.RemoveEdge(nodes[3], nodes[4]);
	graph.RemoveNode(nodes[1]);

	PrintGraph(graph);

	return 0;
}