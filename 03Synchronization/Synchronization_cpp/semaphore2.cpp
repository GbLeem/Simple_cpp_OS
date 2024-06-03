#include <iostream>
#include <thread>
#include <semaphore>

std::counting_semaphore semaphore(1); //한번에 하나의 process(thread) 만 사용한다.
int num = 0; //공유 자원
int safenum = 0;

void CountingSafe() 
{
    semaphore.acquire();
    for (int i = 0; i < 100000; ++i)
        safenum++;
    semaphore.release();   
}

void Counting()
{
    for (int i = 0; i < 100000; ++i)
        num++;
}

int main() {
    std::thread t1(CountingSafe);
    std::thread t2(CountingSafe);
    
    t1.join();
    t2.join();

    std::thread t3(Counting);
    std::thread t4(Counting);

    t3.join();
    t4.join();
    std::cout << "safe num: " << safenum << "\n";

    std::cout << "num: " << num << "\n";    
    return 0;
}

//output 
//safe num : 200000
//num : 127224 (실행할 때마다 달라짐)