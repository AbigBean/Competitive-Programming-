// PART 2
// Using brute-force

#include <bits/stdc++.h>
#include <fstream>
using namespace std;

bool isInvalidID(long long num) {
    string s = to_string(num);
    int n = s.length();

    for (int block_len = 1; block_len <= n / 2; ++block_len) {
        if (n % block_len != 0) continue;

        string block = s.substr(0, block_len);
        bool valid = true;
        int k = n / block_len;
        for (int i = 1; i < k; ++i) {
            if (s.substr(i * block_len, block_len) != block) {
                valid = false;
                break;
            }
        }
        if (valid) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("input.txt");
    if (!file.is_open()) return cerr << "ERROR", 1;
    

    vector<pair<long long, long long>> ranges;
    string line;
    getline(file, line);

    stringstream ss(line);
    string token_key;
    while (getline(ss, token_key, ',')) {
        size_t pos = token_key.find('-');
        long long start = stoll(token_key.substr(0, pos));
        long long end = stoll(token_key.substr(pos + 1));
        ranges.push_back(make_pair(start, end));
    }

    unordered_set<long long> visited;
    long long total = 0;

    for (const auto& range : ranges) {
        long long start = range.first;
        long long end = range.second;
        for (long long num = start; num <= end; ++num) {
            if (visited.find(num) != visited.end()) continue;
            if (isInvalidID(num)) {
                visited.insert(num);
                total += num;
            }
        }
    }

    cout << total << '\n';
    return 0;
}