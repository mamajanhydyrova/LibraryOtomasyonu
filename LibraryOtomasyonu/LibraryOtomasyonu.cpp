#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>
#include <locale.h>
#include <fstream>
#include <cstdio>
#include<iomanip>
#include<sstream>
using namespace std;

int menu()
{
	int secim;
	cout <<"~~~~~~~~~~~~KUTUPHANE OTOMASYONU~~~~~~~~~~~~~\n\n\n" ;
	cout << "*************Ana Menü************\n\n";
	cout << "1-Kitap islemleri\n";
	cout <<"2-Uye islemleri\n";
	cout << "3-Emanet islemleri\n";
	cout <<"0-Programi Kapat\n\n";
	cout <<"Yapmak istediginiz islemi giriniz:";
	cin >> secim;
	return secim;
}

struct Kitap {
	string barkod;
	string kitapAdi;
	string yazarAdi;
	string kitapTuru;
	string teminTarihi;
	string stokSayisi;
}kitap;

struct Uye {
	string tc;
	string AdSoyad;
	string dogumtarihi;
	string telefon;
	string adres;
	string uyelikTarihi;
	bool durum;
}uye;

struct Emanet {
	string uyeTc;
	string kitapBarkod;
	string teslimtarihi;
	string kullanacagiGunSayisi;
	string kullandigiGunSayisi;
	string iadeTarihi;
	string gecikmegunsayisi;
	/*bool durum;*/
}emanet;

void KitapEkle()
{
	system("cls");
	cout << "~~~~~~~~~~~~~~Kitap Ekleme~~~~~~~~~~~~~~~~~~ " << endl;
	string satir;
	bool mevcut = false;
	cout << "Barkod numarasini giriniz:" << endl;
	cin.ignore();
	getline(cin, kitap.barkod);
	///*getline(cin >> ws, kitap.barkod);*/
	//cout << "Kitap adini giriniz:";
	///*getline(cin >> ws, kitap.kitapAdi);*/
	//getline(cin, kitap.kitapAdi);
	//cout << "Kitap turunu giriniz:";
	//getline(cin >> ws, kitap.kitapTuru);
	//cout << "Yazar adini giriniz:";
	//getline(cin >> ws, kitap.yazarAdi);
	//cout << "Stok sayisini giriniz:";
	//getline(cin >> ws, kitap.stokSayisi);

	ifstream dosya("kitaplar.txt");

	if (dosya.is_open()) {
		while (getline(dosya, satir)) {
			istringstream iss(satir);
			string mevcutBarkod;
			getline(iss, mevcutBarkod, '#');
			if (mevcutBarkod == kitap.barkod) {
				mevcut = true;
				break;
			}
		}
		dosya.close();
	}
	else {
		cout << "Dosya acilamadi" << endl;
		return;
	}
	if (mevcut) {
		cout << "Aynı barkod numaralı kitap zaten mevcut!" << endl;
	}
	else {
		/*getline(cin >> ws, kitap.barkod);*/
	    cout << "Kitap adini giriniz:";
	   /*getline(cin >> ws, kitap.kitapAdi);*/
	    getline(cin, kitap.kitapAdi);
	    cout << "Kitap turunu giriniz:";
	    getline(cin >> ws, kitap.kitapTuru);
	    cout << "Yazar adini giriniz:";
	    getline(cin >> ws, kitap.yazarAdi);
	    cout << "Stok sayisini giriniz:";
	    getline(cin >> ws, kitap.stokSayisi);
		ofstream dosya("kitaplar.txt", ios::app);
		if (dosya.is_open()) {
			dosya << kitap.barkod << "#"
				<< kitap.kitapAdi << "#"
				<< kitap.kitapTuru << "#"
				<< kitap.yazarAdi << "#"
				<< kitap.stokSayisi << "\n";
			dosya.close();
			cout << "-----Kitap basariyla eklendi-----" << endl;
		}
		else {
			cout << "Dosya acilamadi" << endl;
		}
	}
}
/*-------------------------------------------------------------------------------------------------------------------*/

