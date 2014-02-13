#pragma once

#include <type_traits>
#include <Furrovine++/inline.h>
#include <Furrovine++/integral_type.h>
#include <Furrovine++/array_view.h>

namespace Furrovine {

#define enummathoperatorsbyusing( TEnum, TOther, TIntegral ) \
	inlinealways TEnum operator+ (const TEnum a, const TOther b) \
	{return static_cast<TEnum>(static_cast<TIntegral>(a) + static_cast<TIntegral>(b));} \
	inlinealways TEnum operator- (const TEnum a, const TOther b) \
	{return static_cast<TEnum>(static_cast<TIntegral>(a) - static_cast<TIntegral>(b));} \
	inlinealways TEnum operator* (const TEnum a, const TOther b) \
	{return static_cast<TEnum>(static_cast<TIntegral>(a) * static_cast<TIntegral>(b));} \
	inlinealways TEnum operator/ (const TEnum a, const TOther b) \
	{return static_cast<TEnum>(static_cast<TIntegral>(a) / static_cast<TIntegral>(b));} \
	static_assert( true, "enummathoperatorswithintegral" )

#define enummathoperatorswith( TEnum, TOther ) enummathoperatorsbyusing( TEnum, TOther, std::underlying_type<TEnum>::type )
#define enummathoperators( TEnum ) enummathoperatorsbyusing( TEnum, TEnum, std::underlying_type<TEnum>::type )

#define enumflagoperatorsselfusing( TEnum, TIntegral ) \
	inlinealways TEnum operator| (const TEnum a, const TEnum b) \
	{return static_cast<TEnum>(static_cast<TIntegral>(a) | static_cast<TIntegral>(b));} \
	inlinealways TEnum operator& (const TEnum a, const TEnum b) \
	{return static_cast<TEnum>(static_cast<TIntegral>(a) & static_cast<TIntegral>(b));} \
	inlinealways TEnum operator^ (const TEnum a, const TEnum b) \
	{return static_cast<TEnum>(static_cast<TIntegral>(a) ^ static_cast<TIntegral>(b));} \
	inlinealways TEnum& operator|= (TEnum& a, const TEnum b) \
	{a = static_cast<TEnum>(static_cast<TIntegral>(a) | static_cast<TIntegral>(b)); return a;} \
	inlinealways TEnum& operator&= (TEnum& a, const TEnum b) \
	{a = static_cast<TEnum>(static_cast<TIntegral>(a) & static_cast<TIntegral>(b)); return a;} \
	inlinealways TEnum& operator^= (TEnum& a, const TEnum b) \
	{a = static_cast<TEnum>(static_cast<TIntegral>(a) ^ static_cast<TIntegral>(b)); return a;} \
	inlinealways TEnum operator~ (const TEnum a) \
	{return static_cast<TEnum>( ~static_cast<TIntegral>(a) );} \
	static_assert( true, "enumflagoperatorsselfusing" )

#define enumflagoperatorsusing( TEnum, TIntegral ) \
	inlinealways TEnum operator| (const TEnum a, const TIntegral b) \
	{return static_cast<TEnum>(static_cast<TIntegral>(a) | static_cast<TIntegral>(b));} \
	inlinealways TEnum operator& (const TEnum a, const TIntegral b) \
	{return static_cast<TEnum>(static_cast<TIntegral>(a) & static_cast<TIntegral>(b));} \
	inlinealways TEnum operator^ (const TEnum a, const TIntegral b) \
	{return static_cast<TEnum>(static_cast<TIntegral>(a) ^ static_cast<TIntegral>(b));} \
	inlinealways TEnum operator| (const TIntegral a, const TEnum b) \
	{return static_cast<TEnum>(static_cast<TIntegral>(a) | static_cast<TIntegral>(b));} \
	inlinealways TEnum operator& (const TIntegral a, const TEnum b) \
	{return static_cast<TEnum>(static_cast<TIntegral>(a) & static_cast<TIntegral>(b));} \
	inlinealways TEnum operator^ (const TIntegral a, const TEnum b) \
	{return static_cast<TEnum>(static_cast<TIntegral>(a) ^ static_cast<TIntegral>(b));} \
	inlinealways TEnum& operator|= (TEnum& a, const TIntegral b) \
	{a = static_cast<TEnum>(static_cast<TIntegral>(a) | static_cast<TIntegral>(b)); return a;} \
	inlinealways TEnum& operator&= (TEnum& a, const TIntegral b) \
	{a = static_cast<TEnum>(static_cast<TIntegral>(a) & static_cast<TIntegral>(b)); return a;} \
	inlinealways TEnum& operator^= (TEnum& a, const TIntegral b) \
	{a = static_cast<TEnum>(static_cast<TIntegral>(a) ^ static_cast<TIntegral>(b)); return a;} \
	static_assert( true, "enumflagoperatorsusing" )

#define enumflagoperatorswith( TEnum, TIntegral ) enumflagoperatorsselfusing( TEnum, TIntegral ); enumflagoperatorsusing( TEnum, TIntegral )
#define enumflagoperatorsself( TEnum ) enumflagoperatorsselfusing( TEnum, std::underlying_type<TEnum>::type )
#define enumflagoperators( TEnum ) enumflagoperatorswith( TEnum, std::underlying_type<TEnum>::type )

	template <typename TLFlag, typename TRFlag = TLFlag> 
	inlinealways bool HasFlags( TLFlag value, TRFlag flags ) {
		return (value & flags) == flags;
	}

	template <typename TLFlag, typename TRFlag = TLFlag>
	inlinealways bool AnyFlags( TLFlag value, TRFlag flags ) {
		return ( value & flags ) != static_cast<TLFlag>( 0 );
	}

	template <typename TLFlag, typename TRFlag = TLFlag>
	inlinealways bool NoFlags( TLFlag value, TRFlag flags ) {
		return ( value & flags ) == static_cast<TLFlag>( 0 );
	}

	template <typename T, ulword n, typename TFlag>
	inlinealways T accumulate_flags( TFlag value, const T(& arr)[n] ) {
		return accumulate_flags( value, array_view<T, n>( arr ) );
	}

	template <typename T, ulword n, typename TFlag>
	inlinealways T accumulate_flags( TFlag value, const std::array<T, n>& arr ) {
		return accumulate_flags( value, array_view<T, n>( arr ) );
	}

	template <typename T, ulword n, typename TFlag>
	inlinealways T accumulate_flags( TFlag value, const array_view<T, n>& arr ) {
		typedef integral_type<sizeof( T )>::type enumword;
		typedef integral_type<sizeof( TFlag )>::type flagword;
		const static ulword flagbitsize = sizeof( flagword ) * CHAR_BIT;
		enumword flags = 0;
		flagword valuebits = static_cast<flagword>( value );
		const enumword upperlimit = n;
		flagword bit = 1;
		if ( valuebits != 0 ) {
			for ( enumword i = 1; i < flagbitsize && i < upperlimit; ++i, bit *= 2 ) {
				if ( AnyFlags( valuebits, bit ) ) {
					flags |= static_cast<enumword>( arr[ i ] );
				}
			}
		}
		return static_cast<T>( flags );
	}

	template <typename T, typename TEnum>
	inlinealways T enum_cast( TEnum value ) {
		return static_cast<T>( static_cast<integral_type_of<TEnum>::type>( value ) );
	}
}
 