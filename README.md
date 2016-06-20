# Large Prime

As part of an extra credit problem for Fundamentals of Computing II ([CSE 20212](http://www3.nd.edu/~semrich/fund2.html)) at Notre Dame, our class held a competition to write a C++ program that finds the largest prime given five minutes of compute time. This repository contains my program, which found the largest prime, beating out the second largest prime by several orders of magnitude.

359,999,982,000,000,151 was the output of my program. My approach for finding a large primes took place in two steps: (1) compute a list of consecutive primes using the [Sieve of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes), and (2) square the largest prime found and decrement until a prime is found. The Sieve used in (1) is a well-known algorithm for finding consecutive primes; the core idea is that testing a number P for primality only requires one to divide P by all primes Q less than or equal to sqrt(P). If P is not divisible by any such Q, then P must be prime, and is added to list of primes. Other optimizations can be made, such are testing only odd numbers for primality. The square root function provided by the C++ library is computationally expensive, so I chose to use [linearization](https://en.wikipedia.org/wiki/Linearization) to approximate the square root function.

Step (2) begins by taking the largest consecutive prime P found in (1) and then squaring it. Since, for any N < P^2, the only primes required to test N for primality are those less than P, we can in fact test any such N for primality using only the primes found in the first step. Starting with N = P^2, my program tests whether N is prime, and if it is not, it decrements N by 2. The [Prime Number Theorem](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes), a result on the distribution of primes in the natural numbers, guarantees that this procedure will termninate fairly quickly.

The second step of the program is really what allowed for the calculation of such a large prime. The first step can actually be sped up considerably using bitsets; this was the approach taken by [Thomas Potthast](https://www.linkedin.com/in/thomas-potthast-0bb76b44), another student taking the course. Though his program did not find nearly as large a prime as mine, the number of consecutive integers his program found in five minutes was roughly an order of magnitude larger than the number of primes found by my program.

Notice that 359,999,982,000,000,151 is not far from [ULLONG\_MAX](http://www.cplusplus.com/reference/climits/). Perhaps ULLONG\_MAX can be surpassed if my program were to use bitsets when calculating a list of consective primes.
