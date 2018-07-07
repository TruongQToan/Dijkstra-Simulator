// The WeightedGraph represents a edge-weighted graph of vertices name through 0 to V.
// Each edge is of type UndirectedEdge and has a real-valued weight.
// It supports the following two primary operations:
//      + add an edge to the graph
//      + iterate over all of edges incident from a given vertex
// It also provides methods for returning the number of vertices V and the number of edges E
// and the methods to check if two vertices are neighbors, remove edge, set edge and node values
// Parallel edges and self-loop are permitted
// This implementation uses and adjacency-lists representation.
#ifndef _WEIGHTED_GRAPH_
#define _WEIGHTED_GRAPH_
#include <vector>
#include <utility>
#include "vertex.h"
#include "undirected_edge.h"

using namespace std;

class WeightedGraph {
    public:
        // Initializes an empty edge-weighted graph with V vertices and 0 edges
        WeightedGraph(const int v) : v_(v), e_(0) {
            for (int i = 0; i < v; i++) {
                adj_.push_back(make_pair(Vertex(i), vector<UndirectedEdge>()));
            }
        };
        // Returns the number of vertices in the graph
        int v() const;
        // Returns the number of edges in the graph
        int e() const;
        // Tests whether there is an edge from vertex v1 to vertex v2
        bool Adjacent(const int v1, const int v2) const;
        // Lists all adjacent edges of vertex v
        vector<UndirectedEdge> Adjacent(const int v) const;
        // Lists all vetex u such that there is an edge from vertex v to vertex u
        vector<Vertex> Neighbors(const int v) const;
        // Adds to the graph the edge from v1 to v2; if it is not there
        void AddEdge(const int v1, const int v2);
        // Removes the edge from v1 to v2; if it is there
        void RemoveEdge(const int v1, const int v2);
        // Returns the value associated with the node v
        double GetNodeValue(const int v) const;
        // Sets the value associated with the node v to value
        void SetNodeValue(const int v, const double value);
        // Returns the value associated with the edge (v1, v2)
        double GetEdgeValue(const int v1, const int v2) const;
        // Sets the value associated with the edge (v1, v2) to w
        void SetEdgeValue(const int v1, const int v2, const double w);
    private:
        int v_; // number of vertices in this graph
        int e_; // number of edges in this graph
        vector<pair<Vertex, vector<UndirectedEdge> > > adj_; // adj[v] = pair(vertex v, adjacency list for vertex v)
};
#endif
