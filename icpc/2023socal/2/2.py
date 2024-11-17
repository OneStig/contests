from collections import defaultdict
import sys
import re

instr = []
varbs = defaultdict(int)
labels = dict()

for line in sys.stdin:
    line = line.strip()

    if len(line) == 0 or line[0] == '*':
        continue

    if ':' in line:
        labels[line.split(':')[0]] = len(instr)
        line = line.split(':')[1].strip()

    if line.startswith("set") or line.startswith("goto"):
        instr.append((line.split(' ', 2)))
    elif line.startswith("show"):
        instr.append((line.split(' ', 1)))
    elif line.startswith("halt"):
        instr.append(("halt"))

ip = 0

def expression(exp):
    used = set(re.split("[+-]", exp))
    for x in used:
        x = x.strip()
        if x.isalpha():
            exp = exp.replace(x, str(varbs[x]))

    return eval(exp)

while ip < len(instr):
    cur = instr[ip]

    if cur[0] == 'halt':
        break

    if cur[0] == 'show':
        print(expression(cur[1]))
    elif cur[0] == 'set':
        varbs[cur[1]] = expression(cur[2])
    elif cur[0] == 'gotoifz':
        if expression(cur[2]) == 0:
            ip = labels[cur[1]]
            continue
    elif cur[0] == 'gotoifp':
        if expression(cur[2]) > 0:
            ip = labels[cur[1]]
            continue
    elif cur[0] == 'gotoifm':
        if expression(cur[2]) < 0:
            ip = labels[cur[1]]
            continue

    ip += 1

