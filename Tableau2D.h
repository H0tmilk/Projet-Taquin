#ifndef TABLEAU2D_H_INCLUDED
#define TABLEAU2D_H_INCLUDED

typedef int Item ;

struct Tableau2D
{
    int lignes, colonnes;
    Item **damier;
};

/* @brief initialiser, initialiser un damier de n lignes et p colonnes
 * @param[in-out] t, tableau � 2 dimensions � initialiser(Tableau2D)
 * @param[in] n, nombre de lignes
 * @param[in] p, nombre de lignes
*/
void initialiser(Tableau2D& t, int n, int p);

/* @brief detruire, d�truit un Tableau2D
 * @param[in-out] t, tableau � 2 dimensions � d�truire (Tableau2D)
*/
void detruire(Tableau2D& t);

/* @brief lire,
 * @param[in-out] t, tableau � 2 dimensions � d�truire (Tableau2D)
*/
void lire(Tableau2D& t);

/* @brief afficher, affiche le tableau 2D
 * @param[in] t, tableau 2D � afficher
*/
void afficher(const Tableau2D& t);

#endif // TABLEAU2D_H_INCLUDED
