#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdint.h>
#include <vector>
#include <bitset>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <time.h>
#include <math.h>
using namespace std;
void Nowypliki(string nazwaPliku, int licznik, char wartosc)
{
    ofstream mFile(nazwaPliku);

        for (int i = 0; i < licznik; i++) {
            mFile << wartosc;

        }
}

void logtxt(const char* Plik1,const char* Plik2, float bit, float ber){
    double wynikber;
    wynikber = ber / bit;
    ofstream mFile("log.txt", ios::app);
    mFile <<"Porównaie pliku:"<< Plik1<< " i "<< Plik2 << " wynosi w bitach: " << bit << " i w ber: " << wynikber << endl;
    cout <<"Porównaie pliku:"<< Plik1<< " i "<< Plik2 << " wynosi w bitach: " << bit << " i w ber: " << wynikber << endl;
}


uint8_t licz(uint8_t a, uint8_t b)
{
    uint8_t c = a ^ b; 
    uint8_t setBits = 0;
    while (c > 0)
    {
        setBits += c & 1;
        c >>= 1;
    }
    return setBits;
}



void Porownanie(const char* Plik1,const char* Plik2) {
    ifstream file1 (Plik1, ios::binary);
    ifstream file2 (Plik2, ios::binary);
    char a{};
    char b{};
    float  bit = 0, ber = 0;

    while (!file1.eof())
    {
        file1 >> a;
        file2 >> b;

        if (file1.eof()) { break; }

        bit = 8 + bit;
        ber = licz(a, b) + ber;
      

    }

    logtxt(Plik1,Plik2,bit,ber);
   
}














int main()
{
    

   Nowypliki("test1.bin", 100, 0x55);
    Nowypliki("test2.bin", 100, 0x55);
    Porownanie("test1.bin","test2.bin");
    
  Nowypliki("test3.bin", 100, 0x55);
    Nowypliki("test4.bin", 100, 0xF5);
    Porownanie("test3.bin","test4.bin");
/*
    Nowypliki("test5.bin", 1024*1024*400, 0x55);
    Nowypliki("test6.bin", 1024*1024*400, 0x50);
    Porownanie("test5.bin","test6.bin");*/
    return 0;
}