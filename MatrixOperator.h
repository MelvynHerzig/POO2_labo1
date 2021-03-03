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

/**
 * @brief Classe mettant en oeuvre les opérations
 *        qui peuvent être effectuée par la classe Matrix.
 * @authors Forestier Quentin, Herzig Melvyn
 * @date 03-03-2021
 */
class MatrixOperator
{
public:

   /**
    * @brief Méthode à implémenter pour définir une opération de Matrix.
    * @param x1 Élément de la première matrice.
    * @param x2 Élément de la seconde matrice.
    * @return Retourne le résultat de l'opération définie.
    */
   virtual unsigned operation(unsigned x1, unsigned x2) const = 0;
};

#endif //POO2_LABO1_MATRIXOPERATOR_H
