class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        if(arr.size() == 0){
            return arr;
        }
        int last = arr[arr.size()-1];
        for(int i = arr.size()-2; i>= 0; i--){
            int val = max(arr[i+1], last);
            last = arr[i];
            arr[i] = val;
        }

        arr[arr.size()-1] = -1;

        return arr;
    }
};