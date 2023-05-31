#include "Pathfinding.h"

#include <queue>
#include <map>
#include <set>

namespace Pathfinding {
	struct GraphInfo {
		std::vector<bool> visited;
		std::vector<int> distances;
		std::map<Graphs::Node*, Graphs::Node*> cameFrom;
		int currentCost;

		GraphInfo(std::vector<Graphs::Node*> nodes) {
			visited = std::vector<bool>(nodes.size(), false);
			distances = std::vector<int>(nodes.size(), INT_MIN);
			cameFrom = std::map<Graphs::Node*, Graphs::Node*>();
			currentCost = 0;
		}
	};

	struct NodeCompare {
		bool operator()(const std::pair<Graphs::Node*, GraphInfo>& node1, const std::pair<Graphs::Node*, GraphInfo>& node2) const {
			return node1.second.currentCost < node2.second.currentCost;
		}
	};

	struct PathCompare {
		bool operator()(const GraphInfo& path1, const GraphInfo& path2) const {
			return path1.currentCost < path2.currentCost;
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
		std::set<GraphInfo, PathCompare> paths;

		GraphInfo graphInfo(graphNodes);
		graphInfo.distances[startNode->GetID()] = 0;

		std::priority_queue<std::pair<Node*, GraphInfo>, std::vector<std::pair<Node*, GraphInfo>>, NodeCompare> queue;

		queue.push(std::make_pair(startNode, graphInfo));

		while (!queue.empty()) {
			auto node = queue.top();
			queue.pop();

			if (node.first == endNode) {
				paths.insert(node.second);
				continue;
			}

			GraphInfo graphInfo = node.second;

			auto neighbours = node.first->GetOutEdges();

			for (auto neighbour : neighbours) {
				Node* neighbourNode = neighbour.first;
				int weight = neighbour.second;

				if (graphInfo.visited[neighbourNode->GetID()] && graph.Connected(neighbourNode, node.first))
					continue;

				int totalCost = graphInfo.distances[node.first->GetID()] + weight;

				if (totalCost > graphInfo.distances[neighbourNode->GetID()]) {
					graphInfo.distances[neighbourNode->GetID()] = totalCost;

					graphInfo.cameFrom[neighbourNode] = node.first;
					queue.push(std::make_pair(neighbourNode, graphInfo));
				}
			}

			graphInfo.visited[node.first->GetID()] = true;
		}

		if (paths.size() != 0) {
			auto graphInfo = *paths.begin();
			return ConstructPath(graphInfo.cameFrom, endNode);
		}
		else {
			return std::list<Node*>();
		}
	}
}