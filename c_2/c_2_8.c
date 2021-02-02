#include<stdio.h>
#define MAXLINE 50

int getline(char s[], int len);
int convert_hex(char s[], int len);

int main(){
   int len, converted;
   char s[MAXLINE];
   while((len = getline(s, MAXLINE)) > 0){
       if(len > 1){
           printf("original is %s\n", s);
           converted = convert_hex(s, len);
           printf("Hex form is %d\n", converted);

       }

   }
}

int getline(char s[], int len){
    int i, c;
    i = c = 0;
    for(i; i < len -1 && (c = getchar()) != EOF && c != '\n'; ++i){
        s[i] = c;

    }
    if(c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int convert_hex(char hexVal[], int len)
{

    // Initializing base value to 1, i.e 16^0
    int base = 1, i;
    i = 0;
    int dec_val = 0;
    if(hexVal[i] == '0'){
            if(hexVal[i] == 'x' || hexVal == 'X'){
    // Extracting characters as digits from last character
    for (i=len-1; i>=2; i--)
    {
        // if character lies in '0'-'9', converting
        // it to integral 0-9 by subtracting 48 from
        // ASCII value.
        if (hexVal[i] >= '0' && hexVal[i]<='9')
        {
            dec_val += (hexVal[i] - 48)*base;

            // incrementing base by power
            base = base * 16;
        }

        // if character lies in 'A'-'F' , converting
        // it to integral 10 - 15 by subtracting 55
        // from ASCII value
        else if (hexVal[i]>='A' && hexVal[i]<='F')
        {
            dec_val += (hexVal[i] - 55)*base;

            // incrementing base by power
            base = base * 16;
        }
        else if(hexVal[i] >= 'a' && hexVal[i] <= 'f'){
            dec_val += (hexVal[i] - 'a' + 10) * base;
             base = base * 16;
        }
    }
  }
  else{
    return -1;
  }

}
 else{
        return -1;
    }

    return dec_val;
}
