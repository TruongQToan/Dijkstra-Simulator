#include <vector>
#include <iostream>
#include "priority_queue.h"

using namespace std;

template <class T>
PriorityQueue<T>::PriorityQueue(const int max_n) {
    max_n_ = max_n;
    n_ = 0;
    pq_.resize(max_n + 1);
    qp_.resize(max_n + 1);
    keys_.resize(max_n + 1);
    for (auto it = qp_.begin(); it != qp_.end(); it++) {
        *it = -1;
    }
}

template <class T>
bool PriorityQueue<T>::IsEmpty() const {
    return n_ == 0;
}

template <class T>
bool PriorityQueue<T>::Contains(const int i) const {
    return qp_.at(i) != -1;
}

template <class T>
int PriorityQueue<T>::Size() const {
    return n_;
}

template <class T>
void PriorityQueue<T>::Insert(const int i, const T& key) {
    n_++;
    qp_.at(i) = n_;
    pq_.at(n_) = i;
    keys_.at(i) = key;
    swim(n_);
}

template <class T>
int PriorityQueue<T>::MinIndex() const {
    return pq_.at(1);
}

template <class T>
T PriorityQueue<T>::MinKey() const {
    return keys_.at(pq_.at(1));
}

template <class T>
int PriorityQueue<T>::DeleteMin() {
    int min_index = pq_.at(1);
    exch(1, n_--);
    sink(1);
    qp_.at(min_index) = -1;
    return min_index;
}

template <class T>
T PriorityQueue<T>::KeyOf(const int i) const {
    return keys_.at(i);
}

template <class T>
void PriorityQueue<T>::ChangeKey(const int i, const T& key) {
    keys_.at(i) = key;
    swim(qp_[i]);
    sink(qp_[i]);
}

template <class T>
void PriorityQueue<T>::DecreaseKey(const int i, const T& key) {
    keys_.at(i) = key;
    swim(qp_.at(i));
}

template <class T>
void PriorityQueue<T>::IncreaseKey(const int i, const T& key) {
    keys_.at(i) = key;
    sink(qp_.at(i));
}

template <class T>
void PriorityQueue<T>::Remove(const int i) {
    int index = qp_.at(i);
    exch(index, n_--);
    swim(index);
    sink(index);
    qp_.at(i) = -1;
}

template <class T>
bool PriorityQueue<T>::greater(const int i, const int j) const {
    return keys_.at(pq_.at(i)) > keys_.at(pq_.at(j));
}

template <class T>
void PriorityQueue<T>::exch(const int i, const int j) {
    int swap = pq_.at(i);
    pq_.at(i) = pq_.at(j);
    pq_.at(j) = swap;
    qp_.at(pq_.at(i)) = i;
    qp_.at(pq_.at(j)) = j;
}

template <class T>
void PriorityQueue<T>::swim(int k) {
    while (k > 1 && greater(k / 2, k)) {
        exch(k, k / 2);
        k /= 2;
    }
}

template <class T>
void PriorityQueue<T>::sink(int k) {
    while (2 * k <= n_) {
        int j = 2 * k;
        if (j < n_ && greater(j, j + 1)) ++j;
        if (!greater(k, j)) break;
        exch(k, j);
        k = j;
    }
}
