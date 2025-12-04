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
    int cols = grid[0].size();
    int totalremoved = 0;

    vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

    while (true) {
        vector<pair<int, int>> toremove;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] != '@') continue;

                int count = 0;
                for (int d = 0; d < 8; ++d) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && grid[ni][nj] == '@') {
                        count++;
                    }
                }

                if (count < 4) {
                    toremove.push_back({i, j});
                }
            }
        }

        if (toremove.empty()) break;

        for (auto [i, j] : toremove) {
            grid[i][j] = '.';
        }

        totalremoved += toremove.size();
    }

    cout << totalremoved << '\n';
    return 0;
}