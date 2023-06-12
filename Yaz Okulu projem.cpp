/****************************************************************************
** SAKARYA ÜNİVERSİTESİ
** BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
** BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
** PROGRAMLAMAYA GİRİŞİ DERSİ
**
** ÖDEV NUMARASI…...:1.Proje
** ÖĞRENCİ ADI...............:Mervan Yuşa Torlak    
** ÖĞRENCİ NUMARASI.:B191210099
** DERS GRUBU…………:A
****************************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

class Urunler {
private:
    int urunNo;
    string urunAdi;
    double birimi;
    string markasi;
    double birimFiyati;
public:

    void urunEkle() {
        Urunler urunDizi[100];
        ifstream dosyaOku("urun.txt");
        int urunSayisi = 0;
        if (dosyaOku.is_open()) {
            while (!dosyaOku.eof())
            {
                dosyaOku >> urunDizi[urunSayisi].urunNo >> urunDizi[urunSayisi].urunAdi >> urunDizi[urunSayisi].birimi >> urunDizi[urunSayisi].markasi >> urunDizi[urunSayisi].birimFiyati;
                urunSayisi++;
            }
        }
        dosyaOku.close();
        for (int j = 0; j < urunSayisi - 1; j++) {
            urunDizi[j].urunNo = j + 1;
        }
        urunDizi[urunSayisi - 1].urunNo = urunSayisi;
        cout << "Urun Adini Griniz:";
        cin >> urunDizi[urunSayisi - 1].urunAdi;
        cout << "\nUrunun Birimini(Adedi) Giriniz:";
        cin >> urunDizi[urunSayisi - 1].birimi;
        cout << "\nUrunun Markasini Giriniz:";
        cin >> urunDizi[urunSayisi - 1].markasi;
        cout << "\nUrunun Birim Fiyatini Giriniz:";
        cin >> urunDizi[urunSayisi - 1].birimFiyati;

        ofstream dosyaYaz("urun.txt");
        if (dosyaYaz.is_open()) {
            for (int i = 0; i < urunSayisi; i++) {
                dosyaYaz << urunDizi[i].urunNo << " " << urunDizi[i].urunAdi << " " << urunDizi[i].birimi << " " << urunDizi[i].markasi << " " << urunDizi[i].birimFiyati << endl;
            }
        }
        dosyaYaz.close();

    }

    void urunleriEkranaYazdir() {
        Urunler urunDizi[100];
        ifstream dosyaOku("urun.txt");
        int urunSayisi = 0;
        if (dosyaOku.is_open()) {
            while (!dosyaOku.eof())
            {
                dosyaOku >> urunDizi[urunSayisi].urunNo >> urunDizi[urunSayisi].urunAdi >> urunDizi[urunSayisi].birimi >> urunDizi[urunSayisi].markasi >> urunDizi[urunSayisi].birimFiyati;
                urunSayisi++;
            }
        }
        dosyaOku.close();
        for (int j = 0; j < urunSayisi - 1; j++) {
            urunDizi[j].urunNo = j + 1;
        }
        ofstream dosyaYaz("urun.txt");
        if (dosyaYaz.is_open()) {
            for (int i = 0; i < urunSayisi - 1; i++) {
                dosyaYaz << urunDizi[i].urunNo << " " << urunDizi[i].urunAdi << " " << urunDizi[i].birimi << " " << urunDizi[i].markasi << " " << urunDizi[i].birimFiyati << endl;
            }
        }
        dosyaYaz.close();

        cout << "Urun No" << setw(20) << "Urun Adi" << setw(20) << "Birimi" << setw(20) << "Markasi" << setw(20) << "Birim Fiyati" << endl;
        for (int i = 0; i < urunSayisi - 1; i++) {
            cout << setw(5) << urunDizi[i].urunNo << setw(21) << urunDizi[i].urunAdi << setw(20) << urunDizi[i].birimi << setw(20) << urunDizi[i].markasi << setw(18) << urunDizi[i].birimFiyati << endl;
        }
    }

    void urunSil() {
        Urunler urunDizi[100];
        int numara;
        cout << "Silinecek Urun Numarasini Girin:";
        cin >> numara;
        ifstream dosyaOku("urun.txt");
        int urunSayisi = 0;
        if (dosyaOku.is_open()) {
            while (!dosyaOku.eof())
            {
                dosyaOku >> urunDizi[urunSayisi].urunNo >> urunDizi[urunSayisi].urunAdi >> urunDizi[urunSayisi].birimi >> urunDizi[urunSayisi].markasi >> urunDizi[urunSayisi].birimFiyati;
                urunSayisi++;
            }
        }
        dosyaOku.close();

        ofstream dosyaYaz("urun.txt");
        if (dosyaYaz.is_open()) {
            for (int i = 0; i < urunSayisi - 1; i++) {
                if (urunDizi[i].urunNo == numara)
                    cout << "Urun Basariyla Silindi\n";
                else
                    dosyaYaz << urunDizi[i].urunNo << " " << urunDizi[i].urunAdi << " " << urunDizi[i].birimi << " " << urunDizi[i].markasi << " " << urunDizi[i].birimFiyati << endl;
            }
        }
        dosyaYaz.close();
    }

    void urunArama() {
        Urunler urunDizi[100];
        ifstream dosyaOku("urun.txt");
        int urunSayisi = 0;
        if (dosyaOku.is_open()) {
            while (!dosyaOku.eof())
            {
                dosyaOku >> urunDizi[urunSayisi].urunNo >> urunDizi[urunSayisi].urunAdi >> urunDizi[urunSayisi].birimi >> urunDizi[urunSayisi].markasi >> urunDizi[urunSayisi].birimFiyati;
                urunSayisi++;
            }
        }
        dosyaOku.close();
        int secim;
        cout << "1. Urun No Ile Arama\n2. Urun Adi Ile Arama\n";
        cin >> secim;
        switch (secim)
        {
        case 1:
            int no;
            cout << "Urun No Giriniz:";
            cin >> no;
            for (int i = 0; i < urunSayisi - 1; i++) {
                if (urunDizi[i].urunNo == no) {
                    //cout << "Urun Bulundu.\n";
                    cout << "Urun No" << setw(10) << "Urun Adi" << setw(9) << "Birimi" << setw(11) << "Markasi" << setw(15) << "Birim Fiyati" << endl;
                    cout << setw(5) << urunDizi[i].urunNo << setw(10) << urunDizi[i].urunAdi << setw(10) << urunDizi[i].birimi << setw(10) << urunDizi[i].markasi << setw(13) << urunDizi[i].birimFiyati << endl;
                }
            }
            break;
        case 2:
            string ad;
            cout << "Urun Adini Giriniz:";
            cin >> ad;
            for (int i = 0; i < urunSayisi - 1; i++) {
                if (urunDizi[i].urunAdi == ad) {
                    //cout << "Urun Bulundu.\n";
                    cout << "Urun No" << setw(10) << "Urun Adi" << setw(9) << "Birimi" << setw(11) << "Markasi" << setw(15) << "Birim Fiyati" << endl;
                    cout << setw(5) << urunDizi[i].urunNo << setw(10) << urunDizi[i].urunAdi << setw(10) << urunDizi[i].birimi << setw(10) << urunDizi[i].markasi << setw(13) << urunDizi[i].birimFiyati << endl;
                }
            }
        }

    }

    void Raporlama() {
        cout << "Raporlama Markaya Gore Yapilmistir.\n";
        Urunler urunDizi[100];
        ifstream dosyaOku("urun.txt");
        int urunSayisi = 0;
        if (dosyaOku.is_open()) {
            while (!dosyaOku.eof())
            {
                dosyaOku >> urunDizi[urunSayisi].urunNo >> urunDizi[urunSayisi].urunAdi >> urunDizi[urunSayisi].birimi >> urunDizi[urunSayisi].markasi >> urunDizi[urunSayisi].birimFiyati;
                urunSayisi++;
            }
        }
        dosyaOku.close();
        string markalar[100];
        int adet;
        for (int i = 0; i < urunSayisi - 1; i++) {
            adet = 0;
            markalar[i] = urunDizi[i].markasi;
            for (int j = 0; j < urunSayisi - 1; j++) {
                if (markalar[i] == urunDizi[j].markasi && urunDizi[j].markasi != "degisti") {
                    urunDizi[j].markasi = "degisti";
                    adet++;
                }
            }
            if (adet != 0)
                cout << markalar[i] << " Markasindan " << adet << " tane vardir\n";
        }


    }

};

class Projeler {
private:
    int projeNo;
    string projeAdi, projeFirmasi, projeSorumlusu, projeKontroloru;

public:
    void projeEkle() {
        Projeler projeDizi[100];
        ifstream dosyaOku("proje.txt");
        int projeSayisi = 0;
        if (dosyaOku.is_open()) {
            while (!dosyaOku.eof())
            {
                dosyaOku >> projeDizi[projeSayisi].projeNo >> projeDizi[projeSayisi].projeAdi >> projeDizi[projeSayisi].projeFirmasi >> projeDizi[projeSayisi].projeSorumlusu >> projeDizi[projeSayisi].projeKontroloru;
                projeSayisi++;
            }
        }
        dosyaOku.close();
        for (int j = 0; j < projeSayisi - 1; j++) {
            projeDizi[j].projeNo = j + 1;
        }
        projeDizi[projeSayisi - 1].projeNo = projeSayisi;
        cout << "Proje Adini Griniz:";
        cin >> projeDizi[projeSayisi - 1].projeAdi;
        cout << "Projeyi Yuruten Firmayi Griniz:";
        cin >> projeDizi[projeSayisi - 1].projeFirmasi;
        cout << "Proje Sorumlusunu Griniz:";
        cin >> projeDizi[projeSayisi - 1].projeSorumlusu;
        cout << "Proje Kontrolorunu Griniz:";
        cin >> projeDizi[projeSayisi - 1].projeKontroloru;

        ofstream dosyaYaz("Projeler.txt");
        if (dosyaYaz.is_open()) {
            for (int i = 0; i < projeSayisi; i++) {
                dosyaYaz << projeDizi[i].projeNo << " " << projeDizi[i].projeAdi << " " << projeDizi[i].projeFirmasi << " " << projeDizi[i].projeSorumlusu << " " << projeDizi[i].projeKontroloru << endl;
            }
        }
        dosyaYaz.close();
    }

    void projeleriEkranaYazdir() {
        Projeler projeDizi[100];
        ifstream dosyaOku("proje.txt");
        int projeSayisi = 0;
        if (dosyaOku.is_open()) {
            while (!dosyaOku.eof())
            {
                dosyaOku >> projeDizi[projeSayisi].projeNo >> projeDizi[projeSayisi].projeAdi >> projeDizi[projeSayisi].projeFirmasi >> projeDizi[projeSayisi].projeSorumlusu >> projeDizi[projeSayisi].projeKontroloru;
                projeSayisi++;
            }
        }
        dosyaOku.close();
        for (int j = 0; j < projeSayisi - 1; j++) {
            projeDizi[j].projeNo = j + 1;
        }

        ofstream dosyaYaz("proje.txt");
        if (dosyaYaz.is_open()) {
            for (int i = 0; i < projeSayisi - 1; i++) {
                dosyaYaz << projeDizi[i].projeNo << " " << projeDizi[i].projeAdi << " " << projeDizi[i].projeFirmasi << " " << projeDizi[i].projeSorumlusu << " " << projeDizi[i].projeKontroloru << endl;
            }
        }
        dosyaYaz.close();

        cout << "Proje No" << setw(20) << "Adi" << setw(20) << "Firma" << setw(20) << "Sorumlu" << setw(20) << "Kontrolor" << endl;
        for (int i = 0; i < projeSayisi - 1; i++) {
            cout << setw(5) << projeDizi[i].projeNo << setw(25) << projeDizi[i].projeAdi << setw(18) << projeDizi[i].projeFirmasi << setw(19) << projeDizi[i].projeSorumlusu << setw(19) << projeDizi[i].projeKontroloru << endl;
        }
    }

    void projeArama() {
        Projeler projeDizi[100];
        ifstream dosyaOku("proje.txt");
        int projeSayisi = 0;
        if (dosyaOku.is_open()) {
            while (!dosyaOku.eof())
            {
                dosyaOku >> projeDizi[projeSayisi].projeNo >> projeDizi[projeSayisi].projeAdi >> projeDizi[projeSayisi].projeFirmasi >> projeDizi[projeSayisi].projeSorumlusu >> projeDizi[projeSayisi].projeKontroloru;
                projeSayisi++;
            }
        }
        dosyaOku.close();

        cout << "1. Proje No Ile Arama\n2. Proje Adi Ile Arama\n";
        int secim;
        cin >> secim;
        switch (secim)
        {
        case 1:
            int no;
            cout << "Proje No Giriniz:";
            cin >> no;
            for (int i = 0; i < projeSayisi - 1; i++) {
                if (projeDizi[i].projeNo == no) {
                    cout << "Proje No" << setw(20) << "Adi" << setw(20) << "Firma" << setw(20) << "Sorumlu" << setw(20) << "Kontrolor" << endl;
                    cout << setw(5) << projeDizi[i].projeNo << setw(25) << projeDizi[i].projeAdi << setw(18) << projeDizi[i].projeFirmasi << setw(19) << projeDizi[i].projeSorumlusu << setw(19) << projeDizi[i].projeKontroloru << endl;
                }
            }
            break;
        case 2:
            string ad;
            cout << "Proje Adini Giriniz:";
            cin >> ad;
            for (int i = 0; i < projeSayisi - 1; i++) {
                if (projeDizi[i].projeAdi == ad) {
                    cout << "Proje No" << setw(20) << "Adi" << setw(20) << "Firma" << setw(20) << "Sorumlu" << setw(20) << "Kontrolor" << endl;
                    cout << setw(5) << projeDizi[i].projeNo << setw(25) << projeDizi[i].projeAdi << setw(18) << projeDizi[i].projeFirmasi << setw(19) << projeDizi[i].projeSorumlusu << setw(19) << projeDizi[i].projeKontroloru << endl;
                }
            }
            break;
        }

    }

    void projeSil() {
        cout << "Silinecek Projenin Numarasini Giriniz:";
        int noGir;
        cin >> noGir;

        Projeler projeDizi[100];
        ifstream dosyaOku("proje.txt");
        int projeSayisi = 0;
        if (dosyaOku.is_open()) {
            while (!dosyaOku.eof())
            {
                dosyaOku >> projeDizi[projeSayisi].projeNo >> projeDizi[projeSayisi].projeAdi >> projeDizi[projeSayisi].projeFirmasi >> projeDizi[projeSayisi].projeSorumlusu >> projeDizi[projeSayisi].projeKontroloru;
                projeSayisi++;
            }
        }
        dosyaOku.close();
        for (int j = 0; j < projeSayisi - 1; j++) {
            projeDizi[j].projeNo = j + 1;
        }

        int projeNolari[100], hakedisDonemleri[100], urunNolari[100];
        double urunBirimFiyatlari[100], urunAdedleri[100];
        int hakedisSayisi = 0;
        ifstream hakedisOku("proje.txt");
        if (hakedisOku.is_open()) {
            while (!hakedisOku.eof()) {
                hakedisOku >> projeNolari[hakedisSayisi] >> hakedisDonemleri[hakedisSayisi] >> urunNolari[hakedisSayisi] >> urunAdedleri[hakedisSayisi] >> urunBirimFiyatlari[hakedisSayisi];
                hakedisSayisi++;
            }
        }
        hakedisOku.close();

        for (int i = 0; i < projeSayisi - 1; i++) {
            for (int j = 0; j < hakedisSayisi - 1; j++) {
                if (projeDizi[i].projeNo != projeNolari[j] && projeDizi[i].projeNo == noGir) {
                    projeDizi[i].projeAdi = "sil";
                }
            }
        }

        ofstream dosyaYaz("proje.txt");
        if (dosyaYaz.is_open()) {
            for (int i = 0; i < projeSayisi - 1; i++) {
                if (projeDizi[i].projeAdi != "sil") {
                    dosyaYaz << projeDizi[i].projeNo << " " << projeDizi[i].projeAdi << " " << projeDizi[i].projeFirmasi << " " << projeDizi[i].projeSorumlusu << " " << projeDizi[i].projeKontroloru << endl;
                }
            }
        }
        dosyaYaz.close();


    }

    void projeRaporlama() {
        int projeNolari[100], hakedisDonemleri[100], urunNolari[100];
        double urunBirimFiyatlari[100], urunAdedleri[100];
        int hakedisSayisi = 0;
        ifstream hakedisOku("hakedis.txt");
        if (hakedisOku.is_open()) {
            while (!hakedisOku.eof()) {
                hakedisOku >> projeNolari[hakedisSayisi] >> hakedisDonemleri[hakedisSayisi] >> urunNolari[hakedisSayisi] >> urunAdedleri[hakedisSayisi] >> urunBirimFiyatlari[hakedisSayisi];
                hakedisSayisi++;
            }
        }
        hakedisOku.close();

        cout << "Hakediste " << hakedisSayisi - 1 << "adet proje vardir." << endl;
        cout << "Proje No" << setw(15) << "Donemi" << setw(15) << "Urun No" << setw(20) << "Kullamilan Birim" << setw(15) << "Birim Fiyati" << setw(15) << "Tutar" << endl;
        for (int i = 0; i < hakedisSayisi - 1; i++) {
            cout << setw(5) << projeNolari[i] << setw(15) << hakedisDonemleri[i] << setw(15) << urunNolari[i] << setw(17) << urunAdedleri[i] << setw(15) << urunBirimFiyatlari[i] << setw(20) << urunBirimFiyatlari[i] * urunAdedleri[i] << endl;
        }
    }

};

class Hakedisler {
private:
    int projeNo, hakedisDonemi, urunNo;
    double urunBirimFiyati, urunAdedi;
public:
    void hakedisEkle() {

        int projeNolari[100];
        string projeAdlari[100], projeFirmalari[100], projeSorumlulari[100], projeKontrolorleri[100];
        int projeSayisi = 0;
        ifstream projeOku("proje.txt");
        if (projeOku.is_open()) {
            while (!projeOku.eof()) {
                projeOku >> projeNolari[projeSayisi] >> projeAdlari[projeSayisi] >> projeFirmalari[projeSayisi] >> projeSorumlulari[projeSayisi] >> projeKontrolorleri[projeSayisi];
                projeSayisi++;
            }
        }
        projeOku.close();

        bool dogrumu = true;
        while (dogrumu == true) {
            cout << "Proje Numarasini Giriniz:";
            cin >> projeNo;
            for (int i = 0; i < projeSayisi - 1; i++) {
                if (projeNo == projeNolari[i]) {
                    dogrumu = false;
                }
            }
        }

        cout << "Hakedis Donemini Giriniz:";
        cin >> hakedisDonemi;

        int urunNolari[100];
        string urunAdlari[100], urunMarkalari[100];
        double urunBirimleri[100], urunBirimFiyatlari[100];
        int urunSayisi = 0;
        ifstream urunOku("urun.txt");
        if (urunOku.is_open()) {
            while (!urunOku.eof())
            {
                urunOku >> urunNolari[urunSayisi] >> urunAdlari[urunSayisi] >> urunBirimleri[urunSayisi] >> urunMarkalari[urunSayisi] >> urunBirimFiyatlari[urunSayisi];
                urunSayisi++;
            }
        }
        urunOku.close();

        int kacinciUrun;
        while (dogrumu == false) {
            cout << "Urun Numarasini Giriniz:";
            cin >> urunNo;
            for (int i = 0; i < urunSayisi - 1; i++) {
                if (urunNo == urunNolari[i]) {
                    kacinciUrun = i;
                    dogrumu = true;
                }
            }
        }

        while (dogrumu == true) {
            cout << "Urunun Birimini(Adedini) Giriniz:";
            cin >> urunAdedi;
            if (urunAdedi <= urunBirimleri[kacinciUrun]) {
                urunBirimleri[kacinciUrun] = urunBirimleri[kacinciUrun] - urunAdedi;
                dogrumu = false;
            }
        }

        ofstream urunYaz("urun.txt");
        if (urunYaz.is_open()) {
            for (int i = 0; i < urunSayisi; i++) {
                if (urunBirimleri[i] != 0)
                    urunYaz << urunNolari[i] << " " << urunAdlari[i] << " " << urunBirimleri[i] << " " << urunMarkalari[i] << " " << urunBirimFiyatlari[i] << endl;
            }
        }
        urunYaz.close();

        urunBirimFiyati = urunBirimFiyatlari[kacinciUrun];

        ofstream hakedisYaz("hakedis.txt", ios::app);
        if (hakedisYaz.is_open()) {
            hakedisYaz << projeNo << " " << hakedisDonemi << " " << urunNo << " " << urunAdedi << " " << urunBirimFiyati << endl;
        }
        hakedisYaz.close();
    }

    void hakedisEkranaYazdir() {
        int projeNolari[100], hakedisDonemleri[100], urunNolari[100];
        double urunBirimFiyatlari[100], urunAdedleri[100];
        int hakedisSayisi = 0;
        ifstream hakedisOku("hakedis.txt");
        if (hakedisOku.is_open()) {
            while (!hakedisOku.eof()) {
                hakedisOku >> projeNolari[hakedisSayisi] >> hakedisDonemleri[hakedisSayisi] >> urunNolari[hakedisSayisi] >> urunAdedleri[hakedisSayisi] >> urunBirimFiyatlari[hakedisSayisi];
                hakedisSayisi++;
            }
        }
        hakedisOku.close();

        cout << "Proje No" << setw(15) << "Donemi" << setw(15) << "Urun No" << setw(20) << "Kullamilan Birim" << setw(15) << "Birim Fiyati" << setw(15) << "Tutar" << endl;
        for (int i = 0; i < hakedisSayisi - 1; i++) {
            cout << setw(5) << projeNolari[i] << setw(15) << hakedisDonemleri[i] << setw(15) << urunNolari[i] << setw(17) << urunAdedleri[i] << setw(15) << urunBirimFiyatlari[i] << setw(20) << urunBirimFiyatlari[i] * urunAdedleri[i] << endl;
        }
    }

    void KullanilanUrunleriListele() {
        int projeNolari[100], hakedisDonemleri[100], urunNolari[100];
        double urunBirimFiyatlari[100], urunAdedleri[100];
        int hakedisSayisi = 0;
        ifstream hakedisOku("hakedis.txt");
        if (hakedisOku.is_open()) {
            while (!hakedisOku.eof()) {
                hakedisOku >> projeNolari[hakedisSayisi] >> hakedisDonemleri[hakedisSayisi] >> urunNolari[hakedisSayisi] >> urunAdedleri[hakedisSayisi] >> urunBirimFiyatlari[hakedisSayisi];
                hakedisSayisi++;
            }
        }
        hakedisOku.close();

        int urunNumarasi;
        string urunAdi, urunMarkasi;
        double urunBirimi, urunBirimFiyatii;

        cout << "Kullanildigi Proje" << setw(15) << "Numarasi" << setw(10) << "Adi" << setw(20) << "Kullanilan Birim" << setw(15) << "Markasi" << setw(15) << "Birim Fiyati" << setw(15) << "Tutar" << endl;
        ifstream urunOku("urun.txt");
        if (urunOku.is_open()) {
            while (!urunOku.eof()) {
                urunOku >> urunNumarasi >> urunAdi >> urunBirimi >> urunMarkasi >> urunBirimFiyatii;
                for (int i = 0; i < hakedisSayisi - 1; i++) {
                    if (urunNolari[i] == urunNumarasi) {
                        cout << setw(10) << projeNolari[i] << setw(20) << urunNumarasi << setw(14) << urunAdi << setw(13) << urunAdedleri[i] << setw(20) << urunMarkasi << setw(10) << urunBirimFiyatii << setw(20) << urunBirimFiyatii * urunAdedleri[i] << endl;
                    }
                }
            }
        }
        urunOku.close();


    }

    void KullanilanUrunlerdeAramaYap() {
        int projeNolari[100], hakedisDonemleri[100], urunNolari[100];
        double urunBirimFiyatlari[100], urunAdedleri[100];
        int hakedisSayisi = 0;
        ifstream hakedisOku("hakedis.txt");
        if (hakedisOku.is_open()) {
            while (!hakedisOku.eof()) {
                hakedisOku >> projeNolari[hakedisSayisi] >> hakedisDonemleri[hakedisSayisi] >> urunNolari[hakedisSayisi] >> urunAdedleri[hakedisSayisi] >> urunBirimFiyatlari[hakedisSayisi];
                hakedisSayisi++;
            }
        }
        hakedisOku.close();

        int urunNumarasi;
        string urunAdi, urunMarkasi;
        double urunBirimi, urunBirimFiyatii;
        cout << "Kullanildigi Proje" << setw(15) << "Numarasi" << setw(10) << "Adi" << setw(20) << "Kullanilan Birim" << setw(15) << "Markasi" << setw(15) << "Birim Fiyati" << setw(15) << "Tutar" << endl;

        cout << "1. Urun No Ile Arama\n2. Urun Adi Ile Arama\n";
        int secim;
        cin >> secim;
        if (secim == 1) {
            cout << "Urun No Giriniz:";
            int noGir;
            cin >> noGir;

            ifstream urunOku("urun.txt");
            if (urunOku.is_open()) {
                while (!urunOku.eof()) {
                    urunOku >> urunNumarasi >> urunAdi >> urunBirimi >> urunMarkasi >> urunBirimFiyatii;
                    for (int i = 0; i < hakedisSayisi - 1; i++) {
                        if (urunNolari[i] == urunNumarasi && urunNumarasi == noGir) {
                            cout << setw(10) << projeNolari[i] << setw(20) << urunNumarasi << setw(14) << urunAdi << setw(13) << urunAdedleri[i] << setw(20) << urunMarkasi << setw(10) << urunBirimFiyatii << setw(20) << urunBirimFiyatii * urunAdedleri[i] << endl;
                        }
                    }
                }
            }
            urunOku.close();
        }
        else if (secim == 2) {
            cout << "Urun Adini Giriniz:";
            string adGir;
            cin >> adGir;

            ifstream urunOku("urun.txt");
            if (urunOku.is_open()) {
                while (!urunOku.eof()) {
                    urunOku >> urunNumarasi >> urunAdi >> urunBirimi >> urunMarkasi >> urunBirimFiyatii;
                    for (int i = 0; i < hakedisSayisi - 1; i++) {
                        if (urunNolari[i] == urunNumarasi && urunAdi == adGir) {
                            cout << setw(10) << projeNolari[i] << setw(20) << urunNumarasi << setw(14) << urunAdi << setw(13) << urunAdedleri[i] << setw(20) << urunMarkasi << setw(10) << urunBirimFiyatii << setw(20) << urunBirimFiyatii * urunAdedleri[i] << endl;
                        }
                    }
                }
            }
            urunOku.close();
        }
        else
            cout << "Yanlis Giris Yaptiniz.";
    }

    void SecilenProjeyeGoreRapor() {
        cout << "Proje Numarasini Giriniz:";
        int noGir;
        cin >> noGir;

        int projeNolari[100], hakedisDonemleri[100], urunNolari[100];
        double urunBirimFiyatlari[100], urunAdedleri[100];
        int hakedisSayisi = 0;
        ifstream hakedisOku("hakedis.txt");
        if (hakedisOku.is_open()) {
            while (!hakedisOku.eof()) {
                hakedisOku >> projeNolari[hakedisSayisi] >> hakedisDonemleri[hakedisSayisi] >> urunNolari[hakedisSayisi] >> urunAdedleri[hakedisSayisi] >> urunBirimFiyatlari[hakedisSayisi];
                hakedisSayisi++;
            }
        }
        hakedisOku.close();

        int urunNumarasi;
        string urunAdi, urunMarkasi;
        double urunBirimi, urunBirimFiyatii;

        cout << "Proje No" << setw(15) << "Urun No" << setw(10) << "Adi" << setw(20) << "Kullanilan Birim" << setw(15) << "Markasi" << setw(15) << "Birim Fiyati" << setw(15) << "Tutar" << endl;
        ifstream urunOku("urun.txt");
        int toplamTutar = 0;
        if (urunOku.is_open()) {
            while (!urunOku.eof()) {
                urunOku >> urunNumarasi >> urunAdi >> urunBirimi >> urunMarkasi >> urunBirimFiyatii;
                for (int i = 0; i < hakedisSayisi - 1; i++) {
                    if (urunNolari[i] == urunNumarasi && projeNolari[i] == noGir) {
                        cout << setw(5) << projeNolari[i] << setw(15) << urunNumarasi << setw(13) << urunAdi << setw(13) << urunAdedleri[i] << setw(20) << urunMarkasi << setw(10) << urunBirimFiyatii << setw(20) << urunBirimFiyatii * urunAdedleri[i] << endl;
                        toplamTutar += urunBirimFiyatii * urunAdedleri[i];
                    }

                }
            }
        }
        urunOku.close();
        cout << "Toplam Tutar:  " << toplamTutar;

    }

    void SecilenDonemeGoreRapor() {
        cout << "Donem Numarasini Giriniz:";
        int noGir;
        cin >> noGir;

        int projeNolari[100], hakedisDonemleri[100], urunNolari[100];
        double urunBirimFiyatlari[100], urunAdedleri[100];
        int hakedisSayisi = 0;
        ifstream hakedisOku("hakedis.txt");
        if (hakedisOku.is_open()) {
            while (!hakedisOku.eof()) {
                hakedisOku >> projeNolari[hakedisSayisi] >> hakedisDonemleri[hakedisSayisi] >> urunNolari[hakedisSayisi] >> urunAdedleri[hakedisSayisi] >> urunBirimFiyatlari[hakedisSayisi];
                hakedisSayisi++;
            }
        }
        hakedisOku.close();

        int urunNumarasi;
        string urunAdi, urunMarkasi;
        double urunBirimi, urunBirimFiyatii;

        cout << "Proje No" << setw(15) << "Urun No" << setw(10) << "Adi" << setw(20) << "Kullanilan Birim" << setw(15) << "Markasi" << setw(15) << "Birim Fiyati" << setw(15) << "Tutar" << endl;
        ifstream urunOku("urun.txt");
        int toplamTutar = 0;
        if (urunOku.is_open()) {
            while (!urunOku.eof()) {
                urunOku >> urunNumarasi >> urunAdi >> urunBirimi >> urunMarkasi >> urunBirimFiyatii;
                for (int i = 0; i < hakedisSayisi - 1; i++) {
                    if (urunNolari[i] == urunNumarasi && hakedisDonemleri[i] == noGir) {
                        cout << setw(5) << projeNolari[i] << setw(15) << urunNumarasi << setw(13) << urunAdi << setw(13) << urunAdedleri[i] << setw(20) << urunMarkasi << setw(10) << urunBirimFiyatii << setw(20) << urunBirimFiyatii * urunAdedleri[i] << endl;
                        toplamTutar += urunBirimFiyatii * urunAdedleri[i];
                    }

                }
            }
        }
        urunOku.close();
        cout << "Toplam Tutar:  " << toplamTutar;
    }
};

int main()
{
    Urunler u1;
    Projeler p1;
    Hakedisler h1;

    while (true)
    {
        cout << "1. Urun Islemleri\n2. Proje Islemleri\n3. Hakedis Islemleri\n4. Cikis\n";
        int secim;
        cin >> secim;

        switch (secim)
        {
        case 1:
            system("cls");
            cout << "1. Urunleri Ekrana Yazdir\n2. Urun Ekle\n3. Urun Sil\n4. Urun Ara\n5. Raporlama\n6. Cikis\n";
            int urunSecim;
            cin >> urunSecim;
            switch (urunSecim)
            {
            case 1:
                u1.urunleriEkranaYazdir();
                break;
            case 2:
                u1.urunEkle();
                break;
            case 3:
                u1.urunSil();
                break;
            case 4:
                u1.urunArama();
                break;
            case 5:
                u1.Raporlama();
                break;
            case 6:
                return false;
            }
            break;
        case 2:
            system("cls");
            cout << "1. Projeleri Ekrana Yazdir\n2. Proje Ekle\n3. Proje Sil\n4. Proje Ara\n5.Raporlama\n6. Cikis\n";
            int projeSecim;
            cin >> projeSecim;
            switch (projeSecim)
            {
            case 1:
                p1.projeleriEkranaYazdir();
                break;
            case 2:
                p1.projeEkle();
                break;
            case 3:
                p1.projeSil();
            case 4:
                p1.projeArama();
                break;
            case 5:
                p1.projeRaporlama();
            case 6:
                return false;
            }
            break;
        case 3:
            system("cls");
            cout << "1. Hakedisleri Ekrana Yazdir\n2. Hakedis Eke\n3. Kullanilan Urunleri Listele\n4. Kullanilan Urunlerde Arama Yap\n5. Projeye Gore Raporla\n6. Doneme Gore Raporla\n7. Cikis\n";
            int hakedisSecim;
            cin >> hakedisSecim;
            switch (hakedisSecim)
            {
            case 1:
                h1.hakedisEkranaYazdir();
                break;
            case 2:
                h1.hakedisEkle();
                break;
            case 3:
                h1.KullanilanUrunleriListele();
                break;
            case 4:
                h1.KullanilanUrunlerdeAramaYap();
                break;
            case 5:
                h1.SecilenProjeyeGoreRapor();
                break;
            case 6:
                h1.SecilenDonemeGoreRapor();
                break;
            case 7:
                return false;

            }
            break;
        case 4:
            return false;
        }
    }


}
