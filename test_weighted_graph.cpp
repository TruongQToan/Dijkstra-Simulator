#include <iostream>
#include "vertex.h"
#include "undirected_edge.h"
#include "weighted_graph.h"

using namespace std;

int main() {
    WeightedGraph g(2);
    // Test AddEdge() function
    g.AddEdge(0, 1);
    g.AddEdge(1, 0);
    cout << "V = " << g.v() << " E = " << g.e() << endl;
    vector<Vertex> neighbors_before = g.Neighbors(0);
    cout << "Neighbors(0) size = " << neighbors_before.size() << endl;
    for (auto it = neighbors_before.begin(); it != neighbors_before.end(); ++it) {
        cout << "neighbors = " << it -> id() << endl;
    }
    // Test SetEdgeValue() function
    g.SetEdgeValue(0, 1, 2.5);
    cout << "value between 0 and 1 " << g.GetEdgeValue(0, 1) << endl;
    // Test SetNodeValue function
    cout << "value of node 0 before " << g.GetNodeValue(0) << endl;
    g.SetNodeValue(0, 1.5);
    cout << "value of node 0 after " << g.GetNodeValue(0) << endl;
    // Test RemoveEdge() function
    g.RemoveEdge(0, 1);
    cout << "V = " << g.v() << " E = " << g.e() << endl;
    vector<Vertex> neighbors_after = g.Neighbors(0);
    cout << "Neighbors(0) size = " << neighbors_after.size() << endl;
    for (auto it = neighbors_after.begin(); it != neighbors_after.end(); ++it) {
        cout << "neighbors = " << it -> id() << endl;
    }
    return 0;
}

