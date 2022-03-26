/* Written by Kaan YILMAZ
*  26 March 2022
*
*    This program is free software; you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation; either version 2 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program; if not, write to the Free Software
*    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <stdio.h>

int main() {
    int numberOfPeople;

    printf("How many people?\n");
    scanf("%d", &numberOfPeople);
    printf("Starting with %d people\n", numberOfPeople);

    int menuPoints[] = {0, 0, 0, 0, 0, 0, 0};
    int newMenuPoints[] = {0, 0, 0, 0, 0, 0, 0};

    char initialMenu[6][20] =
            {"Kebab",
             "Burger",
             "Pasta",
             "Lahmacun",
             "Pizza",
             "Salad"
            };

    for (int i = 0; i < numberOfPeople; i++) {
        int chosen[] = {0, 0, 0, 0, 0, 0, 0};
        printf("PERSON %d \n", i);

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
    printf("threshold is: %d \n", threshold);

    //integer for storing how many passed the threshold
    int proceed = 0;

    for (int i = 0; i < 6; i++) {
        if (menuPoints[i] > threshold) {
            proceed = proceed + 1;
        }
    }


    if (proceed == 0) {
        printf("Nothing passed the threshold, exiting");
    } else if (proceed == 1) {
        for (int i = 0; i < 6; i++) {
            if (menuPoints[i] > threshold) {
                printf("ordering ");
                printf("%s", initialMenu[i]);
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
                    newMenuPoints[choice] = newMenuPoints[choice] + a;
                    printf("%d points given! \n", a);
                    a--;

                } else if (chosen[choice] == 1) {
                    printf("You've already chosen that!\n");

                } else {
                    printf("error unknown");
                }
            }
        }

        printf("\n Points: \n");
        for (int a = 0; a < 5; a++) {
            printf("%s", initialMenu[a]);
            printf(" got ");
            printf("%d", newMenuPoints[a]);
            printf(" Points \n");

        }
        int highest = 0;
        int highestDish = 0;
        for (int a = 0; a < 5; a++) {
            if (newMenuPoints[a] > highest) {
                highest = newMenuPoints[a];
                highestDish = a;
            }
        }
        printf("\n Ordering %s. \n", initialMenu[highestDish]);
    }
    return 0;
}
