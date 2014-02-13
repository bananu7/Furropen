#ifndef FURROVINEREFLECTION_H
#define FURROVINEREFLECTION_H

//#include <typeinfo>
//#include <typeindex>
#include <string>
#include <vector>
#include <unordered_map>

namespace Furrovine { namespace Introspection {

	enum AccessSpecifier {
		Public,
		Private,
		Protected
	};

	struct Identifier {
		std::size_t hash;
		std::string name;
	};

	struct Primitive {
		Identifier id;
	};

	struct Type : public Primitive {
		std::size_t size;
	};

	struct EnumConstant : public Primitive {
		unsigned long long value;
	};

	struct Enum : public Type {
		std::vector<EnumConstant> constants;
	};

	struct Field : public Type {
		AccessSpecifier access;
		std::size_t offset;
	};

	struct Function : public Primitive {
		Type returnvalue;
		std::vector<std::pair<Identifier, Type>> parameters;
	};

	struct Class : public Type {
		bool isstruct;
		std::unordered_map<std::string, std::size_t> enumnames;
		std::vector<Enum> enums;
		std::unordered_map<std::string, std::size_t> fieldnames;
		std::vector<Field> fields;
		std::unordered_map<std::string, std::size_t> functionnames;
		std::vector<Function> functions;
	};

	struct Namespace : public Primitive {
		std::unordered_map<std::string, std::size_t> enumnames;
		std::vector<Enum> enums;
		std::unordered_map<std::string, std::size_t> variablenames;
		std::vector<Type> variables;
		std::unordered_map<std::string, std::size_t> functionnames;
		std::vector<Function> functions;
		std::unordered_map<std::string, std::size_t> classnames;
		std::vector<Class> classes;
		std::unordered_map<std::string, std::size_t> namespacenames;
		std::vector<Namespace> namespaces;
	};

	struct Reflection {
		
		

		// I think we need a general interface here, that
		// defaults to returning empty information
		// if a certain thing is not present for this
		// reflected type
		// E.g. GetMemberFunctions() on a "Field"-based type would
		// return an empty const std::vector& or something.
	};

}}

#endif // FURROVINEREFLECTION_H 