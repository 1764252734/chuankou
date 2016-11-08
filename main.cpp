
#include "SerialPort.h"
#include <iostream>
#include <fstream>
using namespace std;
CSerialPort SerialPort;
unsigned char a[2];
extern ofstream biu;
int main()
{
	biu.open("biu.txt", ios::out | ios::ate);
	if (!biu.is_open())
		cout << "biu open failed!" << endl;
	if (!SerialPort.InitPort(4, 115200))
		cout << 0;
	else if (!SerialPort.OpenListenThread())
		cout << 1;
	unsigned i = 5;
	while (1){

		a[0] = i++;
		SerialPort.WriteData(a, 1);
		//cout << "degrserg" << endl;
		//if (NEW_FLAG==1)
		//cout << Rec_buffer << endl;
		for (int j = 0; j < 100000; j++);
		if (i > 250)break;
	}
	biu.close();
	return 0;
}