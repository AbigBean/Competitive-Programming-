#include <bits/stdc++.h>
 
#define rep(i,n) for (i = 0; i < n; ++i)
#define autorep(i,n) for (auto &i: n)
#define REP(i,k,n) for (i = k; i <= n; ++i)
#define REPR(i,k,n) for (i = k; i >= n; --i)
 
using namespace std;
typedef long long ll;
 
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
 
    string n;
    cin >> n;
    vector<string> unique_permutations;
    sort(n.begin(), n.end());
 
 
    unique_permutations.push_back(n);
 
    while(next_permutation(n.begin(), n.end())){
        unique_permutations.push_back(n);
    }
 
    cout << unique_permutations.size() << endl;
    for (const string& s : unique_permutations) {
        cout << s << "\n";
    }
    return 0;
}