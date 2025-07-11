#pragma once

#define VECTOR_INIT_CAPACITY 10

struct vector {
    bool (*append)(struct vector* pVec, void* data);
    void* (*get)(struct vector* pVec, int index);
    void (*clear)(struct vector *pVec);
    void (*remove)(struct vector* pVec, int index);

    void **pData;
    int size;
    int capacity;
};

void vectorInit(struct vector*);
void vectorDestroy(struct vector* pVec);