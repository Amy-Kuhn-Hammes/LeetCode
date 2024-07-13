#include <stdio.h>
#include <stdlib.h>
#include <string>

using std::string;

// Atrasei o envio pois passei mal, tive que ir no hospital, também, minha solução está bem ruim,
// não estou 100% ainda, mas volto para esse problema alguma outra hora, o problema é bem
// interessante, achei bacana 
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int count = 0, i;
        string stack, p = "ab", q = "ba";
        if(x<y) {
            p = "ba";
            q = "ab";
            i = x;
            x = y;
            y = i;
        }
        for(i = 0; i < s.length(); i++) {
            stack.push_back(s[i]);
            if(stack.length() >1 && p.compare(stack.substr(stack.length()-2, 2)) == 0) {
                stack.pop_back();
                stack.pop_back();
                count += x;
            }
        }
        i = stack.length();
        while(i>1) {
            if(q.compare(stack.substr(i-2, 2)) == 0){
                count += y;
                stack.erase(i-2, 2);
            }
            i--;
        }
        return count;
    }
};