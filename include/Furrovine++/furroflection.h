#ifndef FURROVINEFURROFLECTION_H
#define FURROVINEFURROFLECTION_H

#ifdef __furroflectioning__

#define FURROFLECTMACROPASTE_META(x, y) x ## y
#define FURROFLECTMACROPASTE(x, y) FURROFLECTMACROPASTE_META(x, y)
#define furroflect_unique( x ) FURROFLECTMACROPASTE(x, __COUNTER__)

// Names specfic elements to be reflected
#define furroflect_only(...) __attribute__((annotate("refl_1:"#__VA_ARGS__)))

// Structure Injection
/* Full reflection of the specified named type -- unique structure injection */
/* Partial reflection tag -- same unique structure injection, different prefix tag */
#define furroflect_some(name) namespace furroflect_tagged_ { struct __attribute__((annotate("refl_2:"#name))) furroflect_unique(furroflect_refl) { }; }

// Get everything that this namespace has to offer
#define furroflect __attribute__((annotate("refl_3")))

// Working on it...
//#define furroflectpush_attr(...) struct FURROVINE_UNIQUE(push_attr) { } __attribute__((annotate(#__VA_ARGS__)));
//#define furroflectpop_attr(...) struct FURROVINE_UNIQUE(pop_attr) { } __attribute__((annotate(#__VA_ARGS__)));


/* 
// I hate iterators -- we'll figure this out later
#define furroflectcontainer_iterators(container, read_iterator, write_iterator, keyinfo) \
	furroflect_part(read_iterator) \
	furroflect_part(write_iterator) \
	namespace furroflect_tagged_ { \                                                                                                                                                                                                                       \
	struct \
		__attribute__((annotate("container-" #container "-" #read_iterator "-" #write_iterator "-" #keyinfo))) \
		FURROVINE_UNIQUE(container_info) { }; \
	}
*/
#else

#define furroflect
#define furroflect_only(...)
#define furroflect_some(name)
//#define furroflectpush_attr(...)
//#define furroflectpop_attr(...)
//#define furroflectcontainer_iterators(container, read_iterator, write_iterator, keyinfo)

#endif

#endif // FURROVINEFURROFLECTION_H 