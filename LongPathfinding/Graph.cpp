#include "Graph.h"

#include <cstdlib>
#include <cmath>

namespace Graphs {
	Node::Node(const size_t& id)
	{
		m_ID = id;
	}

	void Node::AddAdjacentNode(Node* node, const int& weight)
	{
		m_AdjacentNodes.push_back(std::make_pair(node, weight));
	}

	std::vector<std::pair<Node*, int>> Node::GetAdjacentNodes() const
	{
		return m_AdjacentNodes;
	}

	size_t Node::GetID() const
	{
		return m_ID;
	}

	Graph::Graph(const std::vector<std::vector<int>>& adjacencyMatrix)
	{
		m_Nodes = std::vector<Node*>(adjacencyMatrix.size());

		for (int i = 0; i < adjacencyMatrix.size(); ++i) {
			m_Nodes[i] = new Node(i);
		}

		for (int i = 0; i < adjacencyMatrix.size(); ++i) {
			for (int j = 0; j < adjacencyMatrix[i].size(); ++j) {
				if (adjacencyMatrix[i][j] != 0) {
					m_Nodes[i]->AddAdjacentNode(m_Nodes[j], adjacencyMatrix[i][j]);
				}
			}
		}
	}

	std::vector<Node*> Graph::GetNodes() const
	{
		return m_Nodes;
	}
}