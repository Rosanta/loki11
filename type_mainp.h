#pragma once

namespace loki11 {

template <int i>
struct Int2Type {
    enum { value = i };
};

}   // namespace loki11
