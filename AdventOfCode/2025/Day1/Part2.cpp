// PART 2

#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int direction(char letter){

    if (letter == 'R') return 1;
    if (letter == 'L') return -1;
    return 0;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("input.txt");
    if (!file.is_open()) return cerr << "ERROR", 1;

    int position = 50;
    int countZeros = 0;
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;

        char direct = line[0];
        int distance = stoi(line.substr(1));

        for (int i = 0; i < distance; ++i) {
            if (direction(direct) == 1) {
                position = (position + 1) % 100;
            } else {
                position = (position - 1 + 100) % 100;
            }
            if (position == 0) {
                countZeros++;
            }
        }
    }

    cout << countZeros << '\n';
    return 0;
}