#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

namespace Graphs {
	class Node {
	private:
		size_t m_ID;
		std::vector<std::pair<Node*, int>> m_OutEdges;
		std::vector<Node*> m_InEdges;
	public:
		Node(const size_t& id);
		~Node();

		void AddInEdge(Node* node);
		void RemoveInEdge(Node* node);

		void AddOutEdge(Node* node, const int& weight);
		void RemoveOutEdge(Node* node);

		std::vector<Node*> GetInEdges() const;
		std::vector<std::pair<Node*, int>> GetOutEdges() const;

		std::vector<Node*> GetAdjacentNodes() const;

		size_t GetID() const;
	};

	class Graph {
	private:
		std::vector<Node*> m_Nodes;
	public:
		Graph();
		Graph(const size_t& size);
		Graph(const std::vector<std::vector<int>>& adjacencyMatrix);
		~Graph();

		void AddNode();
		void AddEdge(Node* startNode, Node* endNode, const size_t& weight = 0);

		void RemoveNode(Node* node);
		void RemoveEdge(Node* startNode, Node* endNode);

		std::vector<Node*> GetNodes() const;
		
		size_t GetAdjacentNodesSize(Node* node) const;
		std::vector<Node*> GetAdjacentNodes(Node* node) const;

		size_t GetNodeSize() const;
		size_t GetEdgeSize() const;

		bool Connected(Node* startNode, Node* endNode);
	};
}
#endif