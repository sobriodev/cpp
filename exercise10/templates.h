#ifndef EXERCISE10_TEMPLATES_H
#define EXERCISE10_TEMPLATES_H

#include "SpecialClass.h"

template <class T>
void swap(T &l, T &r) {
    T temp = l;
    l = r;
    r = temp;
}

template <class T>
void selectionSort(T elements[], int size) {
    int k;
    for (int i = 0; i < size - 1; ++i) {
        k = i;
        for (int j = i + 1; j < size; ++j) {
            if (elements[j] < elements[k]) {
                k = j;
            }
        }
        swap(elements[i], elements[k]);
    }
}

void selectionSort(SpecialClass elements[], int size) {
    int k;
    for (int i = 0; i < size - 1; ++i) {
        k = i;
        for (int j = i + 1; j < size; ++j) {
            if (elements[j].getString().length() < elements[k].getString().length()) {
                k = j;
            }
        }
        swap(elements[i], elements[k]);
    }
}

template <class T>
void quickSort(T elements[], int left, int right) {
    if (right <= left) return;

    int i = left - 1;
    int j = right + 1;
    T pivot = elements[(left + right) / 2];

    while (true)
    {
        while (pivot > elements[++i]);
        while (pivot < elements[--j]);

        if (i <= j) {
            swap(elements[i], elements[j]);
        } else {
            break;
        }
    }
    if (j > left) { quickSort(elements, left, j); }
    if (i < right) { quickSort(elements, i, right); }
}

void quickSort(SpecialClass elements[], int left, int right) {
    if (right <= left) return;

    int i = left - 1;
    int j = right + 1;
    SpecialClass pivot = elements[(left + right) / 2];

    while (true)
    {
        while (pivot.getString().length() > elements[++i].getString().length());
        while (pivot.getString().length() < elements[--j].getString().length());

        if (i <= j) {
            swap(elements[i], elements[j]);
        } else {
            break;
        }
    }
    if (j > left) { quickSort(elements, left, j); }
    if (i < right) { quickSort(elements, i, right); }
}

#endif
