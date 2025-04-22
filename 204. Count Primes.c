/*
Given an integer n, return the number of prime numbers that are strictly less than n.

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0
 

Constraints:

0 <= n <= 5 * 106
*/

int countPrimes(int n) {
    if(n <= 2){
        return 0;
    }
    
    int *primes = calloc(n, sizeof(int));
    primes[0] = false;
    primes[1] = false;
    for(int i=2; i<n; i++){
        primes[i] = true;
    }

    int sqrt_n = (int)sqrt(n);
    for(int i=2; i<n; i++){
        if(sqrt_n <= primes[i]){
            break;
        }

        if(primes[i]){
            int multi_i = i*2;
            while(multi_i < n){
                primes[multi_i] = false;
                multi_i = multi_i + i;
            }
        }
    }

    int count=0;
    for(int i=0; i<n; i++){
        if(primes[i]){
            count++;
        }
    }
    free(primes);
    return count;
}
