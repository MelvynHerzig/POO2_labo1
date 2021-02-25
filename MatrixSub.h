/*
 -----------------------------------------------------------------------------------
 Laboratoire : POO2 labo_01
 Fichier     : MatrixOperator.h
 Auteur(s)   : Forestier Quentin & Melvyn Herzig
 Date        : 24.02.2021

 But         : Implémenter la soustraction de deux matrices.

 Remarque(s) : /

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef POO2_LABO1_MATRIXSUB_H
#define POO2_LABO1_MATRIXSUB_H

#include "MatrixOperator.h" // operation

class MatrixSub : public MatrixOperator
{
public:
   unsigned operation(unsigned x1, unsigned x2) const;
};


#endif //POO2_LABO1_MATRIXSUB_H