#pragma once

#include "type_mainp.h"
#include "typelist.h"

namespace loki11 {

// GenScatterHierarchy
template <class List, template <class> class Unit>
class GenScatterHierarchy;

namespace helper {

template <typename List, template <class> class Unit>
class GenScatterHierarchyHelper;

template <typename ...TArgs, typename A, template <class> class Unit>
class GenScatterHierarchyHelper<TypeList<A, TArgs...>, Unit> : 
    public Unit<A> {};

}   // namespace helper

template <template <class> class Unit>
class GenScatterHierarchy<TypeList<>, Unit> {};

template <typename ...TArgs, typename A, template <class> class Unit>
class GenScatterHierarchy<TypeList<A, TArgs...>, Unit>:
    public helper::GenScatterHierarchyHelper<TypeList<A, TArgs...>, Unit>,
    public GenScatterHierarchy<TypeList<TArgs...>, Unit>
{};

// Field
template <typename T, typename List, template <class> class Unit>
Unit<T>& Field(GenScatterHierarchy<List, Unit>);

template <typename T, typename ...TArgs, template<class> class Unit>
Unit<T>& Field(GenScatterHierarchy<TypeList<TArgs...>, Unit>& obj) {
    return obj;
}

// Field with index
template <int index,  typename List, template <class> class Unit>
Unit<typename TypeAt<List, index>::type>& 
Field(GenScatterHierarchy<List, Unit>& obj);

namespace helper {

template <int index, typename List, template <class> class Unit> 
struct ScatterHierarchyTypeExtractor {
    typedef GenScatterHierarchyHelper<
        typename PopHead<List, index>::type, Unit> type;
};

template <int index, typename List, template <class> class Unit>
typename ScatterHierarchyTypeExtractor<index, List, Unit>::type&
FeildWithIndexHelper(GenScatterHierarchy<List, Unit>& obj) {
    return obj;
}

}   // namespace helper

template <int index, typename ...TArgs, template <class> class Unit>
Unit<typename TypeAt<TypeList<TArgs...>, index>::type>&
Field(GenScatterHierarchy<TypeList<TArgs...>, Unit>& obj) {
    return helper::FeildWithIndexHelper<index, TypeList<TArgs...>>(obj);
}

}   // namespace loki11