void KitapListele()
{
	system("cls");
	cout << "~~~~~~~~~~KitapLari Listele~~~~~~~~~~~~~~" << endl;
	string satir;
	ifstream dosya("kitaplar.txt");
	if (!dosya.is_open()) {
		cout << "Dosya acilamadi" << endl;
		return;
	}
	bool kitapvar = true;
	cout << left << setw(15) << "Barkod"
		<< setw(30) << "Kitap Adi"
		<< setw(20) << "Kitap Turu"
		<< setw(25) << "Yazar Adi"
		<< setw(10) << "Stok Sayisi" << endl;
	cout << string(110, '-') << endl;
	while (getline(dosya, satir)) {
		if (!satir.empty()) {
			kitapvar = true;
			istringstream iss(satir);

			getline(iss, kitap.barkod, '#');
			getline(iss, kitap.kitapAdi, '#');
			getline(iss, kitap.kitapTuru, '#');
			getline(iss, kitap.yazarAdi, '#');
			getline(iss, kitap.stokSayisi);

			cout << left << setw(15) << kitap.barkod
				<< setw(30) << kitap.kitapAdi
				<< setw(20) << kitap.kitapTuru
				<< setw(25) << kitap.yazarAdi
				<< setw(10) << kitap.stokSayisi << endl;
		}
	}
}
/*--------------------------------------------------------------------------------------------------------------------------------*/
void BelirliListeleme(int barkod) {
	string satir;
	ifstream dosya("kitaplar.txt");
	if (!dosya.is_open()) {
		cout << "Dosya acilamadi" << endl;
		return;
	}
	cout << left << setw(15) << "Barkod"
		<< setw(30) << "Kitap Adi"
		<< setw(20) << "Kitap Turu"
		<< setw(25) << "Yazar Adi"
		<< setw(10) << "Stok Sayisi" << endl;
	cout << string(110, '-') << endl;
	while (getline(dosya, satir)) {
		if (satir != "") {
			istringstream iss(satir);
			getline(iss, kitap.barkod, '#');
			getline(iss, kitap.kitapAdi, '#');
			getline(iss, kitap.kitapTuru, '#');
			getline(iss, kitap.yazarAdi, '#');
			getline(iss, kitap.stokSayisi);
			if (stoi(kitap.barkod) == barkod) {
				cout << left << setw(15) << kitap.barkod
					<< setw(30) << kitap.kitapAdi
					<< setw(20) << kitap.kitapTuru
					<< setw(25) << kitap.yazarAdi
					<< setw(10) << kitap.stokSayisi << endl;
			}
		}
	}
}
/*----------------------------------------------------------------------------------------------------------------------------*/
void KitapGuncelle(int barkod)
{
	system("cls");
	cout << "~~~~~~~~~~~~Kitap Guncelleme~~~~~~~~~~~~\n";
	string satir;
	ifstream dosya("kitaplar.txt");
	ofstream temp_dosya("temp.txt");
	if (!dosya.is_open() || !temp_dosya.is_open()) {
		cout << "Dosya acilamadi";
		return;
	}
	while (getline(dosya, satir)) {
		if (satir != "") {
			istringstream iss(satir);
			getline(iss, kitap.barkod, '#');
			getline(iss, kitap.kitapAdi, '#');
			getline(iss, kitap.kitapTuru, '#');
			getline(iss, kitap.yazarAdi, '#');
			getline(iss, kitap.stokSayisi);
			if (stoi(kitap.barkod) != barkod) {
				temp_dosya << satir << endl;
			}
			else {
				cout << "Kitabin barkod numarasini giriniz:";
				cin.ignore();
				getline(cin >> ws, kitap.barkod);
				cout << "Kitap adini giriniz:";
				getline(cin >> ws, kitap.kitapAdi);
				cout << "Kitap turunu giriniz:";
				getline(cin >> ws, kitap.kitapTuru);
				cout << "Yazar adini giriniz:";
				getline(cin >> ws, kitap.yazarAdi);
				cout << "Stok sayisini giriniz:";
				getline(cin >> ws, kitap.stokSayisi);
				temp_dosya << kitap.barkod << "#"
					<< kitap.kitapAdi << "#"
					<< kitap.kitapTuru << "#"
					<< kitap.yazarAdi << "#"
					<< kitap.stokSayisi << endl;
			}
		}
	}
	dosya.close();
	temp_dosya.close();
	remove("kitaplar.txt");
	rename("temp.txt", "kitaplar.txt");
}
/*-------------------------------------------------------------------------------------------------------------*/
void KitapSil()
{
	system("cls");
	cout << "~~~~~~~~~~~~~~Kitap Silme~~~~~~~~~~~~~~" << endl;
	bool  kitapVarYok = false;
	cout << "Silmek istediginiz kitabin barkod numarasini giriniz:";
	string silinecekbarkod;
	cin >> silinecekbarkod;
	ifstream dosya("kitaplar.txt");
	ofstream temp_dosya("temp.txt");
	if (!dosya.is_open() || !temp_dosya.is_open()) {
		cout << "Dosya acilamadi";
		return;
	}

	string satir;
	while (getline(dosya >> ws, satir)) {
		istringstream iss(satir);

		getline(iss, kitap.barkod, '#');
		getline(iss, kitap.kitapAdi, '#');
		getline(iss, kitap.kitapTuru, '#');
		getline(iss, kitap.yazarAdi, '#');
		getline(iss, kitap.stokSayisi);

		if (kitap.barkod != silinecekbarkod)
		{
			temp_dosya << kitap.barkod << "#"
				<< kitap.kitapAdi << "#"
				<< kitap.kitapTuru << "#"
				<< kitap.yazarAdi << "#"
				<< kitap.stokSayisi << endl;
		}
		else
		{
			kitapVarYok = true;
		}
	}
	dosya.close();
	temp_dosya.close();

	if (kitapVarYok) {
		cout << "Kitap basariyla silindi" << endl;
		remove("kitaplar.txt");
		rename("temp.txt", "kitaplar.txt");
	}
	else {
		cout << "Barkod numarasina sahip kitap bulunamadi" << endl;
		remove("temp.txt");
	}
}
/*-----------------------------------------------------------------------------------------------------------*/

