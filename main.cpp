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
#include <cstdlib>  // EXIT_SUCCESS

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

   {
      cout << "\n------------ TEST MATRICES NON CONSTANTES ------------ \n"
           << "The modulus is "  << modulus << endl << endl;

      Matrix m1 = Matrix(x1, y1, modulus);
      Matrix m2 = Matrix(x2, y2, modulus);

      cout << "m1\n" << m1 << endl;
      cout << "m2\n" << m2 << endl;

      cout << "\n m1 - m2 (par valeur statique) \n"
           << m1 - m2 << endl;

      cout << "\n m1 + m2 (par valeur statique) \n"
           << m1 + m2 << endl;

      cout << "\n m1 * m2 (par valeur statique) \n"
           << m1 * m2 << endl;

      Matrix m4 = Matrix(m1);
      cout << "\n m1 -= m2 (par reference) \n"
           << (m4 -= m2) << endl;

      cout << "\n m1 += m2 (par reference) \n"
           << (Matrix(m1) += m2) << endl;

      cout << "\n m1 *= m2 (par reference) \n"
           << (Matrix(m1) *= m2) << endl;

      Matrix* m = m1.subToPtr(m2);
      cout << "\n m1.subToPtr(m2) (par pointeur dynamique) \n"
           << *m << endl;
      delete m;

      m = m1.addToPtr(m2);
      cout << "\n m1.addToPtr(m2) (par pointeur dynamique) \n"
           << *m << endl;
      delete m;

      m = m1.multToPtr(m2);
      cout << "\n m1.multToPtr(m2) (par pointeur dynamique) \n"
           << *m << endl;
      delete m;

      cout << "m1 = m2" << endl;
      m1 = m2;

      cout << "m1\n" << m1 << endl;
      cout << "m2\n" << m2 << endl;

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

      try
      {
         cout << "\"Test d'une operation avec un modulo different :" << endl;
         Matrix m1 = Matrix(x1, x2, modulus);
         Matrix m2 = Matrix(x1, x2, modulus + 1);
         m1 + m2;
      }
      catch (invalid_argument e)
      {
         cout << e.what() << endl;
      }

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
   }

   {
      cout << "\n------------ TEST MATRICES CONSTANTES ------------ \n"
           << "The modulus is "  << modulus << endl << endl;

      const Matrix m1 = Matrix(x1, y1, modulus);
      const Matrix m2 = Matrix(x2, y2, modulus);

      cout << "m1\n" << m1 << endl;
      cout << "m2\n" << m2 << endl;

      cout << "\n m1 - m2 (par valeur statique) \n"
           << m1 - m2 << endl;

      cout << "\n m1 + m2 (par valeur statique) \n"
           << m1 + m2 << endl;

      cout << "\n m1 * m2 (par valeur statique) \n"
           << m1 * m2 << endl;

// Ne compile pas car permissif de cast const en non const -> validé
//      Matrix m4 = Matrix(m1);
//      cout << "\n m1 -= m2 (par reference) \n"
//           << (m4 -= m2) << endl;
//
//      cout << "\n m1 += m2 (par reference) \n"
//           << (Matrix(m1) += m2) << endl;
//
//      cout << "\n m1 *= m2 (par reference) \n"
//           << (Matrix(m1) *= m2) << endl;

      Matrix* m = m1.subToPtr(m2);
      cout << "\n m1.subToPtr(m2) (par pointeur dynamique) \n"
           << *m << endl;
      delete m;

      m = m1.addToPtr(m2);
      cout << "\n m1.addToPtr(m2) (par pointeur dynamique) \n"
           << *m << endl;
      delete m;

      m = m1.multToPtr(m2);
      cout << "\n m1.multToPtr(m2) (par pointeur dynamique) \n"
           << *m << endl;
      delete m;

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

      try
      {
         cout << "\"Test d'une operation avec un modulo different :" << endl;
         Matrix m1 = Matrix(x1, x2, modulus);
         Matrix m2 = Matrix(x1, x2, modulus + 1);
         m1 + m2;
      }
      catch (invalid_argument e)
      {
         cout << e.what() << endl;
      }

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

// Ne compile pas affectation sur un objet constant impossible -> validé.
//      cout << "m1 = m2" << endl;
//      m1 = m2;
//
//      cout << "m1\n" << m1 << endl;
//      cout << "m2\n" << m2 << endl;
   }



   return EXIT_SUCCESS;
}
