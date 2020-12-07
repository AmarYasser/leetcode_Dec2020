
        
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> mat(n, vector<int>(n, 0));
        int X1 = 0, Y1 = 0; //first element
        int X2 = n  , Y2 = n; // far down element 
        int x = 0;
        // loop for each element
        while (x < n*n) {
            for (int j = X1; j < X2; j++) {
                if (mat[Y1][j] == 0)
                    mat[Y1][j] = ++x;
            }
            for (int i = Y1; i < Y2; i++) {
                if (mat[i][X2-1] == 0)
                    mat[i][X2-1] = ++x;
            }
            for (int j = X2-1; j >= X1; j--) {
                if (mat[Y2-1][j] == 0)
                    mat[Y2-1][j] = ++x;
            }
            for (int i = Y2-1; i >= Y1; i--) {
                if (mat[i][X1] == 0)
                    mat[i][X1] = ++x;
            }
            X1++, X2--;Y1++;Y2--;
        }
        return mat;
    }
};
