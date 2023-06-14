#ifndef PATHFINDING_H
#define PATHFINDING_H

#include "Graph.h"

#include <vector>
#include <list>
#include <functional>
<<<<<<< Updated upstream
#include <cstdlib>

namespace Pathfinding {
	std::pair<std::list<Graphs::Node*>, size_t> LongestPath(const Graphs::Graph& graph, Graphs::Node* startNode, Graphs::Node* endNode);

	std::pair<std::list<Graphs::Node*>, size_t> LongestPathHeuristic(const Graphs::Graph& graph, Graphs::Node* startNode, Graphs::Node* endNode);
=======
#include <utility>

namespace Pathfinding {
	std::pair<std::list<Graphs::Node*>, int> LongestPath(const Graphs::Graph& graph, Graphs::Node* startNode, Graphs::Node* endNode);

	std::pair<std::list<Graphs::Node*>, int> LongestPathHeuristic(const Graphs::Graph& graph, Graphs::Node* startNode, Graphs::Node* endNode);
>>>>>>> Stashed changes
}
#endif