#ifndef PATHFINDING_H
#define PATHFINDING_H

#include "Graph.h"

#include <vector>
#include <list>
#include <functional>
#include <cstdlib>

namespace Pathfinding {
	std::pair<std::list<Graphs::Node*>, size_t> LongestPath(const Graphs::Graph& graph, Graphs::Node* startNode, Graphs::Node* endNode);

	std::pair<std::list<Graphs::Node*>, size_t> LongestPathHeuristic(const Graphs::Graph& graph, Graphs::Node* startNode, Graphs::Node* endNode);
}
#endif