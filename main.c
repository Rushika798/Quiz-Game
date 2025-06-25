#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int score = 0;
char player_name[50];

void game() {
    FILE *file;
    char line[200];
    int correct, user;
    int questionNo = 1;

    file = fopen("text.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\nEnter your name: ");
    scanf("%s", player_name);

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "Q") == line) {
            printf("\n%s", line); // Question
            for (int i = 0; i < 4; i++) {
                fgets(line, sizeof(line), file);
                printf("%s", line); // Options
            }
            fgets(line, sizeof(line), file); // Answer line

            // Get correct answer from line (e.g., "Answer:2")
            sscanf(line, "Answer:%d", &correct);

            printf("Your answer (1-4): ");
            scanf("%d", &user);

            if (user == correct) {
                printf("Correct!\n");
                score++;
            } else {
                printf(" Wrong! Correct answer was %d.\n", correct);
            }
        }
    }

    printf("\n %s, your total score is: %d\n", player_name, score);

    fclose(file);
}

int main() {
    char choice;

    printf("\n\t\t************************************");
    printf("\n\t\t\tWELCOME TO QUIZ GAME ");
    printf("\n\t\t************************************");

    printf("\n\n\tMENU\n");
    printf("\t\t* Press S to start the game\n");
    printf("\t\t* Press Q to quit\n");

    choice = getchar();

    switch (choice) {
        case 'S':
        case 's':
            game();
            break;
        case 'Q':
        case 'q':
            exit(0);
        default:
            printf("Please provide a correct option.\n");
    }

    return 0;
}
