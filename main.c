
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

void themMoiSinhVien(SinhVien *p) {
    printf("Vui lòng nhập mã sinh viên: ");
    while (1 == 1) {
        scanf("%s[^\n]", p->id);
        if (strlen(p->id) < 5) {
            printf("Mã sinh viên chưa đủ 5 kí tự\n");
            printf("Vui lòng nhập lại mã sinh viên: ");
        } else
            break;
    }
    fgetc(stdin);
    printf("Vui lòng nhập tên sinh viên: ");
    scanf("%[^\t\n]", p->name);
    fgetc(stdin);
    printf("Vui lòng nhập số điện thoại sinh viên: ");
    scanf("%[^\n]", p->phone);
    fgetc(stdin);
}

void hienThiDanhSach(int dem1, SinhVien *p) {
    printf("%-20s%-5s%-20s%-5s%-20s\n", "Mã sinh viên", "|", "Tên sinh viên", "|", "Số điện thoại");
    dem1++;
    for (int i = 0; i < dem1; ++i) {
        printf("%-18s%-5s%-20s%-5s%-20s\n", p->id, "|", p->name, "|", p->phone);
        p--;
    }
    dem1++;
    for (int j = 0; j < dem1; ++j) {
        p++;
    }
}

void luuDanhSach(int dem1, SinhVien *p) {
  if (p == NULL){
      p--;
      FILE *fp = fopen("danhsachsinhvien.txt", "w+");
      fprintf(fp, "Mã sinh viên      |    Tên sinh viên     |    Số điện thoại\n");
      for (int i = 0; i < dem1; ++i) {
          fprintf(fp, p->id);
          fprintf(fp, "             |    ");
          fprintf(fp, p->name);
          fprintf(fp, "    |    ");
          fprintf(fp, p->phone);
          fprintf(fp, "\n");
          p--;
      }
      fclose(fp);
  } else {
      FILE *fp = fopen("danhsachsinhvien.txt", "w+");
      fprintf(fp, "Mã sinh viên      |    Tên sinh viên     |    Số điện thoại\n");
      for (int i = 0; i < dem1; ++i) {
          fprintf(fp, p->id);
          fprintf(fp, "             |    ");
          fprintf(fp, p->name);
          fprintf(fp, "    |    ");
          fprintf(fp, p->phone);
          fprintf(fp, "\n");
          p--;
      }
      p++;
  }
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
    int size = 10; //Số lượng sinh viên
    SinhVien sinhvien[size];
    SinhVien *p = sinhvien;
    int choice;
    int dem = 0; //Đếm số lần chọn choice 1
    while (1 == 1) {
        menu();
        printf("Vui lòng nhập lựa chọn của bạn là: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Thêm mới sinh viên.\n");
            themMoiSinhVien(p);
            p++;
            dem++;
            if (dem == 4) {
                printf("Danh sách đã đầy.");
                break;
            }
        }
        int dem1 = dem;
        if (choice == 2) {
            printf("Hiển thị danh sách sinh viên.\n");
            hienThiDanhSach(dem1, p);
        }
        if (choice == 3) {
            printf("Lưu danh sách sinh viên ra file.\n");
            luuDanhSach(dem1, p);
        }
        if (choice == 4) {
            printf("Đọc danh sách sinh viên từ file.\n");
            docDanhSach();
        }
        if (choice == 5) {
            printf("Thoát chương trình.\n");
            break;
        }
    }
    return 0;
}