#include <stdio.h>
#include <string.h>
int binary_search(char *arr[], int size, const char *target) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int comparison = strcmp(arr[mid], target);
        if (comparison == 0) {
            return mid; 
        }
        else if (comparison < 0) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1; 
}
int main() {
    char *strings[] = {
        "apple",
        "banana",
        "cherry",
        "date",
        "fig",
        "grape",
        "kiwi",
        "mango",
        "orange",
        "pear"
    };
    int size = sizeof(strings) / sizeof(strings[0]);
    const char *target = "kiwi";
    int result = binary_search(strings, size, target);
    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }
    return 0;
}