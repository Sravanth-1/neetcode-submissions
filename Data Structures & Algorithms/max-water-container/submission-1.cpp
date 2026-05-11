class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxi = 0;
        int i = 0; 
        int j = heights.size()-1;
        while(i < j){
            maxi = max(maxi, min(heights[i], heights[j])*(j-i));
            if(heights[i] < heights[j]){
                i++;
            }else{
                j--;
            }
        }
        return maxi;
    }
};
