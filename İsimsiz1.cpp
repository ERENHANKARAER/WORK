#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int bakiye;

int menu()
{
	system("cls");
	printf("\n KARAER BANK Mobil Þube/ANKARA \n\n Kullanici:EREN KARAER \n IBAN:123456789 \n Kullanilabilir Bakiye : %d USD($) \n\n", bakiye) ;
	
	int secim;
	printf("\n\t Bankamatik Uygulamasi \n");
	printf("\t1 Para Cekme \n");
	printf("\t2 Para Yatirma \n");
	printf("\t3 Havale/EFT \n");
	printf("\t4 Cikis \n");
	scanf("%d",&secim);
	return secim;
}

void paraCek()
{
	int miktar;
	printf("Cekilecek miktari giriniz : "); scanf("%d",&miktar);
	printf("Isleminiz gerceklestiriliyor.... \n"); sleep(2);
	if(bakiye<miktar)
	{
		printf("Bakiye Yetersiz.. \n");
	}
	else
	{
		bakiye -= miktar;
		printf("Para Cekme Islemi Basarili.. \n"); sleep(2);
	}
	printf("Ana Menuye Yonlendiriliyorsunuz.... \n"); sleep(2);
}


void paraYatir()
{
	int miktar;
    printf("Yatirilacak miktari giriniz.. : "); scanf("%d",&miktar);
    printf("Isleminiz gerceklestiriliyor.... \n"); sleep(2);
    
    bakiye += miktar;
    printf("Isleminiz gerceklestiriliyor.... \n"); sleep(2);

    printf("Ana Menuye Yonlendiriliyorsunuz.... \n"); sleep(2);

}


void havaleEFT()
{
	int miktar, iban /*, adsoyad*/;
	printf("Havale yapilacak kisinin iban no giriniz.. : "); scanf("%d",&iban);
	/*printf("Havale yapilacak kisinin adsoyad giriniz.. : "); scanf("%d",&adsoyad);*/
	printf("Havale yapilacak miktari giriniz.. : "); scanf("%d",&miktar);
	if(bakiye<miktar)
	{
		printf("Yetersiz bakiye.. \n");
	}
	else
	{
		if(iban>123456789)
		{
			printf("iban numarasi baska bankaya ait oldugu icin para kesintisi olacaktir.. \n"); sleep(3);
		bakiye -= miktar;
		bakiye=bakiye - ((miktar * 18)/100);
		printf("Isleminiz gerceklestiriliyor.... \n"); sleep(2);
		printf("Havale/EFT basarili.. \n"); sleep(2);
			
		}
	else
	{
		bakiye -= miktar;
		printf("Isleminiz gerceklestiriliyor.... \n"); sleep(2);
		printf("Havale/EFT basarili.. \n"); sleep(2);
	}
	}
	printf("Ana Menuye Yonlendiriliyorsunuz.... \n"); sleep(2);
}



int main()
{
	int parola,i=0;
	printf("\n\n****KARAER BANK**** Hosgeldiniz\n\n\n SIFREnizi giriniz(sifrenizi kimseye gostermeyiniz).. : "); scanf("%d",&parola);
	while(parola!=9696)
	{
		printf("Hatali sifre girdiniz,Sifrenizi giriniz.. : ");
		scanf("%d",&parola);
		if(i==1)
		{
			printf("kartiniz bloke olmustur.. \n"); return 0;
		}
		i++;
	}
	printf("\n Giris Basarili.. \n Sisteme giris yapiliyor.... \n"); sleep(3);
	srand(time(0));
	bakiye=rand() % 5000 + 100 ;
	int secim;
	while(1)
	{
		secim=menu();
		switch(secim)
		{
			case 1: paraCek(); break;
			case 2: paraYatir(); break;
			case 3: havaleEFT(); break;
			case 4: printf("Kartinizi ve paranizi aliniz.."); return 0;
			default: printf("Hatali secim yaptiniz.. \n"); sleep(2);
		}
	}
	return 0;
}



























