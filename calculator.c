#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

double calculating(double a1, double b1, int op);

int main(void)
{
	double a, b, result;
	int choice; // 어떤 연산자로 계산할지 연산자를 선택한다.
		char cop[4]={'+','-','*','/'}; // 총 4개의 연산자 문자 중 하나를 선택하면 해당 연산자로 계산을 실행한다.

	while(1)
	{
	printf("Welcome!!!\n");
	printf("Personal Calculator Program\n");
	printf("version 1.0\n");
	printf("\n");

	printf("원하는 연산을 선택하세요\n");
	printf("1>더하기 2>빼기 3>곱셈 4>나눗셈 5>프로그램 종료\n"); // 앞서 말한 것 처럼 4개의 연산자를 번호를 지정해 선택할 수 있고 5번을 선택해서 프로그램을 종료할 수도 있다
	printf("선택한 연산은?");
	scanf("%d", &choice);

	if(choice==5) // 5번을 입력하면 사칙 연산 계산기 프로그램 종료한다
		break;
	if(choice<1 || choice>5) // 1~5 이외의 숫자를 입력하면 잘못된 값을 입력했다고 출력한다
	{
		printf("\n━━━━━ 잘못된 값 입력 ! ━━━━━\n");
		continue;
	}

	printf("\n연산할 숫자를 입력해주세요.(ex : 1 2)\n");
	scanf("%lf %lf", &a, &b);
	
	if(choice == 4 && b == 0) // a 값을 0으로 나눗셈을 할 경우에 나눌 수 없다는 에러를 출력한다
	{
	printf("error : 0으로 나누실 수 없습니다.\n\n");
	continue;
	}

	result = calculating(a, b, choice); // 사칙연산 계산기의 연산 함수를 호출한다

	printf("\n [계산 결과]\n");
	printf("%.2lf %c %.2lf = %.2lf\n\n", a, cop[choice-1], b, result); // 나눗셈할 경우 나머지가 존재할 수 있으므로 소수점 2번째 자리까지 출력한다
	}
	system("clear");
	printf("\n━━━━━ 계 산 기 종 료! ━━━━━\n");
	printf("Personal Calculator Program을 이용해주셔서 감사드립니다다.\n");
	printf("개발자 : 영남이공대학교 사이버보안과 손승호\n");

	return 0;
	}

	// 인자로 받은 값으로 연산자별로 계산하여 리턴 값으로 반환해준다
	double calculating(double a1, double b1, int op)
	{
	double rs;

	switch(op)
	{
	case 1: // 케이스 1 덧셈구문
	rs=a1+b1;
	break;
	case 2: // 케이스 2 뺄셈구문
	rs=a1-b1;
	break;
	case 3: // 케이스 3 곱셈구문
	rs=a1*b1;
	break;
	case 4: // 케이스 4 나눗셈구문
	rs=a1/b1;
	break;
	}

	return rs;
	}
