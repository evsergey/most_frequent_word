#include <catch2/catch_all.hpp>
#include "words.h"

/*
benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Version 0                                      100             1      3.8159 m
                                         2.29032 s     2.28213 s      2.3014 s
                                        48.1531 ms    37.2636 ms    66.7808 ms

Version 1                                      100             1     12.9073 s
                                         128.72 ms    128.429 ms    129.032 ms
                                        1.54304 ms    1.34571 ms    1.79319 ms

Version 2                                      100             1     3.98191 s
                                        39.9117 ms    39.5739 ms    40.6092 ms
                                        2.37056 ms    1.40714 ms    4.42204 ms

Version 3                                      100             1     4.26918 s
                                        38.8177 ms    38.4517 ms    39.2222 ms
                                        1.95631 ms    1.71156 ms    2.30126 ms

Version 4                                      100             1     3.88161 s
                                        36.1302 ms    35.8383 ms    36.4797 ms
                                        1.62785 ms    1.38041 ms    1.93626 ms
*/
TEST_CASE("Benchmark")
{
    const auto text = load();
    //BENCHMARK("Version 0")
    //{
    //    return count_words_0(text);
    //};
    BENCHMARK("Version 1")
    {
        return count_words_1(text);
    };
    BENCHMARK("Version 2")
    {
        return count_words_2(text);
    };
    BENCHMARK("Version 3")
    {
        return count_words_3(text);
    };
    BENCHMARK("Version 4")
    {
        return count_words_4(text);
    };
}
