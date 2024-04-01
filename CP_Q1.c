#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stats {
    int min;
    int max;
    int sum;
    double average;
    int mode;
};

struct Stats calc_stat(int numbers[], int count) {
    struct Stats stats;
    if (count == 0) {
        stats.min = 0;
        stats.max = 0;
        stats.sum = 0;
        stats.average = 0;
        stats.mode = 0;
        return stats;
    }

    stats.min = numbers[0];
    stats.max = numbers[0];
    stats.sum = numbers[0];
    stats.mode = numbers[0];

    int frequency[MAX_SIZE] = {0};
    int max_freq = 0;

    for (int i = 1; i < count; i++) {
        if (numbers[i] < stats.min) {
            stats.min = numbers[i];
        }
        if (numbers[i] > stats.max) {
            stats.max = numbers[i];
        }
        stats.sum += numbers[i];
        frequency[numbers[i]]++;
        if (frequency[numbers[i]] > max_freq) {
            max_freq = frequency[numbers[i]];
            stats.mode = numbers[i];
        }
    }

    stats.average = (double)stats.sum / count;
    return stats;
}

int main() {
    int stream[MAX_SIZE];
    int stream_size;

    scanf("%d", &stream_size);

    for (int i = 0; i < stream_size; i++) {
        scanf("%d", &stream[i]);
    }

    int numbers[MAX_SIZE];
    struct Stats stats;

    for (int i = 0; i < stream_size; i++) {
        numbers[i] = stream[i];
        stats = calc_stat(numbers, i + 1);
        printf("min, max, sum, average and mode after addition of %d is %d, %d, %d, %.2f, %d.\n", numbers[i], stats.min, stats.max, stats.sum, stats.average, stats.mode);
    }

    return 0;
}
