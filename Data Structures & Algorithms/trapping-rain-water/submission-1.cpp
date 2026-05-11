class Solution {
public:
    int trap(vector<int>& height) {
       if(height.size() == 0){
        return 0;
       }
       int leftmax = height[0];
       int rightmax = height[height.size()-1];
       int i = 0;
       int j = height.size()-1;
       int water = 0;
       while(i <= j){
        if(leftmax < rightmax){
           leftmax = max(height[i], leftmax);
           water += leftmax-height[i];
           i++;
        }else{
            rightmax = max(height[j], rightmax);
            water += rightmax-height[j];
            j--;
        }
       }

       return water;
    }
};