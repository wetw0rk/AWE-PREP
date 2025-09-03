/*
Simple Hello World driver for the Windows Kernel
*/

#include "ntddk.h"

VOID Unload(IN PDRIVER_OBJECT DriverObject)
{
	DbgPrint("Goodbye from Kernel land o/ \r\n");
}

NTSTATUS DriverEntry(IN PDRIVER_OBJECT DriverObject, IN PUNICODE_STRING RegistryPath)
{
	DriverObject->DriverUnload = Unload;

	DbgPrint("Hello from Kernel land o/ \r\n");
	return STATUS_SUCCESS;
}
