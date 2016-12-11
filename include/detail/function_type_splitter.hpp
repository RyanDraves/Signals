#ifndef FUNCTION_TYPE_SPLITTER_HPP
#define FUNCTION_TYPE_SPLITTER_HPP

#include <tuple>

namespace mcurses {

template <typename Function>
class Function_type_splitter;

// Useful for extracting the return and argument types from a function.
template <typename Ret, typename... Args>
class Function_type_splitter<Ret(Args...)> {
   public:
    static const int arity = sizeof...(Args);

    using return_type = Ret;
    using argument_tuple_type = std::tuple<Args...>;
};

}  // namespace mcurses

#endif  // FUNCTION_TYPE_SPLITTER_HPP
