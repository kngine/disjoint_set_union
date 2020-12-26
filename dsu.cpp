    class DSU {
        // with path compression and ranking, amortized complexity O(1) for each operation
        vector<int> parent, rank;
        public:
        DSU(int n) {
            parent.resize(n);
            for (int x = 0; x < n; x++) {
                parent[x] = x;
            }
            rank.resize(n);
        }
        int find(int x) {
            int p = parent[x];
            if (p == x) return x;
            return parent[x] = find(p); // path compression
        }
        void unions(int x, int y) {
            x = find(x); y = find(y);
            if (x == y) return;
            
            if (rank[x] == rank[y]) rank[x]++;
            else if (rank[x] < rank[y]) swap(x, y); //union by rank
            parent[y] = x;
        }
    };
