#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("input.txt");
    if (!file.is_open()) return cerr << "ERROR", 1;


    string line;
    unsigned long long total = 0;

    while (getline(file, line)) {

        if (line.empty()) continue;
        if (line.back() == '\r') line.pop_back();
        if (line.empty()) continue;

        int n = line.size();
        const int keep = 12;
        if (n < keep) continue;


        int to_remove = n - keep;
        string result;
        result.reserve(n);



        for (char c : line) {
            while (!result.empty() && c > result.back() && to_remove > 0) {
                result.pop_back();
                to_remove--;
            }
            result.push_back(c);
        }

        result.resize(keep);
        unsigned long long number = 0;
        for (char c : result) {
            number = number * 10 + (c - '0');
        }
        total += number;
    }

    cout << total << '\n';
    return 0;
}