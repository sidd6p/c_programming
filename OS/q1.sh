#!/bin/sh

read n

for ((index=1; index<=n; index++)){
    for ((indent=index; indent<=n; indent++)){ #loop for left indent
         echo -n -e "\t"
    }
    for((count=0; count<2\*index;count++)){ #loop for printing the value
        echo -e -n "$index\t" 
    }
    echo -e "\n"
}
