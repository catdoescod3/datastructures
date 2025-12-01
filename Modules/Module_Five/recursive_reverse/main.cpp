#include "reverse.hpp"
#include <cstddef>
#include <print>

using std::println;
using std::print;

void print_numbers(int* numbers, std::size_t size)
{
    for (std::size_t i = 0; i < size; i++)
        print("{} ", numbers[i]);
}

void print_test_header(const char* name)
{
    println("\n=== {} ===", name);
}

int main()
{
    //
    // Basic test: full reverse
    //
    print_test_header("Test 1: Full reverse");
    int numbers1[] = {1, 2, 3, 4, 5};
    print("Original: "); print_numbers(numbers1, 5); println();
    reverse_between(numbers1, 0, 4);
    print("Reversed: "); print_numbers(numbers1, 5); println();


    //
    // Reverse back
    //
    print_test_header("Test 2: Full reverse again");
    reverse_between(numbers1, 0, 4);
    print("Restored: "); print_numbers(numbers1, 5); println();


    //
    // Middle reverse
    //
    print_test_header("Test 3: Reverse middle [1, 3]");
    int numbers2[] = {1, 2, 3, 4, 5};
    reverse_between(numbers2, 1, 3);
    print("Result:   "); print_numbers(numbers2, 5); println();


    //
    // Reverse single element (should stay the same)
    //
    print_test_header("Test 4: Reverse single element [2, 2]");
    int numbers3[] = {10, 20, 30, 40, 50};
    reverse_between(numbers3, 2, 2);
    print("Result:   "); print_numbers(numbers3, 5); println();


    //
    // Reverse two adjacent elements
    //
    print_test_header("Test 5: Reverse adjacent [1, 2]");
    int numbers4[] = {5, 4, 3, 2, 1};
    reverse_between(numbers4, 1, 2);
    print("Result:   "); print_numbers(numbers4, 5); println();


    //
    // Reverse almost entire array except edges
    //
    print_test_header("Test 6: Reverse [1, 3] on array of 5");
    int numbers5[] = {10, 20, 30, 40, 50};
    reverse_between(numbers5, 1, 3);
    print("Result:   "); print_numbers(numbers5, 5); println();


    //
    // Reverse array of size 1
    //
    print_test_header("Test 7: Reverse array of size 1");
    int numbers6[] = {99};
    reverse_between(numbers6, 0, 0);
    print("Result:   "); print_numbers(numbers6, 1); println();


    //
    // Reverse empty array
    //
    print_test_header("Test 8: Reverse empty array");
    int numbers7[] = {};
    reverse_between(numbers7, 0, 0);
    print("Result:   (empty)"); println();


    //
    // Reverse with start > end (if your function does nothing)
    //
    print_test_header("Test 9: start > end");
    int numbers8[] = {1, 2, 3, 4, 5};
    reverse_between(numbers8, 4, 1);
    print("Result:   "); print_numbers(numbers8, 5); println();


    //
    // Reverse already reversed array
    //
    print_test_header("Test 10: Reverse reversed array");
    int numbers10[] = {9, 8, 7, 6, 5};
    reverse_between(numbers10, 0, 4);
    print("Result:   "); print_numbers(numbers10, 5); println();


    //
    // Reverse alternating pattern
    //
    print_test_header("Test 11: Reverse alternating pattern");
    int numbers11[] = {1, 9, 1, 9, 1, 9};
    reverse_between(numbers11, 0, 5);
    print("Result:   "); print_numbers(numbers11, 6); println();

    return 0;
}

