#include <stdio.h>
#include <string.h>

#include "functions.h"

int main(void)
{
    char text[500];
    printf("Enter text to mix: ");
    fgets(text, sizeof(text), stdin);
    text[strlen(text)-1] = '\0';        // remove '\n'  before '\0'
    MixText(text, (int) strlen(text));
    printf("Mixed text: %s", text);
}
