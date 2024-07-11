#pragma once
#include <stack>
#include "libArray.h"
#include "libFile.h"
#include "StackArray.h"
#include "libStackList.h"

using namespace std;

/*
Funkcja testuje dzia³anie implelentacji stosu za pomoc¹ tablicy - punkt A
*/
void f_testArrayStack();

/*
Funkcja testuje dzia³anie implelentacji stosu za pomoc¹ listy jednokierunkowej - punkt B
*/
void f_testListStack();

/*
Funkcja testuje dzia³anie implelentacji stosu za pomoc¹ adaptera std::stack - punkt C
*/
void f_testAdapterStack();