void KitapIslem()
{
	system("cls");
	int barkod;
	cout << "~~~~~~~~~~~~~~~~~KITAP ISLEMLERI~~~~~~~~~~~~~~~~\n\n";
	cout <<"1-Kitap Ekle" << endl;
	cout <<"2-Kitap Listele" << endl;
	cout << "3-Belirli Listeleme" << endl;
	cout <<"4-Kitap Guncelle" << endl;
	cout <<"5-Kitap Sil" << endl;
	cout <<"0-Ana Menuye Don\n\n";
	cout <<"Yapmak istediginiz islemi giriniz:";
	int b;
	cin >> b;
	switch (b)
	{
	case 1:KitapEkle(); break;
	case 2:KitapListele(); break;
	case 3:
		cout << "Aramak istediginiz kitabin barkod numarasini giriniz:";
		cin >> barkod;
		BelirliListeleme(barkod); break;
	case 4:
		cout << "Barkod numarasi giriniz:";
		cin >> barkod;
		KitapGuncelle(barkod); break;
	case 5:KitapSil(); break;
	case 0:break;
	default:
		cout << "Hatali islem yaptiniz.Tekrar deneyin" << endl; break;
	}
}
/*-------------------------------------------------------------------------------------------------------------------*/
void UyeEkle()
{
	system("cls");
	cout << "~~~~~~~~~Uye Ekleme~~~~~~~~~~" << endl;
	string satir;
	ifstream dosya("uyeler.txt");
	bool mevcut = false;
	cout << "Tc numarasini giriniz:";
	getline(cin >> ws, uye.tc);
	if (dosya.is_open()) {
		while (getline(dosya, satir)) {
			istringstream iss(satir);
			string mevcutTc;
			getline(iss, mevcutTc, '#');
			if (mevcutTc == uye.tc) {
				mevcut = true;
				break;
			}
		}
		dosya.close();
	}
	else {
		cout << "Dosya acilamadi" << endl;
		return;
	}

	
	if (mevcut) {
		cout << "Aynı TC numaralı üye zaten mevcut!" << endl;
	}
	else {
		cout << "Ad Soyad giriniz:";
		getline(cin >> ws, uye.AdSoyad);
		cout << "Dogum tarihini giriniz:";
		getline(cin >> ws, uye.dogumtarihi);
		cout << "Telefon numarasini giriniz:";
		getline(cin >> ws, uye.telefon);
		cout << "Adres giriniz:";
		getline(cin >> ws, uye.adres);
		cout << "Uyelik tarihini giriniz:";
		getline(cin >> ws, uye.uyelikTarihi);
		uye.durum = true; 
		ofstream dosya("uyeler.txt", ios::app);
		if (dosya.is_open()) {
			dosya << uye.tc << "#"
				<< uye.AdSoyad << "#"
				<< uye.dogumtarihi << "#"
				<< uye.telefon << "#"
				<< uye.adres << "#"
				<< uye.uyelikTarihi << "#"
				<< uye.durum << "\n";
			dosya.close();
			cout << "Üye başarıyla eklendi" << endl;
		}
		else {
			cout << "Dosya acilamadi" << endl;
		}
	}
}
void UyeListele()
{
	system("cls");
	cout << "~~~~~~~~~~~~Uyeleri Listele~~~~~~~~~~~~" << endl;
	string satir;
	ifstream dosya("uyeler.txt");
	if (!dosya.is_open()) {
		cout << "Dosya acilamadi" << endl;
		return;
	}

	cout << left << setw(15) << "Tc"
		<< setw(30) << "Ad Soyad"
		<< setw(20) << "Dogum Tarihi"
		<< setw(15) << "Telefon"
		<< setw(15) << "Adres"
		<< setw(20) << "Uyelik Tarihi"
		<< setw(10) << "Durum" << endl;

	cout << string(120, '-');
	cout << endl;
	while (getline(dosya, satir)) {
		if (satir != "") {
			istringstream iss(satir);
			getline(iss, uye.tc, '#');
			getline(iss, uye.AdSoyad, '#');
			getline(iss, uye.dogumtarihi, '#');
			getline(iss, uye.telefon, '#');
			getline(iss, uye.adres, '#');
			getline(iss, uye.uyelikTarihi, '#');
			iss >> uye.durum;
			cout << left << setw(15) << uye.tc
				<< setw(30) << uye.AdSoyad
				<< setw(20) << uye.dogumtarihi
				<< setw(15) << uye.telefon
				<< setw(15) << uye.adres
				<< setw(20) << uye.uyelikTarihi
				<< setw(10) << uye.durum << endl;
		}
	}
}
void BelirliListele(string tc)
{
	system("cls");
	cout << "~~~~~~~~~~~~Belirli Uyeleri Listele~~~~~~~~~~~~" << endl;
	string satir;
	ifstream dosya("uyeler.txt");
	if (!dosya.is_open()) {
		cout << "Dosya acilamadi" << endl;
		return;
	}
	cout << left << setw(15) << "Tc"
		<< setw(30) << "Ad Soyad"
		<< setw(20) << "Dogum Tarihi"
		<< setw(15) << "Telefon"
		<< setw(30) << "Adres"
		<< setw(20) << "Uyelik Tarihi"
		<< setw(10) << "Durum" << endl;
	cout << string(140, '-') << endl;
	while (getline(dosya, satir)) {
		if (satir != "") {
			istringstream iss(satir);
			getline(iss, uye.tc, '#');
			getline(iss, uye.AdSoyad, '#');
			getline(iss, uye.dogumtarihi, '#');
			getline(iss, uye.telefon, '#');
			getline(iss, uye.adres, '#');
			getline(iss, uye.uyelikTarihi, '#');
			iss >> uye.durum;
			if (uye.tc == tc) {
				cout << left << setw(15) << uye.tc
					<< setw(30) << uye.AdSoyad
					<< setw(20) << uye.dogumtarihi
					<< setw(15) << uye.telefon
					<< setw(30) << uye.adres
					<< setw(20) << uye.uyelikTarihi
					<< setw(10) << uye.durum << endl;
			}
		}
	}
}
void UyeGuncelle(string tc)
{
	system("cls");
	cout << "~~~~~~~~~~~~Uye Guncelleme~~~~~~~~~~~~" << endl;
	string satir;
	ifstream dosya("uyeler.txt");
	ofstream temp_dosya("temp.txt");
	if (!dosya.is_open() || !temp_dosya.is_open()) {
		cout << "Dosya acilamadi";
		return;
	}
	while (getline(dosya, satir)) {
		if (satir != "") {
			istringstream iss(satir);
			getline(iss, uye.tc, '#');
			getline(iss, uye.AdSoyad, '#');
			getline(iss, uye.dogumtarihi, '#');
			getline(iss, uye.telefon, '#');
			getline(iss, uye.adres, '#');
			getline(iss, uye.uyelikTarihi, '#');
			iss >> uye.durum;
			if (uye.tc != tc) {
				temp_dosya << satir << endl;
			}
			else {
				cout << "Uyenin tc numarasini giriniz:";
				cin.ignore();
				getline(cin >> ws, uye.tc);
				cout << "Ad Soyad giriniz:";
				getline(cin >> ws, uye.AdSoyad);
				cout << "Dogum tarihini giriniz:";
				getline(cin >> ws, uye.dogumtarihi);
				cout << "Telefon numarasini giriniz:";
				getline(cin >> ws, uye.telefon);
				cout << "Adres giriniz:";
				getline(cin >> ws, uye.adres);
				cout << "Uyelik tarihini giriniz:";
				getline(cin >> ws, uye.uyelikTarihi);
				cout << "Durumu giriniz:";
				cin >> uye.durum;
				temp_dosya << uye.tc << "#"
					<< uye.AdSoyad << "#"
					<< uye.dogumtarihi << "#"
					<< uye.telefon << "#"
					<< uye.adres << "#"
					<< uye.uyelikTarihi << "#"
					<< uye.durum << endl;
			}
		}
	}
	dosya.close();
	temp_dosya.close();
	remove("uyeler.txt");
	rename("temp.txt", "uyeler.txt");
	cout << "Uye Guncellendi" << endl;
}
void UyeSil(string tc)
{
	system("cls");
	cout << "~~~~~~~~~~~~~~Uye Silme~~~~~~~~~~~~~~\n\n";;
	bool uyeVarYok = false;
	ifstream dosya("uyeler.txt");
	ofstream temp_dosya("temp.txt");
	if (!dosya.is_open() || !temp_dosya.is_open()) {
		cout << "Dosya acilamadi";
		return;
	}
	string satir;
	while (getline(dosya >> ws, satir)) {
		istringstream iss(satir);
		getline(iss, uye.tc, '#');
		getline(iss, uye.AdSoyad, '#');
		getline(iss, uye.dogumtarihi, '#');
		getline(iss, uye.telefon, '#');
		getline(iss, uye.adres, '#');
		getline(iss, uye.uyelikTarihi, '#');
		iss >> uye.durum;
		if (uye.tc != tc) {
			temp_dosya << uye.tc << "#"
				<< uye.AdSoyad << "#"
				<< uye.dogumtarihi << "#"
				<< uye.telefon << "#"
				<< uye.adres << "#"
				<< uye.uyelikTarihi << "#"
				<< uye.durum << endl;
		}
		else {
			uyeVarYok = true;
		}
	}
	dosya.close();
	temp_dosya.close();
	if (uyeVarYok) {
		cout << "Uye basariyla silindi" << endl;
		remove("uyeler.txt");
		rename("temp.txt", "uyeler.txt");
	}
	else {
		cout << "Tc numarasina sahip uye bulunamadi" << endl;
		remove("temp.txt");
	}
}

