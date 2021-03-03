/*
 -----------------------------------------------------------------------------------
 Laboratoire : POO2 labo_01
 Fichier     : MatrixAdd.h
 Auteur(s)   : Forestier Quentin & Melvyn Herzig
 Date        : 24.02.2021

 But         : Implémenter l'addition de deux matrices.

 Remarque(s) : /

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef POO2_LABO1_MATRIXADD_H
#define POO2_LABO1_MATRIXADD_H

#include "MatrixOperator.h" // operation


/**
 * @brief Classe mettant en oeuvre les additions
 *        qui peuvent être effectuée par la classe Matrix.
 * @authors Forestier Quentin, Herzig Melvyn
 * @date 03-03-2021
 */
class MatrixAdd : public MatrixOperator
{
public:

   /**
    * @brief Méthode à implémentant l'addition entre deux matrices Matrix.
    * @param x1 Élément de la première matrice.
    * @param x2 Élément de la seconde matrice.
    * @return Retourne le résultat de l'addition.
    */
   unsigned operation(unsigned x1, unsigned x2) const;
};


#endif //POO2_LABO1_MATRIXADD_H
