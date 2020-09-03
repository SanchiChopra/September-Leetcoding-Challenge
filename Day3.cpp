/* QUESTION: Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

Example 1:

Input: "abab"
Output: True
Explanation: It's the substring "ab" twice.
Example 2:

Input: "aba"
Output: False
Example 3:

Input: "abcabcabcabc"
Output: True
Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
*/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string tmp = s+s;
        /* Remove first char to avoid to match with input string which is from 0 to s.length() */
        tmp = tmp.substr(1);
        /* Remove last char to avoid to match with input string which is appended after s.length() */
        tmp = tmp.substr(0, tmp.length()-1);
        /* if the input string present then then pattern is repeated*/
        return tmp.find(s) != string::npos ? true : false;
    }
};
