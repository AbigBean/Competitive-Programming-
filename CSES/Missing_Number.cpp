#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (i = 0; i < n; ++i)
#define REP(i,k,n) for (i = k; i <= n; ++i)
#define REPR(i,k,n) for (i = k; i >= n; --i)


int main() {
    long long n;
    cin >> n;

    long long total = n * (n + 1) / 2; 
    //becase if we sum all numbers and then calulate the sum of numbers
    // the difference will be our number to find :)

    long long sum = 0; // our sum of the input numbers 

    for (int i = 0; i < n - 1; i++) {
        long long x;
        cin >> x;
        sum += x;
    }

    cout << total - sum;
    return 0;
}
