#include <avr/io.h>
#define F_CPU 1000000 // Clock Frequency
#include <util/delay.h>

int ara[8][8]={
	{1,1,1,1,1,1,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,1,1,1,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,1,1,1,1,1},
	{1,1,0,1,1,1,1,1},
	{1,1,0,1,1,1,1,1},
	{1,1,1,1,1,1,1,1}
	

};

int binaryToInt(int* ara)
{
	int n=0;
	for(int i=0;i<8;i++)
	{
		n*=2;
		n+=ara[i];
	}
	return n;
}

void leftShift()
{
	for(int i=0;i<8;i++){
		int temp=ara[i][0];
		for(int j=0;j<7;j++)
		{
			ara[i][j]=ara[i][j+1];
		}
		ara[i][7]=temp;
	}
}

void topshift()
{
	for(int j=0;j<8;j++)
	{
		int temp=ara[0][j];
		for(int i=1;i<8;i++)
		{
			ara[i-1][j]=ara[i][j];
		}
		ara[7][j]=temp;
	}
}

void downShift()
{
	for(int j=0;j<8;j++)
	{
		int temp=ara[7][j];
		for(int i=7;i>0;i--)
		{
			ara[i][j]=ara[i-1][j];
		}
		ara[0][j]=temp;
	}
}

void rightShift()
{
	for(int i=0;i<8;i++)
	{
		int temp=ara[i][7];
		for(int j=7;j>0;j--)
		{
			ara[i][j]=ara[i][j-1];
		}
		ara[i][0]=temp;
	}
}

void transpose()
{
	//transpose
	for(int i=0;i<8;i++)
	{
		for(int j=i;j<8;j++)
		{
			int temp=ara[i][j];
			ara[i][j]=ara[j][i];
			ara[j][i]=temp;
		}
	}
}

void rightRotate()
{
	transpose();
	//swap rows
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<4;j++)
		{
			int temp=ara[i][j];
			ara[i][j]=ara[i][8-j-1];
			ara[i][8-j-1]=temp;
		}
	}
}

void leftRotate()
{
	transpose();
	for(int j=0;j<8;j++)
	{
		for(int i=0;i<4;i++)
		{
			int temp=ara[i][j];
			ara[i][j]=ara[8-i-1][j];
			ara[8-i-1][j]=temp;
		}
	}
}

void render(int mill_sec)
{
	int itr=mill_sec/12;
	while(itr--)
	{
		for(int i=0;i<8;i++){
			PORTA=1<<i;
			PORTD=binaryToInt(ara[i]);
			_delay_ms(1);
		}
		_delay_ms(4);
	}
}

int main()
{
	DDRA=0xFF;//row
	DDRD=0xFF;//colVal
	
	while(1)
	{
		
		render(1000);
		rightRotate();
		//PORTA=0;
		//leftShift();
		//_delay_ms(2000);
	}
	
}
