// Part 1
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

    long long counter = 0;

    while (getline(file, line)) {
        if (line.empty()) continue;
        long long id = stoll(line);
        bool fresh = false;
        for (auto& [start, end] : ranges) {
            if (id >= start && id <= end) {
                fresh = true;
                break;
            }
        }
        if (fresh) {
            counter++;
        }
    }

    cout << counter << '\n';
    return 0;
}