#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>  // Inclure la bibliothèque pour usleep

// Codes d'échappement ANSI pour la couleur bleue
#define ANSI_COLOR_BLUE "\033[0;34m"
#define ANSI_COLOR_RESET "\033[0m"

void vide_buffer() {
    while (getchar() != '\n') {
    }
}

int main() {
    int verif;

    FILE* f = NULL;  // programme l'intro
    f = fopen("intro.txt", "r+");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        exit(1);
    }

    char c;
    while ((c = fgetc(f)) != EOF) {
        printf(ANSI_COLOR_BLUE "%c" ANSI_COLOR_RESET, c);
        fflush(stdout);     // Vider le tampon de sortie pour afficher le caractère immédiatement
        usleep(50000);      // Pause de 50 000 microsecondes (0,05 seconde)
    }
    fclose(f);

    int a;
    do {
        printf("Tapez 1 ou 2\n");
        verif = scanf("%d", &a);
        vide_buffer();
    } while (a != 1 && a != 2);

    FILE* f1 = NULL;  // programme pour i_c1||c2
    if (a == 1) {
        f1 = fopen("ic1.txt", "r+");
    } else if (a == 2) {
        f1 = fopen("ic2.txt", "r+");
    }

    char c1;
    while ((c1 = fgetc(f1)) != EOF) {
        printf(ANSI_COLOR_BLUE "%c" ANSI_COLOR_RESET, c1);
        /* fflush(stdout);  // Permet d'afficher lettre par lettre avec un délai de 0,05susleep(50000);
        usleep(50000); */
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

    char c2;
    while ((c2 = fgetc(f2)) != EOF) {
        printf(ANSI_COLOR_BLUE "%c" ANSI_COLOR_RESET, c2);
        /* fflush(stdout);  // Vider le tampon de sortie pour afficher le caractère immédiatement
        usleep(50000);  // Pause de 50 000 microsecondes (0,05 seconde) */
    }
    fclose(f2);

    int a2;
    do {
        printf("Tapez 1 ou 2\n");
        verif = scanf("%d", &a2);
        vide_buffer();
    } while (a2 != 1 && a2 != 2);

    FILE* f3 = NULL;
    if (a == 1) {
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

    char c3;
    while ((c3 = fgetc(f3)) != EOF) {
        printf(ANSI_COLOR_BLUE "%c" ANSI_COLOR_RESET, c3);
        /* fflush(stdout);  // Vider le tampon de sortie pour afficher le caractère immédiatement
        usleep(50000);  // Pause de 50 000 microsecondes (0,05 seconde) */
    }
    fclose(f3);

    return 0;
}
