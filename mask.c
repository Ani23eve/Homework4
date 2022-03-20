#include <stdio.h>
#include <stdint.h>

int setBit(__uint32_t mask, unsigned bit){
    return mask|(1<<bit);
}

int clearBit(__uint32_t mask, unsigned bit){
    return mask&~(1<<bit);
}

int changeBit(__uint32_t mask, unsigned bit){
    return mask^(1<<bit);
}

int checkBit(__uint32_t mask, unsigned bit){
    return (mask & (1 << bit)) >> bit;
}


// Trqbwa da ima kak da razberem dali funkciqta e poluchila korekten nomer na uchenik
// ili e poluchila nekorekten nomer na uchenik
// ili e poluchila krai na vyvejdaneto
int enterStudent(int* student_number){
    printf("Enter student number: ");
    if(scanf("%d", student_number) == EOF){
        return 2;
    }
    if(*student_number >= 1 && *student_number <= 32){
        return 0;
    }
    return 1;
}

void printStudents(int attendance_mask, int students_in_class, int is_attending){
    for(int student_number = 1; student_number <= students_in_class; student_number++){
        if(checkBit(attendance_mask, student_number - 1) ==  is_attending){
            printf("%d ", student_number);
        }
    }
}

int main(){
    __uint32_t attendance = 0;
    int option;
    int student_number;
    int students_in_class = 32;
    while (1){
        printf("1. Set attendance\n");
        printf("2. Clear attendance\n");
        printf("3. Attendance info\n");
        printf("4. Change attendance\n");
        printf("5. Exit\n");    
        scanf("%d", &option);
        if (option == 1)
        {  
            while(1){
                int enter_res = enterStudent(&student_number);
                if (enter_res == 0){
                    attendance = setBit(attendance, student_number - 1);
                }
                else if(enter_res == 1){
                    break;
                }
            }
        }
        else if (option == 2)
        {
            while(1){
                int enter_res = enterStudent(&student_number);
                if (enter_res == 0){
                    attendance = clearBit(attendance, student_number - 1);
                }
                else if(enter_res == 1){
                    break;
                }
            }
        }
        else if (option == 3)
        {
            printf("Attending students: ");
            printStudents(attendance, students_in_class, 1);
            printf("\n");
            printf("Absent students: ");
            printStudents(attendance, students_in_class, 0);
            printf("\n");
        }
        else if(option==4){
            while(enterStudent(&student_number) != 0){
                printf("Invalid Number\n");
            }
            attendance = changeBit(attendance, student_number - 1);
        }
        else if(option==5){
            break;
        }
        else{
            printf("Unkown option. Please choose from 1 2 3 4 5.\n");
        }
    
    }
    return 0;  
}

    

        