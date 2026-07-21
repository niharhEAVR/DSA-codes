#include<vector>
#include<queue>

using namespace std;

vector<int> bfs(int V, vector<int> adj[]) {
    
    vector<int> ans;
    vector<int> visited(V, 0);
    queue<int> q;

    q.push(0);
    visited[0] = 1;

    while(!q.empty()) {

        int node = q.front();
        q.pop();

        ans.push_back(node);

        for(auto neighbor : adj[node]) {

            if(!visited[neighbor]) {
                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }

    return ans;
}