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
uf = UnionFind(n)
product = None

for distance, i, j in pairs:
    if uf.union(i, j):
        if uf.components == 1:
            x1 = points[i][0]
            x2 = points[j][0]
            product = x1 * x2
            break

print(product)