class Solution {
public:
    vector<int> parent, size;
    int findupar(int a){
        if(a == parent[a]){
            return a;
        }
        return parent[a] = findupar(parent[a]);
    }
    void makeunion(int a, int b){
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
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        for(int i = 0; i< n; i++){
            parent[i] = i;
        }
        size.resize(n , 1);

        for(auto i: edges){
            makeunion(i[0], i[1]);
        }
        int count = 0;
        for(int i = 0; i< n; i++){
            if(parent[i] == i){
                count++;
            }
        }
        return count;
    }

};
