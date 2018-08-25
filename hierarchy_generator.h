#pragma once

#include "type_mainp.h"
#include "typelist.h"

namespace loki11 {

namespace hierarchy_generator {

// GenScatterHierarchy
template <class List, template <class> class Unit>
class GenScatterHierarchy;

namespace helper {

template <typename List, template <class> class Unit>
class GenScatterHierarchyHelper;

template <typename ...TArgs, typename A, template <class> class Unit>
class GenScatterHierarchyHelper<loki11::typelist::TypeList<A, TArgs...>, Unit> : 
    public Unit<A> {};

}   // namespace helper

template <template <class> class Unit>
class GenScatterHierarchy<loki11::typelist::TypeList<>, Unit> {};

template <typename ...TArgs, typename A, template <class> class Unit>
class GenScatterHierarchy<loki11::typelist::TypeList<A, TArgs...>, Unit>:
    public helper::GenScatterHierarchyHelper<loki11::typelist::TypeList<A, TArgs...>, Unit>,
    public GenScatterHierarchy<loki11::typelist::TypeList<TArgs...>, Unit>
{};

// Field
template <typename T, typename List, template <class> class Unit>
Unit<T>& Field(GenScatterHierarchy<List, Unit>);

template <typename T, typename ...TArgs, template<class> class Unit>
Unit<T>& Field(GenScatterHierarchy<loki11::typelist::TypeList<TArgs...>, Unit>& obj) {
    return obj;
}

}   // hierarchy_generator

}   // namespace loki11