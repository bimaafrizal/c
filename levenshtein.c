#include <stdio.h>
#include <string.h>
#include <math.h>

int LevenshteinDistance(char *s, char *t) {
    int m = strlen(s);
    int n = strlen(t);
    int d[m + 1][n + 1];
    int substitutionCost = 0;

    for (int i = 0; i < m; i++)
    {
        d[i][0] = i;
    }

    for (int j = 0; j < n; j++)
    {
        d[0][j] = j;
    }
  
  for(int j = 1; j <= n; j++) {
    for(int i = 1; i <= m; i++) {
      if(s[i - 1] == t[j - 1]) {
        substitutionCost = 0;
      } else {
        substitutionCost = 1;
      }

      d[i][j] = fmin(fmin(d[i - 1][j] + 1,
                                d[i][j - 1] + 1), 
                           d[i - 1][j - 1] + substitutionCost);
    }
  }
 
  return d[m][n];
}

int main(int argc, char const *argv[])
{
    char fisrtWord[100], secondWord[100];
    printf("Masukan kata pertama: ");
    scanf("%s", &fisrtWord);
    printf("Masukan kata kedua: ");
    scanf("%s", &secondWord);

    int distance = LevenshteinDistance(fisrtWord, secondWord);
    printf("Levenshtein distance between \"%s\" and \"%s\" is %d\n", fisrtWord, secondWord, distance);

    return 0;
}
