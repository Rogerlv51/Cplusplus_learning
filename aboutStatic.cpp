#include <iostream>
using namespace std;

int main(){
    // 什么是static？static 是 C/C++ 中很常用的修饰符，它被用来控制变量的存储方式和可见性。
    
    /* static关键字作用
    （1）在修饰变量的时候，static 修饰的静态局部变量只执行初始化一次，而且延长了局部变量的生命周期，直到程序运行结束以后才释放。
    （2）static 修饰全局变量的时候，这个全局变量只能在本文件中访问，不能在其它文件中访问，即便是 extern 外部声明也不可以。
    （3）static 修饰一个函数，则这个函数的只能在本文件中调用，不能被其他文件调用。static 修饰的变量存放在全局数据区的静态变量区，包括全局静态变量和局部静态变量，都在全局数据区分配内存。初始化的时候自动初始化为 0。
    （4）不想被释放的时候，可以使用static修饰。比如修饰函数中存放在栈空间的数组。如果不想让这个数组在函数调用结束释放可以使用 static 修饰。
    （5）考虑到数据安全性（当程序想要使用全局变量的时候应该先考虑使用 static）。
    
    */

    // 被 static 修饰的变量、被 static 修饰的方法统一属于类的静态资源，是类实例之间共享的，换言之，一处变、处处变。
    // 类的静态成员变量必须先在类外初始化再使用
    // 静态成员函数主要用来方位静态数据成员而不能访问非静态成员
    
    // 主要是作用域的区别，还有类中的特殊使用

    static int i = 100;
    cout << i << endl;
    i = 10;
    cout << i << endl;   // 可以看到

    extern int y;   // extern声明使用作用域之外的全局变量，也可以是别的cpp文件中定义过的
    cout << "extern y = " << y << endl;  // 10
    return 0;
}

int y = 10;