void UyeIslem()
{
	system("cls");
	cout << "~~~~~~~~~~~~Uye Islemleri~~~~~~~~~~~~~\n\n";
	cout << "1-Uye Ekle" << endl;
	cout << "2-Uye Listele" << endl;
	cout << "3-Uyeye gore belirli Listeleme" << endl;
	cout << "4-Uye Guncelleme" << endl;
	cout << "5-Uye Sil" << endl;
	cout << "0-Ana Menuye Don" << endl;
	cout << "Yapmak istediginiz islemi giriniz:";
	int secim;
	cin >> secim;
	string tc;
	switch (secim)
	{
	case 1:UyeEkle(); break;
	case 2:UyeListele(); break;
	case 3:
		cout << "Aramak istediginiz uyenin tc numarasini giriniz:" << endl;
		getline(cin >> ws, tc);
		BelirliListele(tc);
		break;
	case 4:
		cout << "Uyenin tc numarasini giriniz:";
		cin >> tc;
		UyeGuncelle(tc);
		break;
	case 5:
		cout << "Uyenin tc numarasini giriniz:";
		cin >> tc;
		UyeSil(tc);
		break;
	case 0:break;
	default:
		cout << "Hatali islem yaptiniz.Tekrar deneyin" << endl; break;
	}
}
void StokGuncelle(string barkod1,int sayi){
	int sayac = 0;
	string satir;
	bool bulundu = false;
	ifstream dosya("kitaplar.txt");
	ofstream geciciDosya("gecici.txt");
	if (!dosya.is_open() || !geciciDosya.is_open()) {
		cout << "Dosya acilamadi" << endl;
		return;
	}
	while (getline(dosya, satir)) {
		if (satir != "") {
			istringstream iss(satir);
			getline(iss, kitap.barkod, '#');
			iss >> kitap.stokSayisi;

			if (kitap.barkod == barkod1) {
				kitap.stokSayisi += sayi;
				bulundu = true;
				sayac++;
			}
			geciciDosya << kitap.barkod << "#" << kitap.stokSayisi << endl;
		}
	}

	dosya.close();
	geciciDosya.close();
	if (bulundu) {
		remove("kitaplar.txt");
		rename("gecici.txt", "kitaplar.txt");
		cout << "Stok Guncellendi\n";
	}
	else {
		remove("gecici.txt");
		cout << "Barkod numarasi bulunamadi\n";
	}

	
}
void KitapOduncAl()
{
	system("cls");
	cout << "~~~~~~~~~~~~Kitap Odunc Alma~~~~~~~~~~~~\n\n";
	string uyeTc;
	string kitapBarkod;
	cout << "Uye tc numarasini giriniz:";
	cin >> uyeTc;
	cout << "Kitap barkod numarasini giriniz:";
	cin >> kitapBarkod;
	ifstream dosya("uyeler.txt");
	ifstream dosya2("kitaplar.txt");
	ofstream dosya3("emanetler.txt", ios::app);
	if (!dosya.is_open() || !dosya2.is_open() || !dosya3.is_open()) {
		cout << "Dosya acilamadi" << endl;
		return;
	}
	string satir;
	bool uyeVar = false;
	bool kitapVar = false;
	while (getline(dosya, satir)) {
		if (satir != "") {
			istringstream iss(satir);
			getline(iss, uye.tc, '#');
			getline(iss, uye.AdSoyad, '#');
			getline(iss, uye.dogumtarihi, '#');
			getline(iss, uye.telefon, '#');
			getline(iss, uye.adres, '#');
			getline(iss, uye.uyelikTarihi, '#');
			iss >> uye.durum;
			if (uye.tc == uyeTc) {
				uyeVar = true;
				break;
			}
		}
	}
	if (!uyeVar) {
		cout << uyeTc<<"TC numarali üye yok...Kayit olustur\n\n";
	}
	dosya.close();

	while (getline(dosya2, satir)) {
		if (satir != "") {
			istringstream iss(satir);
			getline(iss, kitap.barkod, '#');
			getline(iss, kitap.kitapAdi, '#');
			getline(iss, kitap.kitapTuru, '#');
			getline(iss, kitap.yazarAdi, '#');
			getline(iss, kitap.stokSayisi);
			if (kitap.barkod == kitapBarkod) {
				kitapVar = true;
				break;
			}
		}
	}
	if (!kitapVar) {
		cout <<kitapBarkod<<"barkod numarali kitap kayitli degil";
	}
	dosya2.close();
	if (stoi(kitap.stokSayisi) < 1) {
		cout << "barkod numarali kitaptan stokta kalmamis";
	}
	if (uyeVar && kitapVar){
		time_t t = time(0);
		struct tm now;
		localtime_s(&now, &t);
		string teslimtarihi = to_string(now.tm_mday) + "." + to_string(now.tm_mon + 1) + "." + to_string(now.tm_year + 1900);
		dosya3 << uyeTc << "#"
			<< kitapBarkod << "#"
			<< teslimtarihi << "#"
			<< "0" << "#"
			<< "0" << "#"
			<< "0" << "\n";
		cout << "Kitap odunc alindi" << endl;
		StokGuncelle(kitapBarkod, -1);

	}
	else {
		cout << "Uye veya kitap bulunamadi" << endl;
	}
	
}

