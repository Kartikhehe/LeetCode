class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int MOD = 1e9 + 7;
        
        vector<int> left(n);
        vector<int> right(n);
        stack<int> st;
        
        // Calculate the distance to the Previous Less Element (PLE)
        for (int i = 0; i < n; i++) {
            // Use >= to handle duplicate elements and avoid double counting
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            // If stack is empty, there is no smaller element to the left
            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }
        
        // Clear the stack for the next pass
        while (!st.empty()) {
            st.pop();
        }
        
        // Calculate the distance to the Next Less Element (NLE)
        for (int i = n - 1; i >= 0; i--) {
            // Use > here (since we used >= previously) for duplicates
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            // If stack is empty, there is no smaller element to the right
            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }
        
        // Calculate the total sum
        long long totalSum = 0;
        for (int i = 0; i < n; i++) {
            long long subarraysWithMinArrI = (long long)left[i] * right[i];
            long long contribution = (subarraysWithMinArrI * arr[i]) % MOD;
            totalSum = (totalSum + contribution) % MOD;
        }
        
        return totalSum;
    }
};