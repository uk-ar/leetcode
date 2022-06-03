class Solution {
public:
    vector<string> u20={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen","Twenty"};
    vector<string> u100={"","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety","Hundred"};    
    string helper(int num){
        if(num>=1000000000)
            return helper(num/1000000000)+"Billion "+helper(num%1000000000);
        if(num>=1000000)
            return helper(num/1000000)+"Million "+helper(num%1000000);
        if(num>=1000)
            return helper(num/1000)+"Thousand "+helper(num%1000);
        if(num>=100)
            return helper(num/100)+"Hundred "+helper(num%100);
        if(num>=21)
            return u100[num/10]+" "+helper(num%10);
        if(num==0)
            return "";
        return u20[num]+" ";
    }
    string numberToWords(int num) {
        if(num==0)
            return "Zero";
        string s=helper(num);
        if(s.back()==' ')
            s.pop_back();
        return s;
    }
};