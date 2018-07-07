// The UndirectedEdge class represents a weighted edge in a Graph.
// Each edge consists of two vertices of type Vertex and a real value weight.
// The data type provides methods for accessing the two endpoints 
// of the undirected edge and the weight.

#ifndef _UNDIRECTED_EDGE_
#define _UNDIRECTED_EDGE_
#include "vertex.h"

class UndirectedEdge {
    public:
        // Initializes a directed edge from vertex v1 to vertex v2, weight is set to 0
        UndirectedEdge(const int v1, const int v2) : endpoint1_(Vertex(v1)), endpoint2_(Vertex(v2)), weight_(0) {}
        // Initializes a directed edge from vertex v1 to vertex v2 with the given weight
        UndirectedEdge(const int v1, const int v2, const double weight) : endpoint1_(Vertex(v1)), endpoint2_(Vertex(v2)), weight_(weight) {}
        // Returns one of the endpoint of the edge
        Vertex endpoint1() const;
        // Returns one of the endpoint of the edge
        Vertex endpoint2() const;
        // Returns the other endpoint of the edge given one endpoint
        Vertex OtherVertex(const int v) const;
        // Returns the weight of the edge
        double weight() const;
        // Sets the weight of the edge to w
        void set_weight(const double w);
    private:
        Vertex endpoint1_;
        Vertex endpoint2_;
        double weight_;
};
#endif
