varbs = []

s = input()
s = s.strip()
while s:
    s = s.replace(' ', '')

    each = s.split(')')
    each.pop()

    for v in each:
        v = v.split('(')
        cv = [v[0]] + v[1].split(',')

        varbs.append(cv)

    s = input()
    s = s.strip()


try:
    s = input()
    s.strip()
    while s:
        s = s.replace(' ', '')

        each = s.split(')')
        each.pop()

        for v in each:
            v = v.split('(')
            query = [v[0]] + v[1].split(',')

            ans = 0
            for varb in varbs:
                mp = dict()
                if len(varb) != len(query):
                    continue

                good = 1
                for i in range(len(varb)):
                    if query[i] == '_':
                        continue

                    if query[i][0] == '_':
                        if query[i] in mp and mp[query[i]] != varb[i]:
                            good = 0
                            break
                        mp[query[i]] = varb[i]

                    elif query[i] != varb[i]:
                        good = 0
                        break

                ans += good

            print(ans)

        s = input()
        s = s.strip()

except EOFError:
    pass
