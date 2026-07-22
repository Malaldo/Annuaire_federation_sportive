#ifndef STRUCTURES_H
#define STRUCTURES_H

/*=====================================================
                 Structure date
======================================================*/

typedef struct {
    int jour; int mois; int annee;
} Date;

/*=====================================================
                 Structure adresse
======================================================*/
typedef struct {
    char siege[20], email[30], site_web[40], nom_stade[30], adresse_stade[20];
} Adresse;

/*=====================================================
                 Structure joueur
======================================================*/
typedef struct {
    char id[15];
    char prenom[40], nom[40];
    Date dateNaissance;
    char nationalite[40];
    char categorie[15];
    char poste[30];    
    char clubActuel[40];
    
} Joueur;

/*=====================================================
                 Structure club
======================================================*/
typedef struct {
    char id[15];
    char nom[40];
    Date dateCreation;
    Adresse adresse;
    int points;
    char proprietaire[20], manager[20];
    int nb_pensionnaires, nb_pensionnaires_ajoutes;
    Joueur *pensionnaires;
} Club;

/*=====================================================
                 Structure competition
======================================================*/
typedef struct {
    char id[15];    
    char nom[40];
    char saison[10], type[40];
    int nb_max_paticipants;
    int nb_participants_ajoutes;
    Club *classement;
    Club *participants;
} Competition;


#endif 