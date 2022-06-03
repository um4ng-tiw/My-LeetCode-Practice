class NumMatrix {
public:
    vector<vector<int>> input;
    NumMatrix(vector<vector<int>>& matrix) {
        input = matrix;
        
        for(int i=0; i<input.size(); i++){
            for(int j=1; j<input[0].size(); j++){
                input[i][j] = input[i][j-1] + input[i][j];
            }
        }
        
        for(int i=0; i<input[0].size(); i++){
            for(int j=1; j<input.size(); j++){
                input[j][i] = input[j-1][i] + input[j][i];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
       int total = input[row2][col2];
       int extra = ((col1 != 0) ? input[row2][col1-1]:0) + ((row1 != 0) ? input[row1-1][col2] :0) - ((row1 != 0 && col1 !=0) ? input[row1-1][col1-1] : 0);
        
        return (total - extra);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */