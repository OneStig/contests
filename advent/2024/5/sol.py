import sys
from collections import defaultdict

adj = defaultdict(set)
rev = defaultdict(set)

ans1 = 0
ans2 = 0

for line in sys.stdin:
    line = line.strip()

    if '|' in line:
        a, b = int(line.split('|')[0]), int(line.split('|')[1])
        adj[a].add(b)
        rev[b].add(a)

    elif ',' in line:
        nums = [int(x) for x in line.split(",")]
        good = True
        ns = set()

        for i in range(len(nums)):
            ns.add(nums[i])
            for j in range(i + 1, len(nums)):
                if nums[i] in adj[nums[j]]:
                    good = False

        if good:
            ans1 += nums[len(nums) // 2]
        else:
            newans = []

            while ns:
                for x in ns:
                    yes = True
                    for y in rev[x]:
                        if y in ns:
                            yes = False
                            break

                    if yes:
                        newans.append(x)
                        ns.remove(x)
                        break

            ans2 += newans[len(newans) // 2]
                        

print(ans1)
print(ans2)

