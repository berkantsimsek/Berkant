#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dugum {
    int ucusNo;
    char *isim;
    char *rota;
    struct dugum *ileri;
};

struct dugum *ilk = NULL, *son = NULL, *gecici;

void bekle(){
	printf("Devam etmek icin 'Enter'a basiniz...");
	char secm = getchar();
	secm = getchar();
	system("cls");
}

int ucusEkleme(int _ucusNo, const char *ad, const char *yer,int *sira) {
	struct dugum *yeniDugum = malloc(sizeof(struct dugum));
    yeniDugum->isim = strdup(ad);
    yeniDugum->rota = strdup(yer);
    yeniDugum->ucusNo = _ucusNo;
    yeniDugum->ileri = NULL;

    if (ilk == NULL && son == NULL) {
    	system("cls");
        printf("\n\n %d Ucus Nosundaki %s yolcusu Istanbul --> %s ilk ucusa eklendi...\n\n", _ucusNo, ad, yer);
        ilk=son = yeniDugum;
        (*sira)++;
    } else {
    	system("cls");
        printf("\n\n %d Ucus Nosundaki %s yolcusu Istanbul --> %s yeni ucusa eklendi...\n\n", _ucusNo, ad, yer);
        son->ileri = yeniDugum;
        son = yeniDugum;
        (*sira)++;
    }
    printf("----------------------------------------------------------\n\n\n"); 
    return *sira;
}

void ekranaYazdirTum() {
    int sayac=1;
	struct dugum *gecici = ilk;
     printf("\n Su andaki tum ucus seferleri:\n");
    printf("----------------------------------------------------------\n\n\n");
	while (gecici) {
	    printf(" %d-) %d -->  %s --> %s\n\n",sayac,gecici->ucusNo, gecici->isim, gecici->rota);
        gecici = gecici->ileri;
        sayac++;
    }
    printf("----------------------------------------------------------\n\n\n");
}

void ekranaYazdirIsim() {
	int sayac=1;
    struct dugum *gecici = ilk;
     printf("----------------------------------------------------------\n\n");
	 printf("-Su andaki tum yolcularin isimleri:\n");
    while (gecici) {
        printf("%d-) %s\n",sayac,gecici->isim);
        gecici = gecici->ileri;
    sayac++;
	}
    printf("\n----------------------------------------------------------\n\n\n");
}

void ekranaYazdirYer() {
	int sayac=1;
    struct dugum *gecici = ilk;
    printf("\n----------------------------------------------------------\n\n\n");
     printf("-Gidilecek sehirlerin listesi\n");
    while (gecici) {
        printf("%d-) Istanbul-->%s\n" ,sayac,gecici->rota);
        gecici = gecici->ileri;
        sayac++;
    }
    printf("\n----------------------------------------------------------\n\n\n");
}
int kuyruktanElemanCikarma(int *sira){
	int sayac=1;
	int cikartilacakUcus=1;
	struct dugum *gecici;
	printf("\n----------------------------------------------------------\n\n\n");
	printf("Kacinci ucusu silmek istiyorsunuz?: ");
	scanf("%d",&cikartilacakUcus);
	while(cikartilacakUcus<=0){
		printf("Silmek istediginiz ucusu dogru seciniz: ");
	    scanf("%d",&cikartilacakUcus);
	}
	if(ilk==NULL){
	  printf("Kuyruk bos . islem gerçeklestirilemedi\n");
	}
	else {
	struct dugum  *gecici=ilk;
	struct dugum  *onceki=NULL;
		
		while(gecici !=NULL && sayac < cikartilacakUcus){
	    onceki=gecici;
	    gecici=gecici->ileri;			
		sayac++;
		}
		
	      if (gecici == NULL) {
            printf("Belirtilen sira numarasina sahip ucus bulunamadi.\n");
            printf("\n------------------------------------------------------\n\n");
	      }else {
		   if (onceki == NULL) {          
                ilk = gecici->ileri;
             }    
            else {
                onceki->ileri = gecici->ileri;
            }

            printf("\n------------------------------------------------------\n");
            printf("-%s Yolcusu listeden cikartilmistir.\n", gecici->isim);
            printf("\n------------------------------------------------------\n\n");
			free(gecici->isim);
            free(gecici->rota);
            free(gecici);
             (*sira)--;
             if(ilk==NULL){
             	son=NULL;
			 }
          }
		}  
		return (*sira);  	
	}
	

int yolcuSayisiYazdir(char isim[]){
	int sayac=0;
    gecici = ilk;
        while (gecici != NULL) {
            gecici = gecici->ileri;
            sayac++;
        }
	return sayac;
	
}


int menu() {
    int sira=0;
	int secim;
    char isim[50];
    char yer[25];
    int ucusNo;
    
        
    printf("1- Yeni ucus ekleme\n");
    printf("2- Tum ucuslari listeleme\n");
    printf("3- Tum yolcu isimlerini listeleme\n");
    printf("4- Gidilecek tum sehirleri listeleme\n");
    printf("5- Su andaki toplam ucus sayisi\n");
    printf("6- Ucus silme\n");
    printf("7- Cikis\n");
    printf("\n-Yapmak istediginiz islemi seciniz:");
	scanf("%d", &secim);
	switch (secim){
			
		
	    case 1 :
	        system("cls");
			printf("Yolcunun ismini giriniz: ");
	        scanf(" %s", isim);
	        printf("%s'in gidecegi sehri giriniz: ",isim);
	        scanf(" %s", yer);
	        printf("%s'in Ucus Nosunu giriniz: ",isim);
	        scanf(" %d", &ucusNo);
	        ucusEkleme(ucusNo, isim, yer,&sira);
	        bekle();
	        break;
	    case 2:
	        system("cls");
	        ekranaYazdirTum();
	        bekle();
	        break;
	    case 3:
	        system("cls");
	        ekranaYazdirIsim();
	        bekle();
	        break;
	    case 4:
	        system("cls");
	        ekranaYazdirYer();
	        bekle();
	        break;
	    case 5:
	        system("cls");
	        printf("%d KADAR YOLCU VARDIR.\n",yolcuSayisiYazdir(isim));
	        bekle();
	        break;
	    case 6:
	        system("cls");
			kuyruktanElemanCikarma(&sira);
			bekle();
			break;
	    case 7:
	        printf("Program Bitti! IYI GUNLER DILERIZ...\n");
            exit(0);
            break; 
	    default :
	        printf("Gecersiz secim tekrar deneyiniz.\n");
	        bekle();
	        
            break;
	        
	}
    

}
int main (void){
	while(1){
		system("cls");
		menu();
	}
	return 0;
}
