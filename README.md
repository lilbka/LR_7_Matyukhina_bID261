# Лабораторная работа №7
## Блок-схема к заданию 1:
https://sun9-37.vkuserphoto.ru/s/v1/ig2/uDr6IIm0WrpxFc3glPxT-0o-7Xq043gWti1Dj8o2DAcPGA_PFRNyWcmxhr5-Zwb03OY6_HKOuP7exj1744OxNYYa.jpg?quality=95&as=32x33,48x50,72x75,108x113,160x167,240x250,360x376,480x501,540x563,640x668,671x700&from=bu&u=lE8C6wSbygJzqaxzuJUIo0EaMcmLDSgcCsFRH-v7gog&cs=671x0

## 1. Условие задачи номер 3 (вариант 18)
Напишите программу, которая интерпретирует степени 2 в соответствующие приставки (10 – K, 20 – M, G, T, P, E).

## Блок-схема к заданию 3

https://sun9-52.vkuserphoto.ru/s/v1/ig2/zN3xqZvYKwUlN6r4R6UcNkH3UOQf3ObeEzaNrqx_dWN94QZg1l0DE56vErRM2Sgbv_SswxtYkXW1HuaByj_yuuQL.jpg?quality=95&as=32x17,48x26,72x39,108x59,160x87,240x130,360x195,480x261,540x293,640x347,720x391,1080x586,1280x695&from=bu&u=NQUnjnC45cJOLUig6uZfEYaHxp1N9B2WoDG8VOFp3us&cs=1280x0

## 2. Реализация программы
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES 
#include <locale.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h> // модуль числа

int zad3(void);

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
    zad3();

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

## 3. Результаты работы программы
введите степень двойки (10, 20, 30, 40, 50, 60): 10
2^10 соответствует приставке: K

## 4. Информация о разработчике
Матюхина Софья, бИД-261
