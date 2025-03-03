#include <iostream>
#include <omp.h>

int main() {
    const int N = 1000000;  // Kích thước mảng
    int *arr = new int[N];

    // Khởi tạo mảng với giá trị từ 1 đến N
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }

    long long sum = 0; // Tổng của mảng

    // Tính tổng song song
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < N; i++) {
        sum += arr[i];
    }

    // Tính trung bình
    double avg = (double)sum / N;

    std::cout << "Gia tri trung binh cua mang: " << avg << std::endl;

    delete[] arr;
    return 0;
}
