class Solution {
public:
    int maxArea(vector<int>& heights) {
        int r = heights.size()-1;
        int l = 0;
        int maxarea =0;
        while (l<r){
            int height = min(heights[l],heights[r]);
            int area = height* (r-l);
            maxarea = max(maxarea, area);
            if(heights[l]>heights[r]){
                r--;
            }
            else{
                l++;
            }
        }
        return maxarea;

    }
};
