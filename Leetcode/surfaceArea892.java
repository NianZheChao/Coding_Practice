//import java.util.Scanner;

public class Main{
//    public static void main(String[] args){

//    }

    class Solution {
        public int surfaceArea(int[][] grid) {
            int ans = 0;
            int n = grid.length;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if(grid[i][j]>0)
                    ans += grid[i][j] * 4 + 2;
                    if( i -1 >= 0 && grid[i-1][j] > 0){
                        ans -= (Math.min(grid[i-1][j] , grid[i][j]));
                    }
                    if( i + 1 < n && grid[i+1][j] > 0){
                        ans -= (Math.min(grid[i+1][j] , grid[i][j]));
                    }
                    if( j -1 >= 0 && grid[i][j-1] > 0){
                        ans -= (Math.min(grid[i][j-1] , grid[i][j]));
                    }
                    if( j + 1 < n && grid[i][j+1] > 0){
                        ans -= (Math.min(grid[i][j+1] , grid[i][j]));
                    }
                }
            }
            return ans;
        }
        }
    }
