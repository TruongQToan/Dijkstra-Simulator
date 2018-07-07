#include <iostream>
#include <vector>
#include <utility>
#include "vertex.h"
#include "undirected_edge.h"
#include "weighted_graph.h"

using namespace std;

int WeightedGraph::v() const {
    return v_;
}

int WeightedGraph::e() const {
    return e_;
}

bool WeightedGraph::Adjacent(const int v1, const int v2) const {
    vector<UndirectedEdge> neighbors = adj_.at(v1).second;
    for (auto it = neighbors.begin(); it != neighbors.end(); ++it) {
        if ((it->OtherVertex(v1)).id() == v2) return true;
    }
    return false;
}

vector<UndirectedEdge> WeightedGraph::Adjacent(const int v) const {
    return adj_.at(v).second;
}

// This function will return a new results object for each call, so be careful
vector<Vertex> WeightedGraph::Neighbors(const int v) const {
    vector<Vertex> results;
    vector<UndirectedEdge> neighbors = adj_.at(v).second;
    for (auto it = neighbors.begin(); it != neighbors.end(); ++it) {
        results.push_back(it->OtherVertex(v));
    }
    return results;
}

void WeightedGraph::AddEdge(const int v1, const int v2) {
    // If there is already an edge between v1 and v2, do not add the new add between them
    if (Adjacent(v1, v2)) return;
    UndirectedEdge e(v1, v2);
    adj_.at(v1).second.push_back(e);
    adj_.at(v2).second.push_back(e);
    ++e_;
}

void WeightedGraph::RemoveEdge(const int v1, const int v2) {
    vector<UndirectedEdge> neighbors1 = adj_.at(v1).second;
    for (auto it = neighbors1.begin(); it != neighbors1.end(); ++it) {
        if ((it->OtherVertex(v1)).id() == v2) {
            adj_.at(v1).second.erase(it);
            break;
        }
    }
    vector<UndirectedEdge> neighbors2 = adj_.at(v2).second;
    for (auto it = neighbors2.begin(); it != neighbors2.end(); ++it) {
        if ((it->OtherVertex(v1)).id() == v1) {
            adj_.at(v2).second.erase(it);
            break;
        }
    }
    --e_;
}

void WeightedGraph::SetNodeValue(const int v, const double value) {
    adj_.at(v).first.set_value(value);
}

double WeightedGraph::GetNodeValue(const int v) const {
    return adj_.at(v).first.value();
}

double WeightedGraph::GetEdgeValue(const int v1, const int v2) const {
    vector<UndirectedEdge> neighbors = adj_.at(v1).second;
    for (auto it = neighbors.begin(); it != neighbors.end(); ++it) {
        if ((it->OtherVertex(v1)).id() == v2) {
            return it->weight();
        }
    }
    return 0.0;
}

void WeightedGraph::SetEdgeValue(const int v1, const int v2, const double w) {
    vector<UndirectedEdge> *neighbors = &adj_.at(v1).second;
    for (auto it = neighbors->begin(); it != neighbors->end(); ++it) {
        if ((it->OtherVertex(v1)).id() == v2) {
            it->set_weight(w);
            break;
        }
    }
    neighbors = &adj_.at(v2).second;
    for (auto it = neighbors->begin(); it != neighbors->end(); ++it) {
        if ((it->OtherVertex(v2)).id() == v1) {
            it->set_weight(w);
            break;
        }
    }
}
