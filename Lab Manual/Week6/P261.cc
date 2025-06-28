#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(x!=parent[x]){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
        for(vector<int> edge:edges){
            if (find(edge[0]) == find(edge[1])) return 0;
            parent[find(edge[1])] = find(edge[0]);
            --n;
        }
        return n == 1;
    }
};
