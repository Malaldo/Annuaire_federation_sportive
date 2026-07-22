#include "joueur.h"
#include "structures.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/*********************************************************************************************************************************
*                                                LA GESTION DES JOUEURS                                                          *
*********************************************************************************************************************************/

Joueur *joueurs;
int nb_joueurs_ajoutes = 0, nb_joueurs_max;

                                /*=======================================
                                      FONCTION POUR AJOUTER JOUEUR
                                ========================================*/
void ajouter_joueur(){
    
    effacerEcran();
    printf("\n                                                       ╔════════════════════════════════════╗\n");
    printf("                                                       ║          Ajout d'un joueur         ║\n");
    printf("                                                       ╚════════════════════════════════════╝\n\n");

    if (nb_joueurs_ajoutes >= nb_joueurs_max) {
        Joueur *temp = realloc(joueurs, (nb_joueurs_max + 1) * sizeof(Joueur));
        if (temp == NULL) {
            printf("                                            Nombre maximal de joueurs atteint (Echec de l'allocation mémoire).\n");
            return;
        }
        joueurs = temp;
        nb_joueurs_max++;
    }
    int exist; char id[15];    
    do
    {   
        exist = 0;
        printf("                                            Entrer l'identifiant du joueur : ");
	    scanf(" %[^\n]", id);
        for (int i = 0; i < nb_joueurs_ajoutes; i++)
        {
            if(strcmp(joueurs[i].id, id) == 0){
                exist = 1;
                printf("\n                                            Cet identifiant existe déja.\n");
                break;
            }
        }               
    } while (exist);

    strcpy((joueurs+nb_joueurs_ajoutes)->id, id);    
    printf("                                            Entrer le prénom du joueur : ");
	scanf(" %[^\n]", (joueurs+nb_joueurs_ajoutes)->prenom); 
	printf("                                            Entrer le nom du joueur : ");
	scanf(" %[^\n]", (joueurs+nb_joueurs_ajoutes)->nom);
    int retour; char cj; 
	
    printf("                                            Entrer le jour de naissance du joueur : ");
    while((retour = scanf(" %d%c", &(joueurs+nb_joueurs_ajoutes)->dateNaissance.jour, &cj)) != 2 || cj != '\n' || (joueurs+nb_joueurs_ajoutes)->dateNaissance.jour < 1 || (joueurs+nb_joueurs_ajoutes)->dateNaissance.jour > 31){
        printf("                                            Jour invalide.\n");
        printf("                                            Entrer le jour de naissance du joueur : ");
        nettoyer_tampon(retour, &cj);        
    }

    printf("                                            Entrer le mois de naissance du joueur : ");
    while((retour = scanf(" %d%c", &(joueurs+nb_joueurs_ajoutes)->dateNaissance.mois, &cj)) != 2 || cj != '\n' || (joueurs+nb_joueurs_ajoutes)->dateNaissance.mois < 1 || (joueurs+nb_joueurs_ajoutes)->dateNaissance.mois > 12){
        printf("                                            Mois invalide.\n");
        printf("                                            Entrer le mois de naissance du joueur : ");
        nettoyer_tampon(retour, &cj);        
    }

    printf("                                            Entrer l'année de naissance du joueur : ");
    while((retour = scanf(" %d%c", &(joueurs+nb_joueurs_ajoutes)->dateNaissance.annee, &cj)) != 2 || cj != '\n' || (joueurs+nb_joueurs_ajoutes)->dateNaissance.annee < 1 || (joueurs+nb_joueurs_ajoutes)->dateNaissance.annee > 2026){
        printf("                                            Année invalide.\n");
        printf("                                            Entrer l'année de naissance du joueur : ");
        nettoyer_tampon(retour, &cj);        
    }
                     
	printf("                                            Entrer la nationalité du joueur : ");
	scanf(" %[^\n]", (joueurs+nb_joueurs_ajoutes)->nationalite); 
	printf("                                            Entrer la catégorie du joueur : ");
	scanf(" %[^\n]", (joueurs+nb_joueurs_ajoutes)->categorie); 
	printf("                                            Entrer le poste du joueur : ");
	scanf(" %[^\n]", (joueurs+nb_joueurs_ajoutes)->poste);
	printf("                                            Entrer le club actuel du joueur : ");
    scanf(" %[^\n]", (joueurs+nb_joueurs_ajoutes)->clubActuel);  
    puts("\n");  
    printf("                                            %s %s a été ajouté avec succès !\n", (joueurs+nb_joueurs_ajoutes)->prenom, (joueurs+nb_joueurs_ajoutes)->nom);
    nb_joueurs_ajoutes++; 
}

                                     /*===============================================
                                          FONCTION POUR AFFICHER TOUS LES JOUEURS
                                     ================================================*/
