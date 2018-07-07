#include "vertex.h"
#include <iostream>

using namespace std;

int Vertex::id() const {
    return this->id_;
}

double Vertex::value() const {
    return this->value_;
}

void Vertex::set_value(const double new_value) {
    value_ = new_value;
}
