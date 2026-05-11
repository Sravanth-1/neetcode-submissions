class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(auto str : strs){
            encoded += to_string(str.size()) + '#';
            encoded += str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int last = 0;
        while(last < s.size()){
            int index = s.find('#', last);
            int size = stoi(s.substr(last,index-last));
            string str = s.substr(index+1, size);
            decoded.push_back(str);
            last = index+1+size;
        }
        return decoded;
    }
};
