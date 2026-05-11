class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi = 0;
        int last = -1;
        vector<int> mp(256, -1);
        for(int i = 0; i< s.size(); i++){
            if(mp[(unsigned char)s[i]] > last){
                last = mp[(unsigned char)s[i]];
            }
            maxi = max(i-last, maxi);
            mp[(unsigned char)s[i]] = i;
        }
        return maxi;
    }
};
