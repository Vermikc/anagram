#ifndef ANAGRAM_FUNCTIONS_H
#define ANAGRAM_FUNCTIONS_H

int MixWord(char* word, int len);
char* CreateUsedCharsVector(int len);
int ToLower(char* word, int len);
int MixText(char* text, int len);
int WriteWord(char* dest, const char* word, int index_from, int length);

#endif
