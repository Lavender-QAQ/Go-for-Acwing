#include <iostream>

using namespace std;

void hanoi(int n,char x,char y,char z)
{
    if(n)
    {
        hanoi(n-1,x,z,y);//将n-1个盘子从x移动到z
        cout << x << "——>" << y << endl;//将第n个盘子移动到y
        hanoi(n-1,z,y,x);//将z上的盘子移动到y
    }
}

int main()
{
    int n;
    cin>>n;
    hanoi(n,'A','B','C');
    return 0;
}