void KitapTeslim()
{
	system("cls");
	cout << "~~~~~~~~~~~~Kitap Teslim etme~~~~~~~~~~~~\n\n" ;
	string uyeTc;
	string kitapBarkod;
	string satir;
	int sonuc,sayac=0;
	cout << "Uye tc numarasini giriniz:";
	cin >> uyeTc;
	cout << "Kitap barkod numarasini giriniz:";
	cin >> kitapBarkod;
	ifstream dosya("emanetler.txt");
	if (!dosya.is_open()) {
		cout << "Dosya acilamadi" << endl;
		return;
	}
	while (getline(dosya, satir)) {
		if (satir != "") {
			istringstream iss(satir);
			getline(iss, emanet.uyeTc, '#');
			getline(iss, emanet.kitapBarkod, '#');
			getline(iss, emanet.teslimtarihi, '#');
			if (uye.tc == uyeTc && kitap.barkod == kitapBarkod) {
				sonuc = 1;
				break;
			}
			sayac++;
		}
	}
	if (sonuc == 0) {
		cout << "TC ve barkod numarali emanet kaydi bulunamadi" << endl;
	}
	
	time_t t = time(0);
	struct tm now;
	localtime_s(&now, &t);
	string teslimtarihi = to_string(now.tm_mday) + "." + to_string(now.tm_mon + 1) + "." + to_string(now.tm_year + 1900);
	now.tm_mday += stoi(emanet.kullandigiGunSayisi);
	mktime(&now); 
	string iadeTarihi = to_string(now.tm_mday) + "." + to_string(now.tm_mon + 1) + "." + to_string(now.tm_year + 1900);
}

