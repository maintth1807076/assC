#include <stdio.h>
#include <string.h>

typedef struct {
    char id[20];
    char name[50];
    char phone[20];
} SinhVien;

void menu() {
    printf("Menu cho người dùng lựa chọn:\n");
    printf("1. Thêm mới sinh viên.\n");
    printf("2. Hiển thị danh sách sinh viên.\n");
    printf("3. Lưu danh sách sinh viên ra file.\n");
    printf("4. Đọc danh sách sinh viên từ file.\n");
    printf("5. Thoát chương trình.\n");
}

void themMoiSinhVien(int size, SinhVien sinhvien[]) {
    int dem = 0; //Biến đếm số lần nhập vào
    for (int i = 0; i < size; ++i) {
        printf("Vui lòng nhập mã sinh viên thứ %d: ", i + 1);
        while (1 == 1) {
            scanf("%s[^\n]", sinhvien[i].id);
            if (strlen(sinhvien[i].id) != 5) {
                printf("Mã sinh viên chưa đủ 5 kí tự\n");
                printf("Vui lòng nhập lại mã sinh viên thứ %d: ", i + 1);
            } else
                break;
        }
        fgetc(stdin);
        printf("Vui lòng nhập tên sinh viên thứ %d: ", i + 1);
        scanf("%[^\t\n]", sinhvien[i].name);
        fgetc(stdin);
        printf("Vui lòng nhập số điện thoại sinh viên thứ %d: ", i + 1);
        scanf("%[^\n]", sinhvien[i].phone);
        fgetc(stdin);
        dem++;
        if (dem == 10) {
            printf("Danh sách sinh viên đã đầy\n");
            break;
        }
    }
}

void hienThiDanhSach(int size, SinhVien sinhvien[]) {
    printf("%-20s%-5s%-20s%-5s%-20s\n", "Mã sinh viên", "|", "Tên sinh viên", "|", "Số điện thoại");
    for (int j = 0; j < size; ++j) {
        printf("%-18s%-5s%-20s%-5s%-20s\n", sinhvien[j].id, "|", sinhvien[j].name, "|", sinhvien[j].phone);
    }
}

void luuDanhSach(int size, SinhVien sinhvien[]) {
    FILE *fp = fopen("danhsachsinhvien.txt", "w+");
    fprintf(fp, "Mã sinh viên      |    Tên sinh viên    |    Số điện thoại\n");
    for (int k = 0; k < size; ++k) {
        fprintf(fp, sinhvien[k].id);
        fprintf(fp, "             |    ");
        fprintf(fp, sinhvien[k].name);
        fprintf(fp, "    |    ");
        fprintf(fp, sinhvien[k].phone);
        fprintf(fp, "\n");
    }
    fclose(fp);
}

void docDanhSach() {
    FILE *fp = fopen("danhsachsinhvien.txt", "r");
    int bufferSize = 225;
    char buffer[bufferSize];
    while (fgets(buffer, bufferSize, fp) != NULL) {
        printf("%s", buffer);
    }
}

int main() {
    menu();
    int size = 10;
    SinhVien sinhvien[size];
    int choice;
    while (1 == 1) {
        printf("Vui lòng nhập lựa chọn của bạn là: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Thêm mới sinh viên\n");
            themMoiSinhVien(size, sinhvien);
        };
        if (choice == 2) {
            printf("Hiển thị danh sách sinh viên.\n");
            hienThiDanhSach(size, sinhvien);
        };
        if (choice == 3) {
            printf("Lưu danh sách sinh viên ra file.\n");
            luuDanhSach(size, sinhvien);
        };
        if (choice == 4) {
            printf("Đọc danh sách sinh viên từ file.\n");
            docDanhSach();
        };
        if (choice == 5) {
            printf("Thoát chương trình");
            break;
        };
    }

    return 0;
}