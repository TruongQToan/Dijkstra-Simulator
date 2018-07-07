// This class represents a vertex in graph
// A vertex contain an integer (id) and a real number (value), which is used in Dijkstra algorithm
// The data structure provides methods for accessing id and value
// It also provides method for changing the value of the node

#ifndef _VERTEX_H_
#define _VERTEX_H_
class Vertex {
    public:
        Vertex(const int id) : id_(id), value_(0) {}
        Vertex(const int id, const int value) : id_(id), value_(value) {}
        int id() const;
        double value() const;
        void set_value(const double new_value);
    private:
        int id_;
        double value_;
};
#endif
