#include <REGX52.H>
#include <INTRINS.H>
/*
LED驱动根据电路图已经加在正极上，要点亮LED就是接口输出负极，也就是置零
芯片通过P2寄存器来驱动电路，所以要修改的是P2寄存器的值，P2是八位的那个
延时函数用编译器自带工具生成
*/

void Delay500ms(void)	//@12.000MHz
{
	unsigned char data i, j, k;

	_nop_();
	i = 4;
	j = 205;
	k = 187;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


void main()
{
	
	while(1)
	{
		P2 = 0x1E;	//0001 1110
		Delay500ms();
		P2 = 0x3C;  //0011 1100
		Delay500ms();
		P2 = 0x78;	//0111 1000
		Delay500ms();
		P2 = 0xF0;	//1111 0000
		Delay500ms();
		P2 = 0xE1;	//1110 0001
		Delay500ms();
		P2 = 0xC3;	//1100 0011
		Delay500ms();
		P2 = 0x87;	//1000 0111
		Delay500ms();
		P2 = 0x0F;	//0000 1111
		Delay500ms();

	}
}