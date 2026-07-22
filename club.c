#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "club.h"
#include "util.h"


Club *clubs;
int nb_clubs_ajoutes = 0, nb_max_clubs;


  /*==================================================================================================================================/
 /                                                 LA GESTION DES CLUBS                                                              /
/==================================================================================================================================*/                        

                  /*====================================================
                      FONCTION POUR AJOUTER UN CLUB
                  ====================================================*/
void ajouter_club(){
    effacerEcran();
    int retour; char cj;
    printf("\n                                                       ╔════════════════════════════════════╗\n");
    printf("                                                       ║          Ajout d'un club           ║\n");
    printf("                                                       ╚════════════════════════════════════╝\n\n");
    
    if (nb_clubs_ajoutes >= nb_max_clubs)
    {
        Club *temp = realloc(clubs, (nb_max_clubs + 1) * sizeof(Club));
        if (temp == NULL){
            printf("                                            Nombre maximal de clubs atteint (Echec de l'allocation mémoire).\n");
            return;
        }
        clubs = temp;
        nb_max_clubs++;
    }
    
    int exist; char id[15];    
    do
    {   
        exist = 0;
        printf("                                            Entrer l'identifiant du club : ");
	    scanf(" %[^\n]", id);
        for (int i = 0; i < nb_clubs_ajoutes; i++)
        {
            if(strcmp(clubs[i].id, id) == 0){
                exist = 1;
                printf("                                            Cet identifiant existe déja.\n");
                break;
            }
        }               
    } while (exist);
    strcpy((clubs+nb_clubs_ajoutes)->id, id);
    printf("                                            Entrer le nom du club : ");
    scanf(" %[^\n]", (clubs+nb_clubs_ajoutes)->nom);

    printf("                                            Entrer le jour  de création du club : ");    
    while((retour = scanf(" %d%c", &(clubs+nb_clubs_ajoutes)->dateCreation.jour, &cj)) != 2 || cj != '\n' || (clubs+nb_clubs_ajoutes)->dateCreation.jour < 1 || (clubs+nb_clubs_ajoutes)->dateCreation.jour > 31){
        printf("                                            Jour invalide.\n");
        printf("                                            Entrer le jour de création du club : ");
        nettoyer_tampon(retour, &cj);        
    }

    printf("                                            Entrer le mois de création du club : ");
    while((retour = scanf(" %d%c", &(clubs+nb_clubs_ajoutes)->dateCreation.mois, &cj)) != 2 || cj != '\n' || (clubs+nb_clubs_ajoutes)->dateCreation.mois < 1 || (clubs+nb_clubs_ajoutes)->dateCreation.mois > 12){
        printf("                                            Mois invalide.\n");
        printf("                                            Entrer le mois de création du club : ");
        nettoyer_tampon(retour, &cj);        
    }

    printf("                                            Entrer l'année de création du club : ");
    while((retour = scanf(" %d%c", &(clubs+nb_clubs_ajoutes)->dateCreation.annee, &cj)) != 2 || cj != '\n' || (clubs+nb_clubs_ajoutes)->dateCreation.annee < 1 || (clubs+nb_clubs_ajoutes)->dateCreation.annee > 2026){
        printf("                                            Année invalide.\n");
        printf("                                            Entrer l'année de création du club : ");
        nettoyer_tampon(retour, &cj);        
    }
    
    printf("                                            Entrer le siege du club : ");
    scanf(" %[^\n]", (clubs+nb_clubs_ajoutes)->adresse.siege);
    printf("                                            Entrer l'email du club : ");
    scanf(" %[^\n]", (clubs+nb_clubs_ajoutes)->adresse.email);
    printf("                                            Entrer le site web du club : ");
    scanf(" %[^\n]", (clubs+nb_clubs_ajoutes)->adresse.site_web);
    printf("                                            Entrer le nom du stade du club : ");
    scanf(" %[^\n]", (clubs+nb_clubs_ajoutes)->adresse.nom_stade);
    printf("                                            Entrer l'adresse du stade du club : ");
    scanf(" %[^\n]", (clubs+nb_clubs_ajoutes)->adresse.adresse_stade);
    printf("                                            Entrer le nom du président du club : ");
    scanf(" %[^\n]", (clubs+nb_clubs_ajoutes)->proprietaire);
    printf("                                            Entrer le nom du manager du club : ");
    scanf(" %[^\n]", (clubs+nb_clubs_ajoutes)->manager);
    printf("\n                                            Le club %s a été ajouté avec succès !\n", (clubs+nb_clubs_ajoutes)->nom);
    nb_clubs_ajoutes++;
}

                 /*=======================================
                   FONCTION POUR AFFICHER TOUS LES CLUBS
                 =======================================*/
