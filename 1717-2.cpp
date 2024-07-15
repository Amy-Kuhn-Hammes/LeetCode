#include <stdio.h>
#include <stdlib.h>
#include <string>

using std::string;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int count = 0, i;
        string p = "ab", q = "ba";
        if(x<y) {
            p = "ba";
            q = "ab";
            i = x;
            x = y;
            y = i;
        }
        i =0;
        while(i <= s.length()) {
            if( p.compare(s.substr(i, 2)) == 0) {
                s.erase(i, 2);
                count += x;
                i--;
                if(i>=0)i--;

            }
            i++;
        }
        i = s.length()-1;
        while(i>=0) {
            if(q.compare(s.substr(i, 2)) == 0){
                count += y;
                s.erase(i, 2);
                i++;
            }
            i--;
        }
        return count;
    }
};