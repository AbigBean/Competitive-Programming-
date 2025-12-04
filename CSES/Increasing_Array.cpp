#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (i = 0; i < n; ++i)
#define REP(i,k,n) for (i = k; i <= n; ++i)
#define REPR(i,k,n) for (i = k; i >= n; --i)


int main() {
    long long n;
    cin >> n;
    long long result = 0;
    vector<long long int> numbers(n);
    for(int i = 0; i < n; i++) cin >> numbers[i];

    for(int j=0; j<n - 1; j++){
        if(numbers[j] > numbers[j + 1]){
            result += numbers[j] - numbers[j + 1];
            numbers[j + 1] = numbers[j];
        }
    }
    cout << result << endl;
    return 0;
}