void afficher_club(){
    effacerEcran();
    printf("\n                                                       ╔════════════════════════════════════╗\n");
    printf("                                                       ║          Liste des clubs           ║\n");
    printf("                                                       ╚════════════════════════════════════╝\n\n");    
    if (nb_clubs_ajoutes == 0) {
        printf("\n                                            Liste vide. Aucun club à afficher.\n");
        return;
    }
    
    for(int i = 0; i < nb_clubs_ajoutes; i++){
        printf("                                            __| |________________________________________________| |__ \n");
        printf("                                           (__   ________________________________________________   __)\n");       
        printf("                                              | |                                                | |   \n");
        printf("                                                          Identifiant : %s                             \n", (clubs+i)->id);
        printf("                                                          Nom : %s                                     \n", (clubs+i)->nom);
        printf("                                                          Date de creation : %02d/%02d/%04d            \n", (clubs+i)->dateCreation.jour, (clubs+i)->dateCreation.mois, (clubs+i)->dateCreation.annee);
        printf("                                                          Siège : %s                                   \n", (clubs+i)->adresse.siege);
        printf("                                                          Email : %s                                   \n", (clubs+i)->adresse.email);
        printf("                                                          Site web : %s                                \n", (clubs+i)->adresse.site_web);
        printf("                                                          Nom du stade : %s                            \n", (clubs+i)->adresse.nom_stade);
        printf("                                                          Adresse du stade : %s                        \n", (clubs+i)->adresse.adresse_stade);
        printf("                                                          Président : %s                               \n", (clubs+i)->proprietaire);
        printf("                                                          Manager : %s                                 \n", (clubs+i)->manager);
        printf("                                            __| |________________________________________________| |__ \n");
        printf("                                           (__   ________________________________________________   __)\n");
        printf("                                              | |                                                | |   \n");            
        puts("\n");
    }
}

                 /*========================================
                   FONCTION POUR RECHERCHER UN CLUB
                 ========================================*/
void rechercher_club(){
    effacerEcran();
    char id[15];
    int trouve = 0;
    printf("\n                                                       ╔════════════════════════════════════╗\n");
    printf("                                                       ║        Recherche d'un club         ║\n");
    printf("                                                       ╚════════════════════════════════════╝\n\n");
    if (nb_clubs_ajoutes == 0) {
        printf("\n                                            Aucun club enregistré.\n");
        return;
    }    
    printf("\n                                            Saisir l'identifiant du club recherché: ");    
    scanf(" %[^\n]", id);
    
                          
    for(int i = 0; i < nb_clubs_ajoutes; i++){
        
        if(strcmp(id, (clubs+i)->id) == 0){
        trouve = 1;
        printf("                                            __| |________________________________________________| |__ \n");
        printf("                                           (__   ________________________________________________   __)\n");       
        printf("                                              | |                                                | |   \n");
        printf("                                                          Identifiant : %s                             \n", (clubs+i)->id);
        printf("                                                          Nom : %s                                     \n", (clubs+i)->nom);
        printf("                                                          Date de creation : %02d/%02d/%04d            \n", (clubs+i)->dateCreation.jour, (clubs+i)->dateCreation.mois, (clubs+i)->dateCreation.annee);
        printf("                                                          Siège : %s                                   \n", (clubs+i)->adresse.siege);
        printf("                                                          Email : %s                                   \n", (clubs+i)->adresse.email);
        printf("                                                          Site web : %s                                \n", (clubs+i)->adresse.site_web);
        printf("                                                          Nom du stade : %s                            \n", (clubs+i)->adresse.nom_stade);
        printf("                                                          Adresse du stade : %s                        \n", (clubs+i)->adresse.adresse_stade);
        printf("                                                          Président : %s                               \n", (clubs+i)->proprietaire);
        printf("                                                          Manager : %s                                 \n", (clubs+i)->manager);
        printf("                                            __| |________________________________________________| |__ \n");
        printf("                                           (__   ________________________________________________   __)\n");
        printf("                                              | |                                                | |   \n");            
        puts("\n");
        return;
        }       
    }
    if (!trouve) {
        printf("\n                                            Aucun club enregistré avec cet identifiant\n");
    }
}

                 /*========================================/
                /   FONCTION POUR SUPPRIMER UN CLUB       /
               /========================================*/ 
