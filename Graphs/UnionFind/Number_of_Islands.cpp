#include <iostream>
#include <vector.h>
#include<stdlib.h>
#include<unordered_set>

class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int i , int j){
        int pi = find(i);
        int pj = find(j);

        if(pi == pj) return;
        if(rank[pi] > rank[pj]){
            parent[pj] = pi;
        } else if(rank[pj] > rank[pi]){
            parent[pi] = pj; 
        } else {
            parent[pj] = pi;
            rank[pi]++;
        }
        return;
    };
    // void solve(vector<vector<int>>& grid, int i, int j, int pi, int pj, vector<vector<bool>>& visited){
    //     if()

    //     visited[i][j] = true;
    //     for(auto &dir: directions){
    //         int i 
    //     }
    // }
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool isValid(int i , int j, int n, int m){
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        parent.resize(n * m);
        rank.resize(n * m, 0);

        for(int i = 0; i < parent.size(); i++){
            parent[i] = i;
        }
        // Never take Visited array in Dsu
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    for(vector<int> dir: directions){
                        int ni = i + dir[0]; 
                        int nj = j + dir[1];

                        if(isValid(ni, nj, n, m) && grid[ni][nj] == '1'){
                            int idx = ni * m + nj;
                            int originalIdx = i * m + j;
                            if(find(originalIdx) != find(idx)){
                                Union(originalIdx, idx);
                            }
                        }
                    }
                }
            }
        }
        unordered_set<int> uniqueIslands;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    uniqueIslands.insert(find(i * m + j));
                }
            }
        }
        return uniqueIslands.size();
    }
};