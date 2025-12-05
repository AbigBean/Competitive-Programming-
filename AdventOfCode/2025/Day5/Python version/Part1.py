# Part 1
with open("input.txt", "r") as file:
    lines = [line.strip() for line in file]

try:
    empty = lines.index("")
except ValueError:
    empty = len(lines)

fresh = []
for i in range(empty):
    start, end = map(int, lines[i].split("-"))
    fresh.append((start, end))

goodid = []
for i in range(empty + 1, len(lines)):
    if lines[i]:
        goodid.append(int(lines[i]))

counter = 0
for val in goodid:
    for start, end in fresh:
        if start <= val <= end:
            counter += 1
            break

print(counter)