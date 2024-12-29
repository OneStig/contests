import sys
from collections import defaultdict

wires = dict()

remain = dict()
prereq = dict()
adj = defaultdict(list)

process = []
zs = []

for line in sys.stdin:
    line = line.strip()
    if ':' in line:
        data = line.split(': ')
        wires[data[0]] = data[1] == '1'
        process.append(data[0])

        if data[0][0] == 'z':
            zs.append(data[0])

    if '->' in line:
        data = line.split(' -> ')
        remain[data[1]] = 2

        if data[1][0] == 'z':
            zs.append(data[1])
        
        lhs = data[0].split(' ')
        prereq[data[1]] = lhs
        adj[lhs[0]].append(data[1])
        adj[lhs[2]].append(data[1])

while process:
    cur = process[-1]
    process.pop()

    for nxt in adj[cur]:
        remain[nxt] -= 1

        if remain[nxt] == 0:
            match prereq[nxt][1]:
                case 'OR':
                    wires[nxt] = wires[prereq[nxt][0]] | wires[prereq[nxt][2]]
                case 'AND':
                    wires[nxt] = wires[prereq[nxt][0]] & wires[prereq[nxt][2]]
                case 'XOR':
                    wires[nxt] = wires[prereq[nxt][0]] ^ wires[prereq[nxt][2]]
                case _:
                    pass
            process.append(nxt)

zs.sort()

print(zs)
ans = 0
shift = 0
for z in zs:
    if wires[z]:
        ans += 1 << shift
    
    shift += 1

print(ans)

