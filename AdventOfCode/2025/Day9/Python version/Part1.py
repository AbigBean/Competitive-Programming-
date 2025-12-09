import itertools
with open('input.txt', 'r') as f:
    grid = [line.strip() for line in f if line.strip()]

coords = [tuple(map(int, line.split(','))) for line in grid]
max_area = 0

for p1, p2 in itertools.combinations(coords, 2):
    diff_x = abs(p1[0] - p2[0])
    diff_y = abs(p1[1] - p2[1])
    width = diff_x + 1  # bordes
    height = diff_y + 1 # bordes
    
    area = width * height
    if area > max_area:
        max_area = area


print(max_area)
