#include <iostream>
#include <vector>

#include "Graph.h"
#include "Pathfinding.h"

#include <cassert>

int testCounter = 0;

void LongestPathTest(const std::vector<std::vector<int>>& adjacencyMatrix, const size_t& startNode, const size_t& endNode, const std::vector<int>& correctPath) {
	using namespace Graphs;
	using namespace Pathfinding;
	
	std::cout << "TEST " << testCounter << ": ";

	Graph graph(adjacencyMatrix);

	std::vector<Node*> nodes = graph.GetNodes();
	std::list<Node*> path = LongestPath(graph, nodes[startNode], nodes[endNode]);

	std::vector<int> nodeIDs;

	for (auto node : path) {
		nodeIDs.push_back(node->GetID());
		std::cout << node->GetID() << " ";
	}

	assert(path.size() == correctPath.size());

	for (int i = 0; i < correctPath.size(); ++i) {
		assert(nodeIDs[i] == correctPath[i]);
	}

	std::cout << std::endl;
	++testCounter;
}

int main()
{
	LongestPathTest({
		{0, 1, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 0, 0, 0}
		}, 0, 7, { 0, 1, 3, 6, 7 });

	LongestPathTest({
		{0, 1, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 5, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 10},
		{0, 0, 0, 0, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 0, 0, 0}
		}, 0, 7, { 0, 2, 5, 7});

	LongestPathTest({
		{0, 1, 1, 0},
		{0, 0, 0, 1},
		{0, 0, 0, 1},
		{0, 0, 0, 0},
		}, 3, 1, std::vector<int>());

	LongestPathTest({
		{0, 1, 2, 0},
		{0, 0, 4, 5},
		{1, 0, 0, 2},
		{0, 0, 0, 0},
		}, 0, 3, { 0, 1, 2, 3 });

	LongestPathTest({
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{0, 1, 0, 1},
		{0, 0, 0, 0},
		}, 0, 3, { 0, 1, 2, 3 });

	LongestPathTest({
		{0, 1, 0, 0, 0},
		{0, 0, 3, 0, 4},
		{0, 2, 0, 10, 0},
		{0, 0, 1, 0, 4},
		{0, 2, 0, 1, 0},
		}, 0, 4, { 0, 1, 2, 3, 4 });

	LongestPathTest({
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
		}, 0, 10, { 0, 1, 2, 6, 5, 4, 3, 7, 8, 9, 10 });

	LongestPathTest({
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
		}, 0, 1, { 0, 3, 7, 8, 4, 5, 9, 10, 6, 2, 1 });

	return 0;
}