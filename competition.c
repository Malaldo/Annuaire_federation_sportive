#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "competition.h"
#include "util.h"


Competition *competitions;
int nb_competitions_ajoutes = 0, nb_max_competitions;

  /*=========================================================================================================================================/
 /                                                         GESTION DE COMPETITON                                                            /
/=========================================================================================================================================*/  


/*============================================
      FONCTION POUR AJOUTER UNE COMPETITION
==============================================*/

void ajouter_competition(){
    effacerEcran();
    if (nb_competitions_ajoutes >= nb_max_competitions) {
        Competition *temp = realloc(competitions, (nb_max_competitions + 1) * sizeof(Competition));
        if (temp == NULL) {
            printf("                                            Nombre maximal de compétitions atteint (Echec de l'allocation mémoire).\n");
            return;
        }
        competitions = temp;
        nb_max_competitions++;
        
    }
    printf("\n                                                       ╔════════════════════════════════════╗\n");
    printf("                                                       ║      Ajout d'une compétition       ║\n");
    printf("                                                       ╚════════════════════════════════════╝\n\n");

    int exist; char id[15];    
    /* On vérifie que l'identifiant saisi n'existe pas déjà dans la liste des compétitions. */
    do
    {   
        exist = 0;
        printf("                                            Entrer l'identifiant de la compétition : ");
	    scanf(" %[^\n]", id);
        for (int i = 0; i < nb_competitions_ajoutes; i++)
        {
            if(strcmp(competitions[i].id, id) == 0){
                exist = 1;
                printf("                                            Cet identifiant existe déja.\n");
                break;
            }
        }               
    } while (exist);
    strcpy((competitions + nb_competitions_ajoutes)->id, id);

    printf("                                            Saisir le nom de la compétition : ");
    scanf(" %[^\n]", (competitions + nb_competitions_ajoutes)->nom);
    printf("                                            Saisir la saison de la compétition ( aaaa/aaaa) : ");
    scanf(" %[^\n]", (competitions + nb_competitions_ajoutes)->saison);
    printf("                                            Saisir le type de la compétition (championnat ou bien coupe) : ");
    scanf(" %[^\n]", (competitions + nb_competitions_ajoutes)->type);
    int retour; char cj;    
    printf("                                            Saisir le nombre de participants: ");
    /* La saisie doit être un entier strictement positif, avec contrôle sur la fin de ligne. */
    while((retour =scanf(" %d%c",  &(competitions + nb_competitions_ajoutes)->nb_max_paticipants, &cj)) != 2 ||(competitions + nb_competitions_ajoutes)->nb_max_paticipants <= 0 || cj != '\n') {
        printf("\n                                            Entrée invalide. Veuillez entrer un nombre entier stricetement positif.\n\n");
        printf("                                            Saisir le nombre de participants: ");
        nettoyer_tampon(retour, &cj);
    }
    (competitions + nb_competitions_ajoutes)->participants = malloc(((competitions+nb_competitions_ajoutes)->nb_max_paticipants) * sizeof(Club));
    puts("\n");
    printf("                                            Compétition %s ajoutée avec succès !\n", (competitions + nb_competitions_ajoutes)->nom);
    (competitions + nb_competitions_ajoutes)->nb_participants_ajoutes = 0;
    nb_competitions_ajoutes++;
}

  /*==========================================================/
   FONCTION POUR AJOUTER DES PARTICIPANTS A UNE COMPETITON
/==========================================================*/

