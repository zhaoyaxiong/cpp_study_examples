//
// Created by zhaoyx on 2021/4/28.
//

#ifndef CPP_STUDY_EXAMPLES_TESTTEMPLATE_H
#define CPP_STUDY_EXAMPLES_TESTTEMPLATE_H
template <typename T>
class TestTemplate {
public:
    TestTemplate() = default;
    explicit TestTemplate(T data);
    void print();
private:
    T data_;
};
#endif //CPP_STUDY_EXAMPLES_TESTTEMPLATE_H
