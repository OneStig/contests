import sys
from collections import defaultdict

nodes = set()
gate = dict()

zs = []

rename = dict()

for line in sys.stdin:
    line = line.strip()
    if ':' in line:
        pass

    if '->' in line:
        data = line.split(' -> ')
        
        lhs = data[0].split(' ')

        gate[data[1]] = lhs
        nodes.add(data[1])
        nodes.add(lhs[0])
        nodes.add(lhs[2])

        if lhs[0][1:] == lhs[2][1:] and lhs[0][1:].isdigit():
            rename[data[1]] = lhs[1] + lhs[0][1:]
            
        if data[1][0] == 'z' and lhs[1] != 'XOR':
            print(line)

        if lhs[1] == 'XOR':
            print(f'{lhs[0]} -> {data[1]} [label="{lhs[1]}", color="red"]')
            print(f'{lhs[2]} -> {data[1]} [label="{lhs[1]}", color="red"]')
        else:
            print(f'{lhs[0]} -> {data[1]} [label="{lhs[1]}"]')
            print(f'{lhs[2]} -> {data[1]} [label="{lhs[1]}"]')

zs = []
for x in nodes:
    if x[0] == 'z':
        zs.append(x[0])

zs.sort()

# print(rename)

# z35, jbp
# z22, drg
# z15, jgc
# qjb, gvw < 08

# drg,gvw,jbp,jgc,qjb,z15,z22,z35