void supprimer_club(){
    effacerEcran();
    char id[15];
    int trouve = 0;
    printf("\n                                                       ╔════════════════════════════════════╗\n");
    printf("                                                       ║       Suppression d'un club        ║\n");
    printf("                                                       ╚════════════════════════════════════╝\n\n");
    if (nb_clubs_ajoutes == 0) {
        printf("\n                                            Aucun club enregistré.\n");
        return;
    }
    printf("                                            Saisir l'identifiant du club à supprimer: ");
    scanf(" %[^\n]", id);
    for(int i = 0; i < nb_clubs_ajoutes; i++){
        if(strcmp(id, (clubs+i)->id) == 0){
            trouve = 1;            
            for (int j = i; j < nb_clubs_ajoutes - 1; j++){
                clubs[j] = clubs[j+1];
            }            
            nb_clubs_ajoutes--;
            printf("\n                                            Club supprimé avec succès\n");
            return;
        }       
    }
    if (!trouve) {
        printf("\n                                            Aucun club enregistré avec cet identifiant.\n");
    }    
}

                    /*===================================================/
                   /       FONCTION POUR METTRE A JOUR UN CLUB          /
                  /===================================================*/
void mise_a_jour_club(){
    effacerEcran();
    char id[15]; int choix, trouve = 0; int retour; char cj;
    printf("\n                                                       ╔════════════════════════════════════╗\n");
    printf("                                                       ║       Mise à jour d'un club        ║\n");
    printf("                                                       ╚════════════════════════════════════╝\n\n");
    if (nb_clubs_ajoutes == 0) {
        printf("\n                                            Aucun club enregistré.\n");
        return;
    }
    printf("                                            Saisir l'identifiant du club: ");
    scanf(" %[^\n]", id);
    for(int i = 0; i < nb_clubs_ajoutes; i++){
        if(strcmp(id, (clubs+i)->id) == 0){
            trouve = 1;
            printf("                                             __| |________________________________________________| |__ \n");
            printf("                                            (__   ________________________________________________   __)\n");       
            printf("                                               | |                                                | |   \n");
            printf("                                               | | 1-  Mettre à jour le nom                       | |   \n");
            printf("                                               | | 2-  Metrre à jour la date de création          | |   \n");
            printf("                                               | | 3-  Metrre à jour le siège                     | |   \n");
            printf("                                               | | 4-  Mettre à jour l'email                      | |   \n");
            printf("                                               | | 5-  Mettre à jour le site web                  | |   \n");
            printf("                                               | | 6-  Mettre à jour le nom du stade              | |   \n");
            printf("                                               | | 7-  Mettre à jour l'adresse du stade           | |   \n");
            printf("                                               | | 8-  Mettre à jour le président                 | |   \n");
            printf("                                               | | 9-  Mettre à jour le manager                   | |   \n");             
            printf("                                             __| |________________________________________________| |__ \n");
            printf("                                            (__   ________________________________________________   __)\n");
            printf("                                               | |                                                | |   \n\n"); 
            
            printf("                                            Choisissez une option: ");
            scanf(" %d", &choix); 
            switch (choix)
            {
            case 1:
                printf("                                            Saisir le nouveau nom: ");
                scanf(" %[^\n]", (clubs+i)->nom);
                printf("\n                                            Modification réussie !\n");
                break;    
            case 2:
                printf("                                            Saisir la nouvelle date de création\n");

                printf("                                            Entrer le jour  de création du club : ");    
                while((retour = scanf(" %d%c", &(clubs+i)->dateCreation.jour, &cj)) != 2 || cj != '\n' || (clubs+i)->dateCreation.jour < 1 || (clubs+i)->dateCreation.jour > 31){
                    printf("                                            Jour invalide.\n");
                    printf("                                            Entrer le jour de création du club : ");
                    nettoyer_tampon(retour, &cj);        
                }

                printf("                                            Entrer le mois de création du club : ");
                while((retour = scanf(" %d%c", &(clubs+i)->dateCreation.mois, &cj)) != 2 || cj != '\n' || (clubs+i)->dateCreation.mois < 1 || (clubs+i)->dateCreation.mois > 12){
                    printf("                                            Mois invalide.\n");
                    printf("                                            Entrer le mois de création du club : ");
                    nettoyer_tampon(retour, &cj);        
                }

                printf("                                            Entrer l'année de création du club : ");
                while((retour = scanf(" %d%c", &(clubs+i)->dateCreation.annee, &cj)) != 2 || cj != '\n' || (clubs+i)->dateCreation.annee < 1 || (clubs+i)->dateCreation.annee > 2026){
                    printf("                                            Année invalide.\n");
                    printf("                                            Entrer l'année de création du club : ");
                    nettoyer_tampon(retour, &cj);        
                }
                
                printf("\n                                            Modification réussie !\n");
                break;
            case 3:
                printf("                                            Saisir le nouveau siège du club: ");
                scanf(" %[^\n]", (clubs+i)->adresse.siege);
                printf("\n                                            Modification réussie !\n");
                break;
            case 4:
                printf("                                            Saisir le nouvel email du club: ");
                scanf(" %[^\n]", (clubs+i)->adresse.email);
                printf("\n                                            Modification réussie !\n");
                break;
            case 5:
                printf("                                            Saisir le nouveau site web du club: ");
                scanf(" %[^\n]", (clubs+i)->adresse.site_web);
                printf("\n                                            Modification réussie !\n");
                break;
            case 6:
                printf("                                            Saisir le nouveau nom du stade du club: ");
                scanf(" %[^\n]", (clubs+i)->adresse.nom_stade);
                printf("\n                                            Modification réussie !\n");
                break;
            case 7:
                printf("                                            Saisir la nouvelle adresse du stade du club: ");
                scanf(" %[^\n]", (clubs+i)->adresse.adresse_stade);
                printf("\n                                            Modification réussie !\n");
                break;
            case 8:
                printf("                                            Saisir le nouveau président du club: ");
                scanf(" %[^\n]", (clubs+i)->proprietaire);
                printf("\n                                            Modification réussie !\n");
                break;
            case 9:
                printf("                                            Saisir le nouveau manager du club: ");
                scanf(" %[^\n]", (clubs+i)->manager);
                printf("\n                                            Modification réussie !\n");
                break;
            default:
                printf("                                            Choix invalide\n");
                break;
            }
        }                  
    }
	if(!trouve){
		printf("\n                                            Aucun club enregistré avec cet identifiant.\n");
	}    

}

                /*====================================================/
               /     FONCTION POUR TRIER LES CLUBS SELON LEURS ID    /
              /====================================================*/
