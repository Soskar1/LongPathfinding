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
		/*
			Create a node with specific ID

			@param id — node id
		*/
		Node(const size_t& id);
		~Node();

		/*
			Adds a reference to the node from which an edge was created with this node

			@param node — the node that will be added to the reference vector
		*/
		void AddInEdge(Node* node);

		/*
			Removes a reference to the node from which an edge was created with this node

			@param node — the node that will be added to the reference vector
		*/
		void RemoveInEdge(Node* node);

		/*
			Adds a node reference that points to this node

			@param node — the node that will be added to the reference vector
		*/

		/*
			Adds a reference to the end node of an edge with the weight to which
			this node is linked 

			@param node — the node that will be added to the reference vector
			@param weight — edge weight
		*/
		void AddOutEdge(Node* node, const int& weight);

		/*
			Removes a reference to the end node of an edge with the weight to which
			this node is linked

			@param node — the node to remove
		*/
		void RemoveOutEdge(Node* node);


		/*
			@return all nodes that are pointing to this node
		*/
		std::vector<Node*> GetInEdges() const;

		/*
			@return all nodes that this node is pointing to
		*/
		std::vector<std::pair<Node*, int>> GetOutEdges() const;

		/*
			@return all node references, that are connected to this node
		*/
		std::vector<Node*> GetAdjacentNodes() const;

		/*
			@return node id
		*/
		size_t GetID() const;
	};

	class Graph {
	private:
		std::vector<Node*> m_Nodes;
		size_t m_EdgeSize;
		size_t m_NodeSize;
	public:
		//Creates an empty directed weighted graph
		Graph();

		/*
			Creates a directed weighted graph with a specific number of vertices

			@param size — number of vertices
		*/
		Graph(const size_t& size);

		/*
			Creates a directed weighted graph using adjacency matrix. 0 in adjacency
			matrix means that there will not be edge between two specific nodes.
			Other numbers in the matrix will create edges with weights

			@param adjacencyMatrix — 2D array that represents how nodes are connected
		*/
		Graph(const std::vector<std::vector<int>>& adjacencyMatrix);
		~Graph();

		/*
			Adds an empty node to the graph

			@return array of graph nodes
		*/
		std::vector<Node*> AddNode();

		/*
			Adds directed weighted edge from one node to another. If no weight is
			specified, an edge with weight 0 will be created. If the nodes are
			connected, no edge will be added

			@param startNode — the node from which the edge will be created
			@param endNode — the node to which the edge will be directed
		*/
		void AddEdge(Node* startNode, Node* endNode, const size_t& weight = 0);

		/*
			Removes a node from the graph and removes all edges that are connected
			to that node

			@param node — node to delete
		*/
		void RemoveNode(Node*& node);

		/*
			Removes a directed edge between two nodes from the graph

			@param startNode — the node from which the edge was created
			@param endNode — the node to which the edge is directed
		*/
		void RemoveEdge(Node* startNode, Node* endNode);


		/*
			@return array of graph nodes
		*/
		std::vector<Node*> GetNodes() const;
		
		/*
			@param node — the node for which you want to know the number of neighbouring nodes

			@return number of the adjacent nodes
		*/
		size_t GetAdjacentNodesSize(Node* node) const;

		/*
			@param node — the node for which you want to know the neighbouring nodes

			@return 2D array of the adjacent nodes
		*/
		std::vector<Node*> GetAdjacentNodes(Node* node) const;

		/*
			@return Number of nodes in the graph
		*/
		size_t GetNodeSize() const;

		/*
			@return Number of edges in the graph
		*/
		size_t GetEdgeSize() const;


		/*
			Helper function to determine if the nodes are connected in the directed graph
			
			@param startNode — the node from which the edge is possibly created
			@param endNode — the node to which the edge is possibly directed
			
			@return true — if nodes are connected in the directed graph
			@return false — if nodes are not connected in the directed graph
		*/
		bool Connected(Node* startNode, Node* endNode) const;
	};
}
#endif