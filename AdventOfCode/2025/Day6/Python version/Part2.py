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
    end = col

    op = '+'
    for c in range(start, end):
        ch = grid[height - 1][c]
        if ch in '+*':
            op = ch
            break
    numbers = []
    for c in range(start, end):
        digits = []
        for r in range(height - 1):
            ch = grid[r][c]
            if ch != ' ':
                digits.append(ch)
        if digits:
            num = int(''.join(digits))
            numbers.append(num)


    if op == '+':
        result = sum(numbers)
    else:
        result = 1
        for n in numbers:
            result *= n

    total += result

print(total)