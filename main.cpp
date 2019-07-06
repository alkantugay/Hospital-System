#include <iostream>  //cout,cin vs i�in
#include <conio.h>   //getch(); i�in
#include <fstream>   //dosyalama i�lemleri i�in
#include <string>    //string t�r� i�in
#include <Windows.h> //komut ekran�na renk vermek i�in
#include <clocale>   //T�rk�e karakter i�in
#include <iomanip>   //setw() i�in eklenen kk�t�phane
#include <stdio.h>   

using namespace std;

int main()
{
	system("color 60");  // komut ekran�n� renklendiriyoruz
	setlocale(LC_ALL,"turkish");  // T�rk�e karakter ekledik

	int secim;
	string HastaAdi;     //De�i�kenleri tan�mlad�k
	string HastaSoyadi;
	unsigned long long TcNo=0;
	unsigned long long Telefon=0;
	int KayitNo=0;
	int HastaYas=0;
	string HastaCinsiyet;
	char islem;
	unsigned long long TC;

	string Tarih;
	string DoktorAdi;
	string Teshis;
	string Ilac;
	string Saat;
	string Tahliller;
	double Ucret;

	char cevap;

	do {
		cout<<"1- Hasta kay�t ekleme"<<endl;
		cout<<"2- Hasta Kayd� d�zeltme"<<endl;
		cout<<"3- Hasta silme"<<endl;
		cout<<"4- Randevu alma"<<endl;
		cout<<"5- Randevu silme"<<endl;
		cout<<"6- Randevu g�ncelleme"<<endl;
		cout<<"7- Hasta sorgulama"<<endl;
		cout<<"8- Hasta listesi alma"<<endl;
		cout<<"9- Hasta muayene kayd�"<<endl<<endl;
		cout<<"Yapmak istedi�iniz i�lemi se�iniz: ";  cin>>secim;

		switch(secim) //Se�im yap�yoruz
		{
		case 1: 
			{
			    cout<<endl<<"1- Hasta kay�t ekleme"<<endl;
			        
			    ofstream DosyaYaz;
				
				DosyaYaz.open("Hasta.txt",ios::app);
				do	{
				cout<<"\n Hasta TC : ";  cin>>TC;
				cout<<"\n Hasta Adi: "; cin>>HastaAdi;
				cout<<"\n Hasta Soyadi: ";  cin>>HastaSoyadi;
				cout<<"\n Hasta Yasi: ";    cin>>HastaYas;
				cout<<"\n Telefonu: ";      cin>>Telefon;
				cout<<"\n Hasta Cinsiyeti: ";  cin>>HastaCinsiyet;

				DosyaYaz<<TC<<"     "<<HastaAdi<<' '<<HastaSoyadi<<"     "<<HastaYas<<"     "<<Telefon<<"     "<<HastaCinsiyet<<endl;
				cout<<"\n Baska kayit yapacak m�s�n�z ? (e/E)  (h/H)";  cin>>cevap;
				
				} while(cevap=='e' || cevap =='E');

				DosyaYaz.close();
				cout<<"\nDosyaya yazim tamamlandi."<<endl<<endl;
				
				break;
			} 


		case 2:
			{
				cout<<"2- Hasta kayd� d�zeltme"<<endl;
				ifstream DosyaOku;
				DosyaOku.open("Hasta.txt",ios::app);
			    cout<<"\n Hasta bilgileri\n";
				cout<<"TC no: ";  cin>>TcNo;

				if(TC  == TcNo)
				{
					DosyaOku.close();
					ofstream DosyaYaz;
					DosyaYaz.open("Hasta.txt",ios::app);
				    cout<<"\n Hasta Adi: ";     cin>>HastaAdi;
					cout<<"\n Hasta Soyadi: ";  cin>>HastaSoyadi;
					cout<<"\n Hasta Yasi: ";    cin>>HastaYas;
					cout<<"\n Telefonu: ";      cin>>Telefon;
					cout<<"\n Cinsiyeti: ";     cin>>HastaCinsiyet;

					DosyaYaz.close();
				}
				else
					cout<<"Kimlik Numaras� bulunamad�"<<endl;
				break;
			}



		case 3:
			{
				cout<<"3- Hasta silme"<<endl;

				ifstream in ("Hasta.txt");			
				in.open("Hasta.txt",ios::app);
			    cout<<"TC No:";  cin>>TcNo;


				if(TC == TcNo)
					remove("Hasta.txt");
				break;
			
			}

		case 4:
			{
				cout<<"4- Randevu alma"<<endl;
				cout<<"Hasta TC: ";   cin>>TC;

				ifstream DosyaOku("Hasta.txt");
				
				while(!DosyaOku.eof())
				{
					DosyaOku>>TcNo>>HastaAdi>>HastaSoyadi>>HastaYas>>Telefon>>HastaCinsiyet;
					cout<<endl;
					
					if(TC == TcNo)
					{
						cout<<"\n Hasta Bilgileri \n";
						cout<<"TC no: "<<TcNo<<endl;
						cout<<"Ad�: "<<HastaAdi<<endl;
						cout<<"Soyad�: "<<HastaSoyadi<<endl;
						cout<<"Yas�: "<<HastaYas<<endl;
						cout<<"Telefonu: "<<Telefon<<endl;
						cout<<"Cinsiyeti:"<<HastaCinsiyet<<endl;
						cout<<"Randevu istiyor musunuz (e/h)"<<endl;   cin>>cevap;

						if(cevap=='e' || cevap =='E')
						{
							DosyaOku.close();
							ofstream DosyaYaz;
							DosyaYaz.open("RandecuAl.txt",ios::app);
							
							cout<<"\n Randevu Bilgileri \n"; 
                            cout<<"\n Tarih :"; cin>>Tarih; 
                             cout<<"\n Doktor Adi :"; cin>>DoktorAdi; 
 							cout<<"\n Teshis :"; cin>>Teshis; 
 							cout<<"\n Muayene Ucreti :"; cin>>Ucret;

							 DosyaYaz <<TcNo<<" "<<Tarih<<' '<<DoktorAdi<<' ' <<Teshis<<' '<<Ucret<<"\n";
                             DosyaYaz.close();
						}
					}
				}
				            break;
			}




		case 5:
			{
				 cout<<"5- Randevu silme"<<endl;
                 break;
			}


			case 6:
           {
                cout<<"6- Randevu g�ncelleme"<<endl;
 
                ifstream DosyaOku("Hasta.txt",ios::in); 
                 cout<<"TC no:";
                 cin>>TcNo;
                 if(TC==TcNo)
               { 
                 cout<< "\n Hasta Bilgileri \n"; 
                 cout<<"TC no :"<<TcNo<<endl; 
                 cout<<"Ad� :"<<HastaAdi<<endl; 
                 cout<<"Soyad� :"<<HastaSoyadi<<endl; 
                 cout<<"Ya�� :"<<HastaYas<<endl; 
                 cout<<"Telefonu :"<<Telefon<<endl; 
                 cout<<"Cinsiyeti:"<<HastaCinsiyet<<endl; 
                 
                 ofstream DosyaYaz;
                 DosyaYaz.open("Muayene.txt",ios::app);
                 { 
                 cout<<"\n Randevu Bilgileri \n"; 
                 cout<<"\n Tarih :"; cin>>Tarih; 
                 cout<<"\n Doktor Adi :"; cin>>DoktorAdi; 
                 cout<<"\n Teshis :"; cin>>Teshis; 
                 cout<<"\n Muayene Ucreti :"; cin>>Ucret; 
 
                 DosyaYaz.close();
                 ofstream DosyaYaz;
                 }
                 DosyaOku.close(); 
                 ifstream DosyaOku; 
               }
                 else
                 cout<<"B�yle bir ki�i bulunmamaktad�r.";
 
                 break;
            }



  case 7: 
 { 
 cout<<"7- Hasta sorgulama"<<endl;
 
 cout<<" Hasta TC :";cin>>TC; 
 ifstream DosyaOku("Hasta.txt"); 
 while(!DosyaOku.eof()) 
 { 
 DosyaOku>>TcNo>>HastaAdi>>HastaSoyadi>>HastaYas>>Telefon>>HastaCinsiyet; 
 if(TC==TcNo) 
 { 
 cout<< "\n Hasta Bilgileri \n"; 
 cout<<"TC no :"<<TcNo<<endl; 
 cout<<"Ad� :"<<HastaAdi<<endl; 
 cout<<"Soyad� :"<<HastaSoyadi<<endl; 
 cout<<"Ya�� :"<<HastaYas<<endl; 
 cout<<"Telefonu :"<<Telefon<<endl; 
 cout<<"Cinsiyeti:"<<HastaCinsiyet<<endl; 
 TC=TcNo; 
 
 DosyaOku.close(); 
 ofstream DosyaYaz; 
 DosyaOku.open("Muayene.txt",ios::in); 
 cout<<" randevu bilgileri \n"<<endl; cout<<setw(11)<<" TC "<<setw(10)<<" Tarih "<<setw(12)<<" Doktor Adi "<<setw(10)<<" Teshis "<<setw(6)<<" Ucret"<<endl; 
 
 while(!DosyaOku.eof()) 
 { 
 
 DosyaOku>>TcNo>>Tarih>>DoktorAdi>>Teshis>>Ucret; 
 
 if(TC==TcNo) 
 { 
 cout<<setw(11)<< TcNo<<setw(10)<<Tarih<<setw(12)<< DoktorAdi<<setw(10)<< Teshis<<setw(6)<< Ucret<<endl; 
 } 
 } 
 DosyaYaz.close();
 
 } 
 } 
 

 break;
 }




 case 8:
 {
 cout<<"8- Hasta listesi alma"<<endl;
 ifstream DosyaOku;
 DosyaOku.open("Hasta.txt",ios::in);
 
 while(!DosyaOku.eof()) 
 { 
 DosyaOku>>TcNo>>HastaAdi>>HastaSoyadi>>HastaYas>>Telefon>>HastaCinsiyet; 
 cout<<"\n Hasta Bilgileri \n"; 
 cout<<"TC no :"<<TcNo<<endl; 
 cout<<"Ad� :"<<HastaAdi<<endl; 
 cout<<"Soyad� :"<<HastaSoyadi<<endl; 
 cout<<"Ya�� :"<<HastaYas<<endl; 
 cout<<"Telefonu :"<<Telefon<<endl; 
 cout<<"Cinsiyeti:"<<HastaCinsiyet<<endl; 
 
 DosyaOku.close();
 }
 break;
 }





 case 9: 
 {
 cout<<"9- Hasta muayene kayd�"<<endl;
 ifstream DosyaOku;
 DosyaOku.open("Hasta.txt",ios::in);
 { 
 
 do{
 if(DosyaOku.eof()) break;
 else
 DosyaOku>>TcNo>>DoktorAdi>>Teshis>>Tahliller>>Ilac; 
 cout<<"\n Hasta Bilgileri \n"; 
 cout<<"\n Doktor Ad� :"<<DoktorAdi; 
 cout<<"\n Te�his:"<<Teshis;
 cout<<"\n Tahlil Bilgileri :"<<Tahliller; 
 cout<<"\n �la� :"<<Ilac; 
 }while(true);
 
 
 do{
 if(DosyaOku.eof()) break; 
 
 else
 
 DosyaOku>>TcNo>>HastaAdi>>HastaSoyadi>>HastaYas>>Telefon>>HastaCinsiyet; 
 cout<<"\n Hasta Bilgileri \n"; 
 cout<<"TC no :"<<TcNo<<endl; 
 cout<<"Ad� :"<<HastaAdi<<endl; 
 cout<<"Soyad� :"<<HastaSoyadi<<endl; 
 cout<<"Ya�� :"<<HastaYas<<endl; 
 cout<<"Telefonu :"<<Telefon<<endl; 
 cout<<"Cinsiyeti:"<<HastaCinsiyet<<endl; 
 
 }while(true);
 
 
 ofstream DosyaYaz;
 DosyaYaz.open("Randevu.txt",ios::app);
 DosyaYaz.close();
 }
 DosyaOku.close();
 
 break;
 }
		}


		cout<<"�slem yapmaya devam etmek istiyor musunuz? (e/E) (h/H)";
        cin>>islem;
	}while(islem=='e' || islem=='E'); //Islemi yapt�ktan sonra kar��m�za tekrar men�

	cout<<endl; //��kmas�n� sa�l�yor
   
}

