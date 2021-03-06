#include "CharHandle.h"

void CharHandle::SetCharDataPtr(const void * addr)
{
	m_charData = (CharInfo**)addr;
}

bool CharHandle::IsCharDataNullPtr() const
{
	if (m_charData == 0)
		return true;

	return *m_charData == 0;
}

const CharInfo * CharHandle::GetData() const
{
	return *m_charData;
}

CharPaletteHandle & CharHandle::GetPalHandle()
{
	return m_charPalHandler;
}
