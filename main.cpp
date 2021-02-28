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

/**
 * @brief Point d'entrée du programme. Programme de test.
 * @param argc Nombre d'arguments reçus.
 * @param argv Valeurs des arguments.
 * @return EXIT_SUCCESS en cas d'exécution complète.
 */
int main (int argc, char *argv[])
{
   if(argc != 6)
      throw invalid_argument("args: <height 1> <width 1> <heigt 2> <width 2> <modulus>");

   unsigned x1, x2, y1, y2, modulus;
   x1 = stoul(argv[1]);
   y1 = stoul(argv[2]);
   x2 = stoul(argv[3]);
   y2 = stoul(argv[4]);
   modulus = stoul(argv[5]);

   cout << "\n------------ Test des entrees utilisateur ------------ \n"
        << "The modulus is "  << modulus << endl << endl;

   Matrix m1 = Matrix(x1, y1, modulus);
   Matrix m2 = Matrix(x2, y2, modulus);

   cout << "m1\n" << m1 << endl;
   cout << "m2\n" << m2 << endl;

//   cout << "\n m1 - m2 (par valeur statique)"
//        << m1 - m2 << endl;
//
//   cout << "\n m1 + m2 (par valeur statique)"
//        << m1 + m2 << endl;
//
//   cout << "\n m1 * m2 (par valeur statique)"
//        << m1 * m2 << endl;
//
//   cout << "\n m1 -= m2 (par reference)"
//        << Matrix(m1)-=m2 << endl;
//
//   cout << "\n m1 += m2 (par reference)"
//        << Matrix(m1)+=m2 << endl;
//
//   cout << "\n m1 *= m2 (par reference)"
//        << Matrix(m1)*=m2 << endl;
//
//   cout << "\n m1.sub(m2) (par pointeur dynamique)"
//        << Matrix(m1)-=m2 << endl;
//
//   cout << "\n m1.add(m2) (par pointeur dynamique)"
//        << Matrix(m1)+=m2 << endl;
//
//   cout << "\n m1.mult(m2) (par pointeur dynamique)"
//        << Matrix(m1)*=m2 << endl;

   cout << "\n------------ Test des cas limites ------------" << endl;

   try
   {
      cout << "Test de matrice avec un modulo incorrecte :" << endl;
      Matrix badModulus = Matrix( x1, y1,0);
   }
   catch (runtime_error e)
   {
      cout << e.what() << endl;
   }

   cout << endl;

//   try
//   {
//      cout << "\"Test d'une operation avec un modulo different :" << endl;
//      Matrix m1 = Matrix(x1, x2, modulus);
//      Matrix m2 = Matrix(x1, x2, modulus + 1);
//      m1 + m2;
//   }
//   catch (invalid_argument e)
//   {
//      cout << e.what() << endl;
//   }

   cout << endl;

   try
   {
      cout << "\"Test d'une matrice vide (largeur nulle) :" << endl;
      Matrix m1 = Matrix(x1, 0, modulus);
   }
   catch (runtime_error e)
   {
      cout << e.what() << endl;
   }

   cout << endl;

   try
   {
      cout << "\"Test d'une matrice vide (hauteur nulle) :" << endl;
      Matrix m1 = Matrix(0, y1, modulus);
   }
   catch (runtime_error e)
   {
      cout << e.what() << endl;
   }

   return EXIT_SUCCESS;
}
