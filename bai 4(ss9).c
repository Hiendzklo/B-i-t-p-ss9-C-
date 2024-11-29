#include <stdio.h>

int main() {
    const int maxSize = 100; 
    int array[maxSize];
    int size = 0;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao mang\n");
        printf("2. Hien thi mang\n");
        printf("3. Them phan tu\n");
        printf("4. Sua phan tu\n");
        printf("5. Xoa phan tu\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                // Nhap vao mang
                printf("Nhap so luong phan tu (toi da %d): ", maxSize);
                scanf("%d", &size);
                if (size > maxSize || size <= 0) {
                    printf("So luong phan tu khong hop le.\n");
                    size = 0;
                } else {
                    for (int i = 0; i < size; i++) {
                        printf("Nhap phan tu thu %d: ", i + 1);
                        scanf("%d", &array[i]);
                    }
                }
                break;
            }
            case 2: {
                // Hien thi mang
                printf("Mang hien tai: ");
                for (int i = 0; i < size; i++) {
                    printf("%d ", array[i]);
                }
                printf("\n");
                break;
            }
            case 3: {
                // Them phan tu 
                if (size >= maxSize) {
                    printf("Mang da day, khong the them phan tu.\n");
                } else {
                    int value, pos;
                    printf("Nhap gia tri can them: ");
                    scanf("%d", &value);
                    printf("Nhap vi tri can them (0-%d): ", size);
                    scanf("%d", &pos);

                    if (pos < 0 || pos > size) {
                        printf("Vi tri khong hop le.\n");
                    } else {
                        for (int i = size; i > pos; i--) {
                            array[i] = array[i - 1];
                        }
                        array[pos] = value;
                        size++;
                        printf("Them phan tu thanh cong.\n");
                    }
                }
                break;
            }
            case 4: {
                // Sua phan tu 
                int pos, value;
                printf("Nhap vi tri can sua (0-%d): ", size - 1);
                scanf("%d", &pos);

                if (pos < 0 || pos >= size) {
                    printf("Vi tri khong hop le.\n");
                } else {
                    printf("Nhap gia tri moi: ");
                    scanf("%d", &value);
                    array[pos] = value;
                    printf("Sua phan tu thanh cong.\n");
                }
                break;
            }
            case 5: {
                // Xoa phan tu 
                int pos;
                printf("Nhap vi tri can xoa (0-%d): ", size - 1);
                scanf("%d", &pos);

                if (pos < 0 || pos >= size) {
                    printf("Vi tri khong hop le.\n");
                } else {
                    for (int i = pos; i < size - 1; i++) {
                        array[i] = array[i + 1];
                    }
                    size--;
                    printf("Xoa phan tu thanh cong.\n");
                }
                break;
            }
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 6);
}

