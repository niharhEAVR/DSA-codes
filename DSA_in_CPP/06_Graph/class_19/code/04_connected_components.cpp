class Solution
{
public:
    void dfs(int node, vector<int> adj[], vector<int> &vis)
    {

        vis[node] = 1;

        for (auto neighbour : adj[node])
        {

            if (!vis[neighbour])
            {
                dfs(neighbour, adj, vis);
            }
        }
    }

    int findNumberOfComponent(int V, vector<vector<int>> &edges)
    {
        // adjacency list
        vector<int> adj[V];

        for (auto edge : edges)
        {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // visited array
        vector<int> vis(V, 0);

        int count = 0;

        // traverse all vertices
        for (int i = 0; i < V; i++)
        {

            // new component found
            if (!vis[i])
            {

                count++;

                dfs(i, adj, vis);
            }
        }

        return count;
    }
};