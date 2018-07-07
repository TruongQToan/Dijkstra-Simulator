#include <iostream>
#include <utility>
#include <random>
#include <limits>
#include "shortest_path.h"
#include "vertex.h"
#include "undirected_edge.h"
#include "weighted_graph.h"

using namespace std;

WeightedGraph GraphGenerator(int num_vertices = 50, double density = 0.2, double min_range = 1.0, double max_range = 10.0) {
    WeightedGraph g(num_vertices);
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis1(0.0, 1.0);
    uniform_real_distribution<double> dis2(1.0, 10.0);
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            if (dis1(gen) <= density) {
                g.AddEdge(i, j);
                g.SetEdgeValue(i, j, dis2(gen));
            }
        }
    }
    return g;
}

double Output(int num_vertices, double density) {
    ShortestPath s(GraphGenerator(num_vertices = num_vertices, density = density), 0);
    double average = 0.0;
    double exception = 0;
    for (int i = 1; i < num_vertices; i++) {
        if (s.DistTo(i) != numeric_limits<double>::max())
            average += s.DistTo(i);
        else exception += 1;
    }
    return average / (num_vertices - 1 - exception);
}

int main() {
    const int num_vertices = 50;
    cout << "Average length with 20\% density = " << Output(num_vertices, 0.2) << endl;
    cout << "Average length with 40\% density = " << Output(num_vertices, 0.4) << endl;
    return 0;
}
