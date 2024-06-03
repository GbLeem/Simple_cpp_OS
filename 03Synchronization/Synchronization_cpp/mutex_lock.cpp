#include <iostream>
#include <queue>
#include <thread>
#include <mutex>

void produce();
void consume();

//std::queue<int> q;
int sum = 0;
std::mutex simple_mutex;

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
    simple_mutex.lock();
    for (int i = 0; i < 100000; i++)
    {
        // q.push(1);
        sum++;
    }
    simple_mutex.unlock();
}

void consume()
{
    simple_mutex.lock();

    for (int i = 0; i < 100000; i++)
    {
        // q.pop();
        sum--;
    }
    simple_mutex.unlock();
}

//output
//초기 합계: 0
//producer, consumer 스레드 실행 이후 합계 : 0