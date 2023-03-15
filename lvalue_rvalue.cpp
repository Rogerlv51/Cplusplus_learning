// 什么是左值和右值？
// 对于每一个C++表达式来说都一定有一个值类型
// 值类别是编译器在表达评估期间创建，复制和移动临时对象时必须遵循的规则的基础

// value type主要有以下几个：
/*
    A glvalue is an expression whose evaluation determines the identity of an object, bit-field, or function.
    A prvalue is an expression whose evaluation initializes an object or a bit-field, or computes the value of the operand of an operator, as specified by the context in which it appears.
    An xvalue is a glvalue that denotes an object or bit-field whose resources can be reused (usually because it is near the end of its lifetime). Example: Certain kinds of expressions involving rvalue references (8.3.2) yield xvalues, such as a call to a function whose return type is an rvalue reference or a cast to an rvalue reference type.
    An lvalue is a glvalue that is not an xvalue.
    An rvalue is a prvalue or an xvalue.
*/
/*An lvalue has an address that your program can access. 
Examples of lvalue expressions include variable names, including const variables, 
array elements, function calls that return an lvalue reference, bit-fields, unions, and class members.*/

// lvalues_and_rvalues2.cpp
int main()
{
    int i, j, *p;

    // Correct usage: the variable i is an lvalue and the literal 7 is a prvalue.
    i = 7;

    // Incorrect usage: The left operand must be an lvalue (C2106).`j * 4` is a prvalue.
    7 = i; // C2106
    j * 4 = 7; // C2106

    // Correct usage: the dereferenced pointer is an lvalue.
    *p = i;

    // Correct usage: the conditional operator returns an lvalue.
    ((i < 3) ? i : j) = 7;

    // Incorrect usage: the constant ci is a non-modifiable lvalue (C3892).
    const int ci = 7;
    ci = 9; // C3892
}

// 左值引用用&标识，用来指向对象的地址，右值引用用&&标识，用来指向临时对象的地址
// 左值引用就是绑定在左值上的引用，左值是可以取地址的，有名字的，非临时的表达式。
// 右值引用就是绑定在右值上的引用，右值是不能取地址的，没有名字的，临时的表达式。