void trier_clubs_par_id(){
    effacerEcran();
    printf("\n                                                       ╔════════════════════════════════════╗\n");
    printf("                                                       ║    Tri des clubs par identifant    ║\n");
    printf("                                                       ╚════════════════════════════════════╝\n\n");
    if(nb_clubs_ajoutes == 0){
    	printf("                                            Aucun club enregistré\n");
    	return;
	}
    int i,j, min; Club c;
    for(i=0;i<nb_clubs_ajoutes;i++)
    {
        min = i;
        for(j=i+1;j<nb_clubs_ajoutes; j++){
            if (strcmp(clubs[min].id, clubs[j].id) == 1)
                min = j;
        }
        c = clubs[i];
        clubs[i] = clubs[min];
            clubs[min] = c;
    }
    printf("                                            Clubs triés avec succès");
}

                /*====================================================/
               /    FONCTION POUR TRIER LES CLUBS SELON LEURS NOMS   /
              /====================================================*/
void trier_clubs_par_nom(){
    effacerEcran();
    printf("\n                                                       ╔════════════════════════════════════╗\n");
    printf("                                                       ║       Tri des clubs par nom        ║\n");
    printf("                                                       ╚════════════════════════════════════╝\n\n");
    if(nb_clubs_ajoutes == 0){
    	printf("                                            Aucun club enregistré\n");
    	return;
	}
    int i,j; Club c;
    for(j=1;j<=nb_clubs_ajoutes;j++){ 
      for(i=0;i<nb_clubs_ajoutes-1;i++)
      {
        if (strcmp(clubs[i].nom, clubs[i+1].nom) == 1)
        {
          c = clubs[i];
          clubs[i] = clubs[i+1];
          clubs[i+1] = c;
        }
      }
    }
    printf("                                            Clubs triés avec succès");
}

  /*=========================================================/
 /    FONCTION POUR AJOUTER DES JOUEURS DANS UN CLUB        /
/=========================================================*/

