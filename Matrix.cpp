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
#include "MatriceMult.h" // MatriceMult
#include "MatrixAdd.h"  // MatrixAdd
#include "MatrixSub.h"  // MatrixSub
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
Matrix::Matrix () : modulus(1), matrix(nullptr), height(0), width(0)
{
   if(init) srand((unsigned)time(NULL));
   init = false;
}

Matrix::Matrix (size_t pHeight, size_t pWidth, unsigned pModulus) : Matrix()
{
   realloc(pHeight, pWidth, pModulus);
}

Matrix::Matrix (const Matrix &m) : Matrix()
{
   realloc(m.height, m.width, m.modulus, m.matrix, m.height, m.width);
}

// ----------- Destructeur ------------
Matrix::~Matrix ()
{
   freeContent();
}

//// ----------- Opération ------------

// Multiplication
Matrix& Matrix::multOnSelf (const Matrix &m)
{
   const MatriceMult mo;
   makeOperation(m, mo);
   return *this;
}

Matrix Matrix::multToVal(const Matrix &m) const
{
   Matrix temp = Matrix(*this);
   temp.multOnSelf(m);
   return temp;
}

Matrix* Matrix::multToPtr (const Matrix &m)
{
   Matrix* temp = new Matrix(*this);
   try
   {
      (*temp).multOnSelf(m);
      return temp;
   }
   catch(...)
   {
      delete temp;
      return nullptr;
   }
}

// Addition
Matrix& Matrix::addOnSelf (const Matrix &m)
{
   MatrixAdd mo;
   makeOperation(m, mo);
   return *this;
}

Matrix Matrix::addToVal (const Matrix &m) const
{
   Matrix temp = Matrix(*this);
   temp.addOnSelf(m);
   return temp;
}

Matrix* Matrix::addToPtr (const Matrix &m)
{
   Matrix* temp = new Matrix(*this);
   try
   {
      (*temp).addOnSelf(m);
      return temp;
   }
   catch(...)
   {
      delete temp;
      return nullptr;
   }
}

// Soustraction
Matrix& Matrix::subOnSelf (const Matrix &m)
{
   MatrixSub mo;
   makeOperation(m, mo);
   return *this;
}

Matrix Matrix::subToVal (const Matrix &m) const
{
   Matrix temp = Matrix(*this);
   temp.subOnSelf(m);
   return temp;
}

Matrix* Matrix::subToPtr (const Matrix &m)
{
   Matrix* temp = new Matrix(*this);
   try
   {
      (*temp).subOnSelf(m);
      return temp;
   }
   catch(...)
   {
      delete temp;
      return nullptr;
   }
}

//  ----------- Utilitaires ------------
void Matrix::makeOperation (const Matrix& m, const MatrixOperator &mo)
{
   if(modulus != m.modulus) throw invalid_argument("Les deux matrices operees n ont pas le meme modulo.");

   size_t maxWidth  = max(width , m.width );
   size_t maxHeight = max(height, m.height);

   realloc(maxHeight, maxWidth, modulus, matrix, height, width);

   unsigned v1, v2;
   for(size_t i = 0; i < maxHeight; ++i)
   {
      for(size_t j = 0; j < maxWidth; ++j)
      {
         v1 = getElementNoException(i,j);
         v2 = m.getElementNoException(i,j);

         matrix[i][j] = ( mo.operation(v1, v2) + modulus ) % modulus;
      }
   }

}

// Attention peut lever une out of range exception si pHeight et pWidth ne correspondent
// pas à pMatrix
void Matrix::realloc (std::size_t newHeight, std::size_t newWidth, unsigned pModulus, unsigned** pMatrix, std::size_t pHeight, std::size_t pWidth)
{
   if (newHeight == 0 || newWidth == 0 || pModulus == 0) throw runtime_error("Argument(s) invalide(s)");

   unsigned **temp = new unsigned *[newHeight];

   for (size_t i = 0; i < newHeight; ++i)
   {
      temp[i] = new unsigned[newWidth];

      for (size_t j = 0; j < newWidth; ++j)
      {
         if(pMatrix == nullptr)
         {
            temp[i][j] = (unsigned) rand() %  pModulus;
         }
         if(pMatrix != nullptr)
         {
            if(i < pHeight && j < pWidth) temp[i][j] = pMatrix[i][j];
            else temp[i][j] = 0;
         }
      }
   }

   freeContent();
   swap(matrix, temp);
   height = newHeight;
   width = newWidth;
   modulus = pModulus;
}


void Matrix::freeContent ()
{
   if(matrix == nullptr) return;
   for(size_t i = 0; i < height; ++i)
   {
      delete[] matrix[i];
   }

   delete[] matrix;
}

unsigned Matrix::getElementNoException (std::size_t row, std::size_t col) const
{
   return (row < height && col < width) ? matrix[row][col] : 0;
}

unsigned **Matrix::makeNewMatrix (std::size_t newHeight, std::size_t newWidth, const Matrix *m1, MatrixOperator *pMo, const Matrix *m2)
{
   if (m1 != nullptr && m2 != nullptr && m1->modulus != m2->modulus)
      throw invalid_argument("Les deux matrices operees n ont pas le meme modulo.");

   if (newHeight == 0 || newWidth == 0)
      throw runtime_error("Argument(s) invalide(s)");

   bool operation = (m1 != nullptr && m2 != nullptr && pMo != nullptr);

   unsigned **temp = new unsigned *[newHeight];

   for (size_t i = 0; i < newHeight; ++i)
   {
      temp[i] = new unsigned[newWidth];

      for (size_t j = 0; j < newWidth; ++j)
      {
         if(operation)
         {
            unsigned v1 = m1->getElementNoException(i,j);
            unsigned v2 = m2->getElementNoException(i,j);

            temp[i][j] = ( pMo->operation(v1, v2) + modulus ) % modulus;
         }
        else
         {
            temp[i][j] = rand() % modulus;
         }
      }
   }

   return temp;
}

