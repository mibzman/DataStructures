#include <chrono>
#include <iostream>
#include <random>
#include <vector>
#include "HashChain.hpp"

void TestFind(){
 std::mt19937 prbg;

  for (int n = 1000; n <= 50000; n += 1000) {

    SepHash* hash = new SepHash();
    std::vector<int> seq;
    for (int i = 0; i < n; ++i) {
      std::uniform_int_distribution<int> rand(0, i);

      //int num = rand(prbg);                // Generate a random number
      hash->insert(i);
      //auto iter = linear_search(seq, num); // Find the insertion point
      seq.push_back(i);
    }

    for (int i = n; i < n *2; ++i) {
      std::uniform_int_distribution<int> rand(0, i);

      //int num = rand(prbg);                // Generate a random number
      //hash->insert(i);
      //auto iter = linear_search(seq, num); // Find the insertion point
      seq.push_back(i);
    }

    auto start = std::chrono::system_clock::now();
    for (int f = 0; f < seq.size(); f++){
        int* test = hash->find(f);
    }
    // Get the current system time in nanoseconds.
    auto stop = std::chrono::system_clock::now();

    // Print the number of nanoseconds each test takes.
    std::cout << n << ", " << (stop - start).count() << std::endl;
  }

}


int main()
{
  TestFind();
}
