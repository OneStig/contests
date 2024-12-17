lines = open('input', 'r').read().splitlines()

seeds = [int(x) for x in lines[0].split(' ') if x.isdigit()]
maps = [[] for _ in range(7)]
cur = 0

for line in lines[3:]:
    if line.endswith('map:'):
        cur += 1
    elif line.strip() != '':
        nums = line.split(' ')
        maps[cur].append((nums[0], nums[1], nums[2]))

s_ranges = []

for i in range(len(seeds) // 2):
    s_ranges.append((seeds[i * 2], seeds[i * 2] + seeds[i * 2 + 1] - 1))

ans = 2 ** 64

for x in s_ranges:
    xx = [x]

    for m in maps:
                

    ans = min(ans, s)

print(ans)

