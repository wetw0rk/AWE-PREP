#include "ntddk.h"

VOID Unload(IN PDRIVER_OBJECT DriverObject)
{
	DbgPrint("Goodbye from Kernel land o/ \r\n");
}

NTSTATUS DriverEntry(IN PDRIVER_OBJECT DriverObject, IN PUNICODE_STRING RegistryPath)
{
	DriverObject->DriverUnload = Unload;

	UNICODE_STRING srcString = RTL_CONSTANT_STRING(L"HI\r\n");
	UNICODE_STRING string = { 0 };

	string.Buffer = (PWCHAR)ExAllocatePoolWithTag(NonPagedPool, 10, "fooo");
	if (NULL != string.Buffer)
	{
		string.Length = string.MaximumLength = 4;

		RtlCopyMemory(string.Buffer, srcString.Buffer, srcString.Length);

		// Copying characters into the poolheader using strcpy (the pool header is 16 bytes in x64)
		strcpy(string.Buffer-0x10, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");

		DbgPrint("%wZ\r\n", &string);
		ExFreePool(string.Buffer);
	}

	return STATUS_SUCCESS;
}
