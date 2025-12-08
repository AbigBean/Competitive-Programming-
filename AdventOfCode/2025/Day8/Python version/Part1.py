from collections import defaultdict

class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n
        self.components = n

    def find(self, a):
        if self.parent[a] != a:
            self.parent[a] = self.find(self.parent[a])
        return self.parent[a]

    def union(self, a, b):
        ra = self.find(a)
        rb = self.find(b)
        if ra == rb:
            return False
        if self.size[ra] < self.size[rb]:
            ra, rb = rb, ra
        self.parent[rb] = ra
        self.size[ra] += self.size[rb]
        self.components -= 1
        return True

with open('input.txt', 'r') as f:
    grid = [line.strip() for line in f if line.strip()]

points = []
for line in grid:
    coords = tuple(map(int, line.split(',')))
    points.append(coords)

n = len(points)


pairs = []
for i in range(n):
    for j in range(i + 1, n):
        x1, y1, z1 = points[i]
        x2, y2, z2 = points[j]
        distance = (x1 - x2)**2 + (y1 - y2)**2 + (z1 - z2)**2
        pairs.append((distance, i, j))


pairs.sort(key=lambda x: x[0])
tosee = pairs[:1000]

uf = UnionFind(n)
for distance, i, j in tosee:
    uf.union(i, j)


component_sizes = defaultdict(int)
for i in range(n):
    root = uf.find(i)
    component_sizes[root] = uf.size[root]

sizes = list(component_sizes.values())
sizes.sort(reverse=True)


if len(sizes) < 3:
    while len(sizes) < 3:
        sizes.append(1)

result = sizes[0] * sizes[1] * sizes[2]
print(result)