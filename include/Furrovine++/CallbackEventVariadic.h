#pragma once

#include <Furrovine++/Callback.h>

namespace Furrovine {
	
	template <typename... Tn> 
	class CallbackEvent {
	public:
		typedef void(*TFunctionSignature)(Tn...);
		typedef Callback<void(Tn...)> TCallback;
		typedef std::vector<TCallback> InvocationTable;

	protected:
		InvocationTable invocations;

	public:
		static const std::size_t DefaultFunctorCapacity = 4;

		CallbackEvent() : invocations() {
			invocations.reserve(DefaultFunctorCapacity);
		}

		template <void (* TFunc)(Tn...)>
		void Add() {
			TCallback c = DeduceCallback(TFunc).template Bind<TFunc>();
			invocations.push_back(c);
		}

		template <typename T, void (T::* TFunc)(Tn...)>
		void Add(T& object) {
			Add<T, TFunc>(&object);
		}

		template <typename T, void (T::* TFunc)(Tn...)>
		void Add(T* object) {
			TCallback c = DeduceCallback(TFunc).template Bind<TFunc>(object);
			invocations.push_back(c);
		}

		template <typename T, void (T::* TFunc)(Tn...) const>
		void Add(T& object) {
			Add<T, TFunc>(&object);
		}

		template <typename T, void (T::* TFunc)(Tn...) const> 
		void Add(T* object) {
			TCallback c = DeduceCallback(TFunc).template Bind<TFunc>(object);
			invocations.push_back(c);
		}

		template <typename... TArgn>
		void Invoke( TArgn&&... a ) {
			for(size_t i = 0; i < invocations.size() ; ++i) invocations[i]( std::forward<Tn>( a )... ); 
		}
		
		template <typename... TArgn>
		void operator()( TArgn&&... a ) {
			Invoke( std::forward<Tn>( a )... );
		}

		std::size_t InvocationCount() { return invocations.size(); }

		template <void (* TFunc)(Tn...)> 
		bool Remove () { return Remove (DeduceCallback(TFunc).template Bind<TFunc>()); } 

		template <typename T, void (T::* TFunc)(Tn...)> 
		bool Remove (T& object) { return Remove <T, TFunc>(&object); } 
		
		template <typename T, void (T::* TFunc)(Tn...)> 
		bool Remove (T* object) { return Remove (DeduceCallback(TFunc).template Bind<TFunc>(object)); } 
		
		template <typename T, void (T::* TFunc)(Tn...) const> 
		bool Remove (T& object) { return Remove <T, TFunc>(&object); } 
		
		template <typename T, void (T::* TFunc)(Tn...) const> 
		bool Remove (T* object) { return Remove (DeduceCallback(TFunc).template Bind<TFunc>(object)); } 

	protected:
		bool Remove( TCallback const& target ) {
			auto it = std::find(invocations.begin(), invocations.end(), target);
			if (it == invocations.end()) 
				return false;
			invocations.erase(it);
			return true;
		}
	};
	
}
