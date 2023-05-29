#include "Graph.h"

#include <cstdlib>
#include <cmath>
#include <algorithm>

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

	size_t Node::GetID() const
	{
		return m_ID;
	}

	Graph::Graph()
	{
		m_Nodes = std::vector<Node*>();
	}

	Graph::Graph(const size_t& size)
	{
		for (int i = 0; i < size; ++i) {
			m_Nodes.push_back(new Node(i));
		}
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
					AddEdge(m_Nodes[i], m_Nodes[j], adjacencyMatrix[i][j]);
				}
			}
		}
	}

	Graph::~Graph()
	{
		for (auto node : m_Nodes) {
			delete node;
		}

		m_Nodes.clear();
	}

	void Graph::AddNode()
	{
		Node* node = new Node(m_Nodes.size());
		m_Nodes.push_back(node);
	}

	void Graph::AddEdge(Node* startNode, Node* endNode, const size_t& weight)
	{
		auto outEdges = startNode->GetOutEdges();

		for (auto edge : outEdges) {
			if (edge.first == endNode) {
				return;
			}
		}

		startNode->AddOutEdge(endNode, weight);
		endNode->AddInEdge(startNode);
	}

	void Graph::RemoveNode(Node* node)
	{
		for (auto it = m_Nodes.begin(); it != m_Nodes.end(); ++it) {
			if (*it == node) {
				m_Nodes.erase(it);
				break;
			}
		}

		delete node;
	}

	void Graph::RemoveEdge(Node* startNode, Node* endNode)
	{
		startNode->RemoveOutEdge(endNode);
		endNode->RemoveInEdge(startNode);
	}

	std::vector<Node*> Graph::GetNodes() const
	{
		return m_Nodes;
	}
}