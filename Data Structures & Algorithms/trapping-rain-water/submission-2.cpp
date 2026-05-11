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
        leftmax = max(height[i], leftmax);
        rightmax = max(height[j], rightmax);
        if(leftmax < rightmax){ 
           water += leftmax-height[i];
           i++;
        }else{   
            water += rightmax-height[j];
            j--;
        }
       }

       return water;
    }
};