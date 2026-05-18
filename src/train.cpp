// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

Train::~Train() {
  if (first == nullptr) return;
  Cage* current = first;
  do {
    Cage* nextCage = current->next;
    delete current;
    current = nextCage;
  } while (current != first);
}
void Train::addCar(bool light) {
  Cage* newCage = new Cage{ light, nullptr, nullptr };
  if (first == nullptr) {
    first = newCage;
    first->next = first;
    first->prev = first;
  }
  else {
    Cage* last = first->prev;
    last->next = newCage;
    newCage->prev = last;
    newCage->next = first;
    first->prev = newCage;
    }
}
void Train::resetOpCount() {
  countOp = 0;
}
int Train::getOpCount() {
  return countOp;
}
void Train::setStartPosition(int index) {
  if (first == nullptr || index == 0) return;
  Cage* target = first;
  for (int i = 0; i < index; ++i) {
    target = target->next;
  }
  first = target;
}

int Train::getLength() {
  if (first == nullptr) return 0;
  first->light = true;
  int length = 0;
  while (true) {
    int steps = 0;
    Cage* current = first;
    while (true) {
      current = current->prev;
      countOp++;
      steps++;
      if (current->light) {
        break;
      }
    }
    current->light = false;
    for (int i = 0; i < steps; ++i) {
      current = current->next;
      countOp++;
    }
    if (steps > length) {
      length = steps;
    }
    if (current == first && !first->light && steps == length) {
      break;
    }
  }
  return length;
}
