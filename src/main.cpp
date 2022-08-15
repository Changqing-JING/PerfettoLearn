#include <chrono>
#include <condition_variable>
#include <cstdio>
#include <mutex>
#include <thread>
#include <unistd.h>

std::mutex mut;
std::condition_variable cv;

void worker() {
  printf("worker tid is %d\n", gettid());
  while (true) {
    std::unique_lock<std::mutex> lock(mut);
    cv.wait(lock);
    // printf("cv notifiled\n");
  }
}

void sender() {
  printf("sender tid is %d\n", gettid());
  while (true) {
    cv.notify_one();
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
}

int main() {
  printf("process pid is %d\n", getpid());
  std::thread th_worker(worker);
  std::thread th_sender(sender);

  th_worker.join();
  th_sender.join();
  return 0;
}