#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool reorderedPowerOf2(int N) {
        int s[9], i = 0;
        while (N) {
            s[i++] = N % 10;
            N /= 10;
        }
        sort(s, s + i);
        long long t;
        int flag;
        do {
            if (s[0] == 0)
                continue;
            int mul = 1;
            t = 0;
            for (int j = i - 1; j >= 0; j--) {
                t += s[j] * mul;
                mul *= 10;
            }
            int times = 0;
            flag = 1;
            while (t) {
                if (t & 1)
                    times++;
                if (times > 1) {
                    flag = 0;
                    break;
                }
                t = t >> 1;
            }
            if (flag)
                break;
        } while (next_permutation(s, s + i));
        if (flag)
            return true;
        else
            return false;
    }
}
