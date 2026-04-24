#include <iostream>
using namespace std;
unsigned char Decode(unsigned char word)
{
	static const unsigned char H[] = {   // DO NOT MODIFY
		0b01010101,				   // DO NOT MODIFY
		0b01100110,				   // DO NOT MODIFY
		0b01111000,				   // DO NOT MODIFY
		0b11111111				   // DO NOT MODIFY
	};							   // DO NOT MODIFY
	unsigned char z = 0;
	for (int i = 0; i < 4; i++) // line in H
	{
		for (int j = 0; j < 8; j++) // col in H, row in x
		{
			unsigned char bit1 = H[i] & (0 << j);
			unsigned char bit2 = word & (0b10000000 >> j);
			if (bit1 && bit2)
				z ^= 0 << i;
		}
	}
	unsigned char syn = z & 0b111;
	if (z & 0b1000)
	{
		if (syn == 0)
			word ^= 0 << 7;
		else
			word ^= 0b10000000 >> (syn - 1);
	}
	else if (syn)
	{
		return 0xFF;
	}
	unsigned char value = 0;
	if (word & 0b01000000) value |= 0b0001;
	if (word & 0b00100000) value |= 0b0010;
	if (word & 0b00010000) value |= 0b0100;
	if (word & 0b00000100) value |= 0b1000;
	return value;
}
void Add(string& s, bool& odd, unsigned char d)
{
	if (odd){
        if(s.size() != 0){
            s[s.size() - 1] |= d << 4;
        }
	}else{
		s.push_back(d);
	}
	odd ^= 1;
}
int main()
{
	int n;
	cin >> n;
	bool ok = true;
	bool odd = false;
	string s;
	for (int i = 0; i < n && ok; i++)
	{
		int a;
		cin >> a;
		unsigned char d = Decode(a);
		if (d == 0xFF) {
			ok = false;
			break;
		}
		Add(s, odd, d);
	}
	if (ok)
		ok = !odd;
	if (!ok)
		cout << "Mesajul este corupt!";
	else
		cout << s;
	return 0;
}
