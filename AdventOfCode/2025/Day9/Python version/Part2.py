import itertools

with open('input.txt', 'r') as f:
    grid = [line.strip() for line in f if line.strip()]
    coords = [tuple(map(int, line.split(','))) for line in grid]

num_points = len(coords)
edges = []
for i in range(num_points):
    p1, p2 = coords[i], coords[(i + 1) % num_points]
    x1, y1, x2, y2 = p1[0], p1[1], p2[0], p2[1]
    

    if x1 == x2:
        edges.append({'tipo': 'V', 'x': x1, 'y_min': min(y1, y2), 'y_max': max(y1, y2)})
    else:
        edges.append({'tipo': 'H', 'y': y1, 'x_min': min(x1, x2), 'x_max': max(x1, x2)})

max_area = 0


for p1, p2 in itertools.combinations(coords, 2):
    rx_min, rx_max = min(p1[0], p2[0]), max(p1[0], p2[0])
    ry_min, ry_max = min(p1[1], p2[1]), max(p1[1], p2[1])
    current_area = (rx_max - rx_min + 1) * (ry_max - ry_min + 1)
    if current_area <= max_area: continue


    is_invalid_by_crossing = any(
        (edge['tipo'] == 'V' and rx_min < edge['x'] < rx_max and not (edge['y_max'] <= ry_min or edge['y_min'] >= ry_max)) or
        (edge['tipo'] == 'H' and ry_min < edge['y'] < ry_max and not (edge['x_max'] <= rx_min or edge['x_min'] >= rx_max))
        for edge in edges
    )
    if is_invalid_by_crossing: continue

    mid_x, mid_y = (rx_min + rx_max) / 2.0, (ry_min + ry_max) / 2.0
    intersections = sum(1 for edge in edges if edge['tipo'] == 'V' and edge['x'] > mid_x and edge['y_min'] <= mid_y <= edge['y_max'])
    

    if intersections % 2 == 1:
        max_area = current_area

print(max_area)
