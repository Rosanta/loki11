#pragma once 

#include "hierarchy_generator.h"
#include "typelist.h"

namespace loki11 {

template <typename T>
struct TupleUnit {
  public:
    T value_;
    T& Get() { return value_; }
};

template <typename ...TArgs> 
struct Tuple : public GenScatterHierarchy<TypeList<TArgs...>, TupleUnit> {
//    typedef GenScatterHierarchy<TypeList<TArgs...>, TupleUnit> type;
};

template <int index, typename ...TArgs>
TupleUnit<typename TypeAt<TypeList<TArgs...>, index>::type>&
Field(Tuple<TArgs...>& obj) {
    return helper::FeildWithIndexHelper<index, TypeList<TArgs...>>(obj);
} 

}   // namespace loki11