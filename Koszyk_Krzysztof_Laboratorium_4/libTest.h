#pragma once
#include <stack>
#include "libArray.h"
#include "libFile.h"
#include "StackArray.h"
#include "libStackList.h"

using namespace std;

/*
Funkcja testuje dzia�anie implelentacji stosu za pomoc� tablicy - punkt A
*/
void f_testArrayStack();

/*
Funkcja testuje dzia�anie implelentacji stosu za pomoc� listy jednokierunkowej - punkt B
*/
void f_testListStack();

/*
Funkcja testuje dzia�anie implelentacji stosu za pomoc� adaptera std::stack - punkt C
*/
void f_testAdapterStack();