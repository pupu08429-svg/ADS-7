// Copyright 2022 NNTU-CS
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "train.h"

int main() {
  const int kN = 60;
  std::srand(std::time(nullptr));

  // Все выключены
  Train train_off;
  int count = kN;
  while (count--) {
    train_off.addCar(false);
  }

  std::cout << " Все выключены " << std::endl;
  std::cout << "Длина: " << train_off.getLength() << std::endl;
  std::cout << "Операций: " << train_off.getOpCount() << std::endl;

  // Все включены
  Train train_on;
  count = kN;
  while (count--) {
    train_on.addCar(true);
  }

  std::cout << "\n Все включены " << std::endl;
  std::cout << "Длина: " << train_on.getLength() << std::endl;
  std::cout << "Операций: " << train_on.getOpCount() << std::endl;

  // Случайное распределение
  Train train_rand;
  count = kN;
  while (count--) {
    bool light = std::rand() % 2;
    train_rand.addCar(light);
  }

  std::cout << "\n Случайное распределение " << std::endl;
  std::cout << "Длина: " << train_rand.getLength() << std::endl;
  std::cout << "Операций: " << train_rand.getOpCount() << std::endl;

  return 0;
}
