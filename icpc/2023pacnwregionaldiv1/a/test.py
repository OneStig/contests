ss = input()
none = 0
d = {}
se = []
d["a"] = []
d["b"] = []
d["c"] = []
d["ab"] = []
d["bc"] = []
d["ac"] = []
for i in range(len(ss)):
    a = ss[i]
    if a == "A":
        if d["bc"] != []:
            s = d["bc"].pop()
            se.append((s,i))
        elif d["b"] != []:
            s = d["b"].pop()
            d["ab"].append(s)
        elif d["c"] != []:
            s = d["c"].pop()
            d["ac"].append(s)
        else:
            d["a"].append(i)
    if a == "B":
        if d["ac"] != []:
            s = d["ac"].pop()
            se.append((s,i))
        elif d["a"] != []:
            s = d["a"].pop()
            d["ab"].append(s)
        elif d["c"] != []:
            s = d["c"].pop()
            d["bc"].append(s)
        else:
            d["b"].append(i)
    if a == "C":
        if d["ab"] != []:
            s = d["ab"].pop()
            se.append((s,i))
        elif d["a"] != []:
            s = d["a"].pop()
            d["ac"].append(s)
        elif d["b"] != []:
            s = d["b"].pop()
            d["bc"].append(s)
        else:
            d["c"].append(i)
#print(se)
x = 0
import heapq
curr = [-1]
heapq.heapify(curr)
for a,b in se:
    m = heapq.heappop(curr)
    if a > m:
        heapq.heappush(curr,b)
    else:
        heapq.heappush(curr,m)
        heapq.heappush(curr,a)
print(len(curr))
