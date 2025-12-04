#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (i = 0; i < n; ++i)
#define REP(i,k,n) for (i = k; i <= n; ++i)
#define REPR(i,k,n) for (i = k; i >= n; --i)


int main() {
    long long n;
    cin >> n;

    // first outputting all the even numbers up to n and then all the odd numbers up to n. 
    if(n == 2 || n == 3){
        cout << "NO SOLUTION";
        return 0;
    }
    for (int i = 2; i <= n; i = i + 2) {
        cout << i << " ";
    }
    for (int i = 1; i <= n; i = i + 2) {
        cout << i << " ";
    }
    return 0;
}
