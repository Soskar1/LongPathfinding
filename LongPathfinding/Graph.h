#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

namespace Graphs {
	class Node {
	private:
		size_t m_ID;
		std::vector<std::pair<Node*, int>> m_AdjacentNodes;
	public:
		Node(const size_t& id);

		void AddAdjacentNode(Node* node, const int& weight);
		std::vector<std::pair<Node*, int>> GetAdjacentNodes() const;

		size_t GetID() const;
	};

	class Graph {
	private:
		std::vector<Node*> m_Nodes;
	public:
		Graph(const std::vector<std::vector<int>>& adjacencyMatrix);

		std::vector<Node*> GetNodes() const;
	};
}
#endif