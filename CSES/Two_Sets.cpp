#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (i = 0; i < n; ++i)
#define REP(i,k,n) for (i = k; i <= n; ++i)
#define REPR(i,k,n) for (i = k; i >= n; --i)


int main() {
    long long number;
    cin >> number;

    // we should calculate the sum up to n
    // the formula for an arithmetic progression

    long long sum_to_n = (number * (number + 1)) / 2;

    // we need to check if the sum is odd,
    // because it is not possible to divide the odd sum into two parts
    if (sum_to_n % 2 != 0) {
        cout << "NO" << endl;
        return 0; 
    }else{
        cout << "YES" << endl;
    }

    vector<int> set1, set2;
    vector<int> visited(number + 1, 0); // to track the visited numbers

    long long set1_sum = 0;
    long long max_element = number;

    // filling the set 1
    while (set1_sum < sum_to_n / 2){
        long long  remaining_sum = (sum_to_n / 2) - set1_sum; // indicates the lack of sum to be the half of the sum_to_n

        //If I still need more than the biggest number available,
        // then I can safely take that largest number.

        if (remaining_sum > max_element) {
            set1.push_back(max_element);
            visited[max_element] = 1; //mark as visited
            set1_sum += max_element;
            max_element--;

        // If the required sum is small enough, we can pick exactly the number needed to reach the target.
        }else{
            // If remaining_sum is less than or equal to
            // the maximum element, add remaining_sum to set1
            set1.push_back(remaining_sum);
            visited[remaining_sum] = 1;

            if (remaining_sum == max_element) {
                max_element--; 
            }
            set1_sum = sum_to_n / 2;
        }

    }
    // fill the set2 with not visited elements;
    for (int i = 1; i <= number; i++) {
            if (!visited[i]) {
                set2.push_back(i);
            }
    }


    cout << set1.size() << "\n";
    for (auto x : set1) {
        cout << x << " ";
    }
    cout << "\n";


    cout << set2.size() << "\n";
    for (auto x : set2) {
        cout << x << " ";
    }

    return 0;
}
