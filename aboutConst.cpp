#include <iostream>
using namespace std;

int main(){
    // 一、const修饰普通类型的变量
    const int  a = 7; 
    int  b = a; // 正确
    /*   a = 8;       // 错误，不能改变  */

    // 二、const 修饰指针变量
    /*
        A: const 修饰指针指向的内容，则内容为不可变量。
        B: const 修饰指针，则指针为不可变量。
        C: const 修饰指针和指针指向的内容，则指针和指针指向的内容都为不可变量。
    */
    
    const int *p = &a;    // 常量指针，指针指向的值不能变，但是指针指向的地址可以变

    int d = 8;
    int* const pp = &d;   // 指针常量，指针的地址不能变，但是指针指向的值可以变
    *pp = 9; // 正确
    /*  pp = &b;   // 错误 */

    int c = 8;
    const int * const ppp = &c;  // 地址和值都不能变
    return 0;
}


// 三、const参数传递和函数返回值，同样分三种情况

// const参数传递
// （1）值传递的const修饰传递，一般这种情况不需要const修饰，因为函数会自动产生临时变量复制实参值。
void Cpf(const int a){
    cout<<a;
    //++a;  //是错误的，a 不能被改变
}

// (2) 当 const 参数为指针时，可以防止指针被意外篡改。
void Cpf(int *const a)
{
    cout<<*a<<" ";
    *a = 9;
}
// (3) 见类方法后面加const，防止成员变量被修改


//对于 const 修饰函数的返回值
/*
    A：const 修饰内置类型的返回值，修饰与不修饰返回值作用一样
    B: const 修饰自定义类型的作为返回值，此时返回的值不能作为左值使用，既不能被赋值，也不能被修改。
    C: const 修饰返回的指针或者引用，是否返回一个指向 const 的指针，取决于我们想让用户干什么。

*/