with open("input.txt") as f:
    lines = []
    for line in f:
        if line.strip() == "":
            break
        lines.append(line.rstrip('\n'))


width = max(len(line) for line in lines)
grid = [line.ljust(width) for line in lines]
height = len(grid)

total = 0
col = 0

while col < width:
    if all(grid[r][col] == ' ' for r in range(height)):
        col += 1
        continue
    start = col
    while col < width and any(grid[r][col] != ' ' for r in range(height)):
        col += 1
    problem_cols = [grid[r][start:col] for r in range(height)]
    numbers = []
    op = '+'
    for row in reversed(problem_cols):
        s = row.strip()
        if not s:
            continue
        if s in '+*':
            op = s
        else:
            numbers.append(int(s.replace(' ', '')))
    if op == '+':
        result = sum(numbers)
    else:
        result = 1
        for n in numbers:
            result *= n

    total += result

print(total)