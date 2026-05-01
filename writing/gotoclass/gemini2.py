import sys
from bisect import bisect_left

def solve():
    # Fast I/O: read all tokens at once
    input_data = sys.stdin.read().split()
    if not input_data:
        return
        
    n = int(input_data[0])
    
    # Adjacency list
    adj = [[] for _ in range(n + 1)]
    it = iter(input_data)
    next(it)  # skip n
    for u_str in it:
        u = int(u_str)
        v = int(next(it))
        s = int(next(it))
        adj[u].append((v, s))
        adj[v].append((u, s))

    # Pre-allocate global arrays to defeat GC pauses during BFS
    Q = [0] * (n + 1)
    parent = [-1] * (n + 1)
    sz = [0] * (n + 1)
    removed = [False] * (n + 1)
    
    Q_nodes = [0] * (n + 1)
    Q_max = [0] * (n + 1)
    Q_dist = [0] * (n + 1)
    
    BIT = [0] * (n + 2)

    def get_centroid(start_node):
        head = 0
        tail = 0
        Q[tail] = start_node
        tail += 1
        parent[start_node] = -1
        
        # 1. Top-down traversal
        while head < tail:
            u = Q[head]
            head += 1
            sz[u] = 1
            
            for v, w in adj[u]:
                if not removed[v] and v != parent[u]:
                    parent[v] = u
                    Q[tail] = v
                    tail += 1
                    
        # 2. Bottom-up size calculation
        for i in range(tail - 1, -1, -1):
            u = Q[i]
            p = parent[u]
            if p != -1:
                sz[p] += sz[u]
                
        # 3. Locate the heavy child that acts as the centroid
        total = tail
        c = start_node
        while True:
            heavy = -1
            for v, w in adj[c]:
                if not removed[v] and v != parent[c]:
                    if sz[v] * 2 > total:
                        heavy = v
                        break
            if heavy != -1:
                c = heavy
            else:
                break
        return c

    def get_nodes(start_v, start_w, centroid_c, out_list):
        head = 0
        tail = 0
        Q_nodes[tail] = start_v
        Q_max[tail] = start_w
        Q_dist[tail] = start_w
        tail += 1
        parent[start_v] = centroid_c
        
        while head < tail:
            u = Q_nodes[head]
            m = Q_max[head]
            d = Q_dist[head]
            head += 1
            
            out_list.append((m, d))
            
            for v, w in adj[u]:
                if not removed[v] and v != parent[u]:
                    parent[v] = u
                    Q_nodes[tail] = v
                    Q_max[tail] = m if m > w else w
                    Q_dist[tail] = d + w
                    tail += 1

    def count_pairs(nodes):
        n_nodes = len(nodes)
        
        # MASSIVE OPTIMIZATION: Prune useless overhead for leaves/singletons
        if n_nodes < 2:
            return 0
            
        nodes.sort(key=lambda x: x[0])
        
        # Fast coordinate compression relying entirely on PyPy's Timsort. 
        # bisect_left manages the duplicates automatically.
        D = [x[1] for x in nodes]
        D.sort()
        
        pairs = 0
        
        for i in range(n_nodes):
            m, d = nodes[i]
            target = 2 * m - d
            
            # Query how many nodes strictly meet the condition
            idx = bisect_left(D, target)
            if idx > 0:
                s = 0
                curr = idx
                while curr > 0:
                    s += BIT[curr]
                    curr -= curr & -curr
                pairs += s
            
            # Add current distance to BIT
            pos = bisect_left(D, d) + 1
            curr = pos
            while curr <= n_nodes:
                BIT[curr] += 1
                curr += curr & -curr
                
        # Rollback mutations to maintain the zeroed state safely and consistently
        for i in range(n_nodes):
            d = nodes[i][1]
            pos = bisect_left(D, d) + 1
            curr = pos
            while curr <= n_nodes:
                BIT[curr] = 0
                curr += curr & -curr
                
        return pairs

    total_ans = 0
    centroids_to_process = [1]
    
    # 100% Iterative Centroid Decomposition
    while centroids_to_process:
        start = centroids_to_process.pop()
        
        c = get_centroid(start)
        removed[c] = True
        
        all_nodes = [(0, 0)]
        ans_c = 0
        
        for v, w in adj[c]:
            if not removed[v]:
                subtree_nodes = []
                get_nodes(v, w, c, subtree_nodes)
                
                # Subtract paths heavily restricted to identical subtrees
                ans_c -= count_pairs(subtree_nodes)
                all_nodes.extend(subtree_nodes)
                
                centroids_to_process.append(v)
                
        # Calculate cross-component bottleneck commutes
        ans_c += count_pairs(all_nodes)
        total_ans += ans_c
        
    print(total_ans)

if __name__ == '__main__':
    solve()
