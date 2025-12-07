#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for (i = 0; i < n; ++i)
#define REP(i,k,n) for (i = k; i <= n; ++i)
#define REPR(i,k,n) for (i = k; i >= n; --i)
using namespace std;

ll MOD = 1e9 + 7;

// using the Binary Exponentiation alg.
ll binary_exponentiation(ll base, ll expo) {
    ll result = 1;
    while(expo){
        if (expo & 1){
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        expo >>= 1LL;
    }
    return result;
}

int main() {
    ll number;
    cin >> number;
    // combinatorics 2 ** N because we have two possible digits (1, 0)
    // and we apply them for 3 spaces
    cout << binary_exponentiation(2, number) << endl;
    return 0;
}