#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
#include <ctype.h>

const int GROW_FACTOR = 2; //Increase in capacity is * 2 during resize

struct my_string {
  int capacity;
  int size;
  char* data;
};
typedef struct my_string My_string;

MY_STRING my_string_init_default(void) {
  My_string* pMy_string = (My_string*)malloc(sizeof(My_string));
  if (pMy_string != NULL) {
    pMy_string->capacity = 7;
    pMy_string->size = 0;
    pMy_string->data = (char*)malloc(sizeof(char) * pMy_string->capacity);
    if (pMy_string->data == NULL) {
      free(pMy_string);
      return NULL;
    }
  }
  return pMy_string;
}

void my_string_destroy(MY_STRING* phMy_string) {
  My_string* pMy_string = (My_string*)*phMy_string;
  if (pMy_string != NULL) {
    free(pMy_string->data);
    free(pMy_string);
    *phMy_string = NULL;
  }
}

MY_STRING my_string_init_c_string(const char* c_string) {
    int count=0;
    for (int i = 0; c_string[i] != '\0'; i++) {
        count++;
    }

    My_string* pMy_string = (My_string*)malloc(sizeof(My_string));
    if (pMy_string != NULL) {
        pMy_string->capacity = count+1;
        pMy_string->size = 0;
        pMy_string->data = (char*)malloc(sizeof(char) * pMy_string->capacity);
        if (pMy_string->data == NULL) {
            free(pMy_string);
            return NULL;
        }
        for (int i = 0; c_string[i] != '\0'; i++) {
            pMy_string->data[i] = c_string[i];
            pMy_string->size++;
        }
    }
    return pMy_string;
}

int my_string_get_capacity(MY_STRING hMy_string) {
    My_string* pMy_string = (My_string*)hMy_string;
    if (pMy_string != NULL) {
        return pMy_string->capacity;
    }
    return 0xBEEF;;
}

int my_string_get_size(MY_STRING hMy_string) {
    My_string* pMy_string = (My_string*)hMy_string;
    if (pMy_string != NULL) {
        return pMy_string->size;
    }
    return 0xBEEF;;
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp) {
  My_string* pMy_string = (My_string*)hMy_string;
  if (pMy_string != NULL) {
    for (int z=0; pMy_string->size > z; z++) {
      fprintf(fp, "%c", pMy_string->data[z]);
    }
    return SUCCESS;
  }
  return FAILURE;
}

char* my_string_c_str(MY_STRING hMy_string) {
  My_string* pMy_string = (My_string*)hMy_string;
  if (pMy_string != NULL) {
    if (pMy_string->size >= pMy_string->capacity) {
      char* temp = (char*)malloc((sizeof(char) * pMy_string->capacity) + 1);
      if (temp == NULL) {
        return NULL;
      }
      for (int i = 0; i < pMy_string->size; i++) {
        temp[i] = pMy_string->data[i];
      }
      free(pMy_string->data);
      pMy_string->data = temp;
      //pMy_string->capacity += 1;
    }
    pMy_string->data[pMy_string->size] = '\0';
    return pMy_string->data;
  }
  return NULL;
}

Status my_string_pop_back(MY_STRING hMy_string) {
  My_string* pMy_string = (My_string*)hMy_string;
  if (pMy_string != NULL && my_string_empty(pMy_string) == FALSE) {
    pMy_string->size--;
    return SUCCESS;
  }
  return FAILURE;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string) {
  My_string* pLeft_string = (My_string*)hLeft_string;
  My_string* pRight_string = (My_string*)hRight_string;
  if (pLeft_string == NULL || pRight_string == NULL) {
    return 0xBEEF;
  }

  char* L = my_string_c_str(hLeft_string);
  char* R = my_string_c_str(hRight_string);
  if (L == NULL || R == NULL) {
    return 0xBEEF;
  }

  int value = 0;
  for (int i = 0; L[i] != '\0' || R[i] != '\0'; i++) {
    if (L[i] != R[i]) {
      value = L[i] - R[i];
      break;
    }
  }
  return value;
}

Status my_string_extraction(MY_STRING hMy_string, FILE* fp) {
  My_string* pMy_String = (My_string*)hMy_string;
  if (pMy_String == NULL) {
    return FAILURE;
  }

  int c = fgetc(fp);
  if (c == EOF) {
    return FAILURE;
  }
  while (isspace(c)) {
    c = fgetc(fp);
    if (c == EOF) {
      return FAILURE;
    }
  }

  pMy_String->size = 0;
  while (!isspace(c) && c != EOF) {
    if (pMy_String->capacity <= pMy_String->size + 1) {
      char* temp = (char*)malloc(sizeof(char) * pMy_String->capacity * GROW_FACTOR);
      if (temp == NULL) {
        return FAILURE;
      }
      for (int j = 0; j < pMy_String->size; j++) {
        temp[j] = pMy_String->data[j];
      }
      free(pMy_String->data);
      pMy_String->data = temp;
      pMy_String->capacity *= GROW_FACTOR;
    }

    pMy_String->data[pMy_String->size] = (char)c;
    pMy_String->size++;

    c = fgetc(fp);
  }
  return SUCCESS;
}

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend) {
  My_string* pResult = (My_string*)hResult;
  My_string* pAppend = (My_string*)hAppend;

  if (pAppend != NULL && pResult != NULL) {
    int ogSize = pResult->size;
    if (pAppend->size + pResult->size > pResult->capacity) {
      char* temp = (char*)malloc(sizeof(char) * (pResult->size + pAppend->size + 1));
      if (temp == NULL) {
        return FAILURE;
      }
      for (int i = 0; i < pResult->size; i++) {
        temp[i] = pResult->data[i];
      }
      free(pResult->data);
      pResult->data = temp;
      pResult->capacity = pResult->size + pAppend->size + 1;
    }
    for (int i = 0; i < pAppend->size; i++) {
      pResult->data[ogSize+i] = pAppend->data[i];
      pResult->size++;
    }
    return SUCCESS;
  }
  return FAILURE;
}

