#include <iostream>
#include <thread>
#include <semaphore>

std::counting_semaphore semaphore(1); //critical section에 진입할 수 있는 프로세스의 갯수 1로 지정

void produce();
void consume();
//std::queue<int> q;
int sum = 0;

int main() {

    std::cout << "초기 합계: " << sum << std::endl;
    std::thread producer(produce);
    std::thread consumer(consume);

    producer.join();
    consumer.join();

    std::cout << "producer, consumer 스레드 실행 이후 합계: " << sum << std::endl;

    return 0;
}

void produce()
{
    semaphore.acquire();
    for (int i = 0; i < 100000; i++)
    {
        // q.push(1);
        sum++;
    }
    semaphore.release();
}

void consume()
{
    semaphore.acquire();
    for (int i = 0; i < 100000; i++)
    {
        // q.pop();
        sum--;
    }
    semaphore.release();
}

//output
//초기 합계: 0
//producer, consumer 스레드 실행 이후 합계 : 0