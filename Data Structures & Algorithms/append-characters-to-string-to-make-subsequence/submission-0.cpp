class Solution {
public:
    int appendCharacters(string s, string t) {
        int start = 0;
        for(int i = 0; i< s.size(); i++){
            if(start == t.size()){
                break;
            }
            if(s[i] == t[start]){
                start++;
            }
        }
        return t.size()-start;
    }
};