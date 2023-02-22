#include <iostream>
#include "MatrisIslemleri.cpp"

using namespace std;


int main()
{
	setlocale(LC_ALL, "turkish"); // Türkçe Karakterleri Ekliyoruz.

	int choice;
	double** matris1;
	double** matris2;
	int sutunSayisi;
	int satirSayisi;
	int sutunSayisi2;
	int satirSayisi2;
	MatrisIslemleri islemler;
	while (1)
	{
		cout << "Matris İşlemi seçiniz" << endl;
		cout << "1- Determinant alma." << endl;
		cout << "2- Tersini alma." << endl;
		cout << "3- Transpozesini alma." << endl;
		cout << "4- 2 Matrisi topla." << endl;
		cout << "5- 2 Matrisi çıkar." << endl;
		cout << "6- 2 Matrisi çarp." << endl;
		cin >>choice;
		switch ((int)choice)
		{
		case 1:
			int determinant;
			cout << "Kare matris boyutunu giriniz!" << endl;
			cin >> satirSayisi;
			sutunSayisi= satirSayisi;
			matris1= islemler.matrisOku(satirSayisi, sutunSayisi,0);
			determinant= islemler.determinantAl(matris1, satirSayisi);
			cout << "Determinant: " << determinant << endl;
			break;
		case 2:
			cout << "Kare matris boyutunu giriniz!" << endl;
			cin >> satirSayisi;
			sutunSayisi = satirSayisi;
			matris1 = islemler.matrisOku(satirSayisi, sutunSayisi,0);
			islemler.tersAl(matris1, satirSayisi);
			break;
		case 3:
			cout << "Matrisin satır sayısını giriniz.";
			cin >> satirSayisi;
			cout << "Matrisin sütun sayısını giriniz.";
			cin >> sutunSayisi;
			matris1 = islemler.matrisOku(satirSayisi, sutunSayisi, 0);
			islemler.transpoze(matris1, satirSayisi, sutunSayisi);
			break;
		case 4:
			cout << "Matrislerin satır sayısını giriniz.";
			cin >> satirSayisi;
			cout << "Matrislerin sütun sayısını giriniz.";
			cin >> sutunSayisi;
			matris1 = islemler.matrisOku(satirSayisi, sutunSayisi,1);
			matris2 = islemler.matrisOku(satirSayisi, sutunSayisi, 2);
			islemler.topla(matris1, matris2, satirSayisi, sutunSayisi);
		case 5:
			cout << "Matrislerin satır sayısını giriniz.";
			cin >> satirSayisi;
			cout << "Matrislerin sütun sayısını giriniz.";
			cin >> sutunSayisi;
			matris1 = islemler.matrisOku(satirSayisi, sutunSayisi, 1);
			matris2 = islemler.matrisOku(satirSayisi, sutunSayisi, 2);
			islemler.cikar(matris1, matris2, satirSayisi, sutunSayisi);
		case 6:
			cout << "1. Matrisin satır sayısını giriniz.";
			cin >> satirSayisi;
			cout << "1. Matrisin sütun sayısını giriniz.";
			cin >> sutunSayisi;
			cout << "2. Matrisin satır sayısını giriniz.";
			cin >> satirSayisi2;
			cout << "2. Matrisin sütun sayısını giriniz.";
			cin >> sutunSayisi2;
			matris1 = islemler.matrisOku(satirSayisi, sutunSayisi, 1);
			matris2 = islemler.matrisOku(satirSayisi2, sutunSayisi2, 2);
			if (sutunSayisi == satirSayisi2)
			{
				islemler.carp(matris1, matris2, satirSayisi, sutunSayisi, satirSayisi2, sutunSayisi2);
			}
			else {
				cout << "Gecerli bir değer giriniz.";
			}
		default:
			cout << "Lütfen geçerli bir değer giriniz" << endl;
			break;
		}
	}
}
