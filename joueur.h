#ifndef JOUEUR_H
#define JOUEUR_H

#include "structures.h"

extern Joueur *joueurs;
extern int nb_joueurs_ajoutes;
extern int nb_joueurs_max;

void ajouter_joueur(void);
void liste_joueurs(void);
void rechercher_joueur(void);
void supprimer_joueur(void);
void mise_a_jour_joueur(void);
void trier_joueurs_par_id(void);
void trier_joueurs_par_nom(void);

#endif