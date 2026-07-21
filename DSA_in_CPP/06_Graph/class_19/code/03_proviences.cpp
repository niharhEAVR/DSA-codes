class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& visited) {
        visited[node] = 1;
        for (int j = 0; j < isConnected.size(); j++) {
            if(isConnected[node][j] == 1 && !visited[j]){
                dfs(j,isConnected,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> visited(V, 0);
        int provinces = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                provinces++;
                dfs(i, isConnected, visited);
            }
        }
        return provinces;
    }
};