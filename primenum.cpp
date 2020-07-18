// Written by Vikram Saraph
// Fundamentals of Computing II
// Homework 2, Ironcoder

#include <iostream>
#include <ctime>

// Run for approximately 4 and a half minutes
#define DURATION 285

using namespace std;

some garbage

// Avoiding function calls... they're expensive!
// Cast to long int only when necessary.
// long int arithmetic is much slower.
// Storing a square root once is faster than
// squaring with each pass.

int main(void) {
	// Start timing
	time_t start;
	time_t stop;
	time(&start);

	// Initial conditions to start the sieve
	int* primes = new int[100000000];
	primes[0] = 2;
	cout << 2 << endl;
	int testdivisor;
	int nprimes = 1;
	int n = 3;

	// Upper bound for testing divisors
	// Square root of n
	float primalbound = 1.732;
	int i;

	// Start sieving
	// This list of primes will be used to check primality
	// for much larger numbers
	// Stop when time is called

	while (1) {
		// Check to stop every millionth pass
		if (n % 1000000 == 1) {
			time(&stop);
			if (difftime(stop, start) > DURATION)
				break;
		}
		// Check for primality
		for(i = 0; i < nprimes; i++) {
			testdivisor = primes[i];
			// If bound is exceeded, then n is prime
			if (testdivisor > primalbound) {
				primes[nprimes] = n;
				nprimes += 1;
				cout << n << endl;
				break;
			}
			if (n % testdivisor == 0)
				break;
		}

		// Skip the even numbers
		n += 2;

		// Linear approximation for next square-root bound
		// It is an overestimate, but it becomes increasingly
		// accurate as n approaches infinity
		// Converges fast to actual square root
		primalbound += 1/primalbound;
	}
	cout << "Number of primes: " << nprimes << endl;
	cout << "---- END CONSECUTIVE PRIMES ----" << endl;

	// Time to test primality for much larger integers
	// Thanks to the prime number theorem, the following is
	// relatively quick compared with the previous step
	// Start testing with the square of the largest prime found
	// since every composite number less than this must be divisible
	// by some number from the previously generated list

	// Need long int because of int bounds
	long int hugeprime;
	long int largestprime = primes[nprimes - 1] - 2;
	long int hugeprimetest = largestprime * largestprime;

	// Check for primality
	// If composite, then decrement by two and try again

	while (1) {
		for(i = 0; i < nprimes; i++) {
			testdivisor = primes[i];
			if (hugeprimetest % testdivisor == 0) {
				break;
			}
		}
		// Stop when a prime is found; we want the largest one
		if (i == nprimes) {
			hugeprime = hugeprimetest;
			primes[nprimes] = hugeprime;
			cout << "LARGEST PRIME FOUND: " << hugeprime << endl;
			break;
		}
		hugeprimetest -= 2;
	}
	// Cleanup
	delete [] primes;
	return 0;
}
