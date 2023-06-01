#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Graph.h"
#include "Pathfinding.h"
#include "Experimentator.h"

#define GRAPH_SIZE 1000
#define MAX_COST 100

std::vector<std::vector<int>> GenerateAdjacencyMatrix() {
	std::vector<std::vector<int>> adjacencyMatrix(GRAPH_SIZE, std::vector<int>(GRAPH_SIZE, 0));

	for (int i = 0; i < GRAPH_SIZE; ++i) {
		int randomNodeIndex = 0;

		do {
			randomNodeIndex = rand() % GRAPH_SIZE;
		} while (randomNodeIndex == i || adjacencyMatrix[i][randomNodeIndex] != 0);

		int randomCost = 1 + rand() % MAX_COST;

		adjacencyMatrix[i][randomNodeIndex] = randomCost;
		adjacencyMatrix[randomNodeIndex][i] = randomCost;
	}

	return adjacencyMatrix;
}

Graphs::Graph CreateGraph() {
	auto adjacencyMatrix = GenerateAdjacencyMatrix();

	return Graphs::Graph(adjacencyMatrix);
}

int main() {
	using namespace Graphs;
	using namespace Pathfinding;

	srand((unsigned)time(NULL));

	Graph graph = CreateGraph();

	float time = 0;
	Node* startNode = graph.GetNodes()[0];
	Node* endNode = graph.GetNodes()[0];

	time = GetAverageExecutionTime(
		[&graph, &startNode, &endNode]() {
			LongestPath(graph, startNode, endNode);
		},
		[&graph, &startNode, &endNode]() {
			auto nodes = graph.GetNodes();
			startNode = nodes[rand() % GRAPH_SIZE];

			do {
				endNode = nodes[rand() % GRAPH_SIZE];
			} while (endNode == startNode);
		}
		);

	std::cout << "LongestPath average time: " << time << " ms\n";

	time = GetAverageExecutionTime(
		[&graph, &startNode, &endNode]() {
			LongestPathHeuristic(graph, startNode, endNode);
		},
		[&graph, &startNode, &endNode]() {
			auto nodes = graph.GetNodes();
			startNode = nodes[rand() % GRAPH_SIZE];

			do {
				endNode = nodes[rand() % GRAPH_SIZE];
			} while (endNode == startNode);
		}
		);

	std::cout << "LongestPathHeuristic average time: " << time << " ms\n";

	return 0;
}