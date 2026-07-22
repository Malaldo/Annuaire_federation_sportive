#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <Windows.h>
#include "joueur.h"
#include "competition.h"
#include "club.h"
#include "util.h"


int main(void){
    
    SetConsoleOutputCP(65001); SetConsoleCP(65001);
    setlocale(LC_ALL, "fr_FR.UTF-8");
    //AfficherTexteEnBlanc();
    system("title ANNUAIRE FEDERATION SPORTIVE");
    
    message_d_accueil();
    continuer();
    
    effacerEcran(); 
    printf("\n                                                       ╔════════════════════════════════════╗\n");
    printf("                                                       ║      CONFIGURATION DU SYSTÈME      ║\n");
    printf("                                                       ╚════════════════════════════════════╝\n\n");
    char cj;
    int retour;
       
    printf("                                                      Saisir le nombre maximal de joueurs : ");
        
    while((retour = scanf(" %d%c", &nb_joueurs_max, &cj)) != 2  || nb_joueurs_max <= 0 || cj != '\n'){
        printf("\n                                                      Entrée invalide. Veuillez entrer un nombre entier stricetement positif.\n\n");
        printf("                                                      Saisir le nombre maximal de joueurs: ");
        nettoyer_tampon(retour, &cj);
    }       
    printf("\n");
    
    printf("                                                      Saisir le nombre maximal de clubs: ");
    while((retour =scanf(" %d%c", &nb_max_clubs, &cj)) != 2 || nb_max_clubs <= 0 || cj != '\n') {
        printf("\n                                                      Entrée invalide. Veuillez entrer un nombre entier stricetement positif.\n\n");
        printf("                                                      Saisir le nombre maximal de clubs: ");
        nettoyer_tampon(retour, &cj);
    }
    
    printf("\n");
       
    printf("                                                      Saisir le nombre maximal de compétition: ");
    while((retour = scanf(" %d%c", &nb_max_competitions, &cj)) != 2 || nb_max_competitions <= 0 || cj != '\n') {
        printf("\n                                                      Entrée invalide. Veuillez entrer un nombre entier stricetement positif.\n\n");
        printf("                                                      Saisir le nombre maximal de compétition: ");
        nettoyer_tampon(retour, &cj);
    }

    joueurs = (Joueur *)malloc(nb_joueurs_max * sizeof(Joueur));
    clubs = (Club *)malloc(nb_max_clubs * sizeof(Club));
    competitions = (Competition *)malloc(nb_max_competitions * sizeof(Competition));
    printf("\n                                                                Configuration en cours... ");
    for(int i = 0; i < 3; i++) {
        Sleep(300);
        printf(".");
        fflush(stdout);
    }

    puts("\n");

    int choix, choix_joeurs, choix_clubs, choix_competitions; 
    do{
        effacerEcran();
        AfficherTexteEnBlanc();
        printf("\n                                                       ╔════════════════════════════════════╗\n");
        printf("                                                       ║          MENU PRINCIPALE           ║\n");
        printf("                                                       ╚════════════════════════════════════╝\n\n");

        printf("                                             __| |________________________________________________| |__ \n");
        printf("                                            (__   ________________________________________________   __)\n");       
        printf("                                               | |                                                | |   \n");
        printf("                                               | |            1- Menu joueurs                     | |   \n");
        printf("                                               | |            2- Menu clubs                       | |   \n");
        printf("                                               | |            3- Menu compétitions                | |   \n");
        printf("                                               | |            4- Aller à l'accueil                | |   \n");
        printf("                                               | |            5- QUITTER                          | |   \n");
        printf("                                             __| |________________________________________________| |__ \n");
        printf("                                            (__   ________________________________________________   __)\n");
        printf("                                               | |                                                | |   \n");
        puts("\n");
        printf("                                            Choisissez une option: ");
        scanf(" %d", &choix);
        effacerEcran();
    
        switch (choix)
        {
            case 1:
                AfficherTexteEnVert();
            	printf("\n                                                       ╔════════════════════════════════════╗\n");
                printf("                                                       ║            MENU JOUEURS            ║\n");
                printf("                                                       ╚════════════════════════════════════╝\n\n");

                printf("                                             __| |________________________________________________| |__ \n");
                printf("                                            (__   ________________________________________________   __)\n");       
                printf("                                               | |                                                | |   \n");
                printf("                                               | | 1-  Ajouter un joueur                          | |   \n");
                printf("                                               | | 2-  Afficher tous les joueurs                  | |   \n");
                printf("                                               | | 3-  Rechercher un joueur                       | |   \n");
                printf("                                               | | 4-  Supprimer un joueur                        | |   \n");
                printf("                                               | | 5-  Mettre à jour un joueur                    | |   \n");
                printf("                                               | | 6-  Trier les joueurs par id                   | |   \n");
                printf("                                               | | 7-  Trier les joueurs par nom                  | |   \n");
                printf("                                             __| |________________________________________________| |__ \n");
                printf("                                            (__   ________________________________________________   __)\n");
                printf("                                               | |                                                | |   \n");
                puts("\n");
                printf("                                            Choisissez une option: ");
                scanf(" %d", &choix_joeurs);
                switch (choix_joeurs)
                {
                    case 1:
                        
                        ajouter_joueur();
                        break;
                    case 2:
                        liste_joueurs();
                        break;
                    case 3:
                        rechercher_joueur();
                        break;
                    case 4:
                        supprimer_joueur();
                        break;
                    case 5:
                        mise_a_jour_joueur();
                        break;  
                    case 6:
                        trier_joueurs_par_id();
                        break;
                    case 7:
                        trier_joueurs_par_nom();
                        break;            
                    default:
                        printf("                                            Choix invalide\n");
                        break;
                }
                break;
            case 2:
                AfficherTexteEnBleu();
            	printf("\n                                                       ╔════════════════════════════════════╗\n");
                printf("                                                       ║             MENU CLUBS             ║\n");
                printf("                                                       ╚════════════════════════════════════╝\n\n");

                printf("                                             __| |________________________________________________| |__ \n");
                printf("                                            (__   ________________________________________________   __)\n");       
                printf("                                               | |                                                | |   \n");
                printf("                                               | | 1-  Ajouter un club                            | |   \n");
                printf("                                               | | 2-  Afficher tous les clubs                    | |   \n");
                printf("                                               | | 3-  Rechercher un club                         | |   \n");
                printf("                                               | | 4-  Supprimer un club                          | |   \n");
                printf("                                               | | 5-  Mettre à jour un club                      | |   \n");
                printf("                                               | | 6-  Trier les clubs par id                     | |   \n");
                printf("                                               | | 7-  Trier les clubs par nom                    | |   \n");
                printf("                                               | | 8-  Ajouter un joueur dans un club             | |   \n");
                printf("                                               | | 9-  Afficher les joueurs d'un club             | |   \n");
                printf("                                             __| |________________________________________________| |__ \n");
                printf("                                            (__   ________________________________________________   __)\n");
                printf("                                               | |                                                | |   \n");
                
                puts("\n");
                printf("                                            Choisissez une option: ");
                scanf(" %d", &choix_clubs);
                switch (choix_clubs)
                {
                    case 1:
                        ajouter_club();
                        break;
                    case 2:
                        afficher_club();
                        break;
                    case 3:
                        rechercher_club();
                        break;
                    case 4: 
                        supprimer_club();
                        break;  
                    case 5:
                        mise_a_jour_club();
                        break;
                    case 6:
                        trier_clubs_par_id();
                        break;
                    case 7:
                        trier_clubs_par_nom();
                        break;
                    case 8:
                        ajouter_joueur_club();
                        break;
                    case 9:
                        afficher_joueur_du_club();
                        break;                    
                    default:
                        printf("                                            Choix invalide\n");
                        break;
                }   
                break;            
            case 3:
                AfficherTexteEnRouge();
                printf("\n                                                       ╔════════════════════════════════════╗\n");
                printf("                                                       ║          MENU COMPETITION          ║\n");
                printf("                                                       ╚════════════════════════════════════╝\n\n");

                printf("                                             __| |________________________________________________| |__ \n");
                printf("                                            (__   ________________________________________________   __)\n");       
                printf("                                               | |                                                | |   \n");
                printf("                                               | | 1-  Ajouter une compétition                    | |   \n");
                printf("                                               | | 2-  Ajouter des participants à une compétition | |   \n");
                printf("                                               | | 3-  Afficher les compétitions                  | |   \n");
                printf("                                               | | 4-  Rechercher une compétition                 | |   \n");
                printf("                                               | | 5-  Supprimer une compétition                  | |   \n");
                printf("                                               | | 6-  Supprimer un participant                   | |   \n");
                printf("                                               | | 7-  Mettre à jour une compétition              | |   \n");
                printf("                                               | | 8-  Trier les participants d'une compétition   | |   \n");               
                printf("                                             __| |________________________________________________| |__ \n");
                printf("                                            (__   ________________________________________________   __)\n");
                printf("                                               | |                                                | |   \n");
                puts("\n");
                printf("                                            Choisissez une option: ");
                scanf(" %d", &choix_competitions);
                switch (choix_competitions)
                {
                    case 1:
                        ajouter_competition();
                        break;
                    case 2:
                        ajouter_participants();
                        break;
                    case 3:
                        afficher_competition();
                        break; 
                    case 4:
                        rechercher_competition();  
                        break;
                    case 5:
                        supprimer_competiton();                        
                        break;
                    case 6:
                        supprimer_participant();
                        break;
                    case 7:
                        mise_a_jour_competition();
                        break;
                    case 8:
                        trier_participants();
                        break;                     
                    default:
                        printf("                                            Choix invalide\n");
                        break;
                }    
                break;
            
            case 4:
            	message_d_accueil(); 
            	break;    
            case 5:
                printf("                                            Merci d'avoir utilisé notre application. Au revoir !\n");
                break;    
            default:
                printf("                                            Choix invalide\n");
                break;    
               
        }
        if(choix != 5){
            
        	continuer(); while(getchar() != '\n');           
        	//getchar(); 
		}
    } while (choix != 5);
    
    free(joueurs);
    free(clubs);
    free(competitions);
    return 0;
}