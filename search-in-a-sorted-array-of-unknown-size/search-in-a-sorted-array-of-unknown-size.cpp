/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& r, int t) {
        int ok=0,ng=10000+1;
        while(abs(ok-ng)>1){
            int m=(ok+ng)/2;
            if(r.get(m)<=t)
                ok=m;
            else
                ng=m;
        }
        if(r.get(ok)==t)
            return ok;
        return -1;
    }
};