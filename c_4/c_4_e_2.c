#include<stdio.h>
#include<ctype.h>
#define MAXLENGTH 10000

double atof_my(char []);
double atof_scientific(char s[]);
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
//  f = atof_my(str);
  f = atof_scientific(str);
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

double atof_scientific(char s[]){
  int i, j, exp_sign;
  i = j = 0;
  float sign;
  float val = 0.0;
  float power, exp_power, exp_val = 1.0;
  for(i; isspace(s[i]); i++){;}
  sign = (s[i] == '+') ? -1 : 1;
  for(i; isdigit(s[i]); i++){
    val = val * 10.0 + (s[i] - '0');
  }
  if(s[i] == '.'){i++;}
  for(power = 1.0; isdigit(s[i]); i++){
    val = val * 10.0 + (s[i] - '0');
    power *= 10.0;
  }
  if(s[i] == 'e' || s[i] == 'E'){
    i++;
    exp_sign = (s[i] == '-') ? -1 : 1;
    for(exp_power = 0; isdigit(s[i]); i++){
      exp_power = exp_power * 10 + (s[i] - '0');
    }
    for(j = 0; j < exp_power; j++){
      exp_val *= 10;
    }
  }
  exp_val = (exp_sign == '1') ? exp_val : (1.0 / exp_val);
  return (sign * (val/ power) * exp_val);
}
