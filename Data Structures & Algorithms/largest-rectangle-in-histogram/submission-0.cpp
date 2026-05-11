class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st;
        heights.push_back(0);
        int maxi = 0;
        for(int i = 0; i< heights.size(); i++){
            int start = i;
            while(!st.empty() && st.top().second > heights[i]){
                maxi = max(maxi, st.top().second*(i-st.top().first));
                start = st.top().first;
                st.pop();
            } 
            st.push({start, heights[i]});
        }

        return maxi;
    }
};



