#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

typedef struct {
    int *arr;
    int length;
    int *sorted_arr;
} MergeSortData;

void merge(int *arr, int start, int mid, int end) {
    int len1 = mid - start + 1;
    int len2 = end - mid;

    int left[len1];
    int right[len2];

    for (int i = 0; i < len1; i++) {
        left[i] = arr[start + i];
    }
    for (int i = 0; i < len2; i++) {
        right[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = start;

    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < len1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < len2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(int *arr, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void *merge_sort_thread(void *arg) {
    MergeSortData *data = (MergeSortData *)arg;
    merge_sort(data->arr, 0, data->length - 1);
    pthread_exit(NULL);
}

int read_data_from_file(const char *file_name, int **data) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Could not open the file.\n");
        return -1;
    }

    int count = 0;
    int value;
    while (fscanf(file, "%d", &value) == 1) {
        count++;
    }

    rewind(file);

    *data = (int *)malloc(count * sizeof(int));
    for (int i = 0; i < count; i++) {
        fscanf(file, "%d", &(*data)[i]);
    }

    fclose(file);
    return count;
}

int main() {
    const char *file_name = "input-sort.txt";
    int *data;
    int data_size = read_data_from_file(file_name, &data);
    if (data_size == -1) {
        return -1;
    }

    MergeSortData sort_data;
    sort_data.arr = data;
    sort_data.length = data_size;

    clock_t start_time = clock();

    pthread_t thread;
    pthread_create(&thread, NULL, merge_sort_thread, &sort_data);
    pthread_join(thread, NULL);

    clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    for (int i = 0; i < data_size; i++) {
        printf("%d ", sort_data.arr[i]);
    }
    printf("\n");
    printf("Time taken to sort: %f seconds\n", time_taken);

    free(data);
    return 0;
}