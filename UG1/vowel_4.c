#include<stdio.h>
int main() {
	char huhu;
  printf("write your alphabet to find whether its vowel or consonant:");
  scanf("%c",&huhu);
if(huhu == 'a' || huhu == 'A' || huhu == 'e' || huhu == 'E' || huhu == 'i' || huhu == 'I' || huhu == 'o' || huhu == 'O' || huhu == 'u' || huhu == 'U') {
	printf("its a vowel");
  }
else {
        printf("its consonant"); 
  }
}
