#include "process.h"

#ifndef MERGESORT_H
#define MERGESORT_H
  typedef struct element {
    process* process;
  } Element;

  typedef struct mergeSortElement {
    Element* element;
    int affinity;
  } MergeSortElement;

  void mergesort(MergeSortElement *v, int n, int decreasing);
  MergeSortElement* createMergeSortElement(Element* element, int affinity);
#endif
