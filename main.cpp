#include <stdio.h>
#include <stdlib.h>

#include <windows.h>
#include <winioctl.h>


int main(int argc, char *argv[])
{
    HANDLE hDevice;

    hDevice = CreateFile(TEXT("\\\\.\\PhysicalDrive0"),
          GENERIC_READ,     // access to the drive
          0,                // share mode
          NULL,             // default security attributes
          OPEN_EXISTING,    // disposition
          0,                // file attributes
          NULL);            // do not copy file attributes

    if (hDevice == INVALID_HANDLE_VALUE)
    {
        printf("ça ne marche pas.\n");
        printf ("Error %ld.\n", GetLastError ());
        return (FALSE);
    }
    else
    {
        printf("ça marche !\n");
    }

    CloseHandle(hDevice);

    system("PAUSE");

    return(0);

}
