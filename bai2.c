#include <stdio.h>

int main() {

    int tuoi_benh_nhan[4];
    int co_bao_hiem[4];
    long phi_kham[4];
    long tong_doanh_thu = 0;
    int so_ca_uu_tien = 0;

    printf("=== NHAP THONG TIN TIEP NHAN 4 BENH NHAN ===\n");
    for (int i = 0; i < 4; i++) {
        printf("\nBenh nhan %d:\n", i + 1);
        printf("  - Nhap tuoi: ");
        scanf("%d", &tuoi_benh_nhan[i]);
        printf("  - Co BHYT khong (1: Co, 0: Khong): ");
        scanf("%d", &co_bao_hiem[i]);
    }

    printf("\n==========================================================\n");
    printf("           DANH SACH TIEP NHAN KHAM BENH MEDCARE          \n");
    printf("==========================================================\n");
    printf("%-5s | %-6s | %-10s | %-15s | %-12s\n", 
           "STT", "Tuoi", "BHYT", "Phi kham (VND)", "Phan luong");
    printf("----------------------------------------------------------\n");

    for (int i = 0; i < 4; i++) {
        if (co_bao_hiem[i] != 0 && co_bao_hiem[i] != 1) {
            co_bao_hiem[i] = 0; 
        }

        if (tuoi_benh_nhan[i] <= 0 || tuoi_benh_nhan[i] > 120) {
            phi_kham[i] = 0;
            printf("%-5d | %-6d | %-10s | %-15ld | %-12s\n", 
                   i + 1, tuoi_benh_nhan[i], "Khong", phi_kham[i], "LOI DU LIEU");
        } else {
            if (co_bao_hiem[i] == 1) {
                phi_kham[i] = 40000; 
            } else {
                phi_kham[i] = 200000; 
            }

            tong_doanh_thu += phi_kham[i];

            if (tuoi_benh_nhan[i] > 70) {
                so_ca_uu_tien++;
                printf("%-5d | %-6d | %-10s | %-15ld | %-12s\n", 
                       i + 1, tuoi_benh_nhan[i], 
                       (co_bao_hiem[i] == 1) ? "Co" : "Khong", 
                       phi_kham[i], "UU TIEN");
            } else {
                printf("%-5d | %-6d | %-10s | %-15ld | %-12s\n", 
                       i + 1, tuoi_benh_nhan[i], 
                       (co_bao_hiem[i] == 1) ? "Co" : "Khong", 
                       phi_kham[i], "THUONG");
            }
        }
    }

    printf("==========================================================\n");
    printf("Bao cao tong hop ca truc:\n");
    printf("- Tong doanh thu thu duoc : %ld VND\n", tong_doanh_thu);
    printf("- Tong so ca UU TIEN      : %d benh nhan\n", so_ca_uu_tien);
    printf("==========================================================\n");

    return 0;
}