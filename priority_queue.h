// The PriorityQueue class represents an indexed priority queue of vertex object
// It supports the usual insert and delete-the-minimum operations, 
// along with delete and change-the-key methods. 
// In order to let the client refer to keys on the priority queue, 
// an integer between 0 and max_n - 1 is assocciated with each key.
// The client uses this key to specify which key to delete or change.
// It also support methods for peeking at the minimum key, testing if the priority queue is empty, getting size of priority queue and testing if the priority queue contains an element.
#ifndef PRIORIRTY_QUEUE_H
#define PRIORIRTY_QUEUE_H
#include <vector>

using namespace std;

template <class T>
class PriorityQueue {
    public:
        // Intitializes an empty indexed priority queue with indices between 0 and max_n - 1
        PriorityQueue(const int max_n);
        // Returns true if this priority is empty
        bool IsEmpty() const;
        // Is i an index on this priority queue
        bool Contains(const int i) const;
        // Returns the number of key on this priority queue
        int Size() const;
        // Assocciates key with index i
        void Insert(const int i, const T& key);
        // Returns an index assocciated with a minimum key
        int MinIndex() const;
        // Returns a minimum key
        T MinKey() const;
        // Removes a minimum key and returns its associated index
        int DeleteMin();
        // Returns the keys associated with index i
        T KeyOf(const int i) const;
        // Changes the key associated with index i to the specified value.
        void ChangeKey(const int i, const T& key);
        // Decreases the key associated with index i to the specified value
        void DecreaseKey(const int i, const T& key);
        // Increases the key associated with index i to the specified value
        void IncreaseKey(const int i, const T& key);
        // Remove the key associated with index i
        void Remove(const int i);
    private:
        int max_n_; // maximum number of elements 
        int n_; // number of elements on priority queue
        vector<int> pq_; // binary-heap using 1-based indexing
        vector<int> qp_;
        vector<T> keys_; // keys[i] = priority of i
        // General helper functions
        bool greater(const int i, const int j) const;
        void exch(const int i, const int j);
        // Heap helper functions
        void swim(int k);
        void sink(int k);
};
#endif
