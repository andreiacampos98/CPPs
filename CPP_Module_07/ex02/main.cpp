#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Array.hpp"

#define MAX_VAL 15
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    std::cout << "Default values" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << "Number[" << i << "] = " << numbers[i] << std::endl;
        std::cout << "Mirror[" << i << "] = " << mirror[i] << std::endl;
    }
    std::cout << "Random values" << std::endl;
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
        std::cout << "Number[" << i << "] = " << value << std::endl;
        std::cout << "Mirror[" << i << "] = " << value << std::endl;
    }
    //SCOPE
    {
        std::cout << "\nTesting copy\n";
        Array<int> tmp;
        tmp = numbers;
        Array<int> test(tmp);
        for (int i = 0; i < MAX_VAL; i++)
        {
            std::cout << "Number[" << i << "] = " << numbers[i] << std::endl;
            std::cout << "Tmp[" << i << "]    = " << tmp[i] << std::endl;
            std::cout << "Test[" << i << "]   = " << test[i] << std::endl;
        }
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        Array<int> test1(-2);
        //int* test2 = new int[-2];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
