#ifndef FURROVINECHARTRIE_H
#define FURROVINECHARTRIE_H
/*
#include <Furrovine++/Collections/CollectionsCore.h>

namespace Furrovine { namespace Collections {
	
	template <class T> struct CharTrieNode : public Object {
	protected:
#ifdef _MSC_VER
		template <class T> friend class CharTrie;
#else
		template <class TCast> friend class CharTrie;
#endif
		char elem;
		CharTrieNode<T>** nodes;
		T* entry;

		bool Delete (CharTrieNode<T>& parent, const char* c) {
			if (*c != '\0') {
				CharTrieNode<T>* node = nodes[*c];
				if (node != 0) {
					char del = *c;
					bool nonpathway = node->Delete(*this, ++c);
					if (nonpathway) {
						Delete(del);
						return !Pathway();
					}
					return false;
				}
			}
			else {
				ClearEntry();
				return !Pathway();
			}
		}

		void Delete (char c) {
			if (nodes[c] != 0) {
				nodes[c]->ClearEntry();
				if (!nodes[c]->Pathway()) {
					delete nodes[c];
					nodes[c] = 0;
				}
			}
		}

		void Insert (CharTrieNode<T>& parent, const char* c, T& goal, int& depth) {
			if (*c != '\0') {
				CharTrieNode<T>* node;
				if (nodes[(int)*c] == 0)
					nodes[(int)*c] = new CharTrieNode<T>();
				node = nodes[(int)*c];
				node->elem = *c;
				node->Insert(*this, ++c, goal, ++depth);
			}
			else {
				entry = new T(goal);
			}
		}


	public:
		CharTrieNode () {
			nodes = new CharTrieNode<T>*[256];
			for (lword i = 0; i < 256; i++)
				nodes[i] = 0;
			entry = 0;
		}

		bool Pathway () {
			for (lword i = 0; i < 256; i++)
				if (nodes[i] != 0)
					return true;
			return false;
		}

		void ClearEntry () {
			if (entry != 0)
				delete entry;
			entry = 0;
		}

		T* Entry () {
			return entry;
		}

		virtual lword Insert (const char* c, T treasure) {
			lword depth = 0;
			if (c != 0) {
				if (*c != '\0') {
					CharTrieNode<T>* node = 0;
					if (nodes[(int)*c] == 0)
						nodes[(int)*c] = new CharTrieNode<T>();
					node = nodes[(int)*c];
					node->elem = *c;
					node->Insert(*this, ++c, treasure, ++depth);
				}
			}
			return depth;
		}

		void Delete (const char* c) {
			if (c != 0) {
				if (*c != '\0') {
					CharTrieNode<T>* node = nodes[*c];
					if (node != 0) {
						char del = *c;
						bool nonpathway = node->Delete(*this, ++c);
						if (nonpathway) {
							Delete(del);
						}
					}
				}
			}
		}

		virtual bool TryGetValue (T& out, const char* c) {
			if (c == 0)
				return false;
			CharTrieNode<T>* node = this;
			while (*c != '\0' && node->nodes[(int)*c] != 0) {
				node = node->nodes[(int)*c];
				c++;
			}
			if (*c == '\0' && node != 0 && node->entry != 0) {
				out = *node->entry;
				return true;
			}
			return false;
		}

		CharTrieNode<T>& operator[] (lword index) {
			return nodes[index];
		}

		~CharTrieNode() {
			if (entry != 0)
				delete entry;
			for (lword i = 0; i < 256; i++)
				if (nodes[i] != 0)
					delete nodes[i];
			delete[] nodes;
		}
	};

	template <class T> class CharTrie : public CharTrieNode<T> {
	private:
		CharTrieNode<T>* tunneler;
		lword tunneldepth;
		lword maxdepth;
		bool lasttunnelvalid;

	public:
		CharTrie () {
			tunneler = this;
			tunneldepth = 0;
			maxdepth = 0;
			lasttunnelvalid = false;
		}

		~CharTrie () {
			
		}

		virtual lword Insert(const string& str, T treasure) {
			return Insert(str.c_str(), treasure);
		}

		virtual lword Insert (const char* c, T treasure) {
			lword d = CharTrieNode<T>::Insert(c, treasure);
			maxdepth = Mathema<int>::Max(d, maxdepth);
			return d;
		}

		virtual bool TryGetValue (const string& str, T& out) {
			return TryGetValue(str.c_str(), out);
		}

		virtual bool TryGetValue (const char* c, T& out) {
			if (c == 0)
				return false;
			CharTrieNode<T>* node = this;
			while (*c != '\0' && node->nodes[*c] != 0) {
				node = node->nodes[*c];
				c++;
			}
			if (*c == '\0' && node != 0 && node->entry != 0) {
				out = *node->entry;
				return true;
			}
			return false;
		}

		lword Depth () {
			return maxdepth;
		}

		bool TunnelSuccess () {
			return lasttunnelvalid;
		}

		lword TunnelDepth () {
			return tunneldepth;
		}

		T* TunnelValue () {
			return tunneler->Entry();
		}

		bool TunnelEnd () {
			for (lword i = 0; i < 256; i++) {
				if (tunneler->nodes[i] != null)
					return false;
			}
			return true;
		}

		bool Tunnel (const char& c) {
			if (tunneler->nodes[(int)c] == 0) {
				lasttunnelvalid = false;
				return false;
			}
			tunneler = tunneler->nodes[(int)c];
			tunneldepth++;
			lasttunnelvalid = true;
			return true;
		}

		void TunnelReset () {
			tunneler = this;
			tunneldepth = 0;
			lasttunnelvalid = false;
		}
	};
}}

*/

#endif // FURROVINECHARTRIE_H 
