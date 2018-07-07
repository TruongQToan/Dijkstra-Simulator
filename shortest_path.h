// The ShortestPath class represents a data type for solving the 
// single-source shortest paths problem in edge-weighted graph where
// the edge weights are nonnegative.
// This implementation uses Dijkstra's algorithm with a binary heap.
// The constructor takes time proportional to ElogV, where V is the 
// number of vertices and E is the number of edges.
// Each call to distTo(int) has constant time;
// each call to pathTo(int) takes time proportional to the number of edges in
// the shortest path returned.
#ifndef SHORTEST_PATH_H_
#define SHORTEST_PATH_H_
#include <vector>
#include "vertex.h"
#include "undirected_edge.h"
#include "weighted_graph.h"

using namespace std;

class ShortestPath {
    public:
        // Computes a shortest-paths tree from the source vertex s to every other 
        // vertex in the edge-weighted graph G
        ShortestPath(const WeightedGraph& g, const int s);
        // Returns the length of the shortest path from the source vertex s to vertex v
        double DistTo(const int v) const;
        // Returns a shortest path from the source vertex s to vertex v
        vector<int> PathTo(const int v) const;
    private:
        vector<double> dist_to_; // dist_to_[v] = distance of shortest s->v path
        vector<int> edge_to_; // edge_to_[v] = last edge on shortest s->v path
        int s_; // source vertex
};
#endif
