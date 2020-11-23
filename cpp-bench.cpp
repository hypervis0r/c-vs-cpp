#include <iostream>
#include <chrono>
#include <vector>

int main(void)
{
    using namespace std::chrono;
    
    int i = 0;
    auto start = high_resolution_clock::now();
    auto end = high_resolution_clock::now();
    duration<double> time_count = end - start;

    /****************************************************************/
    // STDOUT time comparison

    start = high_resolution_clock::now();

    for(i = 0; i < 100000; i++)
    {
        // If I remember correctly, appending \n is faster than endl but whatever
        std::cout << i << std::endl;
    }

    end = high_resolution_clock::now();

    time_count = end - start;
    
    std::cout << std::fixed;
    std::cout << "Time elapsed: " << time_count.count() << " seconds" << std::endl;

    /****************************************************************/
    // String concatenation time comparison 
    
    start = high_resolution_clock::now();

    std::string test1 = "Hello ";
    std::string test2 = "World!";
    test1 += test2;

    end = high_resolution_clock::now();
    
    std::cout << test1 << std::endl;
    
    time_count = end - start;
    std::cout << "string concat time elapsed: " << time_count.count() << " seconds" << std::endl;

    /****************************************************************/
    // Vector operations time comparison
    
    start = high_resolution_clock::now();
    
    std::vector<int> testArr;
    for(i = 0; i < 50; i++)
    {
        testArr.push_back(i);
    }
    int value = testArr[25];

    end = high_resolution_clock::now();

    std::cout << value << std::endl;
    
    time_count = end - start;
    std::cout << "Vector operations time elapsed: " << time_count.count() << " seconds" << std::endl; 

    /****************************************************************/
    // Array operations time comparison

    start = high_resolution_clock::now();

    int testArr_new_size = 50;
    int *testArr_new = new(std::nothrow) int[50];
    int value_new = 0;

    if (testArr_new)
    {
        for(i = 0; i < testArr_new_size; i++)
        {
            testArr_new[i] = i;
        }
        value_new = testArr_new[25];
        delete[] testArr_new;
    }
    else
        std::cout << "testArr_new initialize failed!" << std::endl;

    end = high_resolution_clock::now();

    std::cout << value_new << std::endl;

    time_count = end - start;
    std::cout << "Array operations time elapsed: " << time_count.count() << " seconds" << std::endl;

    return 0;
}
