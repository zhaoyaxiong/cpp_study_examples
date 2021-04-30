//
// Created by zhaoyx on 2021/4/28.
//

#include "Staff.h"

Staff::Staff(std::string& name, int age):name_(name), age_(age) {

}

std::ostream &operator<<(std::ostream &os, const Staff &staff) {
    os << "name_: " << staff.name_ << " age_: " << staff.age_;
    return os;
}
