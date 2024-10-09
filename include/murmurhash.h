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

#ifndef _INCLUDE_MURMURHASH_H_
#	define _INCLUDE_MURMURHASH_H_

#	include <stddef.h>
#	include <stdint.h>

#	ifdef __cplusplus
#		define MURMURHASH_PLATFORM extern "C"
#	else
#		define MURMURHASH_PLATFORM
#	endif

MURMURHASH_PLATFORM uint32_t CalculateMurmurHash2(const char *pszInput, size_t nLength);
MURMURHASH_PLATFORM uint32_t CalculateMurmurHash2Lowercase(const char *pszInput, size_t nLength);

MURMURHASH_PLATFORM uint32_t CalculateMurmurHash3(const char *pszInput, size_t nLength);
MURMURHASH_PLATFORM uint32_t CalculateMurmurHash3Caseless(const char *pszInput, size_t nLength);

#endif // _INCLUDE_MURMURHASH_H_
