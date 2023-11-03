class FoodRatings {
public:
    map<string, string> mp;
    map<string, int> rating;
    map<string, set<pair<int, string>>> mp2;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i<n; i++){
            mp[foods[i]] = cuisines[i];
            rating[foods[i]] = ratings[i];
            mp2[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = mp[food];
        mp2[cuisine].erase({-rating[food], food});
        mp2[cuisine].insert({-newRating, food});
        rating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
       return mp2[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */