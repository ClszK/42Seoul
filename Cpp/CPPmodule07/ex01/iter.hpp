#pragma once

#include <iostream>

template <typename T_Arr, typename T_Func>
void iter(T_Arr* arr, size_t length, T_Func func) {
  if (arr == NULL || func == NULL) return;
  for (size_t i = 0; i < length; ++i) func(arr[i]);
}