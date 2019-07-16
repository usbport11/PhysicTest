#include "WindowsFunctions.h"

LONG WINAPI SystemExceptionFilter(PEXCEPTION_POINTERS pExceptionPtrs) {
	/*
	do not forget
	1) add libdbghelp.a
	2) build 32 debud and create pdb by cv2pdb.exe (cv2pdb -C filename)
	3) build release
	4) use windbg for dump analyse (!analyze -v)
	*/
	
    char name[MAX_PATH] = {0};
    int Length;
    GetModuleFileName(GetModuleHandle(NULL), name, MAX_PATH);
    Length = strlen(name);
    name[Length - 3] = 'd';
    name[Length - 2] = 'm';
    name[Length - 1] = 'p';
    
    HANDLE hFile = CreateFile(name, GENERIC_WRITE, FILE_SHARE_READ, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
    if(hFile == INVALID_HANDLE_VALUE) return 1;
    
    MINIDUMP_EXCEPTION_INFORMATION exceptionInfo;
    exceptionInfo.ThreadId = GetCurrentThreadId();
    exceptionInfo.ExceptionPointers = pExceptionPtrs;
    exceptionInfo.ClientPointers = FALSE;
	
	MiniDumpWriteDump(
		GetCurrentProcess(),
    	GetCurrentProcessId(),
		hFile,
		MiniDumpNormal,
		pExceptionPtrs ? &exceptionInfo : NULL,
		NULL,
		NULL
	);
	
	return EXCEPTION_EXECUTE_HANDLER; 
}
