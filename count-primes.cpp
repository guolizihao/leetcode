// https://leetcode.com/problems/count-primes/

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        if (n == 3) return 1;
        vector<bool> isPrime(n, true);
        int count = n - 2;
        for (int i = 2; i * i < n; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    if (isPrime[j]) {
                        isPrime[j] = false;
                        --count;
                    }
                }
            }
        }
        return count;
    }
};

// class Solution {
// public:
//     int countPrimes(int n) {
//         vector<bool> isPrime(n, true);
//         for (int i = 2; i * i < n; ++i) {
//             if (isPrime[i]) {
//                 for (int j = i * i; j < n; j += i) {
//                     isPrime[j] = false;
//                 }
//             }
//         }
//         int count = 0;
//         for (int i = 2; i < n; ++i) {
//             if (isPrime[i]) ++count;
//         }
//         return count;
//     }
// };
