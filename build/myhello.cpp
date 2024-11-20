#include <iostream>
#include <vector>
using namespace std;
std::vector<int> myvec(5,9);
std::vector<int> myvec2{1,2,3,4};
int a = 10;
struct books{
    char title[20];
    char id[20];
    int page; 
}book;
class Box
{
    public:
        double length;
        double breadth;
        double height;
        double get(void);
        void set(double len,double bre,double hei);
};
//成员函数定义
double Box::get(void)
{
    return length*breadth*height;
}
void Box::set(double len,double bre,double hei)
{
    length=len;
    breadth=bre;
    height=hei;
}
//引用传递
void myswap(int &aa,int &bb)
{
    int ii=aa;
    aa=bb;
    bb=ii; 
}
int main()
{
Box box1;
box1.set(1,2,3);
int a=10,b=20;
myswap(a,b);
cout <<"a="<<a<<"b="<<b<<endl;
cout<<box1.get();

//添加元素
// myvec.push_back(7);
// myvec2.push_back(8);
// int size1=myvec.size();
// int size2=myvec2.size();
// int a=0;
// cout <<"size1="<<size1 <<"size2="<<size2<<endl;
// for(auto it = myvec.begin();it != myvec.end();++it,++a)
// {
//     std::cout<<"vec="<<*it<<"\n f \t"<<a<<endl;

// }
// for(auto it = myvec2.begin();it != myvec2.end();++it)
// {
//     std::cout<<"vec="<<*it<<endl;

// }
    // int prev;
    // int rear=prev+1;
    // char arr[10];
    // cout <<"book.page="<<book.page <<endl;
    // struct books *book1;
    // book1=&book;
    // cout <<"book1->page="<<book1->page <<endl;
    // cout <<"prev="<<prev<<endl;
    // cout << "write-" << endl;
    // cin >> arr;
    // cout << arr << endl;
    // cout << "hello cpp-" << endl;
    // cout << " cpp-" << endl;

    return 0;
}
