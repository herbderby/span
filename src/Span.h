//
// Created by Herb Derby on 5/23/20.
//
#pragma once
#include <array>
#include <type_traits>

template<typename T>
class Span {
public:
    constexpr Span(T* ptr, size_t size) : ptr_{ptr}, size_{size} {}
    template <typename U, typename = std::enable_if_t<std::is_same_v<const U, T>>>
    constexpr Span(const Span<U>& that) : Span{that.data(), that.size()} {}
    constexpr Span(const Span& o) = default;
    constexpr Span& operator=(const Span& that) = default;
    template<auto N>
    constexpr Span(T(&a)[N]) : Span{a, N} {}
    template<typename C>
    constexpr Span(C& c) : Span{std::data(c), std::size(c)} {}

    constexpr T& operator [] (size_t i) const { return ptr_[i]; }
    constexpr T* data() { return ptr_; }
    [[nodiscard]] constexpr size_t size() const { return size_; }

private:
    T* ptr_;
    size_t size_;
};

template<typename C>
Span(C) -> Span<std::remove_pointer_t<decltype(std::data(std::declval<C&>()))>>;