void ajouter_participants(){
	effacerEcran();
    char id_participant[15], id_competition[15]; int compet_trouve = 0; int club_trouve = 0;
    printf("\n                                                       ╔════════════════════════════════════╗\n");
    printf("                                                       ║       Ajout d'un participant       ║\n");
    printf("                                                       ╚════════════════════════════════════╝\n\n");
    printf("                                            Saisir l'identifiant de la compétition : ");
    scanf(" %[^\n]", id_competition);
    for(int i = 0; i < nb_competitions_ajoutes; i++){
        if (strcmp(id_competition, (competitions+i)->id) == 0)
        {
            compet_trouve = 1;
            printf("                                            Saisir l'identifiant du club participant: ");
            scanf(" %[^\n]", id_participant);
            /* Empêche l'ajout du même club deux fois dans la même compétition. */
            for (int k = 0; k < competitions[i].nb_participants_ajoutes; k++)
            {
                if(strcmp(id_participant, competitions[i].participants[k].id) == 0){
                    printf("\n                                            Ce club est déja participant à cette compétition\n");
                    return;
                }
            }
            
            /* Vérifie ensuite si le club existe bien dans la liste générale des clubs. */
            for(int j = 0; j < nb_clubs_ajoutes; j++){
                if (strcmp(id_participant, (clubs+j)->id) == 0)

                {
                    club_trouve = 1;
                    if ((competitions+i)->nb_participants_ajoutes < (competitions+i)->nb_max_paticipants)
                    {
                        (competitions+i)->participants[(competitions+i)->nb_participants_ajoutes] = *(clubs+j);                        
                        (competitions+i)->participants[(competitions+i)->nb_participants_ajoutes].points = 0;
                        competitions[i].classement = realloc(competitions[i].classement, ((competitions+i)->nb_participants_ajoutes + 1) * sizeof(Club));
                        competitions[i].classement[(competitions+i)->nb_participants_ajoutes] = *(clubs+j);
                        (competitions+i)->nb_participants_ajoutes++;
                        printf("\n                                            %s ajouté avec succès à la compétition !\n", (clubs+j)->nom);
                    } else {
                        printf("\n                                            Nombre maximal de participants atteint pour cette compétition.\n");
                    }                                           
                }
            }
            if (!club_trouve)
            {
                printf("\n                                            Aucun club enregistré avec cet identifiant.\n");                
            }            
        }
    }
    if (!compet_trouve) printf("\n                                            Aucune compétition enregistrée avec cet identifiant.\n");            
}

  /*==============================================/
 /   FONCTION POUR AFFICHER LES COMPETITIONS     /
/==============================================*/
void afficher_competition(){
    effacerEcran();
    printf("\n                                                       ╔════════════════════════════════════╗\n");
    printf("                                                       ║       Liste des compétitions       ║\n");
    printf("                                                       ╚════════════════════════════════════╝\n\n");    
    if (nb_competitions_ajoutes == 0) {
        printf("\n                                            Liste vide. Aucune compétition à afficher.\n");
        return;
    }
    
    for(int i = 0; i < nb_competitions_ajoutes; i++){
        printf("                                            __| |________________________________________________| |__ \n");
        printf("                                           (__   ________________________________________________   __)\n");       
        printf("                                              | |                                                | |   \n");
        printf("                                                            Identifiant : %s                           \n", (competitions+i)->id);
        printf("                                                            Nom : %s                                   \n", (competitions+i)->nom);
        printf("                                                            Saison : %s                                \n", (competitions+i)->saison);
        printf("                                                            Type : %s                                  \n", (competitions+i)->type);
        printf("                                                            Nombre de participants : %d                \n", (competitions+i)->nb_max_paticipants);
        printf("                                                            Participants :                             \n");
        if ((competitions+i)->nb_participants_ajoutes == 0) {
        printf("                                                            Aucun participant à afficher               \n");
        }
        else {
            for(int j = 0; j < (competitions+i)->nb_participants_ajoutes; j++){
        printf("                                                            - %s %d points                             \n", (competitions+i)->participants[j].nom, (competitions+i)->participants[j].points);
            }           
        } 
        printf("                                            __| |________________________________________________| |__ \n");
        printf("                                           (__   ________________________________________________   __)\n");
        printf("                                              | |                                                | |   \n");            
        puts("\n");
    }
}    

  /*=============================================/
 /    FONCTION POUR RECHERCHER UNE COMPETITON   /
/=============================================*/

