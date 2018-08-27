#pragma once 

#include <type_traits>

namespace loki11 {

// TypeList
template <typename ... TArgs> 
struct TypeList {};

// Length
template <typename List>
struct Length;

template <typename ... TArgs>
struct Length<TypeList<TArgs...>> {
    enum { value = std::integral_constant<int, sizeof...(TArgs)>::value };
};

// TypeAt
template <typename List, int index> 
struct TypeAt;

template <typename ...TArgs, typename A> 
struct TypeAt<TypeList<A, TArgs...>, 0>{
    typedef A type;
};

template <typename ...TArgs, typename Head, int index> 
struct TypeAt<TypeList<Head, TArgs...>, index> {
    typedef typename TypeAt<TypeList<TArgs...>, index - 1>::type type;
};

// TypeAtNonStrict
template <typename List, int index, typename Default> 
struct TypeAtNonStrict {
    typedef Default type;
};

template <typename ...TArgs, typename A, typename Default> 
struct TypeAtNonStrict<TypeList<A, TArgs...>, 0, Default> {
    typedef A type;
};

template <typename ...TArgs, typename Head, int index, typename Default>
struct TypeAtNonStrict<TypeList<Head, TArgs...>, index, Default> {
    typedef typename TypeAtNonStrict<TypeList<TArgs...>, index - 1, Default>::type type;
};

// IndexOf
template <typename List, typename T>
struct IndexOf;

template <typename ...TArgs, typename A> 
struct IndexOf<TypeList<A, TArgs...>, A> {
    enum { value = 0 };
};

template <typename T> 
struct IndexOf<TypeList<>, T> {
    enum { value = -1 };
};

template <typename ...TArgs, typename A, typename T> 
struct IndexOf<TypeList<A, TArgs...>, T> {
    enum { value = IndexOf<TypeList<TArgs...>, T>::value == -1 ? -1 :
                   IndexOf<TypeList<TArgs...>, T>::value + 1 };
};

// Append
template <typename List, typename T>
struct Append;

template <typename ...TArgs, typename T>
struct Append<TypeList<TArgs...>, T> {
    typedef TypeList<TArgs..., T> type;
};

// PopHead
template <typename List, int nelem>
struct PopHead;

template <typename A, typename ...TArgs>
struct PopHead<TypeList<A, TArgs...>, 0> {
    typedef TypeList<A, TArgs...> type;
};

template <typename A, typename ...TArgs, int nelem>
struct PopHead<TypeList<A, TArgs...>, nelem> {
    typedef typename PopHead<TypeList<TArgs...>, nelem - 1>::type type;
};

}   // namespace loki11