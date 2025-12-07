#include <bits/stdc++.h>
#define ll long long

#define rep(i,n) for (i = 0; i < n; ++i)
#define REP(i,k,n) for (i = k; i <= n; ++i)
#define REPR(i,k,n) for (i = k; i >= n; --i)
using namespace std;



int main() {
    // Trailing zeros come from factors of 5 in n! (2s are more than enough).
    // Count how many multiples of 5, 25, 125... are ≤ n.
    // n/5 + n/25 + n/125 + ...n is the formula for the trailing zeros
    ll n;
    cin >> n;

    ll zeros = 0;
    while (n > 0) {
        n /= 5;
        zeros += n;
    }
    cout << zeros << "\n";
    return 0;
}