void rechercher_competition(){
    effacerEcran();
    char id[15]; 
    int trouve = 0;
    printf("\n                                                       ╔════════════════════════════════════╗\n");
    printf("                                                       ║    Recherche d'une compétition     ║\n");
    printf("                                                       ╚════════════════════════════════════╝\n\n");
    if (nb_competitions_ajoutes == 0) {
        printf("\n                                            Aucune compétition enregistrée.\n");
        return;
    }
    
    printf("                                            Saisir l'identifiant de la competition: ");
    scanf(" %[^\n]", id);
    for (int i = 0; i < nb_competitions_ajoutes; i++){
        if(strcmp(id, competitions[i].id) == 0){
        trouve = 1;
        printf("                                            __| |________________________________________________| |__ \n");
        printf("                                           (__   ________________________________________________   __)\n");       
        printf("                                              | |                                                | |   \n");
        printf("                                                            Identifiant : %s                           \n", (competitions+i)->id);
        printf("                                                            Nom : %s                                   \n", (competitions+i)->nom);
        printf("                                                            Saison : %s                                \n", (competitions+i)->saison);
        printf("                                                            Type : %s                                  \n", (competitions+i)->type);
        printf("                                                            Nombre de participants : %d                \n", (competitions+i)->nb_max_paticipants);
        printf("                                                            Participants :                             \n");
        if ((competitions+i)->nb_participants_ajoutes == 0) {
        printf("                                                            Aucun participant à afficher               \n");
        }
        else {
            for(int j = 0; j < (competitions+i)->nb_participants_ajoutes; j++){
        printf("                                                            - %s %d points                             \n", (competitions+i)->participants[j].nom, (competitions+i)->participants[j].points);
            }           
        } 
        printf("                                            __| |________________________________________________| |__ \n");
        printf("                                           (__   ________________________________________________   __)\n");
        printf("                                              | |                                                | |   \n");            
        puts("\n");
        return;                        
                            
        }
    }
    if(!trouve) printf("\n                                            Aucune compétition n'est enregistrée avec cet identifiant\n");        
}

  /*=================================================/
 /   FONCTION POUR METTRE A JOUR UNE COMPETITION    /
/=================================================*/

