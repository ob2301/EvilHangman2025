// #include <stdio.h>
// #include "my_string.h"
// #include <stdlib.h>
// int main(int argc, char* argv[])
// {
//     FILE* fp;
//     if ((fp = fopen("simple.txt", "r")) == NULL) {
//         exit(1);
//     }
//
//     MY_STRING hMy_string1 = my_string_init_default();   //23
//     MY_STRING hMy_string2 = my_string_init_c_string("hi"); //19
//     MY_STRING hLeft_string = my_string_init_c_string("app"); //22
//     MY_STRING hRight_string = my_string_init_c_string("apple"); //22
//     MY_STRING new = my_string_init_default();
//
//     printf("%d\n", my_string_get_capacity(hMy_string2));
//     printf("%d\n", my_string_get_size(hMy_string2));
//     printf("%d\n", my_string_compare(hLeft_string, hRight_string));
//
//     my_string_extraction(new, fp);
//     my_string_insertion(new, fp);
//
//     my_string_destroy(&hMy_string1);
//     my_string_destroy(&hMy_string2);
//     my_string_destroy(&hLeft_string);
//     my_string_destroy(&hRight_string);
//     my_string_destroy(&new);
//
//     fclose(fp);
//
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include "my_string.h"
// int main(int argc, char* argv[])
// {
//     MY_STRING hMy_string = NULL;
//     FILE* fp;
//     hMy_string = my_string_init_default();
//     fp = fopen("simple.txt", "r");
//     while(my_string_extraction(hMy_string, fp))
//     {
//         my_string_insertion(hMy_string, stdout);
//         printf("\n");
//         if(fgetc(fp)== ' ')
//         {
//             printf("Found a space after the string\n");
//         }
//     }
//     my_string_destroy(&hMy_string);
//     fclose(fp);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include "my_string.h"
// int main(int argc, char* argv[]) {
//     MY_STRING hMy_string = NULL;
//     FILE* fp;
//     hMy_string = my_string_init_default();
//     fp = fopen("simple.txt", "r");
//
//     while(my_string_extraction(hMy_string, fp))
//     {
//         if (my_string_get_size(hMy_string)==5)
//         {
//             my_string_insertion(hMy_string, stdout);
//             printf("\n");
//         }
//     }
//     fclose(fp);
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include "my_string.h"
// int main(int argc, char* argv[]) {
//
//     MY_STRING hMy_string = NULL;
//     hMy_string = my_string_init_default();
//
//     my_string_push_back(hMy_string, 'd');
//     my_string_push_back(hMy_string, 'o');
//     my_string_push_back(hMy_string, 'g');
//     my_string_push_back(hMy_string, 'w');
//     my_string_push_back(hMy_string, 'o');
//     my_string_push_back(hMy_string, 'w');
//     my_string_pop_back(hMy_string); //removes w
//     my_string_pop_back(hMy_string); //removes o
//     my_string_pop_back(hMy_string); //removes w
//
//     printf("my_string_insertion: "); my_string_insertion(hMy_string, stdout); //dog
//     char *temp = my_string_at(hMy_string, 0); printf("\nmy_string_at index 0: %c", *temp); //d
//     printf("\nmy_string_c_str: %s", my_string_c_str(hMy_string)); //dog with null terminator at end
//
//     printf("\nSize: %d", my_string_get_size(hMy_string));
//     printf("\nCapacity: %d\n", my_string_get_capacity(hMy_string));
//
//     MY_STRING hResult = my_string_init_c_string("String1+");
//     MY_STRING hAppend = my_string_init_c_string("String2");
//
//     printf("my_string_concat: "); my_string_concat(hResult, hAppend);
//
//     printf("\nSize: %d", my_string_get_size(hResult));
//     printf("\nCapacity: %d\n", my_string_get_capacity(hResult));
//
//     my_string_destroy(&hResult);
//     my_string_destroy(&hAppend);
//     my_string_destroy(&hMy_string);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include "my_string.h"
//
// int main(int argc, char* argv[]) {
//
//     MY_STRING elements[100];
//     for (int i = 0; i < 100; i++) {
//         elements[i] = NULL;
//     }
//
//     elements[0] = my_string_init_c_string("COPY ME!");
//     for (int i = 1; i < 100; i++) {
//         elements[i] = my_string_init_copy(elements[0]);
//     }
//     my_string_destroy(&elements[0]);
//
//     elements[0] = my_string_init_c_string("FIRST FIFTY!");
//     for (int i = 1; i < 50; i++) {
//         my_string_assignment(elements[i], elements[0]);
//     }
//
//     for (int i = 0; i < 50; i++) {
//         my_string_swap(elements[i], elements[99-i]);
//     }
//
//     for (int i = 0; i < 100; i++) {
//         printf("%s\n", my_string_c_str(elements[i]));
//         my_string_destroy(&elements[i]);
//     }
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include "my_string.h"
// #include "generic_vector.h"
//
// ITEM integer_init_copy(ITEM hInt);
// void integer_destroy(ITEM* phInt);
//
// int main(int argc, char* argv[]) {
//     FILE *fp ;
//     fp = fopen( "dictionary.txt", "r" ) ;
//     if ( fp == NULL ) {
//         exit( 1 ) ;
//     }
//
//     GENERIC_VECTOR genVector[30];
//     for ( int i = 0; i < 30; i++ ) {
//         genVector[i] = generic_vector_init_default(integer_init_copy, integer_destroy) ;
//         if ( genVector[i] == NULL ) {
//             exit(1) ;
//         }
//     }
//
//     MY_STRING hString = my_string_init_default() ;
//     if ( hString == NULL ) {
//         exit( 1 );
//     }
//
//     while (my_string_extraction(hString, fp) != FAILURE) {
//         if ( ! (generic_vector_push_back(genVector[my_string_get_size(hString)], hString ))) {
//             exit( 1 ) ;
//         }
//     }
//
     // for ( int i = 1; i <30; i++ ) {
     //     printf("Number of words with %d letters is %d", i, generic_vector_get_size(genVector[i]));
     //     printf("\n");
     // }
