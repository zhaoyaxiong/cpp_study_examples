//
// Created by zhaoyx on 2021/4/16.
//
#include "compare.h"

double test_namespace::max(const double *data, int size) {
    double result = data[0];
    for (int i = 1; i < size; i++) {
        if (result < data[i]) {
            result = data[i];
        }
    }

    return result;
}

double test_namespace::min(const double *data, int size) {
    double result = data[0];
    for (int i = 1; i < size; i++) {
        if (result > data[i]) {
            result = data[i];
        }
    }
    return result;
}

int other_namespace::max(const int *data, int size) {
    return data[0];
}

int other_namespace::min(const int *data, int size) {
    return data[size - 1];
}

test_namespace::Staff::Staff(const std::string &name, int age) : name(name), age(age) {
    cout << "Staff()" << endl;
}

test_namespace::Staff::~Staff() {
    cout << "~Staff()" << endl;
}

ostream &test_namespace::operator<<(ostream &os, const test_namespace::Staff &staff) {
    os << "name: " << staff.name << ",age: " << staff.age;
    return os;
}

bool test_namespace::Staff::operator==(const test_namespace::Staff &rhs) const {
    return name == rhs.name &&
           age == rhs.age;
}

bool test_namespace::Staff::operator!=(const test_namespace::Staff &rhs) const {
    return !(rhs == *this);
}

bool test_namespace::Staff::operator<(const test_namespace::Staff &rhs) const {
    if (name < rhs.name)
        return true;
    if (rhs.name < name)
        return false;
    return age < rhs.age;
}

bool test_namespace::Staff::operator>(const test_namespace::Staff &rhs) const {
    return rhs < *this;
}

bool test_namespace::Staff::operator<=(const test_namespace::Staff &rhs) const {
    return !(rhs < *this);
}

bool test_namespace::Staff::operator>=(const test_namespace::Staff &rhs) const {
    return !(*this < rhs);
}

test_namespace::Staff::Staff(const test_namespace::Staff &staff) {
    this->name = staff.name;
    this->age = staff.age;
}

const string &test_namespace::Staff::getName() const {
    return name;
}

void test_namespace::Staff::setName(const string &name) {
    Staff::name = name;
}
