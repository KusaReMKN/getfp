#include <windows.h>
#include <tchar.h>
#include <strsafe.h>
#include <shlwapi.h>

#pragma comment(lib, "shlwapi.lib")

int _tmain(int argc, TCHAR *argv[])
{
	TCHAR RelativePath[MAX_PATH] = {0}, AbsolutePath[MAX_PATH] = {0};
	size_t AbsolutePathLength, BytesWritten;

	StringCchCopy(RelativePath, MAX_PATH, (argc == 1 ? TEXT(".") : argv[1]));

	GetFullPathName(RelativePath, MAX_PATH, AbsolutePath, NULL);

	StringCchLength(AbsolutePath, MAX_PATH, &AbsolutePathLength);

	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), AbsolutePath, (DWORD)AbsolutePathLength, (LPDWORD)&BytesWritten, NULL);

	return AbsolutePathLength == BytesWritten ? (PathFileExists(AbsolutePath) ? 0 : 1) : -1;
}
