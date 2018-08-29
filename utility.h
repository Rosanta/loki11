#pragma once

namespace loki11 {

struct EmptyType {};

template <bool>
struct CompileError;

template <>
struct CompileError<true> {};

}   // namespace loki11
