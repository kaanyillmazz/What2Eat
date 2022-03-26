#include <stdio.h>

int main() {
    int numberOfPeople;

    printf("How many people?\n");
    scanf("%d", &numberOfPeople);
    printf("Starting with %d people\n", numberOfPeople);

    int menuPoints[] = {0, 0, 0, 0, 0, 0, 0};

    int newMenu[] = {0, 0, 0, 0, 0, 0, 0};

    char initialMenu[6][20] =
            { "Kebab",
              "Burger",
              "Pasta",
              "Lahmacun",
              "Pizza",
              "Salad"
            };



    for (int i = 0; i < numberOfPeople; i++) {
        int chosen[] = {0, 0, 0, 0, 0, 0, 0};
        printf("PERSON %d \n",i);

        printf("Please choose in order of your preference\n");
        printf("0-Kebab, 1-Burger, 2-Pasta, 3-Lahmacun, 4-Pizza, 5-Salad\n");

        for (int a = 5; a > 0;) {
            int choice = ' ';

            printf("choose!");
            scanf("%d", &choice);

            if (chosen[choice] == 0) {
                chosen[choice] = 1;
                menuPoints[choice] = menuPoints[choice] + a;
                printf("%d points given!\n", a);
                a--;

            } else if (chosen[choice] == 1) {
                printf("You've already chosen that!\n");

            } else {
                printf("error unknown");
            }
        }
    }


    for (int a = 0; a < 5; a++) {
        printf("%s", initialMenu[a]);
        printf(" got ");
        printf("%d", menuPoints[a]);
        printf(" Points \n");

    }

    int threshold = numberOfPeople / 2 * 5;
    printf("threshold is: ");
    printf("%d", threshold);
    int proceed = 0;

    for (int i = 0; i < 6; i++) {
        if(menuPoints[i] > threshold) {
            proceed = proceed+1;
        }
    }


    if(proceed == 0) {
        printf("Nothing passed the threshold, exiting");
    } else if (proceed == 1) {
        for (int i = 0; i < 6; i++) {
            if (menuPoints[i] > threshold) {
                printf("ordering ");
                printf("%s",initialMenu[i]);
            }
        }
    } else {
        for (int e = 0; e < numberOfPeople; e++) {
            int chosen[] = {0, 0, 0, 0, 0, 0, 0};
            printf("choose again from the ones who passed! \n");

            for (int i = 0; i < 6; i++) {
            if (menuPoints[i] > threshold) {
                printf("%d", i);
                printf("-");
                printf("%s", initialMenu[i]);
                printf("\n");
            }
        }

            for (int a = proceed; a > 0;) {
                int choice = ' ';

                printf("choose!");
                scanf("%d", &choice);

                if (chosen[choice] == 0) {
                    chosen[choice] = 1;
                    menuPoints[choice] = menuPoints[choice] + a;
                    a--;

                } else if (chosen[choice] == 1) {
                    printf("You've already chosen that!\n");

                } else {
                    printf("error unknown");
                }
            }

        }

        printf("Total Points: \n");
        for (int a = 0; a < 5; a++) {
            printf("%s", initialMenu[a]);
            printf(" got ");
            printf("%d", menuPoints[a]);
            printf(" Points \n");

        }
        printf("ordering bla bla");

    }


    return 0;
}
