#include <iostream>
using namespace std;

int test_1(int num)
{
    if (num == 0)
    {
        throw -1;
    }
    else if (num == 1)
    {
        throw 0.01;
    }
    else if (num == 2)
    {
        throw 'a';
    }
    else if (num == 3)
    {
        throw "abc";
    }
    else
    {
        throw bad_alloc();
    }

    return 0;
}

int main()
{
    int ret = 0;

    try
    {
        ret = test_1(3);
    }
    catch (int& error)
    {
        cout << "Int error" << endl;
        cout << error << endl;
    }
    catch (double error)
    {
        cout << "Double error" << endl;
        cout << error << endl;
    }
    catch (char error)
    {
        cout << "Char error" << endl;
        cout << error << endl;
    }
    catch (const char* error)
    {
        cout << "string error" << endl;
        cout << error << endl;
    }
    catch (const std::exception& e)
    {
        cout << e.what() << endl;
        cout << "Exception Occures" << endl;
    }
    catch (...)
    {
        cout << "All Exception catch" << endl;
    }

    return 0;
}