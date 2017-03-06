#ifndef ETAT_H_INCLUDED
#define ETAT_H_INCLUDED

enum Mouvement { NORD, SUD, EST, OUEST, FIXE };

/**
 * @brief afficher, affiche un mouvement
 * @param [in] mouvement e � afficher
*/
void afficher(Mouvement mv);

struct Etat {
    Tableau2D d; // Damier r�sultant
    Mouvement m; // Dernier mouvement de #
    unsigned int dp; // Index dans lee du damier pr�c�dent
    unsigned int g; // Nombre de coups
    unsigned int h; // Heuristique de e
    unsigned int x, y; // Coordonn�es dans le damier r�sultant
};

/**
 * @brief afficher, affiche un �tat du Taquin
 * @param [in] �tat e � afficher
*/
void afficher(const Etat& e);



#endif // ETAT_H_INCLUDED
