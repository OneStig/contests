# 2, 4 B = A % 8
# 1, 1 B ^= 1
# 7, 5 C = A >> B
# 4, 6 B ^= C
# 1, 4 B ^= 4
# 0, 3 A = A >> 3
# 5, 5 print(B % 8)
# 3, 0 jump to instruction 0 if A != 0

program = [2, 4, 1, 1, 7, 5, 4, 6, 1, 4, 0, 3, 5, 5, 3, 0]

def simulate(A):
    B = 0
    C = 0

    output = []
    while True:
        B = A % 8
        B ^= 1
        C = A >> B
        B ^= C
        B ^= 4
        A = A >> 3
        output.append(B % 8)

        if A == 0:
            break

    return output

cands = set(range(8))

min_ans = 1 << 100

def compute(sfx_len, old_cands):
    global min_ans
    print(sfx_len, len(old_cands), old_cands)

    new_sfx = sfx_len + 3
    new_cands = set()
    # found_ans = False

    for a in range(1 << 20):
        for eacha in old_cands:
            runa = (a << sfx_len) + eacha
            res = simulate(runa)
            
            if len(program) >= len(res) >= new_sfx // 3:
                good = True

                for i in range(len(res)):
                    if res[i] != program[i]:
                        good = False
                        break

                if good:
                    binary = format(runa & (1 << new_sfx) - 1, f'0{new_sfx}b')
                    new_cands.add(int(binary, 2))

            if res == program:
                # found_ans = True
                print(f'answer: {runa}')
                min_ans = min(min_ans, runa)
                print(f'min ans: {min_ans}')
                break

        # if found_ans:
        #     break

    # if not found_ans:
    compute(new_sfx, new_cands)

compute(3, cands)