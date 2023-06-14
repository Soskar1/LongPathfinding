#include "Pathfinding.h"

#include <queue>
#include <map>
#include <set>

namespace Pathfinding {
	struct Path {
		int currentCost;
		std::vector<bool> visited;
		std::vector<int> distances;
		std::map<Graphs::Node*, Graphs::Node*> cameFrom;

		Path(std::vector<Graphs::Node*> nodes) {
			visited = std::vector<bool>(nodes.size(), false);
			distances = std::vector<int>(nodes.size(), INT_MIN);
			cameFrom = std::map<Graphs::Node*, Graphs::Node*>();
			currentCost = 0;
		}
	};

	struct NodeCompare {
		bool operator()(const std::pair<Graphs::Node*, Path>& node1, const std::pair<Graphs::Node*, Path>& node2) const {
			return node1.second.currentCost < node2.second.currentCost;
		}

		bool operator()(const std::pair<Graphs::Node*, int>& node1, const std::pair<Graphs::Node*, int>& node2) const {
			return node1.second < node2.second;
		}
	};

	struct PathCompare {
		bool operator()(const Path& path1, const Path& path2) const {
			return path1.currentCost > path2.currentCost;
		}
	};

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

<<<<<<< Updated upstream
	std::pair<std::list<Graphs::Node*>, size_t> LongestPath(const Graphs::Graph& graph, Graphs::Node* startNode, Graphs::Node* endNode) {
=======
	std::pair<std::list<Graphs::Node*>, int> LongestPath(const Graphs::Graph& graph, Graphs::Node* startNode, Graphs::Node* endNode) {
>>>>>>> Stashed changes
		using namespace Graphs;

		std::vector<Node*> graphNodes = graph.GetNodes();
		std::set<Path, PathCompare> paths;

		Path graphInfo(graphNodes);
		graphInfo.distances[startNode->GetID()] = 0;

		std::priority_queue<std::pair<Node*, Path>, std::vector<std::pair<Node*, Path>>, NodeCompare> queue;

		queue.push(std::make_pair(startNode, graphInfo));

		while (!queue.empty()) {
			auto pathInfo = queue.top();
			queue.pop();

			if (pathInfo.first == endNode) {
				paths.insert(pathInfo.second);
				continue;
			}

			Node* node = pathInfo.first;
			Path path = pathInfo.second;

			path.visited[node->GetID()] = true;

			auto neighbours = node->GetOutEdges();

			for (auto neighbour : neighbours) {
				Node* neighbourNode = neighbour.first;
				int weight = neighbour.second;

				if (path.visited[neighbourNode->GetID()] && graph.Connected(neighbourNode, node))
					continue;

				int totalCost = path.distances[node->GetID()] + weight;

				if (totalCost > path.distances[neighbourNode->GetID()]) {
					path.distances[neighbourNode->GetID()] = totalCost;
					path.currentCost = totalCost;

					path.cameFrom[neighbourNode] = node;
					queue.push(std::make_pair(neighbourNode, path));
				}
			}
		}

		if (paths.size() != 0) {
			auto path = *paths.begin();
			return std::make_pair(ConstructPath(path.cameFrom, endNode), path.currentCost);
		}
		else {
			return std::make_pair(std::list<Node*>(), 0);
		}
	}

<<<<<<< Updated upstream
	std::pair<std::list<Graphs::Node*>, size_t> LongestPathHeuristic(const Graphs::Graph& graph, Graphs::Node* startNode, Graphs::Node* endNode)
=======
	std::pair<std::list<Graphs::Node*>, int> LongestPathHeuristic(const Graphs::Graph& graph, Graphs::Node* startNode, Graphs::Node* endNode)
>>>>>>> Stashed changes
	{
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

				if (visited[neighbourNode->GetID()] && graph.Connected(neighbourNode, node.first))
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
			return std::make_pair(ConstructPath(cameFrom, endNode), distances[endNode->GetID()]);
		else
			return std::make_pair(std::list<Node*>(), 0);
	}
}