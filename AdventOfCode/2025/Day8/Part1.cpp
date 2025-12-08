#include <bits/stdc++.h>
#include <fstream>
using namespace std;

struct UnionFind {
    vector<int> parent, size;
    int components;

    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);
        components = n;
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (size[x] < size[y]) swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        --components;
        return true;
    }
};

int main() {


    ifstream file("input.txt");
    if (!file.is_open()) return cerr << "ERROR", 1;

    string line;
    vector<tuple<long long, long long, long long>> points;

    while (getline(file, line)) {
        if (line.empty()) continue;
        replace(line.begin(), line.end(), ',', ' ');
        stringstream ss(line);
        long long x, y, z;
        ss >> x >> y >> z;
        points.push_back({x, y, z});
    }

    int n = points.size();
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<tuple<long long, int, int>> pairs;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            auto [x1, y1, z1] = points[i];
            auto [x2, y2, z2] = points[j];
            long long dx = x1 - x2;
            long long dy = y1 - y2;
            long long dz = z1 - z2;
            long long dist_sq = dx*dx + dy*dy + dz*dz;
            pairs.push_back({dist_sq, i, j});
        }
    }


    sort(pairs.begin(), pairs.end());


    UnionFind uf(n);
    int connections = 0;
    int max_connections = 1000;

    for (auto &[dist_sq, i, j] : pairs) {
        if (connections >= max_connections) break;
        uf.unite(i, j);
        connections++;
    }


    vector<int> components;
    for (int i = 0; i < n; ++i) {
        if (uf.find(i) == i) {
            components.push_back(uf.size[i]);
        }
    }


    sort(components.rbegin(), components.rend());
    while (components.size() < 3) components.push_back(1);

    long long result = 1LL * components[0] * components[1] * components[2];
    cout << result << endl;

    return 0;
}