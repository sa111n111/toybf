#include <stdio.h>
#include <stdint.h>

char tape[3000] = {0}; 
char *data_pointer;
char *program_pointer;

void parse_brainfuck(char* program) {
    int loop_trigger;
    data_pointer = tape;
    program_pointer = program;

    while(*program_pointer) {
        switch(*program_pointer) {
            case '>':
            data_pointer++;
            break;

            case '<':
            data_pointer--;
            break;

            case '+':
            (*data_pointer)++;
            break;

            case '-':
            (*data_pointer)--;
            break;

            case '.':
            printf("%c", *data_pointer);
            break;

            case ',':
            getchar();
            break;

            case '[':
            loop_trigger = 1;

            while(loop_trigger != 0) {
                switch(*program_pointer) {
                    case '[': loop_trigger++;
                    case ']': loop_trigger--;
                }
                program_pointer++;
            }
            break;

            case ']':
            loop_trigger = 1;
            while(loop_trigger != 0) {
                switch(*program_pointer) {
                    case '[': loop_trigger++;
                    case ']': loop_trigger--;
                }
                program_pointer--;
            }
            break;
        }

       program_pointer++;
    }
}

int main() {
    parse_brainfuck(">++++++++[<+++++++++>-]<.>++++[<+++++++>-]<+.+++++++..+++.>>++++++[<+++++++>-]<++.------------.>++++++[<+++++++++>-]<+.<.+++.------.--------.>>>++++[<++++++++>-]<+.");
}
