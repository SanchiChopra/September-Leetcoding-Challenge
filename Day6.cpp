/* QUESTION: Two images A and B are given, represented as binary, square matrices of the same size.  (A binary matrix has only 0s and 1s as values.)

We translate one image however we choose (sliding it left, right, up, or down any number of units), and place it on top of the other image.  After, the overlap of this translation is the number of positions that have a 1 in both images.

(Note also that a translation does not include any kind of rotation.)

What is the largest possible overlap?

Example 1:

Input: A = [[1,1,0],
            [0,1,0],
            [0,1,0]]
       B = [[0,0,0],
            [0,1,1],
            [0,0,1]]
Output: 3
Explanation: We slide A to right by 1 unit and down by 1 unit.
*/

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        // vector of pair<r, c> for 1  
        int M = A.size(); // row count
        int N = A[0].size(); // column count 
        vector<pair<int, int>> oneA, oneB;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (A[i][j])
                    oneA.emplace_back(i, j);
                if (B[i][j])
                    oneB.emplace_back(i, j);
            }
        }
        
        vector<vector<int>> C(2*M, vector<int>(2*N, 0));
        // for each pair, compute the diff in offset <row shift ro, column shift co>
        // for convenience, (M, N) is the origin
        for (auto a : oneA) {
            for (auto b : oneB) {
                C[b.first + M - a.first][b.second + N - a.second]++;
            }
        }
        
        int maxCnt = 0;
        for (int i = 0; i < 2*M; i++) {
            for (int j = 0; j < 2*N; j++) {
                if (C[i][j] > maxCnt)
                    maxCnt = C[i][j];
            }
        }
        // return max
        return maxCnt;
    }
};
