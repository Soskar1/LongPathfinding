#include "Graph.h"

#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>

namespace Graphs {
	Node::Node(const size_t& id)
	{
		m_ID = id;
	}

	Node::~Node()
	{
		for (auto node : m_OutEdges) {
			node.first->RemoveInEdge(this);
		}

		m_OutEdges.clear();
		
		for (auto node : m_InEdges) {
			node->RemoveOutEdge(this);
		}

		m_InEdges.clear();
	}

	void Node::AddInEdge(Node* node)
	{
		m_InEdges.push_back(node);
	}

	void Node::RemoveInEdge(Node* node)
	{
		for (auto it = m_InEdges.begin(); it != m_InEdges.end(); ++it) {
			if (*it == node) {
				m_InEdges.erase(it);
				break;
			}
		}
	}

	void Node::AddOutEdge(Node* node, const int& weight)
	{
		m_OutEdges.push_back(std::make_pair(node, weight));
	}

	void Node::RemoveOutEdge(Node* node)
	{
		for (auto it = m_OutEdges.begin(); it != m_OutEdges.end(); ++it) {
			if (it->first == node) {
				m_OutEdges.erase(it);
				break;
			}
		}
	}

	std::vector<Node*> Node::GetInEdges() const
	{
		return m_InEdges;
	}

	std::vector<std::pair<Node*, int>> Node::GetOutEdges() const
	{
		return m_OutEdges;
	}

	std::vector<Node*> Node::GetAdjacentNodes() const
	{
		std::vector<Node*> nodes(m_InEdges);
		for (int i = 0; i < m_OutEdges.size(); ++i) {
			nodes.push_back(m_OutEdges[i].first);
		}

		nodes.erase(std::unique(nodes.begin(), nodes.end()), nodes.end());

		return nodes;
	}

	size_t Node::GetID() const
	{
		return m_ID;
	}

	Graph::Graph()
	{
		m_Nodes = std::vector<Node*>();
		m_EdgeSize = 0;
		m_NodeSize = 0;
	}

	Graph::Graph(const size_t& size)
	{
		for (int i = 0; i < size; ++i) {
			m_Nodes.push_back(new Node(i));
		}

		m_EdgeSize = 0;
		m_NodeSize = size;
	}

	Graph::Graph(const std::vector<std::vector<int>>& adjacencyMatrix)
	{
		m_Nodes = std::vector<Node*>(adjacencyMatrix.size());
		m_EdgeSize = 0;
		m_NodeSize = adjacencyMatrix.size();

		Create(adjacencyMatrix);
	}

	Graph::Graph(int** adjacencyMatrix, const int& size)
	{
		m_Nodes = std::vector<Node*>(size);
		std::vector<std::vector<int>> tmpAdjacencyMatrix(size, std::vector<int>(size));
		m_NodeSize = size;
		m_EdgeSize = 0;

		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				tmpAdjacencyMatrix[i][j] = adjacencyMatrix[i][j];
			}
		}

		Create(tmpAdjacencyMatrix);
	}

	Graph::~Graph()
	{
		for (auto node : m_Nodes) {
			delete node;
		}

		m_Nodes.clear();
	}

	void Graph::Create(const std::vector<std::vector<int>>& adjacencyMatrix)
	{
		for (int i = 0; i < adjacencyMatrix.size(); ++i) {
			m_Nodes[i] = new Node(i);
		}

		for (int i = 0; i < adjacencyMatrix.size(); ++i) {
			for (int j = 0; j < adjacencyMatrix[i].size(); ++j) {
				if (adjacencyMatrix[i][j] != 0) {
					AddEdge(m_Nodes[i], m_Nodes[j], adjacencyMatrix[i][j]);
				}
			}
		}
	}

	std::vector<Node*> Graph::AddNode()
	{
		Node* node;
		size_t id = m_Nodes.size();

		for (size_t i = 0; i < m_Nodes.size(); ++i) {
			if (m_Nodes[i] == nullptr) {
				id = i;
				break;
			}
		}

		node = new Node(id);
		
		if (id != m_Nodes.size()) {
			m_Nodes[id] = node;
		}
		else {
			m_Nodes.push_back(node);
		}

		++m_NodeSize;
		return m_Nodes;
	}

	void Graph::AddEdge(Node* startNode, Node* endNode, const size_t& weight)
	{
		if (Connected(startNode, endNode))
			return;

		startNode->AddOutEdge(endNode, weight);
		endNode->AddInEdge(startNode);
		++m_EdgeSize;
	}

	void Graph::RemoveNode(Node*& node)
	{
		for (auto it = m_Nodes.begin(); it != m_Nodes.end(); ++it) {
			if (*it == node) {
				m_EdgeSize -= node->GetInEdges().size() + node->GetOutEdges().size();

				delete* it;
				*it = nullptr;
				break;
			}
		}

		node = nullptr;
		--m_NodeSize;
	}

	void Graph::RemoveEdge(Node* startNode, Node* endNode)
	{
		startNode->RemoveOutEdge(endNode);
		endNode->RemoveInEdge(startNode);
		--m_EdgeSize;
	}

	std::vector<Node*> Graph::GetNodes() const
	{
		return m_Nodes;
	}

	size_t Graph::GetAdjacentNodesSize(Node* node) const
	{
		return node->GetAdjacentNodes().size();
	}

	std::vector<Node*> Graph::GetAdjacentNodes(Node* node) const
	{
		return node->GetAdjacentNodes();
	}

	size_t Graph::GetNodeSize() const
	{
		return m_NodeSize;
	}

	size_t Graph::GetEdgeSize() const
	{
		return m_EdgeSize;
	}

	bool Graph::Connected(Node* startNode, Node* endNode) const
	{
		auto endNodeInEdges = endNode->GetInEdges();
		for (auto it = endNodeInEdges.begin(); it != endNodeInEdges.end(); ++it) {
			if (*it == startNode) {
				return true;
			}
		}

		return false;
	}
}