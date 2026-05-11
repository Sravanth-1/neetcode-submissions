class Solution {
public:
    vector<int> parent, size;
    int findupar(int a){
        if(a == parent[a]){
            return a;
        }
        return parent[a] = findupar(parent[a]);
    }
    bool makeunion(int a, int b){
        a = findupar(a);
        b = findupar(b);
        if(a != b){
            if(size[a] > size[b]){
                parent[b] = a;
                size[a]+= size[b];
            }else{
                parent[a] = b;
                size[b]+= size[a];
            }
            return true;
        }else{
            return false;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        parent.resize(n);
        for(int i = 1; i< n; i++){
            parent[i] = i;
        }
        size.resize(n , 1);
        vector<int> res(2);
        for(auto i: edges){
            if(!makeunion(i[0], i[1])){
                res[0] = i[0];
                res[1] = i[1];
            }
        }
        return res;
    }
};

