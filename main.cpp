#include "words.h"
#include <chrono>
#include <iostream>

int main()
{
    const auto text = load();
    using namespace std::chrono;
    const auto t0 = high_resolution_clock::now();
    auto [word, count] = count_words_0(text);
    std::cout << "Most frequent: \"" << word << "\", count: " << count << std::endl;
    const auto t = high_resolution_clock::now();
    std::cout << "Elapsed: " << duration_cast<microseconds>(t - t0).count() * 1e-6 << std::endl;
}

