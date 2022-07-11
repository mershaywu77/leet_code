class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res (n, vector<int>(n,0));
        vector<vector<int>> dir = {{0,1},{1,0}, {0,-1},{-1,0}};
        //start point
        res[0][0] = 1;
        int x = 0;
        int y = 0;
        
        int move = 0; //control the direction
        
        //fill all reset points
        for(int i = 1; i < n*n; ++i)        
        {
            int new_x = x + dir[move][0];
            int new_y = y + dir[move][1];
            //if move out of box or meet with filled point then change direction
            if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= n || res[new_x][new_y])
            {
                move = (move + 1) % 4;
                new_x = x + dir[move][0];
                new_y = y + dir[move][1];
            }
            res[new_x][new_y] = i + 1;
            x = new_x;
            y = new_y;
        }
        return res;
    }
};