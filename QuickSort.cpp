#include <iostream>
using namespace std;

int Partition(int A[], int p, int r) {
    int x = A[r];
    int i = p - 1;

    for (int j = p; j < r; ++j) {
        if (A[j] <= x) {

            i++;
            swap(A[i], A[j]);
            cout << j << " " <<i<<endl;
        }
    }

    swap(A[i + 1], A[r]);
    return i + 1;
}

void Quicksort(int A[], int p, int r) {
    if (p < r) {
        int q = Partition(A, p, r);
        Quicksort(A, p, q - 1);
        Quicksort(A, q + 1, r);
    }
}

int main() {
    int arr[] = {9, 7, 5, 3, 2, 6, 10, 14, 12, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    Quicksort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
