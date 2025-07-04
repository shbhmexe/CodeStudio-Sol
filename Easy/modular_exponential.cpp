#include <bits/stdc++.h>
using namespace std;

int modularExponentiation(int x, int n, int m) {
    int result = 1;  // Should be 1 for multiplication based exponentiation

    while (n > 0) {
        if (n & 1) {
            result = (1LL * result * x) % m;
        }
        x = (1LL * x * x) % m;
        n = n >> 1;
    }
    return result;
}

int main() {
    int x = 2, n = 5, m = 1000000007;
    cout << modularExponentiation(x, n, m) << endl;  // Output: 32
    return 0;
}


// int modularExponentiation(int x, int n, int m) {
//     int result = 1;  // Should be 1 for multiplication based exponentiation

//     while (n > 0) {
//         if (n & 1) {
//             result = (1LL * result * x) % m;
//         }
//         x = (1LL * x * x) % m;
//         n = n >> 1;
//     }
//     return result;
// }