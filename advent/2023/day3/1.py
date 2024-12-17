def check(g, r, c):
    if r < 0 or r >= len(g) or c < 0 or c >= len(g[0]):
        return False

    return g[r][c] != '.' and not g[r][c].isdigit()

with open('input', 'r') as f:
    grid = f.read().splitlines()

    sum = 0
    delta = [-1, 0, 1]

    i = 0
    while i < len(grid):
        row = grid[i]
        
        j = 0
        while j < len(row):
            if row[j].isdigit():
                cur = 0
                part_found = False

                while j < len(row) and row[j].isdigit():
                    cur *= 10
                    cur += int(row[j])
                    j += 1

                    for x in delta:
                        for y in delta:
                            part_found = part_found or check(grid, i, j)
                
                print(f'{cur} {part_found}')
                if part_found:
                    sum += cur
            j += 1

        i += 1
    
    print(sum)


