#include <stdio.h>

int main() {
    int array[10]; 
    int n, position, newValue;
    printf("Nhap so luong phan tu trong mang (toi da 10): ");
    scanf("%d", &n);
    if (n > 10) {
        printf("So luong phan tu vuot qua gioi han cho phep.\n");
        return 1;
    }
    printf("Nhap %d phan tu vao mang:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    printf("Mang ban dau: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("Nhap vi tri muon sua (0 - %d): ", n - 1);
    scanf("%d", &position);
    if (position < 0 || position >= n) {
        printf("Vi tri khong hop le.\n");
        return 1;
    }
    printf("Nhap gia tri moi: ");
    scanf("%d", &newValue);
    array[position] = newValue;
    printf("Mang sau khi sua: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
}

