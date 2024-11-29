#include <stdio.h>
#include <stdbool.h>

// Ham kiem tra so nguyen to
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int array[100], n, choice, value, position, count;
    
    do {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu\n");
        printf("3. In ra gia tri cac phan tu chan va tinh tong\n");
        printf("4. In ra gia tri lon nhat va nho nhat trong mang\n");
        printf("5. In ra cac phan tu la so nguyen to trong mang va tinh tong\n");
        printf("6. Nhap vao mot so va thong ke trong mang co bao nhieu phan tu do\n");
        printf("7. Them mot phan tu vao vi tri chi dinh\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Nhap mang
                printf("Nhap so luong phan tu: ");
                scanf("%d", &n);
                if (n <= 0 || n > 100) {
                    printf("So luong phan tu khong hop le.\n");
                    break;
                }
                for (int i = 0; i < n; i++) {
                    printf("Nhap gia tri phan tu %d: ", i + 1);
                    scanf("%d", &array[i]);
                }
                break;

            case 2:
                // In ra cac phan tu
                printf("Gia tri cac phan tu trong mang: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", array[i]);
                }
                printf("\n");
                break;

            case 3:
                // In ra phan tu chan va tinh tong
                printf("Gia tri cac phan tu chan: ");
                int sumEven = 0;
                for (int i = 0; i < n; i++) {
                    if (array[i] % 2 == 0) {
                        printf("%d ", array[i]);
                        sumEven += array[i];
                    }
                }
                printf("\nTong cac phan tu chan: %d\n", sumEven);
                break;

            case 4:
                // In ra gia tri lon nhat va nho nhat
                if (n == 0) {
                    printf("Mang rong.\n");
                    break;
                }
                int max = array[0], min = array[0];
                for (int i = 1; i < n; i++) {
                    if (array[i] > max) max = array[i];
                    if (array[i] < min) min = array[i];
                }
                printf("Gia tri lon nhat: %d\n", max);
                printf("Gia tri nho nhat: %d\n", min);
                break;

            case 5:
                // In ra cac so nguyen to va tinh tong
                printf("Gia tri cac phan tu la so nguyen to: ");
                int sumPrimes = 0;
                for (int i = 0; i < n; i++) {
                    if (isPrime(array[i])) {
                        printf("%d ", array[i]);
                        sumPrimes += array[i];
                    }
                }
                printf("\nTong cac so nguyen to: %d\n", sumPrimes);
                break;

            case 6:
                // Thong ke so lan xuat hien cua mot so
                printf("Nhap so can thong ke: ");
                scanf("%d", &value);
                count = 0;
                for (int i = 0; i < n; i++) {
                    if (array[i] == value) {
                        count++;
                    }
                }
                printf("So %d xuat hien %d lan trong mang.\n", value, count);
                break;

            case 7:
                // Them mot phan tu vao vi tri chi dinh
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                printf("Nhap vi tri can them (0-%d): ", n);
                scanf("%d", &position);
                if (position < 0 || position > n) {
                    printf("Vi tri khong hop le.\n");
                    break;
                }
                for (int i = n; i > position; i--) {
                    array[i] = array[i - 1];
                }
                array[position] = value;
                n++;
                printf("Them phan tu thanh cong.\n");
                break;

            case 8:
            	//thoat
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le.\n");
        }

    } while (choice != 8);
}

