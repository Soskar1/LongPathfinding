#ifndef PATHFINDING_H
#define PATHFINDING_H

#include "Graph.h"

#include <vector>
#include <list>
#include <functional>

namespace Pathfinding {
	std::list<Graphs::Node*> LongestPath(const Graphs::Graph& graph, Graphs::Node* startNode, Graphs::Node* endNode);

	std::list<Graphs::Node*> LongestPathHeuristic(const Graphs::Graph& graph, Graphs::Node* startNode, Graphs::Node* endNode);
}
#endif