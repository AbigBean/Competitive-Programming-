with open('input.txt', 'r') as f:
    grid = [line.strip() for line in f if line.strip()]

start_col = -1
start_row = -1
for r, row in enumerate(grid):
    if 'S' in row:
        start_row = r
        start_col = row.index('S')
        break

height = len(grid)
width = len(grid[0])

current = {start_col}
result = 0

for r in range(start_row, height):
    proxim = set()
    for c in current:
        if 0 <= c < width:
            char = grid[r][c]
            if char == '^':
                result += 1
                if c - 1 >= 0:
                    proxim.add(c - 1)
                if c + 1 < width:
                    proxim.add(c + 1)
            else:
                proxim.add(c)
    
    current = proxim
    if not current:
        break
        
print(result)