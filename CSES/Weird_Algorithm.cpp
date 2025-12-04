#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (i = 0; i < n; ++i)
#define REP(i,k,n) for (i = k; i <= n; ++i)
#define REPR(i,k,n) for (i = k; i >= n; --i)

using namespace std;
int main()
{
    long long int number;
    cin >> number;

    while (number != 1) {
        cout << number << " ";
        if (number & 1LL) // checks if it is odd by comparing the last bit, if it is 1, it is odd.
            number = number * 3 + 1;
        else
            number /= 2;
    }
    cout << 1;
}
