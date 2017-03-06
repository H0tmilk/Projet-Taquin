#include <iostream>
#include <cassert>
#include <stdlib.h>

#include "Liste.h"
#include "Tableau2D.h"
#include "Etat.h"
#include "Taquin.h"

using namespace std;

/**
 * @brief initialiser, cr�e un jeu de taquin avec l'�tat initial
 * @param [in-out] t, Taquin � initialiser
*/
void initialiser(Taquin& t)
{
    // D�claration et initialisation de lee - Liste de Etats Explor�s)
    Liste lee;
    initialiser(lee);

    // D�claration et initialisation de leae - Liste de Etats A Explorer)
    Liste leae;
    initialiser(leae);

    // Demande du nbre de colonnes et de lignes � partir du flot d'entr�e standard
    unsigned int lignes, colonnes;
    cin >> lignes;
    cin >> colonnes;

    Etat e_init; // D�claration de l'�tat initial
    e_init.d.lignes = lignes;
    e_init.d.colonnes = colonnes;

    // Initialisation du damier initial
    initialiser(e_init.d, lignes, colonnes);

    // Lecture du damier initial
    lire(e_init.d);

    // On d�finit le mouvement initial � FIXE puisqu'il n'y en a pas encore eu,
    // ainsi que g, le nombre de mouvements � 0
    e_init.m = FIXE;
    e_init.g = 0;

    // On cherche le # dans le damier (qui vaut 0) pour obtenir ses coordonn�es
    for(unsigned int i = 0; i < lignes; i++)
    {
        for(unsigned int j = 0; j < colonnes; j++)
        {
            if(e_init.d.damier[i][j] == 0)
            {
                // Obtention des coordonn�es du 0
                e_init.x = i;
                e_init.y = j;
            }
        }
    }

    // On copie les liste dans t.leae et t.lee
    t.leae = leae;
    t.lee = lee;

    // On d�truit les deux listes devenues obsol�tes
    detruire(leae);
    detruire(lee);

    // On ins�re dans leae l'�tat initial que nous venons de cr�er
    inserer(t.leae, 0, e_init);

    // On affiche le nombre de lignes et de colonnes du taquin
    cout << "Damier : " << lignes << " lignes, " << colonnes << " colonnes" << endl;
}

/**
 * @brief Deplace le # dans le damier, retourne l'�tat r�sultant
 * @param [in] mv, Direction dans laquelle doit bouger le #
 * @param [in] e, Etat depuis lequel le mouvement doit �tre effectu�
 * @return er, etat r�sultant du mouvement
*/
Etat deplacement(Mouvement mv, const Etat& e)
{
    Etat er;
    initialiser(er.d, e.d.lignes, e.d.colonnes);
    for(unsigned int i = 0; i < er.d.lignes; i++)
    {
        for(unsigned int j = 0; j < er.d.colonnes; j++)
        {
            er.d.damier[i][j] = e.d.damier[i][j];
        }
    }
    er.x = e.x;
    er.y = e.y;
    er.m = mv;
    er.g = e.g + 1;
    switch(mv)
    {
        case NORD:
            assert(e.x > 0);
            er.d.damier[er.x][er.y] = er.d.damier[er.x-1][er.y];
            er.d.damier[er.x-1][er.y] = 0;
            er.x--;
            break;
        case OUEST:
            assert(e.y > 0);
            er.d.damier[er.x][e.y] = er.d.damier[er.x][er.y-1];
            er.d.damier[er.x][er.y-1] = 0;
            er.y--;
            break;
        case SUD:
            assert(er.x < er.d.lignes-1);
            er.d.damier[er.x][er.y] = er.d.damier[er.x+1][er.y];
            er.d.damier[er.x+1][er.y] = 0;
            er.x++;
            break;
        case EST:
            assert(er.x < er.d.colonnes-1);
            er.d.damier[er.x][er.y] = er.d.damier[er.x][er.y+1];
            er.d.damier[er.x][er.y+1] = 0;
            er.y++;
            break;
        case FIXE:
            return er;
    }
    return er;
}

/**
 * @brief jouer, pour faire une it�ration de l'algorithme de recherche
 * @param [in-out] Taquin t, le taquin � r�soudre
*/
void jouer(Taquin& t)
{
    // D�placement du dernier �tat ajout� dans leae dans lee
    // NB: A modifier quand l'heuristque sera � traiter
    deplacer(t.leae, t.lee, longueur(t.leae)-1, longueur(t.lee));

    cout << lire(t.lee, longueur(t.lee)-1).x << endl;
    cout << lire(t.lee, longueur(t.lee)-1).d.colonnes << endl;

    Etat courant;
    courant = lire(t.lee, longueur(t.lee)-1);

    // Si c'est possible, on ins�re dans leae les �tats qui d�coulent du dernier �tat entr� dans lee
    if(courant.x > 0)
    {
        inserer(t.leae, longueur(t.leae), deplacement(NORD, courant));
    }
    if(courant.y > 0)
    {
        inserer(t.leae, longueur(t.leae), deplacement(OUEST, courant));
    }
    if(courant.x < courant.d.lignes-1)
    {
        inserer(t.leae, longueur(t.leae), deplacement(SUD, courant));
    }
    if(courant.y < courant.d.colonnes-1)
    {
        inserer(t.leae, longueur(t.leae), deplacement(EST, courant));
    }
}

/**
 * @brief Affiche le contenu des listes lee et leae
 * @param [in] Taquin t, le taquin � afficher
*/
void afficher(Taquin& t)
{
    cout << "*** LEE -long : " << longueur(t.lee) << endl;
    for(unsigned int i = 0; i < longueur(t.lee); i++)
    {
        afficher(lire(t.lee, i).d);
    }

    cout << endl << "*** LEAE -long : " << longueur(t.leae) << endl;
    for(unsigned int i = 0; i < longueur(t.leae); i++)
    {
        afficher(lire(t.leae, i));
    }
}
