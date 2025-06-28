#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int i){
        if(i!=parent[i]){
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }
    int unionn(int x,int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX!=rootY){
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            return 1;
        }
        return 0;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int count = n;
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(vector<int> edge : edges){
            count -= unionn(edge[0],edge[1]);
        }
        return count;
    }
};

