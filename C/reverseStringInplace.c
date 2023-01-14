#include <stdio.h>

char* reverse(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length += 1;
    }

    for (int i = 0; i < length/2; i++) {
        char temp;
        temp = str[i];
        str[i] = str[length-i-1];
        str[length-i-1] = temp;
    }
    for (int i = 0; i < length; i++)
        printf("%c", str[i]);

    return NULL;
}

int main() {

    char word[] = "Happy Birthday!";
    reverse(word);
}