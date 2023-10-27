// 错误的会造成进程死锁的程序，使用了独占式锁mutex
// #include <iostream>
// #include <thread>
// #include <mutex>
// using namespace std;

// struct Calculate
// {
//     Calculate() : m_i(6) {}

//     void mul(int x)
//     {
//         lock_guard<mutex> locker(m_mutex);
//         m_i *= x;
//     }

//     void div(int x)
//     {
//         lock_guard<mutex> locker(m_mutex);
//         m_i /= x;
//     }

//     void both(int x, int y)
//     {
//         lock_guard<mutex> locker(m_mutex);
//         mul(x);
//         div(y);
//     }

//     int m_i;
//     mutex m_mutex;
// };

// int main()
// {
//     Calculate cal;
//     cal.both(6, 3);
//     return 0;
// }

// 正确的代码要使用递归锁，但是一般建议少用
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

struct Calculate
{
    Calculate() : m_i(6) {}

    void mul(int x)
    {
        lock_guard<recursive_mutex> locker(m_mutex);
        m_i *= x;
    }

    void div(int x)
    {
        lock_guard<recursive_mutex> locker(m_mutex);
        m_i /= x;
    }

    void both(int x, int y)
    {
        lock_guard<recursive_mutex> locker(m_mutex);
        mul(x);
        div(y);
    }

    int m_i;
    recursive_mutex m_mutex;
};

int main()
{
    Calculate cal;
    cal.both(6, 3);
    cout << "cal.m_i = " << cal.m_i << endl;
    return 0;
}