void mise_a_jour_competition(){
    char id[15], id_participants[15]; int participant_trouve = 0, choix, competition_trouve = 0;
    effacerEcran();
    printf("\n                                                       ╔════════════════════════════════════╗\n");
    printf("                                                       ║   Mise à jour d'une compétition    ║\n");
    printf("                                                       ╚════════════════════════════════════╝\n\n");
    if (nb_competitions_ajoutes == 0)
    {
        printf("                                            Aucune compétition enregistrée\n");
        return;
    }
    printf("                                            Saisir l'identifiant de la competition: ");
    scanf(" %[^\n]", id);

    for (int i = 0; i < nb_competitions_ajoutes; i++)
    {
       if (strcmp(id, competitions[i].id) == 0)
       {
         competition_trouve++;
            printf("                                             __| |________________________________________________| |__ \n");
            printf("                                            (__   ________________________________________________   __)\n");       
            printf("                                               | |                                                | |   \n");
            printf("                                               | | 1-  Modifier le nom                            | |   \n");
            printf("                                               | | 2-  Modifier la saison                         | |   \n");
            printf("                                               | | 3-  Modifier le type                           | |   \n");
            printf("                                               | | 4-  Modifier le nombre maximal de participants | |   \n");
            printf("                                               | | 5-  Modifier un participant                    | |   \n");             
            printf("                                             __| |________________________________________________| |__ \n");
            printf("                                            (__   ________________________________________________   __)\n");
            printf("                                               | |                                                | |   \n\n");
         
         printf("                                             Choisissez une option: ");
         scanf(" %d", &choix);
         switch (choix){
         
            case 1:
                printf("                                            Saisir le nouveau nom: ");
                scanf(" %[^\n]", competitions[i]. nom);
                printf("\n                                            Modification réussie !\n");
                break;
            case 2:
                printf("                                            Mettre à jour la saison: ");
                scanf(" %[^\n]", competitions[i].saison);
                printf("\n                                            Modification réussie !\n");
                break;
            case 3:
                printf("                                            Mettre à jour le type: ");
                scanf(" %[^\n]", competitions[i].type);
                printf("\n                                            Modification réussie !\n");
                break;    
            case 4:
                printf("                                            Mettre à jour le nombre maximal de participants: ");
                scanf(" %d", &competitions[i].nb_max_paticipants);
                competitions[i].participants = realloc(competitions[i].participants, competitions[i].nb_max_paticipants * sizeof(Club));
                printf("\n                                            Modification réussie !\n");
                break;
            case 5:
                /* Si la compétition ne contient aucun participant, on ne peut pas le modifier. */
                if(competitions[i].nb_participants_ajoutes == 0){
                    printf("\n                                            Aucun participant pour cette compétition\n");
                    return;
                }            
                printf("                                            Saisir l'identifiant du participants: ");
                scanf(" %[^\n]", id_participants);
                for (int j = 0; j < competitions[i].nb_participants_ajoutes; j++)
                {
                    if(strcmp(id_participants, competitions[i].participants[j].id) > 0){
                        participant_trouve++;
                        printf("                                            Saisir le nombre de points: ");
                        scanf(" %d", &(competitions[i].participants[j].points));                        
                        printf("\n                                            Modification réussie !\n");
                    }
                }
                if(!participant_trouve) printf("\n                                            Aucun participant enregistré avec cet identifiant dans cette compétition\n");
                
                
                               
                break;            
            default:
                printf("                                            Choix invalide !");
                break;
         }
        }
       
    }
    if(!competition_trouve) printf("\n                                                    Aucune compétition n'est enregistrée avec cet identifiant.\n");
    
    
}


  /*=============================================/
 /    FONCTION POUR SUPPRIMER UNE COMPETITION   /
/=============================================*/
    
