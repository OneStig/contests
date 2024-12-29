import sys

keypad = [
    "789",
    "456",
    "123",
    " 0A"
]

direc = [
    " ^A",
    "<v>"
]

kpd = dict()
dirc = dict()

for i in range(4):
    for j in range(3):
        kpd[keypad[i][j]] = (i, j)

for i in range(2):
    for j in range(3):
        dirc[direc[i][j]] = (i, j)

ans = 0

def doseq(diction, old_seq):
    sequences = [""]
    cur_kpd = 'A'
    for c in old_seq:
        dr, dc = diction[cur_kpd]
        dr -= diction[c][0]
        dc -= diction[c][1]

        lr = ""
        if dc > 0:
            lr += "<" * dc
        else:
            lr += ">" * -dc

        ud = ""
        if dr > 0:
            ud += "^" * dr
        else:
            ud += "v" * -dr

        local_seq = []
        if diction == kpd:
            # 3, 0
            if (diction[cur_kpd][0], diction[c][1]) == (3, 0) or (diction[c][0], diction[cur_kpd][1]) == (3, 0):
                if dr > 0:
                    local_seq.append(ud + lr)
                else:
                    local_seq.append(lr + ud)
            else:
                if lr == "" or ud == "":
                    local_seq.append(lr + ud)
                else:
                    local_seq.append(lr + ud)
                    local_seq.append(ud + lr)
        else:
            # 0, 0

            if (diction[cur_kpd][0], diction[c][1]) == (0, 0) or (diction[c][0], diction[cur_kpd][1]) == (0, 0):
                if dr < 0:
                    local_seq.append(ud + lr)
                else:
                    local_seq.append(lr + ud)
            else:
                if lr == "" or ud == "":
                    local_seq.append(lr + ud)
                else:
                    local_seq.append(lr + ud)
                    local_seq.append(ud + lr)

        new_sequences = []
        for sequence in sequences:
            for local_s in local_seq:
                new_sequences.append(sequence + local_s + "A")
        sequences = new_sequences

        cur_kpd = c

    return sequences

for line in sys.stdin:

    line = line.strip()
    num = int(line[:3])

    sequences = doseq(kpd, line)
    for _ in range(2):
        sequences3 = []
        for x in sequences:
            sequences3.extend(doseq(dirc, x))
        sequences = sequences3
    # sequences2 = []
    # for x in sequences:
    #     sequences2.extend(doseq(dirc, x))
    # sequences3 = []
    # for x in sequences2:
    #     sequences3.extend(doseq(dirc, x))

    best3 = 'X' * 1000
    for x in sequences:
        if len(x) < len(best3):
            best3 = x

    print(best3)
    print(len(best3))
    ans += num * len(best3)

print(ans)