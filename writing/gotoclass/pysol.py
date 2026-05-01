import sys
from bisect import bisect_left

sys.setrecursionlimit(200000)

def solve():
    input_data = sys.stdin.read().split()
        
    n = int(input_data[0])
    
    adj = [[] for _ in range(n + 1)]
    idx = 1
    for _ in range(n - 1):
        u = int(input_data[idx])
        v = int(input_data[idx+1])
        w = int(input_data[idx+2])
        adj[u].append((v, w))
        adj[v].append((u, w))
        idx += 3
        
    removed = [False] * (n + 1)
    sub_sz = [0] * (n + 1)
    
    def get_sizes(u, p):
        sub_sz[u] = 1
        for v, w in adj[u]:
            if v != p and not removed[v]:
                get_sizes(v, u)
                sub_sz[u] += sub_sz[v]
                
    def get_centroid(u, p, total):
        for v, w in adj[u]:
            if v != p and not removed[v] and sub_sz[v] > total // 2:
                return get_centroid(v, u, total)
        return u
        
    def get_paths(u, p, cur_max, cur_sum, paths):
        paths.append((cur_max, cur_sum))
        for v, w in adj[u]:
            if v != p and not removed[v]:
                get_paths(v, u, cur_max if cur_max > w else w, cur_sum + w, paths)

    # 2. Iterative Segment Tree for fast coordinate-compressed updates/queries
    class SegTree:
        def __init__(self, size):
            self.n = size
            self.tree = [0] * (2 * self.n)
            
        def update(self, i, delta):
            i += self.n
            while i > 0:
                self.tree[i] += delta
                i //= 2
                
        def query(self, l, r):
            # Sum in interval [l, r)
            res = 0
            l += self.n
            r += self.n
            while l < r:
                if l % 2 == 1:
                    res += self.tree[l]
                    l += 1
                if r % 2 == 1:
                    r -= 1
                    res += self.tree[r]
                l //= 2
                r //= 2
            return res

    def count_pairs(paths):
        if not paths: return 0
        
        # Sort primarily by max_edge ascending
        paths.sort(key=lambda x: x[0])
        
        vals = []
        for m, s in paths:
            vals.append(s)
            vals.append(2 * m - s)
            
        # Coordinate compression
        vals = sorted(list(set(vals)))
        st = SegTree(len(vals))
        pairs = 0
        
        for m, s in paths:
            target = 2 * m - s
            target_idx = bisect_left(vals, target)
            
            # Query sum of values strictly less than target
            pairs += st.query(0, target_idx)
            
            sum_idx = bisect_left(vals, s)
            st.update(sum_idx, 1)
            
        return pairs

    def solve_centroid(u):
        get_sizes(u, -1)
        centroid = get_centroid(u, -1, sub_sz[u])
        
        removed[centroid] = True
        local_bottlenecks = 0
        
        all_paths = [(0, 0)]
        
        for v, w in adj[centroid]:
            if not removed[v]:
                sub_paths = []
                get_paths(v, centroid, w, w, sub_paths)
                
                # Subtract overcounted pairs
                local_bottlenecks -= count_pairs(sub_paths)
                all_paths.extend(sub_paths)
                
        # Add all valid pairs going through the centroid
        local_bottlenecks += count_pairs(all_paths)
        
        for v, w in adj[centroid]:
            if not removed[v]:
                local_bottlenecks += solve_centroid(v)
                
        return local_bottlenecks

    print(solve_centroid(1))

solve()
