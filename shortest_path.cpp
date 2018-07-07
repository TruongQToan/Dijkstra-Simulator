#include <vector>
#include <limits>
#include <algorithm>
#include <iostream>
#include "shortest_path.h"
#include "priority_queue.h"
#include "vertex.h"
#include "undirected_edge.h"
#include "weighted_graph.h"

using namespace std;

ShortestPath::ShortestPath(const WeightedGraph& g, const int s) {
    PriorityQueue<double> pq_(g.v());
    dist_to_.resize(g.v());
    edge_to_.resize(g.v());
    s_ = s;

    for (int v = 0; v < g.v(); v++) {
        dist_to_.at(v) = numeric_limits<double>::max();
    }
    dist_to_.at(s) = 0;

    pq_.Insert(s, dist_to_.at(s));
    while (!pq_.IsEmpty()) {
        int v = pq_.DeleteMin();
        for (UndirectedEdge e : g.Adjacent(v)) {
            int w = e.OtherVertex(v).id();
            if (dist_to_[w] > dist_to_[v] + e.weight()) {
                dist_to_.at(w) = dist_to_.at(v) + e.weight();
                edge_to_[w] = v;
                if (pq_.Contains(w)) pq_.DecreaseKey(w, dist_to_.at(w));
                else pq_.Insert(w, dist_to_.at(w));
            }
        }
    }
}

double ShortestPath::DistTo(const int v) const {
    return dist_to_.at(v);
}

vector<int> ShortestPath::PathTo(const int v) const {
    vector<int> path;
    int i = v;
    while (i != s_) {
        path.push_back(i);
        i = edge_to_.at(i);
    }
    path.push_back(s_);
    reverse(path.begin(), path.end());
    return path;
}

#include "priority_queue.cpp"
