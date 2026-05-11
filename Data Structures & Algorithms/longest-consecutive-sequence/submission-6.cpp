class Solution {
public:
    int longestConsecutive(vector<int>& unique) {
        unordered_map<int,int> count;
        
        int maxi = 0;
        for(int i = 0; i< unique.size(); i++){
            if(count[unique[i]]){
                continue;
            }
            int left = count[unique[i]-1];
            int right = count[unique[i]+1];
            int newval = left + right + 1;
            count[unique[i]-left] = newval;
            count[unique[i]+right] = newval;
            count[unique[i]] = newval;
            maxi = max(maxi, newval);
        }
        return maxi;
    }
};
