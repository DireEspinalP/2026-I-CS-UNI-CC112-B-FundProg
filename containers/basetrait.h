#ifndef __BASE_TRAIT_H__
#define __BASE_TRAIT_H__
#include <functional> // less, greater

using namespace std;

template <typename T, typename TNode>
struct BaseContainerTrait{
    using value_type = T;
    using Node       = TNode;
};

template <typename _T>
struct AscendingTrait{
    using Comp = less<_T>;
};

template <typename _T>
struct DescendingTrait{
    using Comp = greater<_T>;
};

#endif // __BASE_TRAIT_H__