void liste_joueurs(){
    effacerEcran();
    
    printf("\n                                                       ╔════════════════════════════════════╗\n");
    printf("                                                       ║         Liste des joueurs          ║\n");
    printf("                                                       ╚════════════════════════════════════╝\n\n");
    if (nb_joueurs_ajoutes == 0) {
        printf("                                            Liste vide. Aucun joueur à afficher.\n");
        return;
    }
    puts("\n");
    for(int i = 0; i < nb_joueurs_ajoutes; i++){
        printf("                                            __| |________________________________________________| |__ \n");
        printf("                                           (__   ________________________________________________   __)\n");       
        printf("                                              | |                                                | |   \n");
        printf("                                                          IDENTIFIANT : %s                                              \n", (joueurs+i)->id);
        printf("                                                          PRENOM: %s                                           \n", (joueurs+i)->prenom);
        printf("                                                          Nom : %s                                             \n", (joueurs+i)->nom);
        printf("                                                          Date de naissance : %02d/%02d/%04d                   \n", (joueurs+i)->dateNaissance.jour, (joueurs+i)->dateNaissance.mois, (joueurs+i)->dateNaissance.annee);
        printf("                                                          Nationalité : %s                                     \n", (joueurs+i)->nationalite);
        printf("                                                          Catégorie : %s                                       \n", (joueurs+i)->categorie);
        printf("                                                          Poste : %s                                           \n", (joueurs+i)->poste);             
        printf("                                                          Club actuel : %s                                     \n", (joueurs+i)->clubActuel);
        printf("                                            __| |________________________________________________| |__ \n");
        printf("                                           (__   ________________________________________________   __)\n");
        printf("                                              | |                                                | |   \n");
        puts("\n");    
    }
    
}
                            /*======================================
                                FONCTION POUR RECHERCHER UN JOUEUR
                            =======================================*/
void rechercher_joueur(){
    effacerEcran();
    char id[15];
    int trouve = 0;
    printf("\n                                                       ╔════════════════════════════════════╗\n");
    printf("                                                       ║       Recherche d'un joueur        ║\n");
    printf("                                                       ╚════════════════════════════════════╝\n\n");
    if (nb_joueurs_ajoutes == 0) {
        printf("                                            Aucun joueur enregistré.\n");
        return;
    }    
    printf("\n                                            Saisir l'identifiant du joueur recherché: ");    
    scanf(" %[^\n]", id);
    puts("\n");                              
    for(int i = 0; i < nb_joueurs_ajoutes; i++){
        if(strcmp(id, (joueurs+i)->id) == 0){                        
        printf("                                            __| |________________________________________________| |__ \n");
        printf("                                           (__   ________________________________________________   __)\n");       
        printf("                                              | |                                                | |   \n");
        printf("                                                          IDENTIFIANT : %s                             \n", (joueurs+i)->id);
        printf("                                                          PRENOM: %s                                   \n", (joueurs+i)->prenom);
        printf("                                                          Nom : %s                                     \n", (joueurs+i)->nom);
        printf("                                                          Date de naissance : %02d/%02d/%04d           \n", (joueurs+i)->dateNaissance.jour, (joueurs+i)->dateNaissance.mois, (joueurs+i)->dateNaissance.annee);
        printf("                                                          Nationalité : %s                             \n", (joueurs+i)->nationalite);
        printf("                                                          Catégorie : %s                               \n", (joueurs+i)->categorie);
        printf("                                                          Poste : %s                                   \n", (joueurs+i)->poste);             
        printf("                                                          Club actuel : %s                             \n", (joueurs+i)->clubActuel);
        printf("                                            __| |________________________________________________| |__ \n");
        printf("                                           (__   ________________________________________________   __)\n");
        printf("                                              | |                                                | |   \n");
        puts("\n");            
            trouve = 1;
            return;
        }       
    }
    if (!trouve) {
        puts("\n");
        printf("                                            Aucun joueur enregistré avec cette identifiant.\n");
    }
}

                    /*==================================
                      FONCTION POUR SUPPRIMER UN JOUEUR 
                    ===================================*/
