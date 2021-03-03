/*
 -----------------------------------------------------------------------------------
 Laboratoire : POO2 labo_01
 Fichier     : Ultils.h
 Auteur(s)   : Forestier Quentin & Melvyn Herzig
 Date        : 24.02.2021

 But         : Classe utilitaire.

 Remarque(s) : /

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef POO2_LABO1_UTILS_H
#define POO2_LABO1_UTILS_H


/**
 * @brief Classe implémentant des méthodes utiliaires.
 * @authors Forestier Quentin, Herzig Melvyn
 * @date 03-03-2021
 */
class Utils
{
private:
   static bool init; // Pour initialiser le seeding une seule fois.

public:
   /**
    * @brief Génère une nombre aléatoire entre 0 et MaxVal (non compris)
    * @param maxVal Borne supérieure non inclue.
    * @return Retourne un nombre aléatoire [0, maxVal [
    */
   static unsigned positiveInteger(unsigned maxVal);
};


#endif //POO2_LABO1_UTILS_H
