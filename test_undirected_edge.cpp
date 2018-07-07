#include "weighted_graph.h"
#include <iostream>

using namespace std;

// Unit tests the UndirectedEdge data type
int main() {
    UndirectedEdge e(0, 1);
    cout << e.endpoint1().id() << " " << e.endpoint2().id() << endl;
    cout << e.OtherVertex(0).id() << " " << e.OtherVertex(1).id() << endl;
    cout << e.weight() << endl;
    e.set_weight(2.5);
    cout << e.weight() << endl;
    return 0;
}
