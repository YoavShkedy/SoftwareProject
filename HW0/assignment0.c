#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main() {
    int source_base, target_base, num, quotient, remainder, i, j;
    char result[100], input_num[100];
    
    // Get the source base
    printf("Enter the source base: ");
    scanf("%d", &source_base);

    if (source_base < 2 || source_base > 16) {
        printf("Invalid source base!\n");
        return 1;
    }
    
    // Get the target base
    printf("Enter the target base: ");
    scanf("%d", &target_base);
    
    if (target_base < 2 || target_base > 16) {
        printf("Invalid target base!\n");
        return 1;
    }
    
    // Get the input number
    printf("Enter a number in base %d: ", source_base);
    scanf("%s", input_num);

    for (i = 0; input_num[i] != '\0'; i++) {

        if (!isalnum(input_num[i]) || isalpha(input_num[i]) && toupper(input_num[i]) > source_base + 'A' - 11) {
            printf("Invalid input number!\n");
            return 1;
        }
        
        num = num * source_base + (isdigit(input_num[i]) ? input_num[i] - '0' : toupper(input_num[i]) - 'A' + 10);
    }
    
    // Convert to target base
    quotient = num;
    i = 0;

    while (quotient > 0) {
        remainder = quotient % target_base;
        result[i++] = (remainder < 10) ? remainder + '0' : remainder + 'A' - 10;
        quotient /= target_base;
    }
    
    // Print the result in reverse order
    printf("The number in base %d is: ", target_base);

    for (j = i - 1; j >= 0; j--) {
        printf("%c", result[j]);
    }

    printf("\n");
    
    return 0;
}
