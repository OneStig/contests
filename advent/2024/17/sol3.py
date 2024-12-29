oa: int = int(input().split(':')[1])
ob: int = int(input().split(':')[1])
oc: int = int(input().split(':')[1])

input()

prog = [int(x) for x in input().split(':')[1].strip().split(',')]

print(prog)

def simulate(a):
    output = []
    b = ob
    c = oc

    def combo(c) -> int:
        match c:
            case 4:
                return a
            case 5:
                return b
            case 6:
                return c
            case 7:
                raise RuntimeError()
            case x:
                return(int(x))

    ip = 0

    while ip < len(prog):
        match prog[ip]:
            case 0:
                a = a >> combo(prog[ip + 1])
            case 1:
                b = b ^ int(prog[ip + 1])
            case 2:
                b = combo(prog[ip + 1]) % 8
            case 3:
                if a != 0:
                    ip = int(prog[ip + 1]) - 2
            case 4:
                b = b ^ c
            case 5:
                output.append(combo(prog[ip + 1]) % 8)

                if len(output) > len(prog) or output[-1] != prog[len(output) - 1]:
                    break
            case 6:
                b = a >> combo(prog[ip + 1])
            case 7:
                c = a >> combo(prog[ip + 1])
            case _:
                raise RuntimeError()

        ip += 2

    return output

cands = set(range(8))
# cands = set()
# cands.add(0)

def compute(sfx_len, old_cands):
    print(sfx_len, len(old_cands), old_cands)

    new_sfx = sfx_len + 3
    new_cands = set()
    # found_ans = False

    for a in range(1 << 20):
        for eacha in old_cands:
            runa = (a << sfx_len) + eacha
            res = simulate(runa)
            
            if len(prog) >= len(res) >= new_sfx // 3:
                good = True

                for i in range(new_sfx // 3):
                    if res[i] != prog[i]:
                        good = False
                        break

                if good:
                    binary = format(runa & (1 << new_sfx) - 1, f'0{new_sfx}b')
                    new_cands.add(int(binary, 2))

            if res == prog:
                # found_ans = True
                print(f'answer: {runa}')
                break

        # if found_ans:
        #     break

    # if not found_ans:
    compute(new_sfx, new_cands)

compute(3, cands)