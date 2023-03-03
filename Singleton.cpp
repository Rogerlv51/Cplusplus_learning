#include <string.h>
#include <iostream>
using namespace std;

#if 0
// 饿汉模式->定义类的时候就创建单例对象
class TaskQue {
public:
  static TaskQue *build() { return m_que; }
  static void setname(string s) { TaskQue::name = s; }
  static void print() { cout << TaskQue::name << endl; }

private:
	// 单例模式下必须把下面三个构造设为default，或者在public中设为delete都行
  TaskQue() = default;
  TaskQue(const TaskQue &t) = default;
  TaskQue &operator=(const TaskQue &t) = default;
  // 只能通过类名访问静态成员函数或属性
  static TaskQue *m_que;
  static string name;
};

// 静态成员变量必须在使用前类外进行初始化，之后才能在函数中正常调用
TaskQue *TaskQue::m_que = new TaskQue;
string TaskQue::name = "";

int main() {
  TaskQue *task = TaskQue::build();
  task->setname("这是单例模式");
  task->print();
}
#endif

// 懒汉模式->在类加载的时候不去创建这个唯一的实例，而是在需要使用的时候再进行实例化
class TaskQueue
{
public:
    // = delete 代表函数禁用, 也可以将其访问权限设置为私有
    TaskQueue(const TaskQueue& obj) = delete;
    TaskQueue& operator=(const TaskQueue& obj) = delete;
    static TaskQueue* getInstance()
    {
        if(m_taskQ == nullptr)
        {
            m_taskQ = new TaskQueue;
        }
        cout << "创建对象" << endl;
        return m_taskQ;
    }
private:
    TaskQueue() = default;
    static TaskQueue* m_taskQ;
};
TaskQueue* TaskQueue::m_taskQ = nullptr;

int main() {
    system("chcp 65001");
    TaskQueue *task = TaskQueue::getInstance();  // 此时才会创建对象
}