#ifndef FURROVINECOMBINATIONPERMUTATIONSET_H
#define FURROVINECOMBINATIONPERMUTATIONSET_H

#include "../Mathema.h"

namespace Furrovine { namespace Collections {

	struct CombinatoricModes {
		enum CombinatoricMode {
			CombinationWithoutRepetition,
			CombinationWithRepetition,
			PermutationsWithoutRepetition,
			PermutationsWithRepetition
		};
	};

	template <typename T> 
	class CombinatoricSet {
	private:
		T* set;
		uint setsize;
		uint subsetsize;
		uint64 count;

		union {
			CombinatoricModes::CombinatoricMode mode;
			struct {
				bool repetitions:1;
				bool permutations:1;
				int:30;
			};
		};

		bool refresh, copied;

		void CombineLimited (T**& elements, uint64& actualcount) {
			bool combined = false;
			uint* indices = new uint[subsetsize];


		}

		void CombineUnlimited (T**& elements, uint64& actualcount) {

		}

		void PermuteLimited (T**& elements, uint64& actualcount) {
			if (subsetsize == 1) {
				for (uint c = 0; c < count; c++) {
					elements[c][0] = set[c];
					actualcount++;
				}
				return;
			}
			uint k, s, ktemp;
			T temp;
			if (subsetsize == setsize) {
				for (k = 0; k < count; k++) {
					ktemp = k;
					memcpy(elements[k], set, subsetsize);
					for (s = 1; s < setsize; ++s) {
						Swap(elements[k][s], elements[k][ktemp % (s + 1)], temp); 
						ktemp /= (s + 1);
					}
					actualcount++;
					/*for (p = 0; p < subsetsize; p++) {
						cout << elements[k][p];
					}
					cout << endl;*/
				}
			}
			else if (subsetsize > setsize - 2) {
				T* clone = new T[setsize];
				for (k = 0; k < count; k++) {
					memcpy(clone, set, setsize);
					ktemp = k;
					for (s = 1; s < setsize; ++s) {
						Swap(clone[s], clone[ktemp % (s + 1)], temp); 
						ktemp /= (s + 1);
					}
					memcpy(elements[k], clone, subsetsize);
					actualcount++;
					/*for (p = 0; p < subsetsize; p++) {
						cout << elements[k][p];
					}
					cout << endl;*/
				}
				delete[] clone;
			}
			else {
				bool cont;
				uint64 e, fullcount = (uint64)pow((double)setsize, (double)setsize);
				uint idx;
				for (e = 0; e < fullcount; e++) {
					cont = false;
					idx = 0;
					string radix = Long::ToString(e, setsize);
					if (radix.length() < subsetsize - 2)
						continue;
					char& c = radix[0];

					while (idx + radix.length() < subsetsize)
						elements[actualcount][idx++] = set[0];

					if (setsize < 10) {
						for (uint r = 0; r < radix.length(); r++) {
							c = radix[r];
							if (Array<>::Contains(set[(c - '0')], elements[actualcount], subsetsize)) {
								cont = true;
								break;
							}
							elements[actualcount][idx++] = set[(c - '0')];
						}
					}
					else {
						for (uint r = 0; r < radix.length(); r++) {
							c = radix[r];
							if (Char::IsDigit(c))
								elements[actualcount][idx++] = set[(c - '0')];
							else
								if (Char::IsLower(c))
									elements[actualcount][idx++] = set[(c - 'W')];
							if (Char::IsUpper(c))
								elements[actualcount][idx++] = set[(c - '7')];
						}
					}
					if (cont)
						continue;
					/*for (uint p = 0; p < subsetsize; p++) {
						cout << elements[actualcount][p];
					}
					cout << endl;*/
					++actualcount;
				}
			}
		}

		void PermuteUnlimited (T**& elements, uint64& actualcount) {
			uint idx = 0, e = 0;
			for (e = 0; e < count; e++) {
				idx = 0;
				string radix = Integer::ToString(e, setsize);
				char& c = radix[0];

				while (idx + radix.length() < subsetsize)
					elements[e][idx++] = set[0];

				if (setsize < 10) {
					for (uint r = 0; r < radix.length(); r++) {
						c = radix[r];
						elements[e][idx++] = set[(c - '0')];
					}
				}
				else {
					for (uint r = 0; r < radix.length(); r++) {
						c = radix[r];
						if (Char::IsDigit(c))
							elements[e][idx++] = set[(c - '0')];
						else
							if (Char::IsLower(c))
								elements[e][idx++] = set[(c - 'W')];
							if (Char::IsUpper(c))
								elements[e][idx++] = set[(c - '7')];
					}
				}
				/*for (uint p = 0; p < subsetsize; p++) {
					cout << elements[e][p];
				}
				cout << endl;*/
				++actualcount;
			}
		}

	public:
		CombinatoricSet () : set(null), setsize(0), subsetsize(0), count(0), mode(CombinatoricModes::CombinationWithoutRepetition), permutations(false), repetitions(false), refresh(false), copied(false) {
		
		}

