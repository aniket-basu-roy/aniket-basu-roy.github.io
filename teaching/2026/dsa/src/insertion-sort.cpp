#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <fstream>

using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int main() {
    ofstream csv("insertion_sort_times.csv");
    csv << "size,time_nanoseconds\n";

    for (int size = 5; size <= 100; ++size) {
        if (size % 5 == 0 && size != 5) continue;

        // Generate random array
        vector<int> arr(size);
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, 1000);
        for (int &x : arr) x = dis(gen);

        // Measure time
        auto start = chrono::high_resolution_clock::now();
        insertionSort(arr);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

        // Write to CSV
        csv << size << "," << duration.count() << "\n";
    }

    csv.close();
    cout << "Results written to insertion_sort_times.csv" << endl;
    return 0;
}
