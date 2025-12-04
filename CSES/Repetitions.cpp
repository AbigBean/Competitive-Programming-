#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (i = 0; i < n; ++i)
#define REP(i,k,n) for (i = k; i <= n; ++i)
#define REPR(i,k,n) for (i = k; i >= n; --i)


int main() {
    
    int count = 1;
    int result = 1;
    string line;
    cin>> line;

    for(int i=0; i < line.length() - 1; i++){

        if (line[i] == line[i+1]){
            count += 1;

        } else{
            count = 1;
        }
        result =  max(result, count);
    }
    cout << result;
 
    return 0;
}

