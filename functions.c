#include "functions.h"

// mix letters in each word in text
int MixText(char* text, int len){
    if(len > 0){
        char word_buffer[300];      // char buffer for word
        int word_len = 0;           // length of word in buffer
        for(int let=0; let<=len; let++){
            if(text[let] != ' ' && text[let] != '\0'){
                word_buffer[word_len] = text[let];
                word_len++;
            }
            else{
                word_buffer[word_len] = '\0';
                MixWord(word_buffer, word_len);
                WriteWord(text, word_buffer, let-word_len, word_len);
                word_len = 0;
            }
        }
    }
    return -1;
}

// mix letters in given word
int MixWord(char* word, int len) {
    if (len > 0) {
        srand(time(0));
        ToLower(word, len);                         // change all capital letters to lower in word
        char* used = CreateUsedCharsVector(len);    // create array with 0
        if(used != 0){
            char new_word[len];
            for (int l = 0; l < len; l++) {
                int index = 0 + rand() % len;       // generate random index
                while(used[index] == 1){
                    index = 0 + rand() % len;       // if letter is used, generate new
                }
                used[index] = 1;                    // put flag on used letter
                new_word[l] = word[index];          // add new letter to mixed word
            }
            for(int i=0; i<len; i++)
                word[i] = new_word[i];              // copy mixed word in original
            return 0;
        }
    }
    return -1;
}

// Create array with length 'len' and filled with 0
char* CreateUsedCharsVector(int len) {
    char* vector = (char*)malloc(len);
    if (vector != 0) {
        for (int i = 0; i < len; i++)
            *(vector+i) = 0;
    }
    return vector;
}

//Change all capital letters to lower
int ToLower(char* word, int len){
    if(len > 0){
        for(int i=0; i<len; i++)
            if(word[i] > 64 && word[i] < 91)    // if letter is capital...
                word[i] += 32;  // ...change it to lower symbol due ASCII table
        return 0;
    }
    return -1;
}

// write word in 'dest' from 'index_from' with length 'length'
int WriteWord(char* dest, char* word, int index_from, int length){
    if(index_from >= 0 && length > 0){
        for(int d_i=index_from, s_i = 0; d_i<length+index_from; d_i++, s_i++)
            dest[d_i] = word[s_i];
        return 0;
    }
    return -1;
}
