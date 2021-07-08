#include <iostream>
#include <chrono>


using namespace std::chrono;


int ReversePalindrome(int x)
{
	int reverse_palindrome = 0;
	int single_digit = 0;

	while (x != 0)
	{
		single_digit = x % 10;
		reverse_palindrome = (reverse_palindrome * 10) + single_digit;
		x = x / 10;
	}
	return(reverse_palindrome);
}


int main()
{
	auto start = high_resolution_clock::now();

	int possible_palindrome = 0;
	int largest_palindrome = 0;

	for (int i = 100; i < 100000; ++i)
	{
		for (int j = 100; j < 100000; ++j)
		{
			possible_palindrome = i * j;
			
			if (possible_palindrome > largest_palindrome)
			{

				int reverse_palindrome = ReversePalindrome(possible_palindrome);

				if (possible_palindrome == reverse_palindrome)
				{
					largest_palindrome = possible_palindrome;
				}
			}
		}
	}

	std::cout << "The greatest palindrome number is " << largest_palindrome << std::endl;

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds> (stop - start);
	std::cout << duration.count() << std::endl;
	return 0;
}
