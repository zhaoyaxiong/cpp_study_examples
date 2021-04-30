//
// Created by zhaoyx on 2021/4/29.
//

#ifndef CPP_STUDY_EXAMPLES_SMARTPTR_H
#define CPP_STUDY_EXAMPLES_SMARTPTR_H

#include <algorithm>

template<typename T>
class SmartPtr {
public:
    SmartPtr(SmartPtr& smartPtr) {
        ptr_  = smartPtr.release();
    }

    SmartPtr& operator=(SmartPtr rhs) {
        rhs.swap(*this);
        return *this;
    }

    explicit SmartPtr(T* ptr = nullptr) : ptr_(ptr) {

    }

    T* get() const {
        return ptr_;
    }

    T* operator->() {
        return ptr_;
    }

    explicit operator bool() const {
        return ptr_;
    }

    virtual ~SmartPtr() {
        delete ptr_;
    }

    T& operator *() const {
       return *ptr_;
    }

    T* release() {
        T* ptr = ptr_;
        ptr_ = nullptr;
        return ptr;
    }

    //移动构造函数
    void swap(SmartPtr&& rhs) {
        using std::swap;
        swap(ptr_, rhs.ptr_);
    }

private:
    T* ptr_;
};


#endif //CPP_STUDY_EXAMPLES_SMARTPTR_H
