#include <stdio.h>
#include <time.h>

typedef struct {
    double x, y, z;
} Vector;

void process_by_value(Vector v) {
    double result = v.x + v.y + v.z; // 간단한 계산
}

void process_by_reference(const Vector *v) {
    double result = v->x + v->y + v->z; // 간단한 계산
}

int main() {
    Vector v = {1.0, 2.0, 3.0};
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    for (long i = 0; i < 10000000; i++) {
        process_by_value(v);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Process by value: %f seconds\n", cpu_time_used);

    start = clock();
    for (long i = 0; i < 10000000; i++) {
        process_by_reference(&v);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Process by reference: %f seconds\n", cpu_time_used);

    return 0;
}
