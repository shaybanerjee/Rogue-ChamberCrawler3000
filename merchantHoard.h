#ifndef _MERCHANT_HOARD_H
#define _MERCHANT_HOARD_H
#include "treasure.h"

class MerchantHoard: public Treasure{
public:
	MerchantHoard();
    char getSymb() override;
};

#endif
