#include <bits/stdc++.h>

#define rep(i,n) for (i = 0; i < n; ++i)
#define autorep(i,n) for (auto &i: n)
#define REP(i,k,n) for (i = k; i <= n; ++i)
#define REPR(i,k,n) for (i = k; i >= n; --i)

using namespace std;
typedef long long ll;


bool isPrime(ll num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    
    // Check if divisible by 2 or 3 quickly to skip many numbers
    if (num % 2 == 0 || num % 3 == 0) return false;
    
    // Check divisors from 5 up to sqrt(num)
    // Increment by 6 because primes > 3 are of the form 6k ± 1
    for (ll i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    
    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            ll n;
            cin >> n;
            
            ll current = n + 1; // Start searching from the next number
            while (true) {
                if (isPrime(current)) {
                    cout << current << "\n";
                    break;
                }
                current++;
            }
        }
    }
    
    return 0;
}
