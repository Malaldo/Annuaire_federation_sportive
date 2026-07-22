#ifndef COMPETITION_H
#define COMPETITION_H

#include "structures.h"
#include "club.h"

extern Competition *competitions;
extern int nb_competitions_ajoutes, nb_max_competitions;

void ajouter_competition(void);
void ajouter_participants(void);
void afficher_competition(void);
void rechercher_competition(void);
void mise_a_jour_competition(void);
void supprimer_competiton(void);
void supprimer_participant(void);
void trier_participants(void);

#endif