void supprimer_joueur(){
    effacerEcran();
    char id[15];
    int trouve = 0;
    printf("\n                                                       ╔════════════════════════════════════╗\n");
    printf("                                                       ║      Suppression d'un joueur       ║\n");
    printf("                                                       ╚════════════════════════════════════╝\n\n");
    if (nb_joueurs_ajoutes == 0) {
        printf("                                            Aucun joueur enregistré.\n");
        return;
    }
    printf("\n                                            Saisir l'id du joeueur à supprimer: ");    
    scanf(" %[^\n]", id);    
    for(int i = 0; i < nb_joueurs_ajoutes; i++){        
        if(strcmp(id, (joueurs+i)->id) == 0){
            trouve = 1;                        
            for (int j = i; j < nb_joueurs_ajoutes - 1; j++)
            {
                joueurs[j] = joueurs[j+1];                                 
            }                        
            nb_joueurs_ajoutes--;
            printf("\n                                            Joueur supprimé avec succès\n");
            return;
        }       
    }
    if (!trouve) {
        puts("\n");
        printf("                                            Aucun joueur enregistré avec cet identifiant \n");
    }
}

                        /*=======================================
                          FONCTION POUR METTRE A JOUR UN JOUEUR
                        ========================================*/
void mise_a_jour_joueur(){
    effacerEcran();
    char id[15]; int choix, trouve = 0; int retour; char cj;
    printf("\n                                                       ╔════════════════════════════════════╗\n");
    printf("                                                       ║      Mise à jour d'un joueur       ║\n");
    printf("                                                       ╚════════════════════════════════════╝\n\n");
    if (nb_joueurs_ajoutes == 0) {
        printf("                                            Aucun joueur enregistré.\n");
        return;
    }
    printf("                                            Saisir l'identifiant du joueur: ");
    scanf(" %[^\n]", id);
    for(int i = 0; i < nb_joueurs_ajoutes; i++){        
        if(strcmp(id, (joueurs+i)->id) == 0){
            trouve = 1;
            printf("                                             __| |________________________________________________| |__ \n");
            printf("                                            (__   ________________________________________________   __)\n");       
            printf("                                               | |                                                | |   \n");
            printf("                                               | | 1-  Mettre à jour le prénom                    | |   \n");
            printf("                                               | | 2-  Mettre à jour le nom                       | |   \n");
            printf("                                               | | 3-  Metrre à jour la date de naissance         | |   \n");
            printf("                                               | | 4-  Mettre à jour la categorie                 | |   \n");
            printf("                                               | | 5-  Mettre à jour le poste                     | |   \n");
            printf("                                               | | 6-  Mettre à jour la nationalité               | |   \n");             
            printf("                                             __| |________________________________________________| |__ \n");
            printf("                                            (__   ________________________________________________   __)\n");
            printf("                                               | |                                                | |   \n\n");                        
            printf("                                            Choisissez une option: ");
            scanf(" %d", &choix); 
            switch (choix)
            {
            case 1:
                printf("                                            Saisir le nouveau prénom: ");
                scanf(" %[^\n]", (joueurs+i)->prenom); puts("\n");
                printf("\n                                            Modification réussie !\n");
                break;    
            case 2:
                printf("                                            Saisir le nouveau nom: ");
                scanf(" %[^\n]", (joueurs+i)->nom); puts("\n");
                printf("                                            Modification réussie !\n");
                break;
            case 3:
                printf("                                            Saisir la nouvelle date de naissance\n");
                printf("                                            Saisir le jour de naissance du joueur : ");
                while((retour = scanf(" %d%c", &(joueurs+i)->dateNaissance.jour, &cj)) != 2 || cj != '\n' || (joueurs+i)->dateNaissance.jour < 1 || (joueurs+i)->dateNaissance.jour > 31){
                    printf("                                            Jour invalide.\n");
                    printf("                                            Entrer le jour de naissance du joueur : ");
                    nettoyer_tampon(retour, &cj);        
                }

                printf("                                            Saisir le mois de naissance du joueur : ");
                while((retour = scanf(" %d%c", &(joueurs+i)->dateNaissance.mois, &cj)) != 2 || cj != '\n' || (joueurs+i)->dateNaissance.mois < 1 || (joueurs+i)->dateNaissance.mois > 12){
                    printf("                                            Mois invalide.\n");
                    printf("                                            Entrer le mois de naissance du joueur : ");
                    nettoyer_tampon(retour, &cj);        
                }

                printf("                                            Saisir l'année de naissance du joueur : ");
                while((retour = scanf(" %d%c", &(joueurs+i)->dateNaissance.annee, &cj)) != 2 || cj != '\n' || (joueurs+i)->dateNaissance.annee < 1 || (joueurs+i)->dateNaissance.annee > 2026){
                    printf("                                            Jour invalide.\n");
                    printf("                                            Entrer l'année de naissance du joueur : ");
                    nettoyer_tampon(retour, &cj);        
                }
                //scanf(" %d %d %d", &(joueurs+i)->dateNaissance.jour, &(joueurs+i)->dateNaissance.mois, &(joueurs+i)->dateNaissance.annee);
                puts("\n");
                printf("\n                                            Modification réussie !\n");
                break;
            case 4:
                printf("                                            Saisir la nouvelle catégorie du joueur: ");
                scanf(" %[^\n]", (joueurs+i)->categorie); puts("\n");
                printf("\n                                            Modification réussie !\n");
                break;
            case 5:
                printf("                                            Saisir le nouveau poste: ");
                scanf(" %[^\n]", (joueurs+i)->poste); puts("\n");
                printf("\n                                            Modification réussie !\n");
                break;
            case 6:
                printf("                                            Saisir la nouvelle nationalité: ");
                scanf(" %[^\n]", (joueurs+i)->nationalite); puts("\n");
                printf("\n                                            Modification réussie !\n");
                break;
                                
            default:
                printf("                                            Choix invalide\n");
                break;
            }
            
            break;
        } 
             
    }
    if(!trouve){
        puts("\n");
        printf("                                            Aucun joueur enregistré avec cet identifiant\n");
    }  

    
}

                        /*===========================================================================
                              FONCTION POUR TRIER LES JOUEURS SELON LEURS ID, TRIE PAR SELECTION
                        ===========================================================================*/
