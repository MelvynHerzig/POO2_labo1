/*
 -----------------------------------------------------------------------------------
 Laboratoire : POO2 labo_01
 Fichier     : Matrix.cpp
 Auteur(s)   : Forestier Quentin & Melvyn Herzig
 Date        : 24.02.2021

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include <stdexcept>     // runtime_error
#include <time.h>        // time
#include <algorithm>     // swap
#include "MatrixMult.h" // MatrixMult
#include "MatrixAdd.h"   // MatrixAdd
#include "MatrixSub.h"   // MatrixSub

#include "Matrix.h"

using namespace std;

ostream& operator<< (ostream& os, const Matrix& m)
{
   for(size_t i = 0; i < m.height; ++i)
   {
      for(size_t j = 0; j < m.width; ++j)
      {
         if(j != 0) os << ' ';
         os << m.matrix[i][j];
      }

      os << endl;
   }

   return os << endl;
}

// ----------- Constructeurs ------------
Matrix::Matrix (const Matrix* m1, const MatrixOperator* mo, const Matrix* m2) : matrix(nullptr), height(0), width(0)
{
   makeNewMatrix(m1, mo, m2);
}

Matrix::Matrix (size_t height, size_t width, unsigned modulus) : modulus(modulus), height(height), width(width)
{
   if(height == 0 || width == 0 || modulus == 0)
      throw runtime_error("La taille et le module ne peuvent etre egaux a 0.");

   matrix = new unsigned *[height];

   srand((unsigned)time(NULL));

   for (size_t i = 0; i < height; ++i)
   {
      matrix[i] = new unsigned[width];

      for (size_t j = 0; j < width; ++j)
      {
         matrix[i][j] = (unsigned) rand() % modulus;
      }
   }
}

Matrix::Matrix (const Matrix &m) : Matrix(&m) {}

// ----------- Destructeur ------------
Matrix::~Matrix ()
{
   freeContent();
}

//// ----------- Opération ------------
Matrix Matrix::operator*(const Matrix &m) const
{
   MatrixMult op = MatrixMult();
   return opToVal(m, &op);
}

Matrix &Matrix::operator*= (const Matrix &m)
{
   MatrixMult op = MatrixMult();
   return opOnSelf(m, &op);
}
Matrix *Matrix::multToPtr (const Matrix &m)
{
   MatrixMult op = MatrixMult();
   return opToPtr(m, &op);
}

Matrix Matrix::operator+ (const Matrix &m) const
{
   MatrixAdd op = MatrixAdd();
   return opToVal(m, &op);
}

Matrix &Matrix::operator+= (const Matrix &m)
{
   MatrixAdd op = MatrixAdd();
   return opOnSelf(m, &op);
}

Matrix *Matrix::addToPtr (const Matrix &m)
{
   MatrixAdd op = MatrixAdd();
   return opToPtr(m, &op);
}

Matrix Matrix::operator- (const Matrix &m) const
{
   MatrixSub op = MatrixSub();
   return opToVal(m, &op);
}

Matrix &Matrix::operator-= (const Matrix &m)
{
   MatrixSub op = MatrixSub();
   return opOnSelf(m, &op);
}

Matrix* Matrix::subToPtr (const Matrix &m)
{
   MatrixSub op = MatrixSub();
   return opToPtr(m, &op);
}

Matrix &Matrix::operator= (const Matrix &m)
{
   if(this != &m)
   {
      modulus = m.modulus;
      makeNewMatrix(&m);
   }
   return *this;
}

//  ----------- Utilitaires ------------

void Matrix::freeContent ()
{
   if(matrix == nullptr) return;

   for(size_t i = 0; i < height; ++i)
   {
      delete[] matrix[i];
   }

   delete[] matrix;

   matrix = nullptr;
   height = 0;
   width = 0;
}

unsigned Matrix::getElementNoException (std::size_t row, std::size_t col) const
{
   return (row < height && col < width) ? matrix[row][col] : 0;
}

void Matrix::makeNewMatrix(const Matrix* m1, const MatrixOperator* mo, const Matrix* m2)
{
   if (m1 != nullptr && m2 != nullptr && m1->modulus != m2->modulus)
      throw invalid_argument("Les deux matrices doivent avoir le meme module.");

   bool binary = m2 != nullptr && mo != nullptr;

   unsigned newWidth  = binary ? max(m1->width , m2->width ) : m1->width ;
   unsigned newHeight = binary ? max(m1->height, m2->height) : m1->height;

   unsigned **temp = new unsigned *[newHeight];

   for (size_t i = 0; i < newHeight; ++i)
   {
      temp[i] = new unsigned[newWidth];

      for (size_t j = 0; j < newWidth; ++j)
      {
         if(binary)
         {
            unsigned v1 = m1->getElementNoException(i,j);
            unsigned v2 = m2->getElementNoException(i,j);
            temp[i][j] = ( mo->operation(v1, v2) + m1->modulus ) % m1->modulus;
         }
         else
         {
            temp[i][j] = m1->matrix[i][j];
         }
      }
   }

   freeContent();
   swap(matrix, temp);
   modulus = m1->modulus;
   height = newHeight;
   width  = newWidth;
}

Matrix Matrix::opToVal (const Matrix &m, const MatrixOperator *op) const
{
   return Matrix(this, op, &m);
}

Matrix& Matrix::opOnSelf (const Matrix &m, const MatrixOperator *op)
{
   makeNewMatrix(this, op, &m);
   return *this;
}

Matrix* Matrix::opToPtr (const Matrix &m, const MatrixOperator *op)
{
   return new Matrix(this, op, &m);
}



