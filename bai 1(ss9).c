#include <stdio.h>

int main() {
    int array[100];  
    int currentLength = 0;  // Bien luu so phan tu hien tai trong mang
    int n, value, addIndex;
    printf("Nhap so luong phan tu ban dau (toi da 100): ");
    scanf("%d", &n);
    if (n > 100) {
        printf("So phan tu vuot qua gioi han cho phep.\n");
        return 1;
    }
    printf("Nhap %d phan tu vao mang:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    currentLength = n;
    printf("Nhap gia tri can them: ");
    scanf("%d", &value);
    printf("Nhap vi tri muon them (0 - %d): ", currentLength);
    scanf("%d", &addIndex);

    // Kiem tra vi tri them co hop ly khong
    if (addIndex < 0 || addIndex > currentLength) {
        printf("Vi tri them khong hop le.\n");
        return 1;
    }

    // Thêm phun tu
    if (addIndex == currentLength) {
        // Neu vi tri them la cuoi mang, chi can gan gia tri vao
        array[currentLength] = value;
    } else {
        // Neu vi tri them o giua mang, dich chuyen cac phan tu sau do
        for (int i = currentLength; i > addIndex; i--) {
            array[i] = array[i - 1];
        }
        array[addIndex] = value;
    }
    currentLength++;
    printf("Mang sau khi them phan tu: ");
    for (int i = 0; i < currentLength; i++) {
        printf("%d ", array[i]);
    }
}

