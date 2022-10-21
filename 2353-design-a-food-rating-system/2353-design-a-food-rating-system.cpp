class FoodRatings {
public:
    unordered_map<string,int>fr;
    unordered_map<string,string>fc;
    unordered_map<string,set<pair<int,string>>>crf;
    FoodRatings(vector<string>& f, vector<string>& c, vector<int>& r) {
        int N=f.size();
        for(int i=0;i<N;i++){
            fr[f[i]]=r[i];
            fc[f[i]]=c[i];
            crf[c[i]].insert(make_pair(-r[i],f[i]));
        }
    }
    
    void changeRating(string f, int r) {
        string c=fc[f];
        crf[c].erase(make_pair(-fr[f],f));
        fr[f]=r;
        crf[c].insert(make_pair(-fr[f],f));
    }
    
    string highestRated(string c) {
        return (*crf[c].begin()).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */