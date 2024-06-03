#include <iostream>
#include <unistd.h>
using namespace std;

void foo()
{
    cout<<"foo executed\n";
}

int main() 
{
    if(fork() == 0) //자식 1
    {
        if(fork() == 0) //자식 1의 자식
        {
            cout<<"child of child1 pid: "<<getpid()<<"\n";
            foo();
        }
        else
        {
            cout<<"child1 pid: "<<getpid()<<"\n";
            foo();
        }
    }
    else
    {
        if(fork() == 0) //자식 2
        {
            cout<<"child2 pid: "<<getpid()<<"\n";
            foo();
        }
        else  //부모
        {
            cout<<"parent pid: "<<getpid()<<"\n";
            foo();
        }
    }
    return 0;
}

//output
//parent pid: 2071
//foo executed
//child1 pid: 2072
//foo executed
//child2 pid: 2073
//foo executed
//child of child1 pid: 2074
//foo executed