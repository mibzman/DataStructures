#include <chrono>
#include <iostream>
#include <random>
#include <vector>
#include "HashChain.hpp"


void TestInsert(){
 std::mt19937 prbg;

  for (int n = 1000; n <= 500000; n += 10000) {

    // Get the starting time point. The type is deduced because it's hard
    // to spell (it is std::chrono::system_clock::time_point).
    auto start = std::chrono::system_clock::now();

    // The actual test.
    SepHash* hash = new SepHash();
    //std::vector<int> seq;
    for (int i = 0; i < n; ++i) {
      std::uniform_int_distribution<int> rand(0, i);

      //int num = rand(prbg);                // Generate a random number
      hash->insert(i);
      //auto iter = linear_search(seq, num); // Find the insertion point
      //seq.insert(iter, num);
    }

    // Get the current system time in nanoseconds.
    auto stop = std::chrono::system_clock::now();

    // Print the number of nanoseconds each test takes.
    std::cout << n << ", " << (stop - start).count() << std::endl;
  }

}

int main()
{
  TestInsert();
}
