#ifndef windowsfunctionsH
#define windowsfunctionsH

#include <windows.h>
#include <DbgHelp.h>

LONG WINAPI SystemExceptionFilter(PEXCEPTION_POINTERS pExceptionPtrs);

#endif