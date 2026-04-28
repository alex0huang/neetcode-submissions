class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row1= matrix.size(),col1 = matrix[0].size();
        int l=0, r = row1*col1-1;
        while(l<=r){
            int m = l+(r-l)/2;
            int row = m/col1, col = m%col1;
            if(target >matrix[row][col]){
                l= m+1;
            }
            else if (target < matrix[row][col]){
                r = m-1;
            }
            else{return true;}


        }
        return false;
    }
};
