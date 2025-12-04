try:
    with open("input.txt", "r") as f:
        lines = []
        for line in f:
            stripped = line.rstrip('\n')
            if stripped != "":
                lines.append(stripped)
except FileNotFoundError:
    print("ERROR")
    exit()

if not lines:
    print(0)
    exit()



grid = [list(line) for line in lines]
rows = len(grid)
column = len(grid[0])
accessible = 0
directions = [(-1, -1), (-1, 0), (-1, 1),(0, -1), (0, 1), (1, -1),  (1, 0),  (1, 1)]


for i in range(rows):
    for j in range(column):
        if grid[i][j] == '@':
            count = 0
            for dx, dy in directions:
                ni = i + dx
                nj = j + dy
                if 0 <= ni < rows and 0 <= nj < column:
                    if grid[ni][nj] == '@':
                        count += 1
            if count < 4:
                accessible += 1

print(accessible)