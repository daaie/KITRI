#include <windows.h>
#include <iostream>
#include <wincon.h>
#define _WIN32_WINNT 0x0500
using namespace std;
int main()
{
// HWND myconsole;
// HDC mydc;
 int size = 0, width = 0, height = 0, z = 54, line = 0, x = 0, y = 0;
 FILE *file;
 char pic[3];
// myconsole = GetConsoleWindow();
// mydc = GetDC(myconsole);
 fopen_s(&file, "c:\\users\\KITRI\\desktop\\ekgow.txt", "r");
 fseek(file, 2, SEEK_SET);
 fread(&size, 8, 1, file);
 fseek(file, 18, SEEK_SET);
 fread(&width, 8, 1, file);
 fseek(file, 22, SEEK_SET);
 fread(&height, 8, 1, file);
 y = height;
 
 while (z < size && z >= 54)
 { 
  fseek(file, z, SEEK_SET);
  fread(pic, 3, 1, file);
  z = z + 3;
  line++;
  if (line > width - 1)
  {
   line = 0;
   z = z + (width % 4);
   x = 0;
   y--;
  }
  COLORREF COLOR = RGB(pic[2], pic[1], pic[0]);
//  SetPixel(mydc, x, y, COLOR);
  x++;
 }
// ReleaseDC(myconsole, mydc);
// cin.ignore();
 fclose(file);
 return 0;
}