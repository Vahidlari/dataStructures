#ifndef BASEDATATYPE_INCLUDED_
#define BASEDATATYPE_INCLUDED_

template <typename Ttype>
class CBaseDataType
{
public:
    static void swap(Ttype& a, int srcIdx, int dstIdx);
    static void print(Ttype a);       
private:
};

#include "baseDataType.inl"
#endif //BASEDATATYPE_INCLUDED_