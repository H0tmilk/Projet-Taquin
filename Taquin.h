#ifndef TAQUIN_H_INCLUDED
#define TAQUIN_H_INCLUDED

struct Taquin {
    Liste lee; // Liste des �tats explor�s
    Liste leae; // Liste des �tats � explorer
    unsigned int lignes, colonnes; // Nombre de lignes et de colonnes du tableau consid�r�
};

/**
 * @brief initialiser, cr�e un jeu de taquin avec l'�tat initial
 * @param [in-out] t, Taquin � initialiser
*/
void initialiser(Taquin& t);

/**
 * @brief Deplace le # dans le damier, retourne l'�tat r�sultant
 * @param [in] mv, Direction dans laquelle doit bouger le #
 * @param [in] e, Etat depuis lequel le mouvement doit �tre effectu�
 * @return er, etat r�sultant du mouvement
*/
Etat deplacement(Mouvement mv, const Etat& e);

/**
 * @brief jouer, pour faire une it�ration de l'algorithme de recherche
 * @param [in-out] Taquin t, le taquin � r�soudre
*/
void jouer(Taquin& t);

/**
 * @brief Affiche le contenu des listes lee et leae
 * @param [in] Taquin t, le taquin � afficher
*/
void afficher(Taquin& t);

#endif // TAQUIN_H_INCLUDED
