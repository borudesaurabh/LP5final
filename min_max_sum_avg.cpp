#include<iostream>
#include <omp.h>
#include <climits>

using namespace std;

void findMin(int arr[], int size) {
    int min_value = INT_MAX;
#pragma omp parallel for reduction(min:min_value)
    for(int i = 0; i < size; i++) {
        if(arr[i] < min_value) {
            min_value = arr[i];
        }
    }
    cout << "Minimum value: " << min_value << endl;
}

void findMax(int arr[], int size) {
    int max_value = INT_MIN;
#pragma omp parallel for reduction(max:max_value)
    for(int i = 0; i < size; i++) {
        if(arr[i] > max_value)
            max_value = arr[i];
    }
    cout << "Maximum value: " << max_value << endl;
}

void findSum(int arr[], int size) {
    int sum = 0;
#pragma omp parallel for reduction(+:sum)
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    cout << "Sum is: " << sum << endl;
}

void findAvg(int arr[], int size) {
    int sum = 0;
#pragma omp parallel for reduction(+:sum)
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    double avg = static_cast<double>(sum) / size;
    cout << "Average is: " << avg << endl;
}

int main() {
    int size;
    cout << "Enter array size: ";
    cin >> size;
    int arr[size];
    cout << "Enter elements: ";
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    findMin(arr, size);
    findMax(arr, size);
    findSum(arr, size);
    findAvg(arr, size);
    return 0;
}
