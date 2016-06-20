# Large Prime

As part of an extra credit problem for Fundamentals of Computing (CSE20212) at Notre Dame, our class held a competition to write a C++ program that finds the largest prime given five minutes of compute time. This repository contains my program, which found the largest prime, beating out the second largest prime by several orders of magnitude.

359,999,982,000,000,151 was the number my program computed. My approach for finding a large primes took place in two steps: (1) compute a list of consecutive primes using the Sieve of Eratosthenes, and (2) square the largest prime found and decrement until a prime is found. The Sieve of Eratosthenes used in (1) is a well-known algorithm for finding consecutive primes; the core idea is that testing a number P for primality only requires one to divide P by all primes Q less than or equal to sqrt(P). If P is not divisible by any such Q, then P must be prime, and is added to list of primes. Other optimizations can be made, such are testing only odd numbers for primality. The square root function provided by the C++ library is computationally expensive, so I chose to use linearization to approximate the square root function.

Step (2) begins by taking the largest consecutive prime P found in (1) and then squaring it. Since, for any N < P^2, the only primes required to test N for primality are those less than P.
