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


    // logic of the problem
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
    
    int height = grid.size();
    int width = grid[0].length();

    set<int> current_moves = {start_col};
    long long total_splits = 0;
    for (int r = start_row; r < height; ++r) {
        set<int> next_beams;
        for (int c : current_moves) {
            if (c >= 0 && c < width) {
                char char_in_grid = grid[r][c];
                
                if (char_in_grid == '^') {
                    total_splits++;
                
                    if (c - 1 >= 0) {
                        next_beams.insert(c - 1);
                    }
                    
                    if (c + 1 < width) {
                        next_beams.insert(c + 1);
                    }
                } else {
                    next_beams.insert(c);
                }
            }
        }
        current_moves = next_beams;

        if (current_moves.empty()) {
            break;
        }
    }
        
    cout << total_splits << endl;
    
    return 0;
}