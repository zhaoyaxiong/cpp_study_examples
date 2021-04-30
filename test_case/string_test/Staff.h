//
// Created by zhaoyx on 2021/4/28.
//

#ifndef CPP_STUDY_EXAMPLES_STAFF_H
#define CPP_STUDY_EXAMPLES_STAFF_H

#include <string>
#include <ostream>

class Staff {
private:
    std::string name_;
    int age_;
public:
    Staff() = default;

    Staff(std::string &name, int age);

    Staff(const Staff &staff) = delete;

    friend std::ostream &operator<<(std::ostream &os, const Staff &staff);

};


#endif //CPP_STUDY_EXAMPLES_STAFF_H
