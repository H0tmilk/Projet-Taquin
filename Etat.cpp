#include <iostream>
#include <cassert>
#include <stdlib.h>

#include "Tableau2D.h"
#include "Etat.h"

using namespace std;

/**
 * @brief afficher, affiche un mouvement
 * @param [in] mouvement e � afficher
*/
void afficher(Mouvement mv)
{
    switch(mv)
    {
        case NORD:
            cout << "NORD" << endl;
            break;
        case OUEST:
            cout << "OUEST" << endl;
            break;
        case SUD:
            cout << "SUD" << endl;
            break;
        case EST:
            cout << "EST" << endl;
            break;
        case FIXE:
            cout << "FIXE" << endl;
            break;
    }
}

/**
 * @brief afficher, affiche un �tat du Taquin
 * @param [in] �tat e � afficher
*/
void afficher(const Etat& e)
{
    // On affiche le dernier mouvement seulement s'il y en a eu au moins 1
    if(e.g > 0)
    {
        afficher(e.m);
    }

    // On affiche maintenant le damier r�sultant (fonction afficher(Tableau2D&))
    afficher(e.d);
}
