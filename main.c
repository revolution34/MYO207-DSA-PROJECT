#include <stdio.h>

void dizi_yazdir(int dizi[], int boyut) {
    int i;
    for (i = 0; i < boyut; i++) {
        printf("%d ", dizi[i]);
    }
    printf("\n");
}

void araya_ekleme_sirala(int dizi[], int boyut) {
    int i, j, anahtar;
    for (i = 1; i < boyut; i++) {
        anahtar = dizi[i];
        j = i - 1;
        
        while (j >= 0 && dizi[j] > anahtar) {
            dizi[j + 1] = dizi[j];
            j--;
        }
        dizi[j + 1] = anahtar;
    }
}

int ikili_arama(int dizi[], int sol, int sag, int aranan) {
    while (sol <= sag) {
        int orta = sol + (sag - sol) / 2;

        if (dizi[orta] == aranan)
            return orta;
            
        if (dizi[orta] < aranan)
            sol = orta + 1;
        else
            sag = orta - 1;
    }
    
    return -1;
}

int main() {
    int A[] = {15, 32, 7, 19, 4, 25};
    int N = sizeof(A) / sizeof(A[0]);
    int aranan_sayi, sonuc;

    printf("Orijinal Dizi: ");
    dizi_yazdir(A, N);

    araya_ekleme_sirala(A, N);
    printf("Siralanmis Dizi: ");
    dizi_yazdir(A, N);


    printf("\nAranacak sayiyi giriniz: ");
    scanf("%d", &aranan_sayi);

    sonuc = ikili_arama(A, 0, N - 1, aranan_sayi);

    if (sonuc != -1) {
        printf("Sayi bulundu! Dizinin %d. indisinde yer aliyor.\n", sonuc);
    } else {
        printf("Sayi dizi icerisinde bulunamadi.\n");
    }

    return 0;
}