#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};

    int start_index = 2;
    int end_index = arr.size()-1;

    // Check if the indices are within bounds
    if (start_index >= 0 && end_index < arr.size() && start_index <= end_index) {
        int temp = arr[start_index];
        for (int i = start_index; i < end_index; i++) {
            arr[i] = arr[i + 1];
        }
        arr[end_index] = temp;
    } else {
        std::cout << "Invalid input indices" << std::endl;
    }

    // Print the counterclockwise rotated array
    for (int num : arr) {
        std::cout << num << " ";
    }

    return 0;
}