void EmanetListele() {
	system("cls");
	string satir;
	ifstream dosya("emanetler.txt");
	cout << left << setw(15) << "Uye TC"
		<< setw(15) << "Kitap Barkod"
		<< setw(15) << "Teslim Tarihi"
		<< setw(30) << "Kullandigi Gun Sayisi"
		<< setw(15) << "Iade Tarihi"
		<< setw(10) << "Gecikme" << endl;
		/*<< setw(10) << "Durum" << endl;*/
	cout << string(120, '-') << endl;

	while (getline(dosya, satir)) {
		if (satir != "") {
			istringstream iss(satir); 
			getline(iss, emanet.uyeTc, '#');
			getline(iss, emanet.kitapBarkod, '#');
			getline(iss, emanet.teslimtarihi, '#');
			getline(iss, emanet.kullandigiGunSayisi, '#');
			getline(iss, emanet.gecikmegunsayisi, '#');
			cout << left << setw(15) << emanet.uyeTc
				<< setw(15) << emanet.kitapBarkod
				<< setw(15) << emanet.teslimtarihi
				<< setw(30) << emanet.kullandigiGunSayisi
				<< setw(15) << emanet.iadeTarihi
				<< setw(10) << emanet.gecikmegunsayisi << endl;
				/*<< setw(10) << emanet.durum << endl;*/
		}
	}
}


void EmanetIslem()
{
	system("cls");
	cout << "~~~~~~~~~~~~Emanet Islemleri~~~~~~~~~~~~" << endl;
	cout << "1-Kitap Odunc Al" << endl;
	cout << "2-Kitap Teslim Et" << endl;
	cout << "3-Emanet Listele" << endl;
	cout << "0-Ana Menuye Don" << endl;
	cout << "Yapmak istediginiz islemi giriniz:";
	int secim;
	cin >> secim;
	switch (secim)
	{
	case 1: KitapOduncAl(); break;
	case 2: KitapTeslim(); break;
	case 3: EmanetListele(); break;
	case 0:break;
	default:
		cout << "Hatali islem yaptiniz.Tekrar deneyin" << endl; break;
	}
}

int main()
{
	setlocale(LC_ALL, "Turkish");

	int a = menu();
	while (a != 0)
	{
		switch (a)
		{
		case 1:KitapIslem(); break;
		case 2:UyeIslem(); break;
		case 3:EmanetIslem(); break;
		case 0:break;
		default:
			cout << "Hatali secim yaptiniz. Tekrar deneyin"; break;
		}
		
		a = menu();
		
	}
	return 0;
}
