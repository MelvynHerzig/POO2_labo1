/*
 -----------------------------------------------------------------------------------
 Laboratoire : POO2 labo_01
 Fichier     : Matrix.h
 Auteur(s)   : Forestier Quentin & Melvyn Herzig
 Date        : 24.02.2021

 But         : Classe implémentant des matrices de taille personnalisable.
               Le contenu est défini modulo N.
               Les opérations d'additions, soustractions et multiplications sont
               supportées.

 Remarque(s) : Les opérations sont implémentées 1:1

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef POO2_LABO1_MATRIX_H
#define POO2_LABO1_MATRIX_H

#include <cstdlib> // size_t, srand, rand
#include <ostream> // ostream

#include "MatrixOperator.h" // operation, MatrixOperator


/**
 * @brief Class implémentant des Matrices dont le contenu et définit modulo N.
 *        Les opérations sont éffectuée élément par élément.
 *        Si deux matrices ne sont pas de même taille, la matrice résultante
 *        et la fusion le la valeur max de leur taille et dont les opérandes
 *        manquand sont remplacé par des 0
 */
class Matrix
{
friend std::ostream& operator<<(std::ostream& os, const Matrix& m);

private:

   unsigned modulus; // Modulo de la matrix

   unsigned** matrix;  // Contenu de la matrix
   std::size_t height; // Heuteur de la matrix
   std::size_t width;  // Largeur de la matrix

   // ----------- Constructeurs ------------
private:
   Matrix(const Matrix* m1, const MatrixOperator* mo = nullptr, const Matrix* m2 = nullptr);

public:
   Matrix(std::size_t height, std::size_t width, unsigned modulus);
   Matrix(const Matrix& m);

public:
   // ----------- Destructeur ------------
   ~Matrix();

   // ----------- Opération ------------

   // Multiplication
   Matrix operator*(const Matrix& m) const;
   Matrix& operator*=(const Matrix& m);
   Matrix* multToPtr (const Matrix& m);

   // Addition
   Matrix operator+(const Matrix& m) const;
   Matrix& operator+=(const Matrix& m);
   Matrix* addToPtr (const Matrix& m);

   // Soustraction
   Matrix operator-(const Matrix& m) const;
   Matrix& operator-=(const Matrix& m);
   Matrix* subToPtr (const Matrix& m);

   // Affectation
   Matrix& operator=(const Matrix& m);


private:
   //  ----------- Utilitaires ------------
   void freeContent();

   void makeNewMatrix(const Matrix* m1, const MatrixOperator *mo = nullptr, const Matrix* m2 = nullptr);

   //  ----------- Manipulation ------------
   unsigned getElementNoException(std::size_t row, std::size_t col) const;

   //  ----------- Operation ------------
   Matrix  opToVal (const Matrix& m, const MatrixOperator* op) const;
   Matrix& opOnSelf(const Matrix& m, const MatrixOperator* op);
   Matrix* opToPtr (const Matrix& m, const MatrixOperator* op);

};


#endif //POO2_LABO1_MATRIX_H
