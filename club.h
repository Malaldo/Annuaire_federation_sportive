#ifndef CLUB_H
#define CLUB_H

#include "joueur.h"
#include "structures.h"
#include "util.h"

extern Club *clubs;
extern int nb_clubs_ajoutes, nb_max_clubs;

void ajouter_club(void);
void afficher_club(void);
void rechercher_club(void);
void supprimer_club(void);
void mise_a_jour_club(void);
void trier_clubs_par_id(void);
void trier_clubs_par_nom(void);
void ajouter_joueur_club(void);
void afficher_joueur_du_club(void);
#endif