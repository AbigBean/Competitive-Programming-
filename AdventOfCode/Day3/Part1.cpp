#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("input.txt");
    if (!file.is_open()) {
        cerr << "ERROR";
        return 1;
    }

    string line;
    long long total = 0;

    while (getline(file, line)) {
        if (line.empty()) continue;

        int maxJoltage = 0;
        int n = line.size();

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int num = (line[i] - '0') * 10 + (line[j] - '0');
                if (num > maxJoltage) {
                    maxJoltage = num;
                }
            }
        }

        total += maxJoltage;
    }

    cout << total << '\n';
    return 0;
}