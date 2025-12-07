#include <bits/stdc++.h>
#include <fstream>
using namespace std;

long long safe_stoll(const string& s) {
    try {
        return stoll(s);
    } catch (...) {
        return 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("input.txt");
    if (!file.is_open()) return cerr << "ERROR", 1;

    string line;
    vector<string> lines;
    size_t maxlen = 0;

    while (getline(file, line)) {
        if (line.empty()) break;
        lines.push_back(line);
        maxlen = max(maxlen, line.size());
    }

    for (auto& l : lines) {
        l.resize(maxlen, ' ');
    }

    long long grtotal = 0; 
    int rows = (int)lines.size();
    if (rows == 0) {
        cout << 0 << endl;
        return 0;
    }


    int col = 0;
    while (col < (int)maxlen) {
        while (col < (int)maxlen) {
            bool allspaces = true;
            for (int r = 0; r < rows; ++r) {
                if (lines[r][col] != ' ') {
                    allspaces = false;
                    break;
                }
            }
            if (!allspaces) break;
            col++;
        }

        if (col >= (int)maxlen) break;
        int startcol = col;
        while (col < (int)maxlen) {
            bool allspaces = true;
            for (int r = 0; r < rows; ++r) {
                if (lines[r][col] != ' ') {
                    allspaces = false;
                    break;
                }
            }
            if (allspaces) break;
            col++;
        }
        int endcol = col;
        vector<long long> numbers; 
        char op = '+';

        if (rows > 0) {
            string op_str = "";
            for (int c = startcol; c < endcol; ++c) {
                if (lines[rows - 1][c] != ' ') {
                    op_str += lines[rows - 1][c];
                }
            }
            if (op_str.size() == 1 && (op_str[0] == '+' || op_str[0] == '*')) {
                op = op_str[0];
            }
        }
        
        for (int c = endcol - 1; c >= startcol; --c) {
            long long current_number = 0;
            long long powerr = 1;
            bool number_found = false;

            for (int r = rows - 2; r >= 0; --r) {
                char ch = lines[r][c];
                
                if (isdigit(ch)) {
                    current_number += (ch - '0') * powerr;
                    powerr *= 10;
                    number_found = true;
                } 
            }
            if (number_found) {
                numbers.push_back(current_number);
            }
        }
        
        long long result = (op == '+') ? 0LL : 1LL;
        for (long long val : numbers) {
            if (op == '+') {
                result += val;
            } else {
                result *= val;
            }
        }

        grtotal += result;
    }

    cout << grtotal << endl;
    return 0;
}