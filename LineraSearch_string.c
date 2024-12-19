#include <stdio.h>
#include <string.h>
int linear_search(char *arr[], int size, const char *target) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i], target) == 0) {
            return i; 
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
    const char *target = "grape";
    int result = linear_search(strings, size, target);
    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }
    return 0;
}