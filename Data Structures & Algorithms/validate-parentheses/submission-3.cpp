class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> pairs;
        pairs['('] = ')';
        pairs['{'] = '}';
        pairs['['] = ']';

        stack<char> st;

        for(auto i: s){
            if(pairs.find(i) == pairs.end()){
                if(st.empty() || pairs[st.top()] != i){
                    return false;
                }
                st.pop();
            }else{
                st.push(i);
            }
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
};
