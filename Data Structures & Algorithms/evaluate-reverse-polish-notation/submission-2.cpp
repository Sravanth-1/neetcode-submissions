class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() == 0){
            return 0;
        }
        stack<int> s;
        for(auto i: tokens){
            if(i != "+" && i != "-" && i != "*" && i != "/"){
                s.push(stoi(i));
            }else{
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                if(i == "+"){
                    s.push(b+a);
                }else if(i == "-"){
                    s.push(b-a);
                }else if(i == "*"){
                    s.push(b*a);
                }else{
                    s.push(b/a);
                }
            }
        }

        return s.top();
    }
};
