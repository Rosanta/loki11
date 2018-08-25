#pragma once

namespace loki11 {

namespace type_mainp {

template <int i>
struct Int2Type {
    enum { value = i };
};

}   // namespace type_mainp

}   // namespace loki11