//
//     my_string_destroy(&hString) ;
//     for (int i = 0; i < 30; i++)
//     {
//         generic_vector_destroy(&genVector[i]);
//     }
//     fclose(fp) ;
// }
//
// ITEM integer_init_copy(ITEM hInt)
// {
//     int* pInt;
//     int* pArg = (int*)hInt;
//     pInt = (int*)malloc(sizeof(int));
//     if (pInt != NULL)
//     {
//         *pInt = *pArg;
//     }
//     return pInt;
// }
//
// void integer_destroy(ITEM* phInt)
// {
//     int* pInt = (int*)*phInt;
//     free(pInt);
//     *phInt = NULL;
// }

/***************************************************
Program: Evil Hangman Game
Author: Harry Joshi
Date: 04/27/2025

Description: Driver for Evil Hangman. Manages the game loop,
user input, and dynamically updates word families
using custom data structures (my_string, vector, AVL).
The program avoids selecting a word by constantly
shifting to the largest word family, making it harder
for the player to win.
***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "my_string.h"
#include "generic_vector.h"
#include "avl_tree.h"

//Clears any remaining input from the keyboard buffer.
void clearKeyboardBuffer();
//Prompt user with a yes/no question
//Return 1 for yes, 0 for no.
int yes_no(char* message);

int main(int argc, char* argv[]) {
    do {
        int noc;
        int length;
        int guesses;
        char LGuess =' ';

        //Open dictionary file for reading
        FILE *fp = fopen("dictionary.txt", "r");
        if ( fp == NULL ) {
            exit( 1 ) ;
        }

        //Initialize AVL tree and supporting MY_STRING structures for tracking guessed letters,
        //current word pattern, word families, and a placeholder for the next word family vector.
        TREE tree = avl_tree_init_default() ;
        MY_STRING letters_guessed = my_string_init_default() ;
        MY_STRING word_key = my_string_init_default();
        MY_STRING word_family = my_string_init_default();
        GENERIC_VECTOR new_family = NULL;

        //Insert all words into generic vector
        GENERIC_VECTOR genVector[30];
        for (int i = 0; i < 30; i++) {
            genVector[i] = generic_vector_init_default(my_string_init_copy, my_string_destroy) ;
            if ( genVector[i] == NULL ) {
                exit(1) ;
            }
        }
        MY_STRING hString = my_string_init_default() ;
        if (hString == NULL) {
            exit( 1 );
        }
        while (my_string_extraction(hString, fp) != FAILURE) {
            if (generic_vector_push_back(genVector[my_string_get_size(hString)], hString) != SUCCESS) {
                exit( 1 ) ;
            }
        }

        //Get valid word length from user
        int NValid = 0;
        while (NValid != 1) {
            printf("What word length do you want to play with: ");
            noc = scanf(" %d", &length);
            if (noc==1 && length > -1 && length < 30 ) {
                if (generic_vector_get_size(genVector[length]) != 0) {
                    NValid++;
                }
                else {
                    printf("\nThere are no words of this length. Please try again.\n");
                }
            } else {
                printf("\nBad input. Please try again\n");
            }
            clearKeyboardBuffer();
        }

        //Get valid guess count from user
        int GValid = 0;
        while (GValid != 1) {
            printf("How many guesses do you want to play with: ");
            noc = scanf(" %d", &guesses);
            if (noc==1 && guesses > 0) {
                GValid++;
            } else {
                printf("\nBad input. Please try again\n");
            }
            clearKeyboardBuffer();
        }

        //Get running total display preference from user.
        int running_total = yes_no("Do you want a running total of the number of words remaining in the word list (y/n): ");

        //Initialize word_key with dashes based on word length.
        for (int i = 0; i < length; i++ ) {
            my_string_push_back(word_key, '-') ;
        }

        while (guesses != 0) { //Continue until the user runs out of guesses
            printf("Current word: %s\n", my_string_c_str(word_key));
            printf("Guesses remaining: %d\n", guesses);
            printf("Letters Guessed: %s\n", my_string_c_str(letters_guessed));

            //Get valid character guess count from user
            int valid = 0;
            while (valid != 1) {
                char guess[100];
                printf("\nGuess a character in the alphabet: ");
                noc = scanf(" %s", guess);
                int size=0;
                for (int i = 0; guess[i] != '\0'; i++) {
                    size++;
                }
                int valid2 = 0;
                if (isalpha(guess[0]) == FALSE || noc!=1 || size != 1) {
                    printf("\nBad input. Please try again");
                    valid2 = 1;
                }
                if (valid2 != 1) {
                    LGuess = tolower(guess[0]);
                    int valid3 = 0;
                    for (int i = 0; i<1; i++) {
                        if (use_check(letters_guessed, LGuess) == TRUE) {
                            valid3 = 1;
                            break;
                        }
                    }
                    if (valid3 == 0) {
                        valid = 1;
                    }
                }
                clearKeyboardBuffer();
            }

            //Add guessed letter + a space to the list of guessed letters.
            my_string_push_back(letters_guessed, LGuess);
            my_string_push_back(letters_guessed, ' ') ;

            //If enabled, display header for the running total of remaining words.
            if (running_total == 1) {
                printf("\nTotal number of words remaining in the word list: %d\nBreakdown:\n", generic_vector_get_size(genVector[length]));
            }

            //Generate word families based on the guess and insert them into the AVL tree.
            for (int i = 0; i < generic_vector_get_size(genVector[length]); i++) {
                get_word_key_value(word_key,word_family,*generic_vector_at(genVector[length], i), LGuess);
                avl_tree_insert(tree, word_family, *generic_vector_at(genVector[length], i));
            }

            //Get the largest word family from the AVL tree, and if enabled, display the breakdown for remaining words
            new_family = avl_tree_get_largest_family(tree, running_total);

            //Update word list with words from the largest family.
            generic_vector_destroy(&(genVector[length]));
            genVector[length] = generic_vector_init_default(my_string_init_copy, my_string_destroy);
            for (int i = 0; i < generic_vector_get_size(new_family); i++) {
                generic_vector_push_back(genVector[length], *generic_vector_at(new_family, i)) ;
            }

            //Generate updated word key and check if the guessed letter is in the word. Decrease remaining guesses if the letter is not found.
            get_word_key_value(word_key, word_family, *generic_vector_at(genVector[length], 0), LGuess);
            if (my_string_compare(word_key, word_family) == 0) {
                printf("\nNo %c in the word\n", LGuess);
                guesses--;
            }
            else {
                printf("\nThere is %c in the word :)\n", LGuess);
            }

            //Update the current word key
            my_string_assignment(word_key, word_family);

            //Clean up and reinitialize word family and tree for next guess.
            generic_vector_destroy(&new_family);
            avl_tree_destroy(&tree);
            my_string_destroy(&word_family);
            word_family = my_string_init_default();
            tree = avl_tree_init_default();

            //Check for game over
            //Loss if no guesses remain, win if the word is fully guessed.
            if (guesses == 0) {
                printf("Zero guesses remaining | YOU LOSE :(\nThe word was %s\n", my_string_c_str(*generic_vector_at(genVector[length], 0)));
                break;
            }
            if (my_string_compare(*generic_vector_at(genVector[length], 0), word_key) == 0 && generic_vector_get_size(genVector[length]) == 1) {
                printf("YOU WON! The word was %s\n", my_string_c_str(*generic_vector_at(genVector[length], 0)));
                break;
            }
        }

        //Free all allocated memory for tree and strings.
        avl_tree_destroy(&tree);
        my_string_destroy(&hString);
        my_string_destroy(&word_key);
        my_string_destroy(&letters_guessed);
        my_string_destroy(&word_family);

        //Destroy all vectors in genVector array.
        for (int i = 0; i < 30; i++)
        {
            generic_vector_destroy(&genVector[i]);
        }

        //Close dictionary file
        fclose(fp);

    } while (yes_no("\nWould you like to play again? (y/n): ") == 1); //Prompts user to play again
}

void clearKeyboardBuffer() {
    char c;
    do {
        scanf("%c", &c);
    } while (c != '\n');
}

int yes_no(char* message) {
    int valid = 0;
    int answer = 0;
    while (valid == 0) {
        char c[100];
        printf("%s", message);
        int noc = scanf(" %s", c);
        int size = 0;
        for (int i = 0; c[i] != '\0'; i++) {
            size++;
        }
        if (isalpha(c[0]) && size == 1 && noc==1 && (c[0] == 'y' || c[0] == 'Y' || c[0] == 'n' || c[0] == 'N')) {
            if ((c[0] == 'y') || (c[0] == 'Y')) {
                answer = 1;
            }
            else {
                answer = 0;
            }
            valid++;
        }
        else {
            printf("\nBad input. Please try again\n");
        }
        clearKeyboardBuffer();
    }
    printf("\n");
    return answer;
}