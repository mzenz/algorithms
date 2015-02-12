#include <iostream>
#include <vector>
#include <list>

// Sieve of Eratosthenes algorithm
void getPrimeNumbers(size_t n, std::list<size_t>& primes)
{
	std::vector<bool> v(n, false);
	v[0] = v[1] = true;

	for (size_t p = 2; p < n; ) {
		for (size_t i = 2 * p; i < n; i += p)
			v[i] = true;

		while (p < n && v[++p]);
	}
	for (size_t i = 0; i < n; ++i)
		if (!v[i])
			primes.push_back(i);
}

int main(int argc, const char * argv[])
{
	std::list<size_t> primes;
	size_t n = 120;
	getPrimeNumbers(n, primes);

	std::cout << primes.size() << " prime numbers found from 1 to " << n << std::endl;
	for (auto i : primes)
		std::cout << i << std::endl;
}
