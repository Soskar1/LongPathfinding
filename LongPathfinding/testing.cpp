#include <cstdio>
#include <list>
#include <set>
#include <iostream>
#include <utility>
#include "Graph.h"
#include "Pathfinding.h"

using namespace Pathfinding;
using namespace Graphs;
using namespace std;

// final result
int result;

// output				
vector<int> output;


void longestPath(int** input, int size) {
	// result: set to the length of the longest path
	// output: node indices (starting at 0) in the longest path; 
	// if many such paths are present, output should be such that it represents
	// the largest multidigital number among those possible
	// heuristic: the longer the path, the better

	struct PathCompare {
		bool operator()(const pair<list<Node*>, size_t>& path1, const pair<list<Node*>, size_t>& path2) const {
			return path1.first.size() > path2.first.size();
		}
	};

	Graph graph(input, size);
	std::vector<Node*> nodes = graph.GetNodes();

	set<pair<list<Node*>, size_t>, PathCompare> paths;

	for (int i = 1; i < size; ++i) {
		auto pathInfo = LongestPathHeuristic(graph, nodes[0], nodes[i]);
		paths.insert(pathInfo);
	}

	auto longestPathInfo = *paths.begin();
	list<Node*> longestPath = longestPathInfo.first;

	for (auto node : longestPath) {
		output.push_back(node->GetID());
	}

	result = longestPathInfo.second;
}

int main() {
	int size = 6;
	int** adjacencyMatrix = new int*[size];
	
	for (int i = 0; i < size; ++i) {
		adjacencyMatrix[i] = new int[size];
	}

	/*
	0 25 0 1 0 0
	0 0 75 0 0 0
	0 0 0 0 0 0
	0 0 0 0 1 0
	0 0 0 0 0 1
	0 0 1 0 0 0
	*/

	adjacencyMatrix[0][1] = 25;
	adjacencyMatrix[0][3] = 1;
	adjacencyMatrix[1][2] = 75;
	adjacencyMatrix[3][4] = 1;
	adjacencyMatrix[4][5] = 1;
	adjacencyMatrix[5][2] = 1;

	longestPath(adjacencyMatrix, size);

	for (int i = 0; i < output.size(); ++i) {
		std::cout << output[i] << " ";
	}
	std::cout << std::endl;
	std::cout << result << std::endl;

	for (int i = 0; i < size; ++i) {
		delete[] adjacencyMatrix[i];
	}

	delete[] adjacencyMatrix;

	return 0;
}