import sys

ans = 0

for line in sys.stdin:
    rep = list(map(int, line.split()))

    good = True
    dirs = set()
    for i in range(len(rep) - 1):
        if 1 <= abs(rep[i] - rep[i + 1]) <= 3:
            dirs.add((rep[i] - rep[i + 1]) / abs(rep[i] - rep[i + 1]))
        else:
            good = False
            break

    ans += 1 if good and len(dirs) == 1 else 0

    if not good or len(dirs) != 1:
        for j in range(len(rep)):
            rrep = []
            for k in range(len(rep)):
                if j != k:
                    rrep.append(rep[k])

            dirs = set()
            good = 1
            for i in range(len(rrep) - 1):
                if 1 <= abs(rrep[i] - rrep[i + 1]) <= 3:
                    dirs.add((rrep[i] - rrep[i + 1]) / abs(rrep[i] - rrep[i + 1]))
                else:
                    good = False
                    break

            if good and len(dirs) == 1:
                ans += 1
                break

print(ans)
