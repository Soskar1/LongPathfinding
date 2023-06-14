#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <string.h>
#include <vector>


// other includes and definitions
#include "Graph.h"
#include "Pathfinding.h"
#include <set>

using namespace Graphs;
using namespace Pathfinding;
using namespace std;


// throw the following class if function is not implemented
class NotImplementedException {
};

// final result
int result;

// output				
vector<int> output;




void hamiltonianCycle(int** input, int size) {
	// result: set to size if hamiltonian cycle exists, and to 0 otherwise	
	// output: node indices (starting at 0) in the hamiltonian cycle; 
	// if many cycles are present, output should be such that it represents
	// the largest multidigital number among those possible
	// heuristic: the longer the cycle, the better
	/* YOUR CODE HERE */
	throw NotImplementedException();
}
void largestClique(int** input, int size) {
	// result: set to the size of the largest clique
	// output: node indices (starting at 0) in the largest clique in a descending order; 
	// if many such cliques are present, output should be such that it represents
	// the largest multidigital number among those possible
	// heuristic: the larger the clique, the better
	/* YOUR CODE HERE */
	throw NotImplementedException();
}
void dominatingSet(int** input, int size) {
	// result: set to the size of the minimum dominating set
	// output: node indices (starting at 0) in the minimum dominating set in a descending order; 
	// if many such sets are present, output should be such that it represents
	// the largest multidigital number among those possible
	// heuristic: the smaller the set, the better
	/* YOUR CODE HERE */
	throw NotImplementedException();
}
void independentSet(int** input, int size) {
	// result: set to the size of the maximum independent set
	// output: node indices (starting at 0) in the maximum independent set in a descending order; 
	// if many such sets are present, output should be such that it represents
	// the largest multidigital number among those possible
	// heuristic: the larger the set, the better
	/* YOUR CODE HERE */
	throw NotImplementedException();
}
void vertexCover(int** input, int size) {
	// result: set to the size of the minimum vertex cover
	// output: node indices (starting at 0) in the minimum vertex cover in a descending order; 
	// if many such covers are present, output should be such that it represents
	// the largest multidigital number among those possible
	// heuristic: the smaller the cover, the better
	/* YOUR CODE HERE */
	throw NotImplementedException();
}
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
	vector<Node*> nodes = graph.GetNodes();

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
void intersectionNumber(int** input, int size) {
	// result: set to the intersection number (edge clique cover number)
	// output: clique sizes that cover the graph, in a descending order
	// heuristic: the smaller the number, the better
	/* YOUR CODE HERE */
	throw NotImplementedException();
}
void vertexColoring(int** input, int size) {
	// result: set to the chromatic number
	// output: numbers of vertices colored in each color, in a descending order;
	// if many such colorings are possible, output should be such that it represents
	// the largest multidigital number among those possible
	// heuristic: the smaller the number, the better
	/* YOUR CODE HERE */
	throw NotImplementedException();
}
void edgeColoring(int** input, int size) {
	// result: set to the chromatic index
	// output: numbers of edges colored in each color, in a descending order;
	// if many such colorings are possible, output should be such that it represents
	// the largest multidigital number among those possible
	// heuristic: the smaller the index, the better	
	/* YOUR CODE HERE */
	throw NotImplementedException();
}





/* DO NOT MODIFY CODE BELOW */

int main() {
	try {

		int x = -1;
		while (1) {
			cin >> x;
			if (x == 0) {
				break;
			}
			else {
				int n;
				cin >> n;
				int** input = new int* [n];
				for (int i = 0; i < n; ++i) {
					input[i] = new int[n];
				}
				for (int i = 0; i < n; ++i) {
					for (int j = 0; j < n; ++j) {
						cin >> input[i][j];
					}
				}
				switch (x) {
				case 1:
					hamiltonianCycle(input, n);
					break;
				case 2:
					largestClique(input, n);
					break;
				case 3:
					dominatingSet(input, n);
					break;
				case 4:
					independentSet(input, n);
					break;
				case 5:
					vertexCover(input, n);
					break;
				case 6:
					longestPath(input, n);
					break;
				case 7:
					intersectionNumber(input, n);
					break;
				case 8:
					vertexColoring(input, n);
					break;
				case 9:
					edgeColoring(input, n);
					break;
				}
				cout << result << endl;
				for (unsigned int i = 0; i < output.size(); ++i) {
					cout << output[i] << " ";
				}
				cout << endl;


				for (int i = 0; i < n; ++i) {
					delete[] input[i];
				}
				delete[] input;

			}
		}
	}
	catch (NotImplementedException& e) {
		return 2018;
	}
	catch (...) {
		return -1;
	}
	return 0;
}