// PART 1 
// using precalculation of the invalid IDs

#include <bits/stdc++.h>
#include <fstream>
using namespace std;

struct Pair {
    long long start;
    long long end;
};


bool isInvalidID(long long num) {
    string s = to_string(num);
    int n = s.size();
    if (n % 2 != 0) return false;
    int half = n / 2;
    return s.substr(0, half) == s.substr(half);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("input.txt");
    if (!file.is_open()) return cerr << "ERROR", 1;

    vector<Pair> data;
    string line;
    getline(file, line);

    stringstream ss(line);
    string range;
    while (getline(ss, range, ',')) {
        size_t dash = range.find('-');
        long long start = stoll(range.substr(0, dash));
        long long end = stoll(range.substr(dash + 1));
        data.push_back({start, end});
    }

    long long total = 0;
    const long long MAX_LEN = 12; 

    for (int len = 2; len <= MAX_LEN; len += 2) {
        int half = len / 2;
        long long start_val = pow(10, half - 1);
        long long end_val = pow(10, half) - 1;

        for (long long prefix = start_val; prefix <= end_val; ++prefix) {
            string s = to_string(prefix);
            string doubled = s + s;
            long long num = stoll(doubled);

            for (const auto& p : data) {
                if (num >= p.start && num <= p.end) {
                    total += num;
                    break; 
                }
            }
        }
    }

    cout << total << '\n';

    return 0;
}
