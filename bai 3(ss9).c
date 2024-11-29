#include <stdio.h>

int main() {
    int array[100];  
    int n, position, currentLength;
    printf("Nhap so luong phan tu trong mang (toi da 100): ");
    scanf("%d", &n);
    if (n > 100) {
        printf("So luong phan tu vuot qua gioi han cho phep.\n");
        return 1;
    }
    currentLength = n;
    printf("Nhap %d phan tu vao mang:\n", currentLength);
    for (int i = 0; i < currentLength; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    printf("Mang ban dau: ");
    for (int i = 0; i < currentLength; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("Nhap vi tri muon xoa (0 - %d): ", currentLength - 1);
    scanf("%d", &position);
    if (position < 0 || position >= currentLength) {
        printf("Vi tri khong hop le.\n");
        return 1;
    }
    for (int i = position; i < currentLength - 1; i++) {
        array[i] = array[i + 1];
    }
    currentLength--;
    printf("Mang sau khi xoa: ");
    for (int i = 0; i < currentLength; i++) {
        printf("%d ", array[i]);
    }
}

