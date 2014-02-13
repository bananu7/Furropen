#pragma once

namespace Furrovine { namespace Unicode {

	enum class indic_syllabic_category : unsigned char {
		Bindu,
		Visarga,
		Avagraha,
		Nukta,
		Virama,
		Vowel_Independent,
		Vowel_Dependent,
		Vowel,
		Consonant_Placeholder,
		Consonant,
		Consonant_Dead,
		Consonant_Repha,
		Consonant_Subjoined,
		Consonant_Medial,
		Consonant_Final,
		Consonant_Head_Letter,
		Modifying_Letter,
		Tone_Letter,
		Tone_Mark,
		Register_Shifter,
		Other,
	};

}}