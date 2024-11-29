#include <stdio.h>

int main() {
    int arr[100][100], rows, cols, choice;
	int maxSumRow = 0, maxSum = 0;
    do {
        printf("\nMENU\n");
        printf("1. Nhap kich co va gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In gia tri cac phan tu la le va tinh tong\n");
        printf("4. In ra cac phan tu nam tren duong bien va tinh tich\n");
        printf("5. In ra cac phan tu nam tren duong cheo chinh\n");
        printf("6. In ra cac phan tu nam tren duong cheo phu\n");
        printf("7. In ra dong co tong gia tri cac phan tu la lon nhat\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Nhap mang 2 chieu
                printf("Nhap so dong (hang): ");
                scanf("%d", &rows);
                printf("Nhap so cot: ");
                scanf("%d", &cols);

                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        printf("Nhap gia tri cho phan tu arr[%d][%d]: ", i, j);
                        scanf("%d", &arr[i][j]);
                    }
                }
                break;

            case 2:
                // In ma tran
                printf("Gia tri cua cac phan tu trong ma tran: \n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        printf("%d ", arr[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 3:
                // In phan tu le va tinh tong
                printf("Gia tri cac phan tu le: ");
                int oddSum = 0;
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        if (arr[i][j] % 2 != 0) {
                            printf("%d ", arr[i][j]);
                            oddSum += arr[i][j];
                        }
                    }
                }
                printf("\nTong cac phan tu le: %d\n", oddSum);
                break;

            case 4:
                // In phan tu duong bien va tinh tich
                printf("Gia tri cac phan tu duong bien: ");
                int boundaryProduct = 1;
                for (int i = 0; i < cols; i++) boundaryProduct *= arr[0][i]; // Dong dau
                for (int i = 1; i < rows; i++) boundaryProduct *= arr[i][0]; // Cot dau
                for (int i = 1; i < cols; i++) boundaryProduct *= arr[rows - 1][i]; // Dong cuoi
                for (int i = 1; i < rows - 1; i++) boundaryProduct *= arr[i][cols - 1]; // Cot cuoi
                printf("\nTich cua cac phan tu duong bien: %d\n", boundaryProduct);
                break;

            case 5:
                // In phan tu duong cheo chinh
                printf("Gia tri cac phan tu tren duong cheo chinh: ");
                for (int i = 0; i < rows && i < cols; i++) {
                    printf("%d ", arr[i][i]);
                }
                printf("\n");
                break;

            case 6:
                // In phan tu duong cheo phu
                printf("Gia tri cac phan tu tren duong cheo phu: ");
                for (int i = 0; i < rows && i < cols; i++) {
                    printf("%d ", arr[i][cols - 1 - i]);
                }
                printf("\n");
                break;

            case 7:
                // In dong co tong lon nhat
                for (int i = 0; i < rows; i++) {
                    int currentSum = 0;
                    for (int j = 0; j < cols; j++) {
                        currentSum += arr[i][j];
                    }
                    if (currentSum > maxSum) {
                        maxSum = currentSum;
                        maxSumRow = i;
                    }
                }
                printf("Dong co tong lon nhat la dong %d voi tong: %d\n", maxSumRow + 1, maxSum);
                break;

            case 8:
                // Thoat
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le.\n");
        }

    } while (choice != 8);
}

