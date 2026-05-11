class Solution {
public:
    vector<int> parent;
    vector<int> size;
    int findupar(int a){
        if(a == parent[a]){
            return a;
        }
        return parent[a] = findupar(parent[a]);
    }
    bool issame(int a, int b){
        a = findupar(a);
        b = findupar(b);
        if(a == b){
            return true;
        }
        if(size[a] > size[b]){
            parent[b] = a;
            size[a]+= size[b];
        }else{
            parent[a] = b;
            size[b]+= size[a];
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1){
            return false;
        }
        parent.resize(n);
        for(int i = 0; i< n; i++){
            parent[i] = i;
        }
        size.resize(n, 1);
        for(auto edge: edges){
            if(issame(edge[0], edge[1])){
                return false;
            }
        }
        return true;
    }
};
