#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

long minimumZPliku(string nazwaPliku, int system)
{
  ifstream file;
  char* endptr;
  long liczba, min;
  string liczba1, liczba2;
  file.open("\nazwaPliku\"");
  bool pierwszy = true;
  
  if(file.good())
     while (!file.eof()) {
        file>>liczba1 >> liczba2;
        liczba =  strtol(liczba2.c_str(), &endptr, system);
        if (pierwszy) {
            min = liczba;
            pierwszy = false;
        }
        else 
        	if(liczba < min)
                min = liczba;
     }
  
  file.close();
  return min;
}

int main(int argc, char** argv)
{
 ofstream fileOut;
 fileOut.open("C:\\fileOut.txt"); 

 fileOut<<"Pierwszy plik: "<<minimumZPliku("C:\\dane_systemy1.txt", 2)<<"\n";
 fileOut<<"Drugi plik: "<<minimumZPliku("C:\\dane_systemy2.txt", 4)<<"\n";
 fileOut<<"Trzeci plik: "<<minimumZPliku("C:\\dane_systemy3.txt", 8)<<"\n";
 
 fileOut.close();
 return 0;
}
