// Part 2
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("input.txt");
    if (!file.is_open()) return cerr << "ERROR", 1;

    vector<pair<long long, long long>> ranges;
    string line;

    while (getline(file, line)) {
        if (line.empty()) break;
        size_t dash = line.find('-');
        long long start = stoll(line.substr(0, dash));
        long long end = stoll(line.substr(dash + 1));
        ranges.emplace_back(start, end);
    }

    sort(ranges.begin(), ranges.end());

    vector<pair<long long, long long>> merged;
    for (auto& r : ranges) {
        if (merged.empty() || merged.back().second < r.first) {
            merged.push_back(r);
        } else {
            merged.back().second = max(merged.back().second, r.second);
        }
    }

    long long counter = 0;
    for (auto& r : merged) {
        counter += (r.second - r.first + 1);
    }

    cout << counter << '\n';
    return 0;
}