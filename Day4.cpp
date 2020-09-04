/* QUESTION: A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

 

Example 1:

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
*/

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        int n = S.size();
        vector<pair<int,int>> F_L(26, {n,n});
        
        for (int i=0;i<n;i++) {
            int index = S[i] - 'a';
            if (F_L[index].first == n) {
                F_L[index].first = i;
            }
        }
        
        for (int i=n-1;i>=0;i--) {
            int index = S[i] - 'a';
            if (F_L[index].second == n ) {
                F_L[index].second = i;
            }
        }
        
        sort(F_L.begin(), F_L.end());
        
        int p1 = F_L[0].first;
        int p2 = F_L[0].second;
        for (int i=1;i<26;i++) {
            if (F_L[i].first == n) {
                break;
            }
            if (F_L[i].first > p2) {
                int x = p2 - p1 + 1;
                res.push_back(x);
                p1 = F_L[i].first;
                p2 = F_L[i].second;
            }else {
                if ( F_L[i].second > p2) {
                    p2 = F_L[i].second;
                }
            }
        }
        
        res.push_back(p2-p1+1);
        
        return res;
    }
};
