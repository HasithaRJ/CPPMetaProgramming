#pragma once

/*
// Usage:
// 	using myTypes = HS_TypeList<int, char, bool, void>;
//	static_assert(myTypes::HasType<int>());
*/
#include "type_traits"

template <typename... T> //primary template
struct HS_TypeList {};

template <typename T0, typename... Types>
struct HS_TypeList<T0, Types...>
{
	using Head = T0;
	using Tail = HS_TypeList<Types...>;

	template <typename T>
	static constexpr bool HasType() // A function template accepting template parameter as a input to check if the given type is exsiting
	{
		return Tail::template HasType<T>(); // type name dance - T depend on the Tail which is also a type
	}

	template<>
	static constexpr bool HasType<T0>() { return true; }

};

template <typename T0> // Partial specialization omitting list. For lists with size 1
struct HS_TypeList<T0>
{
	using Head = T0;
	using Tail = void;

	template<typename T>
	static constexpr bool HasType()
	{
		return std::is_same_v<T0, T>();
	}

};

template <>
struct HS_TypeList<>
{
	using Head = void;
	using Tail = void;

	template<typename T>
	static constexpr bool HasType() { return false; }
};
