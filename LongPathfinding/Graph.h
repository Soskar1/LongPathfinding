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
		Graph();
		Graph(const std::vector<std::vector<int>>& adjacencyMatrix);

		void AddNode();
		void AddEdge(Node*& firstNode, Node*& secondNode);

		void RemoveNode(Node*& node);
		void RemoveEdge(Node*& firstNode, Node*& secondNode);

		std::vector<Node*> GetNodes() const;
		
		size_t GetAdjacentNodesCount(Node*& node) const;
		std::vector<Node*> GetAdjacentNodes(Node*& node) const;

		size_t GetNodeSize() const;
		size_t GetEdgeSize() const;
	};
}
#endif