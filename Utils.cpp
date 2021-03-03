/*
 -----------------------------------------------------------------------------------
 Laboratoire : POO2 labo_01
 Fichier     : Ultils.h
 Auteur(s)   : Forestier Quentin & Melvyn Herzig
 Date        : 24.02.2021

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include <ctime>
#include <cstdlib>
#include "Utils.h"

using namespace std;

bool Utils::init = true;

unsigned Utils::positiveInteger (unsigned int maxVal)
{
   if(init)
   {
      srand((unsigned)time(nullptr));
      init = false;
   }

   return (unsigned)  rand() % (maxVal);
}

