#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

void MoveClick(int x, int y)
{
	mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, x * 65535 / 1600, y * 65535 / 900, 0, 0);
	Sleep(50);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0); // Press Left
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);   // Release Left
 }
 
void Recording()
{
	
	int way[2] = { 0x27 , 0x25 };

	keybd_event(0x5B, 0, 0, 0); // Press WIN
	keybd_event(0x11, 0, 0, 0); // Press CTRL
	keybd_event(way[0], 0, 0, 0); // Press ¡ú
	Sleep(10);
	keybd_event(way[0], 0, 2, 0); // Release ¡ú
	// To Left

	Sleep(500);
	MoveClick(1390, 660);
	//Click Recording
    
	keybd_event(way[1], 0, 0, 0); // Press ¡û
	Sleep(50);
	keybd_event(way[1], 0, 2, 0); // Release ¡û
	keybd_event(0x5B, 0, 2, 0);	  // Release WIN
	keybd_event(0x11, 0, 2, 0);	  // Release CTRL
}

void GetPoint()
{
    POINT pt;
	GetCursorPos(&pt);
	cout << "Êó±ê×ø±ê:" << pt.x << ',' << pt.y;
}

void Dingding()
{
	MoveClick(1030, 94);
	Sleep(2500);
	MoveClick(818, 389);
	MoveClick(818, 389);
}


int main(){

	short time=0;
    bool Flag = true;

    while (Flag)
	{
    	
		SYSTEMTIME ct;
		GetLocalTime(&ct);
		time = ct.wHour*100 + ct.wMinute ;

		if (time % 2 == 0)
		{
			cout << "[Program] " << ct.wMonth << '-' << ct.wDay << ' ' << ct.wHour << ':' << ct.wMinute
			<< " | Running Normally!";
			Sleep(60000);
		}

		if (time == 827)
		{
			Dingding();
			Sleep(1500);
			Recording(); 
			Sleep(60000);
		}
		//8:27 Start recording

		if (time == 1140)
		{
			Recording(); 
			Sleep(60000);
		}
		//11:40 End recording

		if (time == 1327)
		{
			Dingding();
			Sleep(1500);
			Recording(); 
			Sleep(60000);
		}
		//13:27 Restart recording

		if (time == 1640)
		{
			Recording(); // stop
			Flag=false;
			Sleep(60000);
		}
		//16:40 End recording

	}
	
	return 0;
} 



//https://learn.microsoft.com/zh-cn/windows/win32/inputdev/virtual-key-codes
