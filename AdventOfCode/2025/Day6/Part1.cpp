#include <bits/stdc++.h>
#include <fstream>
using namespace std;

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
        int endCol = col;

        vector<string> numbers;
        char op = '+';

        for (int r = rows - 1; r >= 0; --r) {
            string nums = "";
            for (int c = startcol; c < endCol; ++c) {
                if (lines[r][c] != ' ') {
                    nums += lines[r][c];
                }
            }
            if (nums.empty()) continue;

            if (nums == "+" || nums == "*") {
                op = nums[0];
            } else {
                string normalnum = "";
                for (char ch : nums) {
                    if (ch != ' ') normalnum += ch;
                }
                if (!normalnum.empty()) {
                    numbers.push_back(normalnum);
                }
            }
        }
        long long result = (op == '+') ? 0LL : 1LL;
        for (const string& nums : numbers) {
            long long val = stoll(nums);
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