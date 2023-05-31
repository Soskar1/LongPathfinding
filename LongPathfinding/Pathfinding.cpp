#include "Pathfinding.h"

#include <queue>
#include <map>

namespace Pathfinding {
	struct NodeCompare {
		bool operator()(const std::pair<Graphs::Node*, int>& node1, const std::pair<Graphs::Node*, int>& node2) {
			return node1.second < node2.second;
		}
	};

	bool FindCycle(const Graphs::Graph& graph, std::map<Graphs::Node*, Graphs::Node*>& cameFrom, Graphs::Node* source) {
		using namespace Graphs;

		Node* tmp = source;

		while (cameFrom.find(tmp) != cameFrom.end()) {
			tmp = cameFrom[tmp];

			if (graph.Connected(tmp, source)) {
				return true;
			}
		}

		return false;
	}

	std::list<Graphs::Node*> ConstructPath(std::map<Graphs::Node*, Graphs::Node*>& cameFrom, Graphs::Node* endNode) {
		using namespace Graphs;

		std::list<Node*> path;

		Node* tmp = endNode;
		path.push_front(endNode);
		while (cameFrom.find(tmp) != cameFrom.end()) {
			tmp = cameFrom[tmp];
			path.push_front(tmp);
		}

		return path;
	}

	std::list<Graphs::Node*> LongestPath(const Graphs::Graph& graph, Graphs::Node* startNode, Graphs::Node* endNode) {
		using namespace Graphs;

		std::vector<Node*> graphNodes = graph.GetNodes();
		std::vector<bool> visited(graphNodes.size(), false);
		std::vector<int> distances(graphNodes.size(), INT_MIN);
		std::map<Node*, Node*> cameFrom;

		std::priority_queue<std::pair<Node*, int>, std::vector<std::pair<Node*, int>>, NodeCompare> queue;

		distances[startNode->GetID()] = 0;

		queue.push(std::make_pair(startNode, 0));

		while (!queue.empty()) {
			auto node = queue.top();
			queue.pop();

			if (node.first == endNode) {
				continue;
			}

			auto neighbours = node.first->GetOutEdges();

			for (auto neighbour : neighbours) {
				Node* neighbourNode = neighbour.first;
				int weight = neighbour.second;

				if (graph.Connected(neighbourNode, node.first))
					continue;

				int totalCost = distances[node.first->GetID()] + weight;

				if (totalCost > distances[neighbourNode->GetID()]) {
					distances[neighbourNode->GetID()] = totalCost;

					cameFrom[neighbourNode] = node.first;
					queue.push(std::make_pair(neighbourNode, totalCost));
				}
			}

			visited[node.first->GetID()] = true;
		}

		if (cameFrom.find(endNode) != cameFrom.end())
			return ConstructPath(cameFrom, endNode);
		else
			return std::list<Node*>();
	}
}