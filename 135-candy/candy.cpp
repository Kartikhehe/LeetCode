class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> minimas;
        vector<int> candies(n, 0);
        int totalcandies = 0;
        
        for(int i = 0; i<n; i++){
            if((i==0 || ratings[i-1] >= ratings[i]) && (i==n-1 || ratings[i+1] >= ratings[i])){
                // FIX 1: Removed the if/else for equal ratings. 
                // ALL local minima (even flat ones) must be added to the minimas list.
                // If they aren't added, they can't expand outwards to their taller neighbors.
                candies[i] = 1;
                minimas.push_back(i);
            }
        }
        
        // Note: I removed your secondary loop that set `candies[minimas[i]] = 1` 
        // since we are already doing it in the loop above.
        
        for(int i = 0; i<minimas.size(); i++){
            int idx = minimas[i];
            int left = idx ;
            int right = idx ;
            
            // FIX 2: Removed `candies[left-1] == 0` from the left expansion loop.
            // This ensures we always climb all the way to the peak, updating it with max() if necessary.
            while(left > 0 && ratings[left-1] > ratings[left]){
                left--;
                candies[left] = max(candies[left], candies[left + 1] + 1);
            }
            
            while(right < n-1 && ratings[right + 1] > ratings[right]){
                right++;
                candies[right] = max(candies[right], candies[right - 1] + 1);
            }
        }
        
        for(int i =0;i<n; i++){
            totalcandies += candies[i];
        }
        
        return totalcandies;
    }
};