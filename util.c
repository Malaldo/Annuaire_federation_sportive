#include "util.h"
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
  /*====================================================/ 
 /        FONCTION POUR NETTOYER LE TERMINAL           /
/====================================================*/
void effacerEcran() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void continuer() {

    puts("\n");
    printf("                                               --> Appuyez sur [ENTREE] pour continuer...");
    puts("\n");
    while (1) {
        // On vérifie si une touche a été pressée
        if (_kbhit()) {
            char touche = _getch();

            // Sur Windows, la touche Entrée renvoie le caractère '\r' (Carriage Return)
            if (touche == '\r') {
                break; // On sort de la boucle immédiatement !
            }
        }
        
    }
    Sleep(2000);
    fflush(stdout);
    
}

void message_d_accueil(){
    puts("\n"); 
    
	printf("██████╗ ██████╗  ██████╗      ██╗███████╗████████╗      █████╗███╗   ██╗███╗   ██╗██╗   ██╗█████╗  ██╗██████╗ ███████╗                   ________________________________________________________\n");
    printf("██╔══██╗██╔══██╗██╔═══██╗     ██║██╔════╝╚══██╔══╝    ██╔══██╗████╗  ██║████╗  ██║██║   ██║██╔══██╗██║██╔══██╗██╔════╝                  |                                                        |\n");
    printf("██████╔╝██████╔╝██║   ██║     ██║█████╗     ██║       ███████║██╔██╗ ██║██╔██╗ ██║██║   ██║███████║██║██████╔╝█████╗                    | Ce projet est réalisé par Mamadou Malal Diallo         |\n");
    printf("██╔═══╝ ██╔══██╗██║   ██║██   ██║██╔══╝     ██║       ██╔══██║██║╚██╗██║██║╚██╗██║██║   ██║██╔══██║██║██╔══██╗██╔══╝                    | étudiant en 2ème année de licence Mathématiques et     |\n");
    printf("██║     ██║  ██║╚██████╔╝╚█████╔╝███████╗   ██║       ██║  ██║██║ ╚████║██║ ╚████║╚██████╔╝██║  ██║██║██║  ██║███████╗                  | Informatique à l'Université Iba Der Thiam de Thiès     |\n");
    printf("╚═╝     ╚═╝  ╚═╝ ╚═════╝  ╚════╝ ╚══════╝   ╚═╝       ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝╚═╝╚═╝  ╚═╝╚══════╝                  |________________________________________________________|\n");

    puts("\n"); 

    
    printf("                                      ██████╗ ╔══╗██╗   ██╗███╗   ██╗███████╗\n");
    printf("                                      ██╔══██╗╚██╝██║   ██║████╗  ██║██╔════╝\n");
    printf("                                      ██║  ██║    ██║   ██║██╔██╗ ██║█████╗  \n");
    printf("                                      ██║  ██║    ██║   ██║██║╚██╗██║██╔══╝  \n");
    printf("                                      ██████╔╝    ╚██████╔╝██║ ╚████║███████╗\n");
    printf("                                      ╚═════╝      ╚═════╝ ╚═╝  ╚═══╝╚══════╝\n");

    puts("\n");

    
    printf("                 ███████╗███████╗██████╗ ███████╗██████╗  █████╗ ████████╗██╗ ██████╗ ███╗   ██╗\n");
    printf("                 ██╔════╝██╔════╝██╔══██╗██╔════╝██╔══██╗██╔══██╗╚══██╔══╝██║██╔═══██╗████╗  ██║\n");
    printf("                 █████╗  █████╗  ██║  ██║█████╗  ██████╔╝███████║   ██║   ██║██║   ██║██╔██╗ ██║\n");
    printf("                 ██╔══╝  ██╔══╝  ██║  ██║██╔══╝  ██╔══██╗██╔══██║   ██║   ██║██║   ██║██║╚██╗██║\n");
    printf("                 ██║     ███████╗██████╔╝███████╗██║  ██║██║  ██║   ██║   ██║╚██████╔╝██║ ╚████║\n");
    printf("                 ╚═╝     ╚══════╝╚═════╝ ╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝ ╚═════╝ ╚═╝  ╚═══╝\n");

    puts("\n");

    
    printf("                           ███████╗██████╗  ██████╗ ██████╗ ████████╗██╗██╗   ██╗███████╗\n");
    printf("                           ██╔════╝██╔══██╗██╔═══██╗██╔══██╗╚══██╔══╝██║██║   ██║██╔════╝\n");
    printf("                           ███████╗██████╔╝██║   ██║██████╔╝   ██║   ██║██║   ██║█████╗  \n");
    printf("                           ╚════██║██╔═══╝ ██║   ██║██╔══██╗   ██║   ██║╚██╗ ██╔╝██╔══╝  \n");
    printf("                           ███████║██║     ╚██████╔╝██║  ██║   ██║   ██║ ╚████╔╝ ███████╗\n");
    printf("                           ╚══════╝╚═╝      ╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═══╝  ╚══════╝\n");

    puts("\n");

    
    printf("                        ███╗   ███╗█████╗  ██╗     █████╗  ██╗     ██████╗  ██████╗ \n");
    printf("                        ████╗ ████║██╔══██╗██║     ██╔══██╗██║     ██╔══██╗██╔═══██╗\n");
    printf("                        ██╔████╔██║███████║██║     ███████║██║     ██║  ██║██║   ██║\n");
    printf("                        ██║╚██╔╝██║██╔══██║██║     ██╔══██║██║     ██║  ██║██║   ██║\n");
    printf("                        ██║ ╚═╝ ██║██║  ██║███████╗██║  ██║███████╗██████╔╝╚██████╔╝\n");
    printf("                        ╚═╝     ╚═╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚═════╝  ╚═════╝ \n");


    puts("\n");
    Sleep(5000);

}

void nettoyer_tampon(int resultat_scanf, char *cj) {
   
    if (resultat_scanf != 2 || *cj != '\n') {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    *cj = 0; // Réinitialisation propre
}

void AfficherTexteEnVert(){
   HANDLE console_id = GetStdHandle(STD_OUTPUT_HANDLE); // Récupère l'identifiant de la console
   SetConsoleTextAttribute(console_id, FOREGROUND_GREEN | FOREGROUND_INTENSITY); // Définit la couleur du texte en vert clair
}

void AfficherTexteEnBlanc(){
    HANDLE console_id = GetStdHandle(STD_OUTPUT_HANDLE); // Récupère l'identifiant de la console
    SetConsoleTextAttribute(console_id, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY); // Définit la couleur du texte en blanc clair
}

void AfficherTexteEnBleu(){
    HANDLE console_id = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_id, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

void AfficherTexteEnRouge(){
    HANDLE console_id = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_id, FOREGROUND_RED | FOREGROUND_INTENSITY);
}