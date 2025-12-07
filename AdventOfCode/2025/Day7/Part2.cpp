#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("input.txt");
    if (!file.is_open()) return cerr << "ERROR", 1;
    
    //the reading part of the problem :(
    string line;
    vector<string> grid;
    while (getline(file, line)) {
        if (line.empty() || line.find_first_not_of(" \t\r\n") == string::npos) continue; 
        size_t end = line.find_last_not_of(" \t\r\n");
        if (string::npos != end) {
            line = line.substr(0, end + 1);
        } else {
            line = "";
        }
        
        if (!line.empty()) {
            grid.push_back(line);
        }
    }
    if (grid.empty()) return 0;

    // logic
    int start_col = -1;
    int start_row = -1;
    for (int r = 0; r < grid.size(); ++r) {
        size_t s_pos = grid[r].find('S');
        if (s_pos != string::npos) {
            start_row = r;
            start_col = static_cast<int>(s_pos);
            break;
        }
    }

    if (start_row == -1) return 0; 
    
    const int height = grid.size();
    const int width = grid[0].length();
    vector<vector<long long>> timeline(height, vector<long long>(width, 0));

    timeline[start_row][start_col] = 1; 

    for (int r = start_row; r < height; ++r) {
        for (int c = 0; c < width; ++c) {
            long long current = timeline[r][c];
            if (current == 0) continue; 
            char cell = grid[r][c];

            if (cell == '^') {
                if (c - 1 >= 0 && r + 1 < height) {
                    timeline[r + 1][c - 1] += current;
                }
                if (c + 1 < width && r + 1 < height) {
                    timeline[r + 1][c + 1] += current;
                }
                
            } 
            else { 
                if (r + 1 < height) {
                    timeline[r + 1][c] += current;
                }
            }
        }
    }

    long long result = 0;
    if (height > 0) {
        for (long long count : timeline[height - 1]) {
            result += count;
        }
    }
    
    cout << result << endl;
    
    return 0;
}