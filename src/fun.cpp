// Copyright 2022 UNN-IASR
#include "fun.h"
#include <math.h>

unsigned int faStr1(const char *str) {
    bool inWord = false;
    bool cifra = false;
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            inWord = true;
            if (str[i] >= '0' && str[i] <= '9') {
                cifra = true;
            }
            else if (str[i] == ' ' && inWord == true) {
                if (cifra ==  false) {
                    count++;
                }
                inWord = false;
                cifra = false;
            }
        }
        i++; 
    }
    return count;
}

unsigned int faStr2(const char *str) {
    bool first = true;
    bool correct = false;
    bool second = false;
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ')
        {
            correct = false;
            if (str[i] >= 'A' && str[i] <= 'Z' && first == true) {
                correct = true;
                first = false;
            }
            else if (str[i] >= 'a' && str[i] <= 'z') {
                first = false;
                second = true;
            }
            else {
                if (correct == true && second == true) {
                    count +=1;
                }
                first = true;
                correct = false;
                second = false;
            }
        }
        i++;
    }
    return count;
    
}

unsigned int faStr3(const char *str) {
    bool inWord = false;
    int count = 0;
    int len = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ' && inWord == false) {
            if (inWord == false) {
                inWord = true;
                count += 1;
            }
            len += 1;
        }
        else if (str[i] == ' ' && inWord == true) {
            inWord = false;
        }
        i++;
    }
    float ans = static_cast<float>(len) / count;
    if (count == 0) {
        return 0;
    }
    else {
        if ((ans - static_cast<int>(ans)) >= 0.5) {
            return static_cast<int>(ans) + 1;
        }
        else {
            return static_cast<int>(ans);
        }
    } 
}

