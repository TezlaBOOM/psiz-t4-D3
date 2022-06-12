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
using namespace std;
void Nowypliki(string nazwaPliku, int licznik, char wartosc)
{
    ofstream mFile(nazwaPliku);

        for (int i = 0; i < licznik; i++) {
            mFile << wartosc;

        }
}



int main( int argc, char * argv[] )
{
    Nowypliki("test1.bin", 100, 0x55);
    Nowypliki("test2.bin", 100, 0x55);

    Nowypliki("test3.bin", 100, 0x55);
    Nowypliki("test4.bin", 100, 0xF5);

    Nowypliki("test5.bin", 1024*1024*400, 0x55);
    Nowypliki("test6.bin", 1024*1024*400, 0x50);
    return 0;
}