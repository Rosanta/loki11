#pragma once

namespace loki11 {

template <bool>
struct CompileError;

template <>
struct CompileError<true> {};

}   // namespace loki11
