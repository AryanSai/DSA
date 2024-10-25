#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool dfs(int node, vector<int> &vis, vector<vector<int>>& adj){
        vis[node]=1;
        for(int i:adj[node])
            if (vis[i] == 0 && !dfs(i, vis, adj)) 
                return false;
            else if (vis[i] == 1)  // if neighbor is still visiting, a cycle is detected
                return false;
        vis[node] = 2; // mark the current node as fully processed
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses,0);
        // all courses[a,b] dependent on b are in their adj lists
        for(auto p : prerequisites)
            adj[p[1]].push_back(p[0]);

        for (int i = 0; i < numCourses; i++)
            if (vis[i] == 0 && !dfs(i,vis,adj)) 
                return false;

        return true;
    }
};