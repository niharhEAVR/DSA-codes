#include<vector>

using namespace std;

void dfs(int node, vector<int> adj[], vector<int>& visited, vector<int>& ans) {

    visited[node] = 1;
    ans.push_back(node);

    for(auto neighbor : adj[node]) {

        if(!visited[neighbor]) {
            dfs(neighbor, adj, visited, ans);
        }
    }
}
vector<int> dfsTraversal(int V, vector<int> adj[]) {

    vector<int> visited(V, 0);
    vector<int> ans;

    dfs(0, adj, visited, ans);

    return ans;
}