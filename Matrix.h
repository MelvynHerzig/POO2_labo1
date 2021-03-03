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
#include "Utils.h" // positiveInteger


/**
 * @brief Class implémentant des Matrices dont le contenu et définit modulo N.
 *        Les opérations sont éffectuée élément par élément.
 *        Si deux matrices ne sont pas de même taille, la matrice résultante
 *        et la fusion le la valeur max de leur taille et dont les opérandes
 *        manquand sont remplacé par des 0
 * @authors Forestier Quentin, Herzig Melvyn
 * @date 03-03-2021
 */
class Matrix
{

/**
 * @brief Affiche une matrice.
 * @param os Flux de sortie.
 * @param m Matrice à afficher.
 * @return Référence sur le flux modifié avec la matrice.
 */
friend std::ostream& operator<<(std::ostream& os, const Matrix& m);

private:

   unsigned modulus; // Modulo de la matrix

   unsigned** matrix;  // Contenu de la matrix
   std::size_t height; // Heuteur de la matrix
   std::size_t width;  // Largeur de la matrix

   // ----------- Constructeurs ------------
private:

   /**
    * @brief Constructeur permettant de créer une nouvelle matrice issue de deux autres
    *        ou si la deuxième est nullptr, copie la première.
    * @param m1 Première matrice opérande.
    * @param mo Opération à réaliser.
    * @param m2 Deuxième matrice opérande.
    * @throw invalid_argument Si m2 n'est pas nullptr et n'a pas le même module que m1.
    * @throw runtime_error si m1 est nullptr.
    */
   Matrix(const Matrix* m1, const MatrixOperator* mo = nullptr, const Matrix* m2 = nullptr);

public:
   /**
    * @brief Constructeur par defaut. Initialise matrix à nullptr et les valeurs à 0.
    */
   Matrix();

   /**
    * @brief Construit une matrice de taille height * width avec un contenu sur modulus.
    * @param height Taille de la matrice.
    * @param width Largeur de la matrice.
    * @param modulus Modulu à utiliser pour la génération du contenu.
    * @throw runtime_error si un des paramètre est nul.
    */
   Matrix(std::size_t height, std::size_t width, unsigned modulus);

   /**
    * Constructeur de copie
    * @param m Matrice à copier.
    * @throw runtime_error si m est nullptr.
    */
   Matrix(const Matrix& m);

public:
   // ----------- Destructeur ------------
   /**
    * @brief Destructeur.
    */
   ~Matrix();

   // ----------- Opération ------------

   // Multiplication

   /**
    * @brief Multiplie la matrice actuelle avec m et renvoie une nouvelle matrice
    *        résultante.
    * @param m  Deuxième matrice opérante.
    * @return Retourne une copie de la matrice résultante.
    * @throw invalid_argument Si m n'a pas le même module que la matrice actuelle.
    */
   Matrix operator*(const Matrix& m) const;
   /**
    * @brief Multiplie la matrice actuelle avec m et renvoie une référence sur
    *        la matrice actuelle.
    * @param m Deuxième matrice opérante.
    * @return Retourne une référence sur la matrice actuelle modifiée.
    * @throw invalid_argument Si m n'a pas le même module que la matrice actuelle.
    */
   Matrix& operator*=(const Matrix& m);
   /**
   * @brief Multiplie la matrice actuelle avec m et renvoie une nouvelle matrice
   *        résultante. Ne pas delete la matrice résultante débouche sur une
    *       fuite de mémoire.
   * @param m  Deuxième matrice opérante.
   * @return Retourne un pointeur sur la matrice résultante.
   * @throw invalid_argument Si m n'a pas le même module que la matrice actuelle.
   */
   Matrix* multToPtr (const Matrix& m) const;

   // Addition

   /**
   * @brief Additionne la matrice actuelle avec m et renvoie une nouvelle matrice
   *        résultante.
   * @param m  Deuxième matrice opérante.
   * @return Retourne une copie de la matrice résultante.
   * @throw invalid_argument Si m n'a pas le même module que la matrice actuelle.
   */
   Matrix operator+(const Matrix& m) const;
   /**
    * @brief Additionne la matrice actuelle avec m et renvoie une référence sur
    *        la matrice actuelle.
    * @param m Deuxième matrice opérante.
    * @return Retourne une référence sur la matrice actuelle modifiée.
    * @throw invalid_argument Si m n'a pas le même module que la matrice actuelle.
    */
   Matrix& operator+=(const Matrix& m);
   /**
   * @brief Additionne la matrice actuelle avec m et renvoie une nouvelle matrice
   *        résultante. Ne pas delete la matrice résultante débouche sur une
    *       fuite de mémoire.
   * @param m  Deuxième matrice opérante.
   * @return Retourne un pointeur sur la matrice résultante.
   * @throw invalid_argument Si m n'a pas le même module que la matrice actuelle.
   */
   Matrix* addToPtr (const Matrix& m) const;

