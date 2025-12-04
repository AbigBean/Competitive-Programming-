#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("input.txt");
    if (!file.is_open()) return cerr << "ERROR", 1;

    vector<string> grid;
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;
        grid.push_back(line);
    }

    if (grid.empty()) {
        cout << 0 << '\n';
        return 0;
    }

    int rows = grid.size();
    int column = grid[0].size();
    int accessible = 0;

    vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < column; ++j) {
            if (grid[i][j] != '@') continue;

            int count = 0;
            for (int k = 0; k < 8; ++k) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx >= 0 && nx < rows && ny >= 0 && ny < column && grid[nx][ny] == '@') {
                    count++;
                }
            }

            if (count < 4) {
                accessible++;
            }
        }
    }

    cout << accessible << '\n';
    return 0;
}