void supprimer_competiton(){
    effacerEcran();
    char id[15]; int trouve = 0;
    printf("\n                                                       ╔════════════════════════════════════╗\n");
    printf("                                                       ║   Suppression d'une compétition    ║\n");
    printf("                                                       ╚════════════════════════════════════╝\n\n");
    if(nb_competitions_ajoutes == 0){
        printf("                                            Aucune compétition enregistrée\n");
        return;
    }
    printf("                                            Saisir l'identifiant de la compétition: ");
    scanf(" %[^\n]", id);
    for(int i = 0; i < nb_competitions_ajoutes; i++){
        if(strcmp(id, (competitions + i)->id) == 0){
            trouve = 1;            
            /* On décale les éléments suivants pour retirer la compétition sélectionnée. */
            for (int j = i; j < nb_competitions_ajoutes; j++)
            {
                competitions[j] = competitions[j+1];                
                break; 
            }
            nb_competitions_ajoutes--;                        
            printf("\n                                            Compétition supprimée avec succès !\n");
            return;
        }       
    }
    if(!trouve) printf("\n                                            Aucune compétition n'est enregistrée avec cet identifiant.\n");
}

  /*==================================================================/ 
 /    FONCTION POUR SUPPRIMER UN PARTICIPANT A UNE COMPETITION       /
/==================================================================*/
void supprimer_participant(){
    effacerEcran();
    char id_competition[15], id_partcipant[15]; int competition_trouve = 0, participant_trouve = 0;
    printf("\n                                                       ╔════════════════════════════════════╗\n");
    printf("                                                       ║    Suppression d'un participant    ║\n");
    printf("                                                       ╚════════════════════════════════════╝\n\n");
    if(nb_competitions_ajoutes == 0){
        printf("                                            Impossible de supprimer un participant car aucune compétition n'est enregistrée\n");
        return;
    }
               
    printf("                                            Saisir l'identifiant de la compétition du participant: ");
    scanf(" %[^\n]", id_competition);
    for (int i = 0; i < nb_competitions_ajoutes; i++)
    {
        if(strcmp(competitions[i].id, id_competition) == 0 ){
            competition_trouve++;
            if(competitions[i].nb_participants_ajoutes == 0){
              printf("\n                                            Impossible de supprimer un participant car il n'y en a aucun");
              return;
            }
            printf("                                            Saisir l'identifiant du participant: ");
            scanf(" %[^\n]", id_partcipant);
            /* Chaque participant suivant est décalé pour compenser la suppression. */
            for (int j = 0; j < competitions[i].nb_participants_ajoutes; j++)
            {
                if(strcmp(competitions[i].participants[j].id, id_partcipant) == 0){
                    participant_trouve++;
                    for (int k = j; k < competitions[i].nb_participants_ajoutes; k++)
                    {
                        competitions[i].participants[k] = competitions[i].participants[k+1];                                                                                             
                    }
                    competitions[i].nb_participants_ajoutes--;
                    printf("\n                                            Participant supprimé avec succès\n");
                      
                }                               
            }
            if(!participant_trouve) printf("\n                                            Aucun participant enregistré avec cet identifiant dans cette compétition\n");
        }
    }
    if(!competition_trouve) printf("\n                                            Aucune compétition n'est enregistrée avec cet identifiant.\n");
    
}

  /*=========================================================/
 /          FONCTION POUR TRIER LES PARTICIPANTS            /
/=========================================================*/

void trier_participants(){
    effacerEcran();
    char id[15], *nom; int competition_trouve = 0;
    printf("\n                                                       ╔════════════════════════════════════╗\n");
    printf("                                                       ║        Tri des participants        ║\n");
    printf("                                                       ╚════════════════════════════════════╝\n\n");
    if(nb_competitions_ajoutes == 0){
        printf("\n                                            Aucune compétition enregistrée.\n");
        return;
    }
    printf("\n                                            Saisir l'identifiant de la compétition: ");
    scanf(" %[^\n]", id);
    
    for(int i = 0; i < nb_competitions_ajoutes; i++){
        if(strcmp(competitions[i].id, id) == 0){
            if(competitions[i].nb_participants_ajoutes == 0){
                printf("\n                                            Aucun participant pour cette compétition\n");
                return;
            }
            competition_trouve++; nom = competitions[i].nom;
                        
            for(int j = 0; j < competitions[i].nb_participants_ajoutes; j++){
                competitions[i].classement[j] = competitions[i].participants[j];
            }
            
           /* Tri par sélection : on place à chaque étape le participant avec le plus de points en tête du sous-tableau restant. */
            int k, max; Club tmp;
            for(k=0; k < competitions[i].nb_participants_ajoutes; k++)
            {
                max = k;
                for(int l = k+1; l < competitions[i].nb_participants_ajoutes; l++){
                    if (competitions[i].classement[max].points < competitions[i].classement[l].points)
                        max = l;
                }
                
                tmp = competitions[i].classement[k];
                competitions[i].classement[k] = competitions[i].classement[max];
                competitions[i].classement[max] = tmp;
            }
            
            
            printf("\n                                            Classement des participants de la compétition %s:\n", nom);
            for(int j = 0; j < competitions[i].nb_participants_ajoutes; j++){
                printf("                                            %d. %s - %d points\n", j + 1, competitions[i].classement[j].nom, competitions[i].classement[j].points);
        }
                                        
        }
    }
    if(!competition_trouve) printf("\n                                            Aucune compétition n'est enregistrée avec cet identifiant.\n");
    
}