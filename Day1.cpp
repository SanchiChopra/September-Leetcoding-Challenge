/* QUESTION: Given an array of 4 digits, return the largest 24 hour time that can be made.

The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 00:00, a time is larger if more time has elapsed since midnight.

Return the answer as a string of length 5.  If no valid time can be made, return an empty string.

 

Example 1:

Input: [1,2,3,4]
Output: "23:41"
Example 2:

Input: [5,5,5,5]
Output: ""
*/

class Solution {
public:
    string res="";
    void solve(vector<int>& A,vector<bool> used,int i,string s){
        // cout<<i<<" "<<s<<endl;
        if(i==A.size()){
            if(s.size()==5){
                res = max(res,s);
            }
            return;
        }
        if(s.size()==1){
            if(s[0]>'2'){
                return;
            }
        }
        if(s.size()==2 && s[0]=='2' && s[1]>='4'){
            return;
        }
        if(s.size()==4 && s[3]>='6'){
            return;
        }
        if(s.size()==2){
            s+=":";
        }
        
        for(int k=0;k<A.size();k++){
            if(!used[k]){
                s.push_back('0'+A[k]);
                used[k]=true;
                solve(A,used,i+1,s);
                s.pop_back();
                used[k]=false;
            }
        }
        
        
    }
    
    string largestTimeFromDigits(vector<int>& A) {
        vector<bool> used(A.size(),false);
        solve(A,used,0,"");
        return res;
    }
};
