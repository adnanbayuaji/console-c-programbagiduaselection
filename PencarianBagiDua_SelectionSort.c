/*PROGRAM PENCARIANBagiduaMenurun_SelectionSort*/
//Program untuk menambahkan elemen baru dalam baru jika belum ada. mencari dari sekumpulan data inputan dan muncul pesan baik ditemukan maupun tidak
//larik terurut menurun

#include<stdio.h>				//file header
#define Nmaks 100				//konstanta Nmaks

/*Tipe bentukan baru*/
typedef enum {false=0, true=1} boolean;		//bentukan Boolean
typedef int LarikInt [Nmaks];				//bentukan LarikInt berbentuk Array

/*DEKLARASI PROTOTYPE*/
void BacaLarik (LarikInt L, int n);							//prosedur BacaLarik
void SelectionSort5 (LarikInt L, int n);					//prosedur SelectionSort5
void BinarySearch (LarikInt L, int n, int x, int *idx);		//prosedur SeqSearch4 untuk nilai indeks

main()						//main program
{
	/*DEKLARASI*/
	LarikInt L;		//var L bertipe LarikInt
	int i;			//pencacah
	int n;			//variabel n sebagai masukan
	int x;			//variabel x sebagai data yang dicari
	int idx;		//variabel indeks
	
	/*DESKRIPSI*/
	printf("\t\tPROGRAM PENCARIAN BINARY(Menurun)\n\n");
	printf("Masukkan jumlah elemen : ");
	scanf("%i", &n);		//inputan
	
	BacaLarik (L, n);		//pemanggilan BacaLarik
	
	SelectionSort5(L, n);	//pemanggilan SelectionSort5
	
	printf("\nMasukkan nilai yang dicari : ");
	scanf("%i", &x);	//input data yang dicari
	
	BinarySearch(L, n, x, &idx); //pemanggilan BinarySearch
	if (idx!=-1)		//jika indeks tidak sama dengan -1
	{
		printf("\n%i sudah terdapat dalam larik ke-%i", x, idx+1);
	}
	else				//jika indeks == -1
	{
		L[n]=x;			//menambah elemen
		for(i=0; i<=n; i++)	//perulangan pencetakan
		{
			printf("%i\t", L[i]);	//pencetakan
		}
	} 
}

void BacaLarik (LarikInt L, int n)		//prosedur
{
	/*DEKLARASI*/
	int i;			//pencacah

	/*DESKRIPSI*/
	for(i=0; i<n; i++)
	{
		printf("\nMasukkan data ke-%i : ", i+1);
		scanf("%i", &L[i]);	//Masukkan data tiap array
	}
}

void SelectionSort5 (LarikInt L, int n) //prosedur SelectionSort5
{
	/*DEKLARASI*/
	int i;		//pencacah
	int k;		//pencacah
	int imax;	//penyimpan indeks nilai terbesar
	int temp;	//penyimpan nilai sementara
	
	/*DESKRIPSI*/
	for(i=0; i<n-1; i++)	//perulangan 
	{
		imax=i;					//nilai indeks terbesar di inisialisasi oleh i
		for (k=i+1; k<n; k++)	//perulangan 
		{
			if(L[k]>L[imax])	//kondisi jika nilai yang akan dipindahkan adalah lebih besar
			{
				imax=k;			//imax akan menyimpan nilai k
			}
		}
		temp=L[i];		//proses pertukaran
		L[i]=L[imax];
		L[imax]=temp;
	}
}

void BinarySearch(LarikInt L, int n, int x, int *idx) //fungsi
{
	/*DEKLARASI*/
	int i, j;			//bantuan indeks
	int k;				//indeks elemen tengah
	boolean found;	//nilai found menyimpan true or false
	
	/*DESKRIPSI*/
	i=0;			//inisialisasi
	j=n-1;
	found=false;	//nilai diawali dengan false
	while (!found && i<=j)	//jika terpenuhi
	{
		k=(i+j)/2;
		if(L[k]==x)			//jika sama dengan
		{
			found=true;		//found bernilai benar
		}
		else				//jika berbeda
		{
			if(L[k]<x)		//jika lebih kecil akan masuk masuk ke bagian kiri
			{
				j=k-1;		//penentu indeks
			}
			else			//jika tidak, cek bagian kanan
			{
				i=k+1;		//penentu indeks awal
			}
		}
	}
	
	if(found)				//jika bernilai benar
	{
		*idx=k;				//idx diisi dengan indeks
	}
	else					//jika bernilai salah
	{
		*idx=-1;			//idx diisi dengan -1
	}
	
}
