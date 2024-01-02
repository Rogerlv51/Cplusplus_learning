/*                    类的基础知识，包括继承多态等功能          */

#include <iostream>
#include <vector>
using namespace std;

struct Vector
{
  size_t m_size;
  int *m_data;

  Vector(size_t n)
  {
    m_size = n;
    m_data = (int *)malloc(n * sizeof(int));
  }

  Vector(const Vector &other){
    m_size = other.m_size;
    m_data = (int *)malloc(m_size * sizeof(int));
    // 注意要使用内存拷贝，而不是直接赋值 m_data = other.m_data!!!
    memcpy(m_data, other.m_data, other.m_size * sizeof(int));
  }

  Vector &operator=(const Vector &other){
    this->~Vector();  // 先销毁当前自身的空间
    new(this) Vector(other);  // 再调用拷贝构造函数
    return *this;

    // 或者像下面这种写法
    // m_size = other.m_size;
    // m_data = (int *)malloc(m_size * sizeof(int));
    // // 注意要使用内存拷贝，而不是直接赋值 m_data = other.m_data!!!
    // memcpy(m_data, other.m_data, other.m_size * sizeof(int));
    // return *this;
  }

  // 移动构造
  Vector(Vector &&other) : m_size(other.m_size), m_data(other.m_data){
    other.m_size = 0;
    other.m_data = nullptr;
  }

  ~Vector()
  {
    free(m_data);
  }

  size_t size()
  {
    return m_size;
  }

  void resize(size_t n)
  {
    m_size = n;
    m_data = (int *)realloc(m_data, n * sizeof(int));
  }

  int &operator[](size_t index)
  {
    return m_data[index];
  }
};

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

   void justadd() const{   // const修饰的成员函数不能修改成员变量，只能访问，表示这个函数是只读模式
        // age = 2;   此时修改成员变量会报错
        cout << "这是一个只读函数" << endl;
    }
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
    A.justadd();
    return 0;

    // 对于一个类来说我们知道编译器通常会自动生成默认的构造函数、拷贝构造、赋值构造、移动构造、析构函数等
    // 因此当我们自己创建一个类的时候应该手动实现上述这些函数，又或者是直接用C11特性default来声明默认，或者delete删除默认
    // 下面我们阐述一个例子来说明什么是移动构造？对于stl标准模版库来说直接使用std::move()函数就可以实现移动构造
    vector<int> v1(2);
    v1[0] = 1;
    v1[1] = 5;
    vector<int> v2(3);
    v2[0] = 2;
    v2[1] = 3;
    v2[2] = 4;

    // 如果使用v1=v2即赋值构造，那么v1的大小会变成3，同时不会释放v2的空间，这样时间复杂度是O(n)
    v1 = move(v2);  // 然而使用move函数即移动的意思，把v2的空间移动给v1，同时v2的空间会被释放，这样时间复杂度是O(1)
    cout << v1.size() << endl;  // 输出3
    cout << v2.size() << endl;  // 输出0
    
    for(size_t j = 0; j < v1.size(); j++){
        cout << v1[j] << endl;
    }
}