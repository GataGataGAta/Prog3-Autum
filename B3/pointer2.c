#include <stdio.h>

int main()
{
    int a, b;
    double x, y;
    a = 12;
    b = 34;
    x = 1.0;
    y = 2.0;

    printf(" a のの番地は%pです。\n", &a);
    printf(" b のの番地は%pです。\n", &b);
    printf(" x のの番地は%pです。\n", &x);
    printf(" y のの番地は%pです。\n", &y);

    printf("\n");
    printf(" a の値は%dです。\n", a);
    printf(" b の値は%dです。\n", b);
    printf(" x の値は%fです。\n", x);
    printf(" y の値は%fです。\n", y);

    a = 24;
    b = 56;
    x = 3.0;
    y = 4.0;
    
    printf("\n");
    printf(" a の値は%dです。\n", a);
    printf(" b の値は%dです。\n", b);
    printf(" x の値は%fです。\n", x);
    printf(" y の値は%fです。\n", y);

    return 0;
}

/*
#include <stdio.h>

int main(void)
{
	int a, b;
	double x, y;
	a = 12;
	b = 34;
	x = 3.0;
	y = 4.0;
	
	printf("aの番地: %p\n", &a);
	printf("bの番地: %p\n", &b);
	printf("xの番地: %p\n", &x);
	printf("yの番地: %p\n", &y);
	//aの番地: 0x7ffffcc2c
	//bの番地: 0x7ffffcc28
	//xの番地: 0x7ffffcc20
	//yの番地: 0x7ffffcc18
	
	printf("\n");
	*((int*)0x7ffffcc2c) = 24;  
 	*((int*)0x7ffffcc28) = 56;  
  	*((double*)0x7ffffcc20) = 16.0;
	*((double*)0x7ffffcc18) = 23.0;
	
	 printf("\n");
 	 printf("a の値 = %d\n", a);
 	 printf("b の値 = %d\n", b);
 	 printf("x の値 = %lf\n", x);
	 printf("y の値 = %lf\n", y);

  return 0;
}
自分の使っている環境では動作しなかったため、学校のpcではこのコードで実行しました。
*/