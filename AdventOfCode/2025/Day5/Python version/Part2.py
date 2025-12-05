# Part 1
with open("input.txt", "r") as file:
    lines = [line.strip() for line in file]

try:
    empty = lines.index("")
except ValueError:
    empty = len(lines)

fresh = []
for i in range(empty):
    try:
        start, end = map(int, lines[i].split("-"))
        fresh.append((start, end))
    except ValueError:
        continue

if not fresh:
    print(0)
else:
    fresh.sort()
    merged = [fresh[0]]

    for start, end in fresh[1:]:
        last_start, last_end = merged[-1]
        if start <= last_end + 1:
            merged[-1] = (last_start, max(last_end, end))
        else:
            merged.append((start, end))

    total = sum(end - start + 1 for start, end in merged)
    print(total)