Status my_string_push_back(MY_STRING hMy_string, char item) {
  My_string* pMy_string = (My_string*)hMy_string;
  if (pMy_string != NULL) {
    if (pMy_string->size >= pMy_string->capacity) {
      char* temp = (char*)malloc(sizeof(char) * pMy_string->capacity * GROW_FACTOR);
      if (temp == NULL) {
        return FAILURE;
      }
      for (int i = 0; i < pMy_string->size; i++) {
        temp[i] = pMy_string->data[i];
      }
      free(pMy_string->data);
      pMy_string->data = temp;
      pMy_string->capacity *= GROW_FACTOR;
    }
    pMy_string->data[pMy_string->size++] = item;
    return SUCCESS;
  }
  return FAILURE;
}

char* my_string_at(MY_STRING hMy_string, int index) {
  My_string* pMy_string = (My_string*)hMy_string;
  if (pMy_string == NULL || index >= pMy_string->size || index < 0) {
    return NULL;
  }
  return &(pMy_string->data[index]);
}

Status my_string_assignment(MY_STRING hLeft, MY_STRING hRight) {
  My_string* pLeft = (My_string*)hLeft;
  My_string* pRight = (My_string*)hRight;
  if (pLeft != NULL && pRight != NULL) {
    if (pLeft == pRight) {
      return SUCCESS;
    }
    //int right_size = my_string_get_size(pRight);
    if (pRight->size > pLeft->capacity) {
      char* temp = (char*)malloc(sizeof(char) * (pRight->size+1));
      if (temp == NULL) {
        return FAILURE;
      }
      free(pLeft->data);
      pLeft->data = temp;
      pLeft->capacity = pRight->size+1;
    }
    while (my_string_empty(pLeft) != TRUE) {
      my_string_pop_back(pLeft);
    }
    for (int i = 0; i < my_string_get_size(pRight); i++) {
      pLeft->data[i] = pRight->data[i];
    }
    pLeft->size=pRight->size;

    return SUCCESS;
  }
  return FAILURE;
}

Boolean my_string_empty(MY_STRING hMy_string) {
  My_string* pMy_string = (My_string*)hMy_string;
  if (pMy_string->size > 0) {
    return FALSE;
  }
  return TRUE;
}

Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess) {
  My_string* pCurrent_word_family = (My_string*)current_word_family;
  My_string* pNew_key = (My_string*)new_key;
  My_string* pWord = (My_string*)word;

  if (pWord == NULL || pNew_key == NULL || pCurrent_word_family == NULL) {
    return FAILURE;
  }

  while (my_string_empty(pNew_key) != TRUE) {
    if (my_string_pop_back(pNew_key) == FAILURE) {
      return FAILURE;
    }
  }

  for (int i = 0; i < my_string_get_size(pWord); i++) {
    char* word_char = my_string_at(pWord, i);
    char* family_char = my_string_at(pCurrent_word_family, i);

    if (word_char == NULL || family_char == NULL) {
      return FAILURE;
    }

    char c;
    if (*word_char == guess) {
      c = guess;
    } else {
      c = *family_char;
    }

    if (my_string_push_back(pNew_key, c) == FAILURE) {
      return FAILURE;
    }
  }

  return SUCCESS;
}

MY_STRING my_string_init_copy(MY_STRING hMy_string) {
    My_string* pMy_string = (My_string*)hMy_string;
    if (pMy_string != NULL) {
        char* temp = my_string_c_str(hMy_string);
        if (temp != NULL) {
            MY_STRING new = my_string_init_c_string(temp);
            if (new != NULL) {
                return new;
            }
        }
    }
    return NULL;
}

void my_string_swap(MY_STRING hLeft, MY_STRING hRight) {
    My_string* pLeft = (My_string*)hLeft;
    My_string* pRight = (My_string*)hRight;

    if (pLeft != NULL && pRight != NULL) {
        char* L = (char*)malloc(sizeof(char) * pRight->capacity);
        char* R = (char*)malloc(sizeof(char) * pLeft->capacity);
        if (L != NULL && R != NULL) {
            for (int i = 0; i < my_string_get_size(pLeft); i++) {
                R[i] = pLeft->data[i];
            }
            for (int i = 0; i < my_string_get_size(pRight); i++) {
                L[i] = pRight->data[i];
            }
            free(pLeft->data);
            free(pRight->data);
            pLeft->data = L;
            pRight->data = R;

            int s= pLeft->size;
            int c= pLeft->capacity;
            pLeft->size = pRight->size;
            pLeft->capacity = pRight->capacity;
            pRight->size = s;
            pRight->capacity = c;
        }
    }
}

Boolean use_check(MY_STRING guess_list, char c) {
  My_string* pMy_string = (My_string*)guess_list;
  if (pMy_string != NULL) {
    for (int i = 0; i < my_string_get_size(guess_list); i++) {
      if (pMy_string->data[i] == c) {
        printf("\nYou already guessed this letter. Please try again");
        return TRUE;
      }
    }
    return FALSE;
  }
  return TRUE;
}