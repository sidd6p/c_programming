#include<stdio.h>
#include<ctype.h>
#define MAXLENGTH 10000

double atof_my(char []);
int main(){
  int i = 0;
  char c, str[MAXLENGTH];
  float f;
  for(i = 0; i < MAXLENGTH; i++){
    str[i] = '0';
  }
  while((c = getchar()) != '\n'){
    str[i] = c;
    i++;
  }
  f = atof_my(str);
  printf("Float is %f", f);
  return 0;

}
double atof_my(char s[]){
  double val, power;
  int i, sign;
  for(i = 0; isspace(s[i]); i++){;}
  sign = (s[i] == '-') ? -1 : 1;
  if(s[i] == '+' || s[i] == '-'){i++;}
  for(val = 0.0; isdigit(s[i]); i++){
    val = 10.0 * val + (s[i] - '0');
  }
  if(s[i] == '.'){i++;}
  for(power = 1.0; isdigit(s[i]); i++){
    val = val * 10.0 + (s[i] - '0');
    power *= 10.0;
  }
  return (sign * val) / power;
}
