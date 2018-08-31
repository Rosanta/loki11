#pragma once

#include <memory>
#include <functional>

namespace loki11 {

template <typename T, typename ...TArgs>
class FunctorImpl {
  public:
    virtual ~FunctorImpl() {};

    virtual T operator() (TArgs...args) = 0;
};

template <typename Parent, typename Func, typename ...TArgs>
class FuncHandler : public Parent::ImplType {
  public:
    virtual ~FuncHandler() {};

    virtual typename Parent::ReturnType operator() (TArgs ...args) {
      return func_(args...);
    }

    FuncHandler(const Func& func): func_(func) {}

  private:
    Func func_;
};

template <typename T, typename ...TArgs>
class Functor {
  public:
    typedef FunctorImpl<T, TArgs...> ImplType;

    typedef T ReturnType;

    explicit Functor(ImplType impl): impl_(impl) {}

    template <typename Func>
    Functor(Func func):
        impl_(new FuncHandler<Functor, Func, TArgs...>(func))
    {}

    T operator() (TArgs&&... args) {
      return (*impl_)(std::forward<TArgs>(args)...);
    }

  private:
    std::shared_ptr<ImplType> impl_;
};

}  // namespace loki11
