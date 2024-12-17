with open('input', 'r') as f:
    lines = f.read().splitlines()
    
    seeds = []

    for a in lines[0].split(' '):
        if a.isdigit():
            seeds.append(int(a))

    maps = [{} for _ in range(7)]

    cur = -1

    for line in lines[2:]:
        if line.endswith('map:'):
            cur += 1
        elif line.strip() != '':
            nums = line.split(' ')

            maps[cur][(int(nums[1]), int(nums[2]))] = int(nums[0])
    
    ans = 2 ** 32
    for s in seeds:
        for i in range(7):
            for k in maps[i]:
                if s >= k[0] and s <= k[0] + k[1] - 1:
                    s = s - k[0] + maps[i][k]
                    break

        ans = min(ans, s)

    print(ans)
