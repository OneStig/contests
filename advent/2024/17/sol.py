oa: int = int(input().split(':')[1])
ob: int = int(input().split(':')[1])
oc: int = int(input().split(':')[1])

input()

prog = [int(x) for x in input().split(':')[1].strip().split(',')]

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

def simulate(a):
    output = []
    b = ob
    c = oc

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

    # if len(output) > 3 and output[0] == prog[0] and output[1] == prog[1] and output[2] == prog[2] and output[3] == prog[3]:
    #     test = test | newa
    #     print(format(newa, 'b'))
    #     print(output)

    if output == prog:
        print(output)
        print(f'ans2: {ta} {a}')
        break

# 2, 4 B = A % 8
# 1, 1 B ^= 1
# 7, 5 C = A /8 
# 4, 6 B ^= C
# 1, 4 B ^= 4
# 0, 3 A = A / 8
# 5, 5 out(B % 8)
# 3, 0 jump if A != 0