#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES 
#include <locale.h>
#include <stdio.h>
#include <math.h>


int zad1(void);
int zad2(void);
int zad3(void);

int symbol(char c)
{
    switch (c)
    {
    case '0': case '1': 
    case '2': case '3': 
    case '4': case '5': 
    case '6': case '7': 
    case '8': case '9':
        return 1; // цифры

    case 'A': case 'a':
    case 'B': case 'b':
    case 'C': case 'c':
    case 'D': case 'd':
    case 'E': case 'e':
    case 'F': case 'f':
    case 'G': case 'g': 
    case 'H': case 'h': 
    case 'I': case 'i': 
    case 'J': case 'j':
    case 'K': case 'k': 
    case 'L': case 'l':
    case 'M': case 'm': 
    case 'N': case 'n': 
    case 'O': case 'o': 
    case 'P': case 'p':
    case 'Q': case 'q': 
    case 'R': case 'r':
    case 'S': case 's': 
    case 'T': case 't': 
    case 'U': case 'u': 
    case 'V': case 'v': 
    case 'W': case 'w': 
    case 'X': case 'x':
    case 'Y': case 'y':
    case 'Z': case 'z':
        return 2; // буквы

    default:
        return 0; // другие символы

    }
}

float calculate(float x, float y, char operation)
{
    switch (operation)
    {
    case '+': 
        return x + y;
    case '-': 
        return x - y;
    case '*': 
        return x * y;
    case '/': 
        return x / y; 
    case '^': 
        return pow(x, y);

    default:  
        return 0; 
    }
}

char pow_prefix(int pow)
{
    switch (pow) 
    {
    case 10:
        return 'K'; // киби 2^10
    case 20:
        return 'M'; // меби 2^20
    case 30:
        return 'G'; // гиби 2^30
    case 40:
        return 'T'; // теби 2^40
    case 50:
        return 'P'; // пеби 2^50
    case 60:
        return 'E'; // экби 2^60

    default:
        return '0';
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");

    zad1();
    zad2();
    zad3();

    return 0;
}

int zad1(void)
{
    char c;
    int result;

    printf("введите символ: ");
    scanf("%c", &c);

    result = symbol(c);

    switch (result)
    {
    case 1:
        printf("'%c' - это цифра.\n", c);
        break;
    case 2:
        printf("'%c' - это английская буква.\n", c);
        break;

    default:
        printf("'%c' - неопознанный символ\n\n\n", c);
        break;
    }

    return 0;
}

int zad2(void)
{
    float x, y, result;
    char operation;

    printf("введите выражение без пробелов: ");

    if (scanf("%f%c%f", &x, &operation, &y) != 3) 
    {
        printf("ошибка формата ввода\n\n");
        while (getchar() != '\n');
        return 1;
    }

    if (operation != '+' && operation != '-' && operation != '*' && operation != '/' && operation != '^') 
    {
        printf("неизвестная операция '%c'.\n\n", operation);
        return 1;
    }

    if (operation == '/' && y == 0.0f) 
    {
        printf("деление на ноль невозможно.\n\n");
        return 1;
    }

    result = calculate(x, y, operation);

    printf("= %f\n\n\n", result);

    return 0;
}

int zad3(void) //вариант 18
{
    int pow;
    char prefix;

    printf("введите степень двойки (10, 20, 30, 40, 50, 60): ");

    if (scanf("%d", &pow) != 1) 
    {
        printf("ошибка формата ввода!\n");
        return 1;
    }

    prefix = pow_prefix(pow);

    if (prefix == '0') 
    {
        printf("неизвестная степень двойки (%d).\n", pow);
    }

    else 
    {
        printf("2^%d соответствует приставке: %c\n", pow, prefix);
    }

    return 0;
}