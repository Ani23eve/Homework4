#include <stdio.h>
#include <ctype.h>
#include <string.h>

int validNumber(char* number){
    for(int i=0;i<strlen(number); i++){
        if(!isalpha(number[i])&&!isdigit(number[i])){
            return 1;
        }
    }
    return 0;
}

int enterNumber(char* number){
    scanf("%s",number);
    return validNumber(number);
}

int validBase(int base){
    if(base>=2 && base<=36){
        return 0;
    }
    return 1;
}

int enterBase(int* base ){
    scanf("%d", base);
    return validBase(*base);
}

int symbolToNumber(char symbol, int base){
    if(symbol >='0' && symbol <= '9'){
        return symbol - '0';
    }
    if(symbol >= 'a' && symbol <= 'z'){
        return symbol - 'a' + 10;
    }
    if(symbol >= 'A' && symbol <= 'Z'){
        return symbol - 'A' + 10;
    }
}

char numberToSymbol(int number, int base){
    if(number < 10 ){
        return '0' + number;
    }
    return 'A' + (number - 10);
}


// ot base kym decimal
long convertToDecimal(int base, char* number){
    long result = 0;
    for(int i = 0; i < strlen(number); i++){
        result *= base;
        result += symbolToNumber(number[i], base);
    }
    return result;
} 

void recursiveConversionFromDecimalTo(int base, long number){
    long res = number / base;
    int reminder = number % base;
    if(res != 0)
        recursiveConversionFromDecimalTo(base, res);
    printf("%c", numberToSymbol(reminder, base));
}



int main(){
    char number[100];
    int base1, base2;
    enterNumber(number);
    enterBase(&base1);
    enterBase(&base2);
    long n = convertToDecimal(base1, number);
    recursiveConversionFromDecimalTo(base2, n);
    printf("\n");
    return 0;
}


