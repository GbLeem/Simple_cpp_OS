#include <iostream>
#include <unistd.h>
using namespace std;


int main() 
{
    cout<<"my pid: "<<getpid()<<"\n";
    
    if(fork() == 0)
    {
      cout<<"parents pid: "<<getppid()<<"\n";
      cout<<"child pid: "<<getpid()<<"\n";
    }
      
    cout<<"executed\n";
    
    //<output>
    //my pid: 63183
    //executed
    //my pid: 63183
    //parents pid: 63183
    //child pid: 63184
    //executed
}