		void ReferenceItems (T* elements, uint size) {
			if (copied) {
				delete[] set;
				setsize = 0;
				copied = false;
			}
			setsize = size;
			set = elements;
			refresh = true;
		}

		void ReferenceItems (const vector<T>& elements) {
			if (copied) {
				delete[] set;
				setsize = 0;
				copied = false;
			}
			setsize = elements.size();
			if (setsize == 0)
				set = null
			else
				set = &(elements[0]);
			refresh = true;
		}

		void Items (T* elements, uint size) {
			if (copied) {
				delete[] set;
				setsize = 0;
				copied = false;
			}
			setsize = size;
			if (elements == null) {
				set = null;
				setsize = 0;
			}
			if (setsize != 0 && elements != null) {
				set = new T[setsize];
				memcpy(set, elements, setsize);
				copied = true;
			}
			refresh = true;
		}

		void Items (const vector<T>& elements) {
			if (copied) {
				delete[] set;
				setsize = 0;
				copied = false;
			}
			setsize = elements.size();
			if (setsize == 0) {
				set = null;
			}
			else {
				set = new T[setsize];
				memcpy(set, &(elements[0]), setsize);
				copied = true;
			}
			refresh = true;
		}

		void Subset (uint subsize) {
			subsetsize = subsize;
			refresh = true;
		}

		uint Subset () {
			return subsetsize;
		}

		uint64 Count () {
			if (refresh) {
				if (subsetsize < 1)
					count = 0;
				if (permutations && repetitions) {
					count = (uint64)pow((double)setsize, (double)subsetsize);
				}
				else if (subsetsize > setsize) {
					count = 0;
				}
				else {
					uint64 nfactorial = Mathema<uint64>::Factorial(setsize);
					uint64 rfactorial = Mathema<uint64>::Factorial(subsetsize);
					uint64 denom = 0;
					if (permutations) {
						denom = Mathema<uint64>::Factorial(setsize - subsetsize);
						if (denom != 0)
							count = nfactorial / denom;
						else
							count = 0;
					}
					else if (repetitions) {
						denom = (rfactorial * Mathema<uint64>::Factorial(setsize - 1));
						if (denom != 0)
							count = nfactorial / denom;
						else
							count = 0;
					}
					else {
						denom = (Mathema<uint64>::Factorial(setsize - subsetsize) * rfactorial);
						if (denom != 0)
							return nfactorial / denom;
						else
							count = 0;
					}
				}
				refresh = false;
			}
			return count;
		}

		T** Sequences () {
			Count();
			if (setsize < 1 || subsetsize < 1 || (!repetitions && subsetsize > setsize) || count == 0 ) {
				return null;
			}
			uint64 actualcount = 0;
			T** elements = new T*[(uint)count];
			if (elements == null) {
				return null;
			}
			else {
				for (uint c = 0; c < (uint)count; c++) {
					elements[c] = new T[subsetsize];
				}
			}
			if (setsize == 1) {
				elements[0][0] = set[0];
				return elements;
			}

			if (mode == CombinatoricModes::CombinationWithoutRepetition) {
				if (subsetsize == setsize) {
					if (count > 1) {
						cout << "WHADDAPHUCK COUNT > 1 AND SUBSETSIZE == SETSIZE AND CombinationsWithoutRepetition" << endl;
						delete[] elements;
					}
					for (uint i = 0; i < setsize; i++) {
						elements[0][i] = set[i];
					}
					return elements;
				}
				CombineLimited(elements, actualcount);
			}
			else if (mode == CombinatoricModes::CombinationWithRepetition) {
				CombineUnlimited(elements, actualcount);
			}
			else if (mode == CombinatoricModes::PermutationsWithoutRepetition) {
				PermuteLimited(elements, actualcount);
			}
			else if (mode == CombinatoricModes::PermutationsWithRepetition) {
				PermuteUnlimited(elements, actualcount);
			}

			if (count != actualcount) {
				cout << "Warning: The Actual Items Element Count [ " << actualcount << " ] is not equivalent to the Theortical Count() [ " << count << " ] !" << endl;
			}

			return elements;
		}

		bool Repetitions () {
			return repetitions;
		}

		void Repetitions (bool repeats) {
			refresh |= repeats != repetitions;
			repetitions = repeats;
		}

		bool Permutations () {
			return permutations;
		}

		void Permutations (bool perms) {
			refresh |= perms != permutations;
			permutations = perms;
		}

		CombinatoricModes::CombinatoricMode Mode () {
			return mode;
		}

		void Mode (CombinatoricModes::CombinatoricMode ComboPermuteMode) {
			mode = ComboPermuteMode;
		}

		~CombinatoricSet () {
			if (copied) {
				delete[] set;
			}
		}
	};

}}

#endif // FURROVINECOMBINATIONPERMUTATIONSET_H 