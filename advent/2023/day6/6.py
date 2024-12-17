l = open('input', 'r').read().splitlines()

times = [int(x) for x in l[0].split(' ')]
dist = [int(x) for x in l[1].split(' ')]


ans = 1

for i, x in enumerate(times):
    opt = 0

    for k in range(x):
        if k * (x - k) > dist[i]:
            opt += 1

    ans *= opt

print(ans)
