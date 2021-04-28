//
// Created by zhaoyx on 2021/4/16.
//

#ifndef NAMESPACE_TEST_COMPARE_H
#define NAMESPACE_TEST_COMPARE_H

#include <string>
#include <iostream>

using namespace std;
namespace test_namespace {
    double max(const double *data, int size);

    double min(const double *data, int size);

    class Staff {
    public:
        Staff(const std::string &name, int age);

        virtual ~Staff();

        Staff(const Staff& staff);


        bool operator<(const Staff &rhs) const;

        bool operator>(const Staff &rhs) const;

        bool operator<=(const Staff &rhs) const;

        bool operator>=(const Staff &rhs) const;

        bool operator==(const Staff &rhs) const;

        bool operator!=(const Staff &rhs) const;

        friend ostream &operator<<(ostream &os, const Staff &staff);

        const string &getName() const;

        void setName(const string &name);

    private:
        std::string name;
        int age;
    };
}

namespace other_namespace {
    int max(const int *data, int size);

    int min(const int *data, int size);
}
#endif //NAMESPACE_TEST_COMPARE_H