   // Soustraction
   /**
   * @brief Soustrait la matrice actuelle avec m et renvoie une nouvelle matrice
   *        résultante.
   * @param m  Deuxième matrice opérante.
   * @return Retourne une copie de la matrice résultante.
   * @throw invalid_argument Si m n'a pas le même module que la matrice actuelle.
   */
   Matrix operator-(const Matrix& m) const;
   /**
   * @brief Soustrait la matrice actuelle avec m et renvoie une référence sur
   *        la matrice actuelle.
   * @param m Deuxième matrice opérante.
   * @return Retourne une référence sur la matrice actuelle modifiée.
   * @throw invalid_argument Si m n'a pas le même module que la matrice actuelle.
   */
   Matrix& operator-=(const Matrix& m);
   /**
   * @brief Soustrait la matrice actuelle avec m et renvoie une nouvelle matrice
   *        résultante. Ne pas delete la matrice résultante débouche sur une
   *       fuite de mémoire.
   * @param m  Deuxième matrice opérante.
   * @return Retourne un pointeur sur la matrice résultante.
   * @throw invalid_argument Si m n'a pas le même module que la matrice actuelle.
   */
   Matrix* subToPtr (const Matrix& m) const;

   // Affectation
   /**
    * @brief Affecte la matrice m à la matrice actuelle.
    * @param m Matrice affectante.
    * @return Retourne une référence sur la matrice actuelle modifiée.
    */
   Matrix& operator=(const Matrix& m);

private:
   //  ----------- Utilitaires ------------
   /**
    * @brief Supprime le contenue de matrix et matrix puis
    *        set matrix à nullptr.
    */
   void freeContent();

   /**
    * @brief Affecte m1 ou m1 *,+,- m2 à la matrice actuelle
    * @param m1 Matrice à affecter / première opérande.
    * @param mo Opération, par défaut nullptr.
    * @param m2 Deuxième opérande, par défaut nullptr.
    * @throw invalid_argument Si m2 n'est pas nullptr et n'a pas le même module que m1.
    * @throw runtime_error si m1 est nullptr.
    */
   void makeNewMatrix(const Matrix* m1, const MatrixOperator *mo = nullptr, const Matrix* m2 = nullptr);

   //  ----------- Manipulation ------------
   /**
    * @brief Retourne le contenu de la matrice à la position row col.
    *        Si out of bounds retourne 0.
    * @param row Ligne à chercher.
    * @param col Colonne à chercher.
    * @return Retourne l'élément sinon 0.
    */
   unsigned getElementNoException(std::size_t row, std::size_t col) const;

   //  ----------- Operation ------------
   /**
    * @brief Applique op entre la matrice actuelle et m et renvoie une nouvelle matrice
    *        résultante.
    * @param m Deuxième matrice opérante.
    * @param op Opération à effectuer.
    * @return Retourne une copie de la matrice résultante.
    * @throw invalid_argument Si m n'a pas le même module que la matrice actuelle.
    */
   Matrix  opToVal (const Matrix& m, const MatrixOperator* op) const;
   /**
    * @brief Applique op entre la matrice actuelle et m et renvoie une référence sur
    *        la matrice actuelle.
    * @param m Deuxième matrice opérante.
    * @param op Opération à effectuer.
    * @return Retourne une référence sur la matrice actuelle.
    * @throw invalid_argument Si m n'a pas le même module que la matrice actuelle.
    */
   Matrix& opOnSelf(const Matrix& m, const MatrixOperator* op);
    /**
    * @brief Applique op entre la matrice actuelle et m et renvoie une nouvelle matrice
    *        résultante. Ne pas delete la matrice résultante débouche sur une
    *        fuite de mémoire.
    * @param m  Deuxième matrice opérante.
    * @return Retourne un pointeur sur la matrice résultante.
    * @throw invalid_argument Si m n'a pas le même module que la matrice actuelle.
    */
   Matrix* opToPtr (const Matrix& m, const MatrixOperator* op) const;

};


#endif //POO2_LABO1_MATRIX_H
