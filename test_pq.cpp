#include <iostream>
#include <string>
#include <vector>
#include "priority_queue.h"

using namespace std;

int main() {
    vector<int> test_array = {4, 2, 1, 0, -1, -1, 5};
    PriorityQueue<int> pq(test_array.size());
    int i = 0;
    for (int n : test_array) {
        pq.Insert(i++, n);
    }
    while (!pq.IsEmpty()) {
        int i = pq.DeleteMin();
        cout << i << " " << pq.KeyOf(i) << endl;
    }
    return 0;
}

#include "priority_queue.cpp"
