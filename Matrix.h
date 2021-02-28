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

   bool init = true;

   // ----------- Constructeurs ------------
private:
   Matrix();

public:
   Matrix(std::size_t pHeight, std::size_t pWidth, unsigned pModulus);
   Matrix(const Matrix& m);

public:
   // ----------- Destructeur ------------
   ~Matrix();

   // ----------- Opération ------------

   // Multiplication
   Matrix& multOnSelf(const Matrix& m);
   Matrix  multToVal (const Matrix& m) const;
   Matrix* multToPtr (const Matrix& m);

   // Addition
   Matrix& addOnSelf(const Matrix& m);
   Matrix  addToVal (const Matrix& m) const;
   Matrix* addToPtr (const Matrix& m);

   // Soustraction
   Matrix& subOnSelf(const Matrix& m);
   Matrix  subToVal (const Matrix& m) const;
   Matrix* subToPtr (const Matrix& m);


private:
   //  ----------- Utilitaires ------------
   void makeOperation(const Matrix& m, const MatrixOperator& mo);
   void realloc(std::size_t newHeight, std::size_t newWidth, unsigned pModulus, unsigned** pMatrix = nullptr, std::size_t pHeight = 0, std::size_t pWidth = 0);
   void freeContent();

   unsigned** makeNewMatrix(std::size_t newHeight, std::size_t newWidth, const Matrix* m1 = nullptr, MatrixOperator *pMo = nullptr, const Matrix* m2 = nullptr);

   //  ----------- Manipulation ------------
   unsigned getElementNoException(std::size_t row, std::size_t col) const;
};




#endif //POO2_LABO1_MATRIX_H
