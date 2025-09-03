/*
Simple snippet showcasing some UNICODE_STRING usage within a Driver
*/

#include "ntddk.h"

VOID Unload(IN PDRIVER_OBJECT DriverObject)
{
	DbgPrint("Goodbye from Kernel land o/ \r\n");
}

NTSTATUS DriverEntry(IN PDRIVER_OBJECT DriverObject, IN PUNICODE_STRING RegistryPath)
{
	DriverObject->DriverUnload = Unload;

	// Three methods of Initializing a UNICODE_STRING
	//
	// 1.
	UNICODE_STRING string1 = RTL_CONSTANT_STRING(L"Hello I'm a UNICODE_STRING\r\n");

	// 2.
	UNICODE_STRING string2 = { 0 };
	RtlInitUnicodeString(&string2, L"Hello, I'm also a UNICODE_STRING\r\n");

	// 3.
	UNICODE_STRING string3 = { 0 };
	WCHAR str[120] = { 0 };

	string3.Buffer = str;
	string3.MaximumLength = 120;
	string3.Length = wcslen(L"Me too, I'm a UNICODE_STRING\r\n") * sizeof(WCHAR);

	wcscpy(string3.Buffer, L"Me too, I'm a UNICODE_STRING\r\n");

	DbgPrint("Hello from Kernel land o/ \r\n");
	DbgPrint("%wZ\r\n", string1);
	DbgPrint("%wZ\r\n", string2);
	DbgPrint("%wZ\r\n", string3);

	// Copying strings
	UNICODE_STRING src = RTL_CONSTANT_STRING(L"I'm originally in the src variable\r\n");
	UNICODE_STRING dst = { 0 };

	WCHAR newBuffer[60];
	dst.Buffer = newBuffer;
	dst.Length = dst.MaximumLength = 60;

	RtlCopyUnicodeString(&dst, &src);

	DbgPrint("%wZ\r\n", src);

	// Uppercasing strings
	UNICODE_STRING lSrc = RTL_CONSTANT_STRING(L"I will change to uppercase\r\n");
	UNICODE_STRING dSrc = { 0 };

	RtlUpcaseUnicodeString(&dSrc, &lSrc, TRUE);

	DbgPrint("%wZ\r\n", lSrc);
	DbgPrint("%wZ\r\n", dSrc);

	RtlFreeUnicodeString(&dSrc);

	// Converting from UNICODE to ANSI
	UNICODE_STRING srcUnicode = RTL_CONSTANT_STRING(L"I'm going to be turned into ANSI\r\n");
	ANSI_STRING dstAnsi = { 0 };

	RtlUnicodeStringToAnsiString(&dstAnsi, &srcUnicode, TRUE);

	DbgPrint("%Z\r\n", dstAnsi);

	RtlFreeAnsiString(&dstAnsi);

	return STATUS_SUCCESS;
}
