import sys

# Increase limit just in case, though we are going iterative
sys.setrecursionlimit(300000)

def solve():
    # Use fast I/O
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    
    head = [-1] * (n + 1)
    nxt = [-1] * ((n - 1) * 2)
    to = [0] * ((n - 1) * 2)
    weight = [0] * ((n - 1) * 2)
    
    idx = 1
    for i in range(n - 1):
        u, v, w = int(input_data[idx]), int(input_data[idx+1]), int(input_data[idx+2])
        idx += 3
        # Edge u -> v
        to[2*i] = v; weight[2*i] = w; nxt[2*i] = head[u]; head[u] = 2*i
        # Edge v -> u
        to[2*i+1] = u; weight[2*i+1] = w; nxt[2*i+1] = head[v]; head[v] = 2*i+1
        
    removed = [False] * (n + 1)
    sub_sz = [0] * (n + 1)
    
    # ITERATIVE get_sizes and get_centroid
    def get_centroid_iterative(root):
        # 1. Get sizes using iterative DFS
        stack = [(root, -1, 0)] # node, parent, state (0: pre, 1: post)
        order = []
        while stack:
            u, p, state = stack.pop()
            if state == 0:
                order.append((u, p))
                stack.append((u, p, 1))
                e = head[u]
                while e != -1:
                    v = to[e]
                    if v != p and not removed[v]:
                        stack.append((v, u, 0))
                    e = nxt[e]
        
        for u, p in reversed(order):
            sub_sz[u] = 1
            e = head[u]
            while e != -1:
                v = to[e]
                if v != p and not removed[v]:
                    sub_sz[u] += sub_sz[v]
                e = nxt[e]
        
        # 2. Find centroid
        total = sub_sz[root]
        curr = root
        parent = -1
        while True:
            heavy_v = -1
            e = head[curr]
            while e != -1:
                v = to[e]
                if v != parent and not removed[v] and sub_sz[v] > total // 2:
                    heavy_v = v
                    break
                e = nxt[e]
            if heavy_v == -1: return curr
            parent = curr
            curr = heavy_v

    # ITERATIVE get_paths
    def get_paths_iterative(root, p_of_root, initial_max, initial_sum):
        paths_m, paths_s = [], []
        stack = [(root, p_of_root, initial_max, initial_sum)]
        while stack:
            u, p, cur_max, cur_sum = stack.pop()
            paths_m.append(cur_max)
            paths_s.append(cur_sum)
            e = head[u]
            while e != -1:
                v = to[e]
                if v != p and not removed[v]:
                    w = weight[e]
                    stack.append((v, u, max(cur_max, w), cur_sum + w))
                e = nxt[e]
        return paths_m, paths_s

    def count_pairs(paths_m, paths_s):
        if not paths_m: return 0
        paths = sorted(zip(paths_m, paths_s))
        
        # Coordinate compression
        vals = []
        for m, s in paths:
            vals.append(s)
            vals.append(2 * m - s)
        unique_vals = sorted(list(set(vals)))
        val_to_idx = {val: i + 1 for i, val in enumerate(unique_vals)}
        
        bit_size = len(unique_vals)
        bit = [0] * (bit_size + 1)
        pairs = 0
        for m, s in paths:
            t_idx = val_to_idx[2 * m - s] - 1
            i = t_idx
            while i > 0:
                pairs += bit[i]
                i -= i & -i
            s_idx = val_to_idx[s]
            i = s_idx
            while i <= bit_size:
                bit[i] += 1
                i += i & -i
        return pairs

    # ITERATIVE solve_centroid
    ans = 0
    c_stack = [1]
    while c_stack:
        curr_root = c_stack.pop()
        centroid = get_centroid_iterative(curr_root)
        removed[centroid] = True
        
        all_m, all_s = [0], [0]
        e = head[centroid]
        while e != -1:
            v = to[e]
            if not removed[v]:
                pm, ps = get_paths_iterative(v, centroid, weight[e], weight[e])
                ans -= count_pairs(pm, ps)
                all_m.extend(pm)
                all_s.extend(ps)
                c_stack.append(v)
            e = nxt[e]
        ans += count_pairs(all_m, all_s)
        
    sys.stdout.write(str(ans) + '\n')

solve()
