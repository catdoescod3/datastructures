#include "reverse.hpp"

static void swap(int* numbers, int a, int b)
{
	int temp = numbers[a];
	numbers[a] = numbers[b];
	numbers[b] = temp;
}

void reverse_between(int* numbers, int low, int high)
{
	if (low >= high) return;

	swap(numbers, low, high);	
	reverse_between(numbers, low + 1, high - 1);
}
