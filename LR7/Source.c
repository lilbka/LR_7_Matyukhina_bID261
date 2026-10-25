#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES 
#include <locale.h>
#include <stdio.h>
#include <math.h>

int symbol(char c);
float calculate(float x, float y, char operation);
char pow_prefix(int pow);

int main()
{
    setlocale(LC_ALL, "RUS");

    // задание 1

    char c;
    int result_sym;

    printf("введите символ: ");
    scanf(" %c", &c);

    result_sym = symbol(c);

    switch (result_sym)
    {
    case 1:
        printf("'%c' - это цифра.\n\n", c);
        break;
    case 2:
        printf("'%c' - это английская буква.\n\n", c);
        break;

    default:
        printf("'%c' - неопознанный символ\n\n", c);
        break;
    }

    // задание 2

    float x, y, result_calc;
    char operation;

    printf("введите выражение без пробелов: ");
    if (scanf("%f%c%f", &x, &operation, &y) != 3)
    {
        printf("ошибка формата ввода\n\n");
        return 1;
    }

    if (operation != '+' && operation != '-' && operation != '*' && operation != '/' && operation != '^')
    {
        printf("неизвестная операция '%c'.\n\n", operation);
    }
    else if (operation == '/' && y == 0.0f)
    {
        printf("деление на ноль невозможно.\n\n");
    }
    else
    {
        result_calc = calculate(x, y, operation);
        printf("= %f\n\n", result_calc);
    }

    // задание 3 (вариант 18)

    int pow_val;
    char prefix;

    printf("введите степень двойки (10, 20, 30, 40, 50, 60): ");
    if (scanf("%d", &pow_val) != 1)
    {
        printf("ошибка формата ввода!\n");
        return 1;
    }

    prefix = pow_prefix(pow_val);

    if (prefix == '0')
    {
        printf("неизвестная степень двойки (%d).\n", pow_val);
    }
    else
    {
        printf("2^%d соответствует приставке: %c\n", pow_val, prefix);
    }

    return 0;
}

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

        // заглавные буквы 
    case 'A': case 'B': 
    case 'C': case 'D': 
    case 'E': case 'F':
    case 'G': case 'H': 
    case 'I': case 'J': 
    case 'K': case 'L':
    case 'M': case 'N': 
    case 'O': case 'P': 
    case 'Q': case 'R':
    case 'S': case 'T': 
    case 'U': case 'V': 
    case 'W': case 'X':
    case 'Y': case 'Z':

        // строчные буквы
    case 'a': case 'b': 
    case 'c': case 'd': 
    case 'e': case 'f':
    case 'g': case 'h': 
    case 'i': case 'j': 
    case 'k': case 'l':
    case 'm': case 'n': 
    case 'o': case 'p': 
    case 'q': case 'r':
    case 's': case 't': 
    case 'u': case 'v': 
    case 'w': case 'x':
    case 'y': case 'z':

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