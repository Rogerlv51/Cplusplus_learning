/*                    类的基础知识，包括继承多态等功能          */

#include <iostream>

using namespace std;

class Teacher{
public:
    Teacher(string n, int a);     // 自定义构造函数，如果没有定义编译器会自动生成默认构造函数
    void update(int x);      // 只能通过公有函数接口修改private成员变量（或者是友元函数）
    void print();
    virtual void justPrint(string x);
    /*为什么需要虚函数？*/
    /*
        只有当类方法是虚函数时，使用引用或者指针指向对象才能正确地使用多态后的子类方法，否则的话即使你实现了多态，也还是会自动调用基类的
    */
   void set(int ii) { i=ii; cout << i <<endl;}   // 修改静态成员变量
   void get(){ cout << i << endl;}         // 访问静态成员变量
private:
    string name = " ";
    int age = 1;
    void getData(){ cout << "我的名字是： "<< name << "年龄为： "<< age <<endl;};    // 将成员函数写在private里面起到封装接口的作用

    static int i;     // 定义一个静态成员变量
    /*
        静态成员变量意味着它为该类的所有实例所共享，也就是说当某个类的实例修改了该静态成员变量，其修改值为该类的其它所有实例所见
    */
    // 对于不在类中实现的普通static变量则是作用域仅限当前cpp文件，其他文件无法访问
};

class Student : public Teacher{
public:
    Student(string w, int x);
    virtual void justPrint(string x);     // 多态的意思是重写基类方法，但是要保证参数和返回类型一致
};


Teacher::Teacher(string n, int a){
    name = n;
    age = a;
}

void Teacher::justPrint(string x){
    cout <<  "这是基类的虚函数" << endl;
}

void Student::justPrint(string x){
    cout << "这是子类多态继承的虚函数" << x << endl;
}

/*  派生类不能直接访问基类的private成员，而必须通过基类方法进行访问  */
// 如果基类是显式声明了构造函数，那么派生类一定要声明自己的构造函数
Student::Student(string w, int x):Teacher(w, x){
    // Student::Teacher(w, x);        所以这里必须使用:调用基类的构造函数赋值给private成员
                                 //   也可以在派生类的构造函数给自己的private成员初始化，同时注意:后面的参数不要带类型
}


void Teacher::print(){
    getData();
}


void Teacher::update(int x){
    this->age = x;
}


int Teacher::i;     // 这里一定要手动声明下静态成员，才能在main函数调用
int main(){
    system("chcp 65001");
    Teacher A = Teacher("roger", 20);
    A.print();
    A.update(50);
    A.print();
    A.justPrint("a");
    A.set(100);
    Student B("aa", 100);
    B.get();     // 可以发现B访问静态成员变量的值已经改为100，说明了静态成员变量的意义
    B.print();
    B.justPrint("yes");
    Teacher& C = B;   // 创建一个引用指向对象B
    C.justPrint("wuwuwu");    // 可见成功调用子类多态函数 
    
    return 0;
}