class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxwater = 0;
        int start = 0;
        int last = heights.size()-1;
        while(start < last){
            maxwater = max(maxwater, min(heights[start], heights[last])*(last-start));
            if(heights[start] < heights[last]){
                start++;
            }else{
                last--;
            }
        }
        return maxwater;
    }
};
