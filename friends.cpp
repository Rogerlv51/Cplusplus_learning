#include <iostream>
using namespace std;

// 友元实际上就是除了继承以外的另一种关系，因为有时候两个类确实没有直接联系
// 但是我们又想他们之间产生一些关联与操作，比如用遥控器控制电视类等，此时就需要friend
// 友元可以在public、protected、private任意中声明，但是友元函数不能是类的成员函数
// 定义了友元后甚至可以访问类的私有成员（函数），但是友元函数不能访问类的私有成员，提供了更灵活的接口实现
class TV{
public:
    friend class Remote;
    TV(int volume, bool stat){
        this->volume = volume;
        this->stat = stat;
        cout<<"TV is created"<<endl;
        cout<<"初始化音量为："<<this->volume <<endl;
        cout<<"初始化状态为："<<this->stat<<endl;
    }
    void onAndoff(){
        if(stat == true){
            stat = false;
            cout << "TV is off" << endl;
        }
        else{
            stat = true;
            cout << "TV is on" << endl;
        }
        
    }
    

private:
    int volume;
    bool stat;
    void changeVolume(int volume){
        this->volume = volume;
        cout<<"当前音量为："<<this->volume<<endl;
    }
};

class Remote{
public:
    void controlTV(TV& tv){
        tv.onAndoff();
    }
    void changeVolume(TV& tv, int volume){
        tv.changeVolume(volume);
    }

};

int main(){
    system("chcp 65001");
    TV tv(10, false);
    Remote remote;
    remote.controlTV(tv);
    remote.changeVolume(tv, 20);
    remote.controlTV(tv);
    return 0;
}