void ajouter_joueur_club(){
	effacerEcran();
    printf("\n                                                       ╔════════════════════════════════════╗\n");
    printf("                                                       ║   Ajout d'un joueur dans un club   ║\n");
    printf("                                                       ╚════════════════════════════════════╝\n\n");
	if(nb_clubs_ajoutes == 0){
        printf("                                            Aucun club enregistré\n"); 
        return;       
    }

    if(nb_joueurs_ajoutes == 0){
        printf("                                            Aucun joueur enregistré\n");
        return;
    }

    char id_club[15], id_joueur[15];
    int club_trouve = 0, joueur_trouve = 0;
    printf("                                            Saisir l'identifiant du club: ");
    scanf(" %[^\n]", id_club);
    for(int i = 0; i < nb_clubs_ajoutes; i++){
    	if(strcmp(clubs[i].id, id_club) == 0){
            club_trouve = 1;
    		printf("                                            Saisir l'identifiant du joueur: ");
    		scanf(" %[^\n]", id_joueur);
            for (int k = 0; k < clubs[i].nb_pensionnaires_ajoutes; k++)
            {
                if(strcmp(id_joueur, clubs[i].pensionnaires[k].id) == 0){
                    printf("\n                                            Ce joueur est déjà pensionnaire de ce club\n");
                    return;
                }
            }
            
    		for(int j = 0; j < nb_joueurs_ajoutes; j++){
    			if(strcmp(id_joueur, joueurs[j].id) == 0){
                    joueur_trouve = 1;
                    clubs[i].pensionnaires = realloc(clubs[i].pensionnaires, (clubs[i].nb_pensionnaires_ajoutes + 1) * sizeof(Joueur));
                    clubs[i].pensionnaires[clubs[i].nb_pensionnaires_ajoutes] = joueurs[j];                    
                    clubs[i].nb_pensionnaires_ajoutes++;

                    printf("\n                                            %s %s a été ajouté dans le club %s", joueurs[j].prenom, joueurs[j].nom, clubs[i].nom);
                }
			}
            if(!joueur_trouve){
                printf("\n                                            Aucun joueur enregistré avec cet identifiant\n");
            }
            break;
		}
	}
    if(!club_trouve){
        printf("\n                                            Aucun club enregistré avec cet identifiant\n", id_club);
    }
    
}

  /*=========================================================/
 /    FONCTION POUR AFFICHER LES JOUEURS D'UN CLUB          /
/=========================================================*/
void afficher_joueur_du_club(){
    effacerEcran();
    printf("\n                                                       ╔════════════════════════════════════╗\n");
    printf("                                                       ║  Affichage des joueurs  d'un club  ║\n");
    printf("                                                       ╚════════════════════════════════════╝\n\n");
    char id[15]; int club_trouve = 0;
    printf("                                            Saisir l'identifiant du club: ");
    scanf(" %[^\n]", id);
    for(int i = 0; i < nb_clubs_ajoutes; i++){
        if(strcmp(id, clubs[i].id) == 0){
            club_trouve = 1;
            printf("\n                                            Joueurs du club %s \n", clubs[i].nom);
            if (clubs[i].nb_pensionnaires_ajoutes == 0) {
                printf("                                            Aucun joueur à afficher pour ce club.\n");
                return;
            }
            for(int j = 0; j < clubs[i].nb_pensionnaires_ajoutes; j++){
                printf("                                            - %s %s\n", clubs[i].pensionnaires[j].prenom, clubs[i].pensionnaires[j].nom);
            }
        }
    }
    if(!club_trouve) printf("\n                                            Aucun club enregistré avec cet identifiant\n");
}  

