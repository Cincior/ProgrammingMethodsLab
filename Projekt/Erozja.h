#pragma once
#include "Przeksztalcenie.h"
#include "BitmapaExt.h"
class Erozja : public Przeksztalcenie
{
public:
    void przeksztalc(Bitmapa& bitmap) override;
};
