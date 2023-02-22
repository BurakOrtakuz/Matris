#include <iostream>

using namespace std;

class MatrisIslemleri
{
	
private:

public:
    double** matrisOku(int satirSayisi, int sutunSayisi, int çiftIslem)
    {
        double** matris = new double* [satirSayisi];
        int deger = NULL;
        for (int i = 0; i < satirSayisi; i++)
        {
            double* satir = new double[sutunSayisi];
            for (int j = 0; j < sutunSayisi; j++)
            {
                if (çiftIslem != 0)
                {
                    cout << çiftIslem << ". matrisin";
                }
                cout << i << ". satýr " << j << ".sütündaki deðeri giriniz." << endl;
                cin >> deger;
                satir[j] = (int)deger;
            }
            matris[i] = satir;
        }
        return matris;
    }
	void yazdýr(double** matris, int satirSayisi, int sutunSayisi)
	{
		//cout <<"Boyutlar "<< sizeof matris / sizeof matris[0] << "  " << sizeof matris[0] / sizeof matris[0][0] <<" " << sizeof(int) << endl;
		for (int i = 0; i < satirSayisi; i++)
		{
			for (int j = 0; j < sutunSayisi; j++)
			{
				cout << matris[i][j] << " ";
			}
			cout << endl;
		}
	}
	int determinantAl(double** matris, int boyut)
	{
        int sayi1;
        int sayi2;
        int determinant = 1;
        int indeks;
        int toplam = 1;

        
        int *gecici= new int[boyut+1];

        // Her elaman için döngü
        for (int i = 0; i < boyut; i++)
        {
            indeks = i;

            // 0 olmayan deðerleri bulma
            while (indeks < boyut && matris[indeks][i] == 0)
            {
                indeks++;
            }
            if (indeks == boyut) // Sýfýr olmayan deðer kontrolü
            {
                continue;
            }
            if (indeks != i)
            {
                //Köþegenlerin deðiþimi için döngü 
                for (int j = 0; j < boyut; j++)
                {
                    swap(matris[indeks][j], matris[i][j]);
                }
                //Ýþaret her seferine deðiþiyor
                determinant = determinant * pow(-1, indeks - i);
            }

            // Köþegenleri depolamak
            for (int j = 0; j < boyut; j++)
            {
                gecici[j] = matris[i][j];
            }
            // Köþegenlerin altýný dolaþma
            for (int j = i + 1; j < boyut; j++)
            {
                sayi1 = gecici[i]; // köþegen elemanýn deðeri
                sayi2 = matris[j][i]; // Sýradaki satýr

                //Satýr dolaþýmý
                for (int k = 0; k < boyut; k++)
                {
                    matris[j][k] = (sayi1 * matris[j][k]) - (sayi2 * gecici[k]);
                }
                toplam = toplam * sayi1; // Det(kA)=kDet(A);
            }
        }

        //Determinantý bulmak için köþegenleri çarpma
        for (int i = 0; i < boyut; i++)
        {
            determinant = determinant * matris[i][i];
        }
        return (determinant / toplam); // Det(kA)/k=Det(A);
	}
    void tersAl(double**matris, int boyut)
    {
        if (determinantAl(matris, boyut) == 0)
        {
            cout << "Determinant 0 olduðu için tersi alýnamaz!"<<endl;
            return;
        }
        for (int i = 0; i < boyut; i++)//Ters matris bulma iþlemleri
        {
            for (int j = 0; j < boyut; j++)
            {
                for (int k = 0; k < boyut; k++)
                {
                    if (!(i == k || j == i))
                    {
                        matris[j][k] = matris[j][k] - matris[j][i] * matris[i][k] / matris[i][i];
                    }
                }
            }
            matris[i][i] = -1 / matris[i][i];
            for (int j = 0; j < boyut; j++)
            {
                if (!(i == j))
                {
                    matris[j][i] = matris[j][i] * matris[i][i];
                }
            }
            for (int k = 0; k < boyut; k++)
            {
                if (!(k == i))
                {
                    matris[i][k] = matris[i][k] * matris[i][i];
                }
            }
        }
        for (int i = 0; i < boyut; i++)
        {
            for (int j = 0; j < boyut; j++)
            {
                cout << -matris[i][j] << " ";
            }
            cout << endl;
        }
    }
    void transpoze(double** matris, int satirSayisi, int sutunSayisi) {
        for (int i = 0; i < sutunSayisi; i++)//Transpoze iþlemleri
        {
            for (int j = 0; j < satirSayisi; j++)
            {
                cout<< matris[j][i] <<" ";
            }
            cout<<endl;
        }

    }
    void topla(double** matris1, double** matris2, int satirSayisi, int sutunSayisi)
    {
        for (int i = 0; i < satirSayisi; i++)//Satýr döngüsü
        {
            for (int j = 0; j < sutunSayisi; j++)//Sütün döngüsü
            {
                cout << matris1[i][j] + matris2[i][j] << " ";
            }
            cout<<endl;
        }
    }
    void cikar(double** matris1, double** matris2, int satirSayisi, int sutunSayisi)
    {
        for (int i = 0; i < satirSayisi; i++)//Satýr döngüsü
        {
            for (int j = 0; j < sutunSayisi; j++)//Sütün döngüsü
            {
                cout << matris1[i][j] - matris2[i][j] << " ";
            }
            cout << endl;
        }
    }
    void carp(double** matris1, double** matris2, int satirSayisi, int sutunSayisi, int satirSayisi2, int sutunSayisi2)
    {
        for (int l = 0; l < sutunSayisi2; l++)//Satýr döngüsü
        {
            for (int k = 0; k < satirSayisi; k++)//Sütün döngüsü
            {
                double sonuç = 0;
                for (int j = 0; j < sutunSayisi; j++)//Çarpma iþlemi döngüsü
                {
                    sonuç = sonuç + (matris1[l][j] * matris2[j][k]);

                }
                cout<<sonuç<<" ";
            }
            cout<<endl;
        }
    }
};
