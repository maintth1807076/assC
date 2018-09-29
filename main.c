#include <stdio.h>
#include <string.h>

typedef struct {
    char id[20];
    char name[20];
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

void themMoiSinhVien(int index, SinhVien sinhvien[]) {
    printf("Vui lòng nhập mã sinh viên: ");
    while (1 == 1) {
        scanf("%s[^\n]", sinhvien[index].id);
        if (strlen(sinhvien[index].id) != 5) {
            printf("Mã sinh viên chưa đủ 5 kí tự\n");
            printf("Vui lòng nhập lại mã sinh viên: ");
        } else
            break;
    }
    fgetc(stdin);
    printf("Vui lòng nhập tên sinh viên: ");
    scanf("%[^\t\n]", sinhvien[index].name);
    fgetc(stdin);
    printf("Vui lòng nhập số điện thoại sinh viên: ");
    scanf("%[^\n]", sinhvien[index].phone);
    fgetc(stdin);
}

void hienThiDanhSach(int dem, SinhVien sinhvien[]) {
    printf("%-20s%-5s%-20s%-5s%-20s\n", "Mã sinh viên", "|", "Tên sinh viên", "|", "Số điện thoại");
    for (int i = 0; i < dem; ++i) {
        printf("%-18s%-5s", sinhvien[i].id, "|");
        printf("%-20s%-5s", sinhvien[i].name, "|");
        printf("%-20s\n", sinhvien[i].phone);
    }
}

void luuDanhSach(int dem, SinhVien sinhvien[]) {
    FILE *fp = fopen("danhsachsinhvien.txt", "w+");
    fprintf(fp, "Mã sinh viên      |    Tên sinh viên     |    Số điện thoại\n");
    for (int i = 0; i < dem; ++i) {
        fprintf(fp, sinhvien[i].id);
        fprintf(fp, "             |    ");
        fprintf(fp, sinhvien[i].name);
        fprintf(fp, "    |    ");
        fprintf(fp, sinhvien[i].phone);
        fprintf(fp, "\n");
    }
    fclose(fp);
}

void docDanhSach() {
    FILE *f = fopen("danhsachsinhvien.txt", "r");
    int bufferSize = 225;
    char buffer[bufferSize];
    while (fgets(buffer, bufferSize, f) != NULL) {
        printf("%s", buffer);
    }
}

int main() {
    menu();
    int size =10;
    SinhVien sinhvien[size];
    int index = 0;
    int choice;
    while (1 == 1) {
        printf("Vui lòng nhập lựa chọn của bạn là: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Thêm mới sinh viên.\n");
            themMoiSinhVien(index, sinhvien);
            index++;
            if (index == 10) {
                printf("Danh sách đã đầy.");
                break;
            }
        }
        int dem = index; //Biến dem đếm số lần nhập
        if (choice == 2) {
            printf("Hiển thị danh sách sinh viên.\n");
            hienThiDanhSach(dem, sinhvien);
        }
        if (choice == 3) {
            printf("Lưu danh sách sinh viên ra file.\n");
            luuDanhSach(dem, sinhvien);
        }
        if (choice == 4) {
            printf("Đọc danh sách sinh viên từ file.\n");
            docDanhSach();
        }
        if (choice == 5) {
            printf("Thoát chương trình\n");
            break;
        }
    }
    return 0;
}