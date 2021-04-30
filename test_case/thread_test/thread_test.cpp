//
// Created by zhaoyx on 2021/4/30.
//
#include <iostream>
#include <thread>
#include <vector>

using namespace std;
vector<thread> threadList;
vector<shared_ptr<thread>> sharePtrList;

void func(int i, double d, const string& s) {
    this_thread::sleep_for(chrono::seconds(3));
    cout << i << " " << d << " " << s << endl;
    cout << "Do some work" <<endl;
}

void func2() {
    cout << "threadId: " << this_thread::get_id() <<endl;
    cout <<"func2" <<endl;
}

void createThread() {
    thread t1(func2);
    threadList.push_back(std::move(t1));
    sharePtrList.push_back(make_shared<thread>(func2));
}


int main() {
    thread t(func, 1, 2, "test");
    thread t2([](int a, double b){cout << "test" << endl;},1 ,2);
    //t.detach();  线程和线程对象分离

    createThread();
    for (auto& thread : threadList) {
        thread.join();
    }

    for (auto & thread : sharePtrList) {
        thread->join();
    }
    cout << "Cpu Number: " << thread::hardware_concurrency() << endl;
    t.join();
    t2.join();
    return 0;
}
