#include <iostream>
#include <vector>
using namespace std;

int lowerBound(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size();
    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int upperBound(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size();
    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] <= target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4};
    int target = 2;
    int lb = lowerBound(arr, target);
    int ub = upperBound(arr, target);
    cout << "Lower Bound: " << lb << endl;
    cout << "Upper Bound: " << ub << endl;
    cout << "Frequency: " << ub - lb << endl;

    return 0;
}
