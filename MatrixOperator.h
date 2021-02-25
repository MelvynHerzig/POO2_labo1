/*
 -----------------------------------------------------------------------------------
 Laboratoire : POO2 labo_01
 Fichier     : MatrixOperator.h
 Auteur(s)   : Forestier Quentin & Melvyn Herzig
 Date        : 24.02.2021

 But         : Classe abstraite définissant les méthodes que doivent
               supporter les opérateur entre deux matrices.

 Remarque(s) : /

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef POO2_LABO1_MATRIXOPERATOR_H
#define POO2_LABO1_MATRIXOPERATOR_H

class MatrixOperator
{
public:
   virtual unsigned operation(unsigned x1, unsigned x2) const = 0;
};

#endif //POO2_LABO1_MATRIXOPERATOR_H
