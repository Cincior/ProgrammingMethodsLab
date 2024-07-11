#pragma once
class cDouble
{
public:
    double a, b;
    cDouble(double a, double b)
    {
        this->a = a;
        this->b = b;
    }
};

class cChar
{
public:
    char* a;
    char* b;
    cChar(char* a, char* b)
    {
        this->a = a;
        this->b = b;
    }
};

class cFloat
{
public:
    float a, b;
    cFloat(float a, float b)
    {
        this->a = a;
        this->b = b;
    }
};

class cInt
{
public:
    int a, b;
    cInt(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
};
