// In the "100 game," two players take turns adding, to a running total, any integer from 1..10. The player who first causes the running total to reach or exceed 100 wins. 
//
// What if we change the game so that players cannot re-use integers? 
//
// For example, two players might take turns drawing from a common pool of numbers of 1..15 without replacement until they reach a total >= 100.
//
// Given an integer maxChoosableInteger and another integer desiredTotal, determine if the first player to move can force a win, assuming both players play optimally. 
//
// You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300.
//
//
// Example
//
// Input:
// maxChoosableInteger = 10
// desiredTotal = 11
//
// Output:
// false
//
// Explanation:
// No matter which integer the first player choose, the first player will lose.
// The first player can choose an integer from 1 up to 10.
// If the first player choose 1, the second player can only choose integers from 2 up to 10.
// The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
// Same with other integers chosen by the first player, the second player will always win.
//
//


class Solution {
public:
    int m[1<<20] = {0};
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int M = maxChoosableInteger, T = desiredTotal;
        int S = M * (M + 1) >> 1;
        return M >= T ? true : S < T ? false : S == T ? M % 2 : dfs(M, T, 0);
    }
    
    bool dfs(int M, int T, int k){
        if(T <= 0 || m[k]) return T > 0 && m[k] > 0;
        
        for(int i = 0; i < M; i++){
            if(!(k & 1<<i) && !(dfs(M, T - i - 1, k | 1<<i)))
               return m[k] = 1;
        }
        return !(m[k] = -1);
    }
};
