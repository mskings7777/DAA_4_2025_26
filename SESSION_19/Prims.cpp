class Solution {
  public:
    
    vector<int> parent, rankArr;
    
    int find(int x) {
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    
    void unionSet(int x, int y) {
        int px = find(x);
        int py = find(y);
        
        if(px == py) return;
        
        if(rankArr[px] < rankArr[py])
            parent[px] = py;
        else if(rankArr[px] > rankArr[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rankArr[px]++;
        }
    }
    
    int spanningTree(int V, vector<vector<int>>& edges) {
        
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });
        
        parent.resize(V);
        rankArr.resize(V, 0);
        
        for(int i = 0; i < V; i++)
            parent[i] = i;
        
        int mstWeight = 0;
        
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            if(find(u) != find(v)) {
                mstWeight += w;
                unionSet(u, v);
            }
        }
        
        return mstWeight;
    }
};