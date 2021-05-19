//
// Created by zhaoy on 2021/5/20.
//

#ifndef CPP_STUDY_EXAMPLES_TESTA_H
#define CPP_STUDY_EXAMPLES_TESTA_H


#include <ostream>

class TestA {
private:
    int m_id;
    int m_channel;
public:
    TestA() = default;
    TestA(const TestA& testA)
    {
        std::cout << "Copy Constructor..." << std::endl;
    }

    TestA(int mId, int mChannel) : m_id(mId), m_channel(mChannel) {}

    ~TestA()
    {
        std::cout << "~TestA..." << std::endl;
    }

    friend std::ostream &operator<<(std::ostream &os, const TestA &a) {
        os << "m_id: " << a.m_id << " m_channel: " << a.m_channel;
        return os;
    }
};


#endif //CPP_STUDY_EXAMPLES_TESTA_H
