with open('input.txt', 'r') as file:
    grid = [line.strip() for line in file if line.strip()]

start_col = -1
start_row = -1
for r, row in enumerate(grid):
    if 'S' in row:
        start_row = r
        start_col = row.index('S')
        break
        
height = len(grid)
width = len(grid[0])

current = {start_col: 1}

for r in range(start_row, height):
    next_time = {}
    for c, count in current.items():
        char = grid[r][c]  
        if char == '^':
            if c - 1 >= 0:
                next_time[c - 1] = next_time.get(c - 1, 0) + count
            if c + 1 < width:
                next_time[c + 1] = next_time.get(c + 1, 0) + count
        else:
            next_time[c] = next_time.get(c, 0) + count  
    current = next_time
    if not current:
        break
        
result = sum(current.values())
print(result)