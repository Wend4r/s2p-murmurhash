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

#include <main.h>
#include <murmurhash.h>

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

static volatile bool s_bKeepRunningProgram = true;

static void SigIntHandler(int iSigNum)
{
	s_bKeepRunningProgram = false;
}

static void HandleInputString()
{
	printf("%s", "Enter a string: ");

	// Get a input string.
	{
		char sInput[256];

		fgets(sInput, sizeof(sInput), stdin);
		sInput[strcspn(sInput, "\n")] = 0;

		size_t nLength = strlen(sInput);

		// Calculate & print hashes.
		{
			printf("MurmurHash:\n");

			uint32_t nHash;

			{
				nHash = CalculateMurmurHash2(sInput, nLength);
				printf("\t2: %u (0x%08X)\n", nHash, nHash);

				nHash = CalculateMurmurHash2Lowercase(sInput, nLength);
				printf("\t   %u (0x%08X)\n\n", nHash, nHash);
			}

			{
				nHash = CalculateMurmurHash3(sInput, nLength);
				printf("\t3: %u (0x%08X)\n", nHash, nHash);

				nHash = CalculateMurmurHash3Caseless(sInput, nLength);
				printf("\t   %u (0x%08X)\n\n", nHash, nHash);
			}
		}
	}
}

int main(int iArgC, char *pszArgV[])
{
	while(s_bKeepRunningProgram)
	{
		HandleInputString();
	}
}
