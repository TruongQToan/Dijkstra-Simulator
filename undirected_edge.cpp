#include <iostream>
#include "undirected_edge.h"

using namespace std;

Vertex UndirectedEdge::endpoint1() const {
    return endpoint1_;
}

Vertex UndirectedEdge::endpoint2() const {
    return endpoint2_;
}

Vertex UndirectedEdge::OtherVertex(const int v) const {
    if (v == endpoint1_.id()) return endpoint2_;
    return endpoint1_;
}

double UndirectedEdge::weight() const {
    return weight_;
}

void UndirectedEdge::set_weight(const double w) {
    weight_ = w;
}

