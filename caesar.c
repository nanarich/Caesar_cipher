/*  theoritical idear from https//:en.wikipedia.org/wiki/Caesar_cipher
 *  Authour: Richard Adusei
 *  email: nanaregi86@gmail.com
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define N 2 /*  number of shifts */

char scheme[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

/* return index from scheme for computation */
int return_index(int t)
{
  int i;
  for(i = 0; i < 26; i++){
    if(scheme[i] == t){
  		return i;
  	} 
  }	
}


int main()
{
  int index, i = 0;
  char encrypt;
  /*  message to encrypt */
  char msg[] = "ABCDEFHGIJKLMNOPQRSTUVWXYZ";
  char encrypted[64] = {0};
  
  printf("Message: %s\n", msg);
  
  /* encryption */
  puts("Encrypting message ...");
  while(msg[i]){
  	if(isupper(msg[i])){
		index = return_index(msg[i]);
		encrypted[i] = scheme[(index + N) % 26];
	}
	i++;
  }
  
  puts(encrypted);
  
  /* decryption */
  i = 0;
  puts("Decrypting message ...");
  while(encrypted[i]){
  	int md;
  	if(isupper(encrypted[i])){
		index = return_index(encrypted[i]);
		md = (index - N) % 26;   // to compensate for c modulo operation
		putchar(scheme[md < 0 ? md + 26 : md]);
	}
	i++;
  }
  putchar('\n');
  
  
}
