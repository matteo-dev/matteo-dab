#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> // Inclure la bibliothèque pour usleep

// Codes d'échappement ANSI pour la couleur bleue
#define ANSI_COLOR_BLUE "\033[0;34m"
#define ANSI_COLOR_RESET "\033[0m"

void vide_buffer() {                        //éviter les boucles infinies
    while (getchar() != '\n') {
    }
}

int main() {
    int verif;

    FILE* f = NULL;  
    f = fopen("intro.txt", "r+");      //ouverture de l'intro          
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        exit(1);
    }

    char c;
    while ((c = fgetc(f)) != EOF) {                       //affichage du texte sur le terminal
        printf(ANSI_COLOR_BLUE "%c" ANSI_COLOR_RESET, c);
        fflush(stdout);     // Vider le tampon de sortie pour afficher le caractère immédiatement
        usleep(50 000);      // Pause de 50 000 microsecondes
    }
    fclose(f);

    int a;                                  //choix de l'utilisateur
    do {
        printf("Tapez 1 ou 2\n");
        verif = scanf("%d", &a);
        vide_buffer();
    } while (a != 1 && a != 2);

    FILE* f1 = NULL;                       // programme pour i_c1||c2
    if (a == 1) {
        f1 = fopen("ic1.txt", "r+");
    } else if (a == 2) {
        f1 = fopen("ic2.txt", "r+");
    }

    char c1;                                  //affichage du texte sur le terminal
    while ((c1 = fgetc(f1)) != EOF) {
        printf(ANSI_COLOR_BLUE "%c" ANSI_COLOR_RESET, c1);
        fflush(stdout);  // Permet d'afficher lettre par lettre avec un délai;
        usleep(5000); 
    }
    fclose(f1);

    int a1;
    do {
        printf("Tapez 1 ou 2\n");
        verif = scanf("%d", &a1);
        vide_buffer();
    } while (a1 != 1 && a1 != 2);

    FILE* f2 = NULL;      
    if (a == 1) {
        if (a1 == 1) {
            f2 = fopen("ic1_c1.txt", "r+");
        } else if (a1 == 2) {
            f2 = fopen("ic1_c2.txt", "r+");
        }
    } else if (a == 2) {
        if (a1 == 1) {
            f2 = fopen("ic2_c1.txt", "r+");
        } else if (a1 == 2) {
            f2 = fopen("ic2_c2.txt", "r+");
        }
    }

    char c2;                                                       //affichage du texte sur le terminal
    while ((c2 = fgetc(f2)) != EOF) {
        printf(ANSI_COLOR_BLUE "%c" ANSI_COLOR_RESET, c2);
         fflush(stdout);  // Vider le tampon de sortie pour afficher le caractère immédiatement
        usleep(50 000);  // Pause de 50 000 microsecondes 
    }
    fclose(f2);

    int a2;
    do {
        printf("Tapez 1 ou 2\n");
        verif = scanf("%d", &a2);
        vide_buffer();
    } while (a2 != 1 && a2 != 2);

    FILE* f3 = NULL;
    if (a == 1) {                                            /*ouvrir les fichiers correspodants aux choix.*/
        if (a1 == 1) {
            if (a2 == 1) {
                f3 = fopen("ic1_c1_c1.txt", "r+");
            } else if (a2 == 2) {
                f3 = fopen("ic1_c1_c2.txt", "r+");
            }
        } else if (a1 == 2) {
            if (a2 == 1) {
                f3 = fopen("ic1_c2_c1.txt", "r+");
            } else if (a2 == 2) {
                f3 = fopen("ic1_c2_c2.txt", "r+");
            }
        }
    } else if (a == 2) {
        if (a1 == 1) {
            if (a2 == 1) {
                f3 = fopen("ic2_c1_c1.txt", "r+");
            } else if (a2 == 2) {
                f3 = fopen("ic2_c1_c2.txt", "r+");
            }
        } else if (a1 == 2) {
            if (a2 == 1) {
                f3 = fopen("ic2_c2_c1.txt", "r+");
            } else if (a2 == 2) {
                f3 = fopen("ic2_c2_c2.txt", "r+");
            }
        }
    }

    char c3;                                                     //affichage du texte sur le terminal
    while ((c3 = fgetc(f3)) != EOF) {
        printf(ANSI_COLOR_BLUE "%c" ANSI_COLOR_RESET, c3);
        fflush(stdout);  // Vider le tampon de sortie pour afficher le caractère immédiatement
        usleep(50 000);  // Pause de 50 000 microsecondes 
    }
    fclose(f3);

    return 0;
}