void trier_joueurs_par_id(){
    effacerEcran();

    printf("\n                                                       ╔════════════════════════════════════╗\n");
    printf("                                                       ║  Tri des joueurs par identifiant   ║\n");
    printf("                                                       ╚════════════════════════════════════╝\n\n");
    if(nb_joueurs_ajoutes == 0){
    	printf("                                            Aucun joueur enregistré\n");
    	return;
	}
    int i,j, min; Joueur tmp;
    for(i=0;i<nb_joueurs_ajoutes;i++)
    {
        min = i;
        for(j=i+1;j<nb_joueurs_ajoutes; j++){
            if (strcmp(joueurs[min].id, joueurs[j].id) > 0)
                min = j;
        }
        tmp = joueurs[i];
        joueurs[i] = joueurs[min];
            joueurs[min] = tmp;
    }
    printf("                                            Joueurs triés avec succès\n");
}
                  /*====================================================
                      FONCTION POUR TRIER LES JOUEURS SELON LEURS NOMS
                  ====================================================*/
void trier_joueurs_par_nom(){
    effacerEcran();
    printf("\n                                                       ╔════════════════════════════════════╗\n");
    printf("                                                       ║      Tri des joueurs par nom       ║\n");
    printf("                                                       ╚════════════════════════════════════╝\n\n");
    if(nb_joueurs_ajoutes == 0){
    	printf("                                            Aucun joueur enregistré\n");
    	return;
	}
    int i,j; Joueur c;
    for(j=1;j<=nb_joueurs_ajoutes;j++){ 
      for(i=0;i<nb_joueurs_ajoutes-1;i++)
      {
        if ( strcmp(joueurs[i].nom, joueurs[i+1].nom) > 0)
        {
          c = joueurs[i];
          joueurs[i] = joueurs[i+1];
          joueurs[i+1] = c;
        }
      }
    printf("                                            Joueurs triés avec succès\n");
    }
}