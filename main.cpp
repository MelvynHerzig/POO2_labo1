/*
 -----------------------------------------------------------------------------------
 Laboratoire : POO2 labo_01
 Fichier     : main.cpp
 Auteur(s)   : Forestier Quentin & Melvyn Herzig
 Date        : 24.02.2021

 But         : Tester l'implémentation de la classe Matrix

 Remarque(s) : /

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include <iostream> // cout

#include "Matrix.h"

using namespace std;

int main ()
{

   Matrix m2 = Matrix(2,4, 5);
   cout << m2 << endl;

   Matrix m1 = Matrix(4,2, 5);
   cout << m1 << endl;

   cout << m1.multToVal(m2) << endl;

   return EXIT_SUCCESS;
}
