/**
 * vim: set ts=4 sw=4 tw=99 noet :
 * ======================================================
 * Source 2 - MurmurHash.
 * Written by Wend4r (2024).
 * ======================================================

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <murmurhash.h>

#include <tier0/utlstringtoken.h>
#include <tier0/murmurhash3.h>

uint32_t CalculateMurmurHash2(const char *pszInput, size_t nLength)
{
	return MurmurHash2(pszInput, nLength, STRINGTOKEN_MURMURHASH_SEED);
}

uint32_t CalculateMurmurHash2Lowercase(const char *pszInput, size_t nLength)
{
	return MurmurHash2LowerCase(pszInput, nLength, STRINGTOKEN_MURMURHASH_SEED);
}

uint32_t CalculateMurmurHash3(const char *pszInput, size_t nLength)
{
	return MurmurHash3String(pszInput, nLength);
}

uint32_t CalculateMurmurHash3Caseless(const char *pszInput, size_t nLength)
{
	return MurmurHash3StringCaseless(pszInput, nLength);
}
