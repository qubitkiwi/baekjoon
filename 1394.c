#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char word[101], cipher[1000001];
    int encoder[128] = {0, };
    int word_len, cipher_len, cnt=0;

    scanf("%s", word);
    scanf("%s", cipher);

    word_len = strlen(word);
    cipher_len = strlen(cipher);

    for (int i = 0; i < word_len; i++)
        encoder[word[i]] = i+1;
    
    for (int i = 0; i < cipher_len; i++)
    {
        cnt *= word_len;
        cnt += encoder[cipher[i]];
        cnt %= 900528;
    }
    
    printf("%d\n", cnt);
    return 0;
}

/* 
abcdefghijklmnopqrstuvwxyz
ak

15 + 11

bca
b, c, a, bb, bc, ba, cb, cc, ca, ab, ac, aa, bbb, bbc

b = 1
c = 2
a = 3

bb = 3+1
cb = 3*2+1
ab = 3*3+1

 */