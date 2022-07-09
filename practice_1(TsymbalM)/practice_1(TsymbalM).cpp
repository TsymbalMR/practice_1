/**
* @file practise_1.cpp
* @author Цимбал Максим 515-і1
* @date 06.07.2022
* @brief Навчальна практика
*
* Калькулятор для довільного трикутника за заданими параметрами
**/
#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<iostream>
#define SIZE 1024
#define SIZE_V 10

double a, b, c;//оголошення змінних
double A, B, C;
double ma, mb, mc;
double ha, hb, hc;
double xA, xB, xC, yA, yB, yC;
double S, p;
//оголошення функцій
void read_param(char*);//функція для запису введених у РЯДОК параметрів
char* read_value(double*, char*);//функція для зчитування введених у РЯДОК параметрів
void three_sides();//функція для розрахунку трикутника(введено 3 сторони)
void output_param();//функція для виведення результату
void two_sides_and_angle();//функція для розрахунку трикутника(введено 2 сторони та кут)
bool triangle_exists();//функція для перевірки на коректність введених даних
void tree_heights();//функція для розрахунку трикутника(введено 3 висоти)
void three_coordinates();//функція для розрахунку трикутника(введено координати точок)
void print_menu();//функція для виведення інструкції калькулятора

bool flag_trg_or_param = true;//для перевірки на правильність введених даних
bool error_input = false;//для перевірки на коректність введених даних

int main()//головна функція
{
	int key, k = 0;
	int start;
	char param_str[SIZE] = { '\0' };
	setlocale(LC_ALL, "Ukr");
	print_menu();
	while (1)
	{
		a = 0, b = 0, c = 0;
		A = 0, B = 0, C = 0;
		ma = 0, mb = 0, mc = 0;
		ha = 0, hb = 0, hc = 0;
		xA = 0, xB = 0, xC = 0, yA = 0, yB = 0, yC = 0;
		S = 0, p = 0;
		printf("Введiть параметри: \n");
		gets_s(param_str);
		read_param(param_str);
		if (error_input)
		{
			printf("Некоректне введення парметрiв!!!\n");
			error_input = false;
			continue;
		}

		flag_trg_or_param = triangle_exists();

		if (!flag_trg_or_param)
		{
			printf("Введiть параметри ще раз!!!\n");
			continue;
		}

		if (a != 0 && b != 0 && c != 0)
		{
			three_sides();
			if (!flag_trg_or_param)
			{
				continue;
			}
			output_param();
			continue;
		}
		else if (a != 0 && b != 0 && C != 0 || b != 0 && c != 0 && A != 0 || a != 0 && c != 0 && B != 0)
		{
			two_sides_and_angle();
			if (!flag_trg_or_param)
			{
				continue;
			}
			output_param();

			continue;
		}
		else if (ha != 0 && hb != 0 && hc != 0)
		{
			tree_heights();
			output_param();
			continue;
		}
		else if (xA != 0 && xB != 0 && xC != 0 && yA != 0 && yB != 0 && yC != 0)
		{
			three_coordinates();
			output_param();
			continue;
		}
		else
		{
			printf("Недостатньо параметрiв!!!\n");
		}
	}

	system("pause");
	return 0;
}

/**
* Запис параметру
* @param param_str рядок
* @return відсутній
**/
void read_param(char* param_str)
{
	char* reader = param_str;
	while (*reader != '\0')
	{
		if (error_input)
		{
			return;
		}
		switch (*reader)
		{
		case 'a':
			reader = read_value(&a, reader);
			break;
		case 'b':
			reader = read_value(&b, reader);
			break;
		case 'c':
			reader = read_value(&c, reader);
			break;
		case 'A':
			reader = read_value(&A, reader);
			break;
		case 'B':
			reader = read_value(&B, reader);
			break;
		case 'C':
			reader = read_value(&C, reader);
			break;
		case 'm':
			reader++;
			switch (*reader)
			{
			case 'a':
				reader = read_value(&ma, reader);
				break;
			case 'b':
				reader = read_value(&mb, reader);
				break;
			case 'c':
				reader = read_value(&mc, reader);
				break;
			}
			break;
		case 'h':
			reader++;
			switch (*reader)
			{
			case 'a':
				reader = read_value(&ha, reader);
				break;
			case 'b':
				reader = read_value(&hb, reader);
				break;
			case 'c':
				reader = read_value(&hc, reader);
				break;
			}
			break;
		case 'x':
			reader++;
			switch (*reader)
			{
			case 'A':
				reader = read_value(&xA, reader);
				break;
			case 'B':
				reader = read_value(&xB, reader);
				break;
			case 'C':
				reader = read_value(&xC, reader);
				break;
			}
			break;
		case 'y':
			reader++;
			switch (*reader)
			{
			case 'A':
				reader = read_value(&yA, reader);
				break;
			case 'B':
				reader = read_value(&yB, reader);
				break;
			case 'C':
				reader = read_value(&yC, reader);
				break;
			}
			break;
		case 'S':
			reader = read_value(&S, reader);
			break;
		case 'p':
			reader = read_value(&p, reader);
			break;
		default:
			error_input = true;
		}
	}

}

/**
* Зчитування параметрів
* @param reader - рядок
* @return reader
**/
char* read_value(double* boofer, char* reader)
{
	bool numeral = false;
	bool separator = false;
	char value_in_str[SIZE_V] = { '\0' };
	char* ptr_value = value_in_str;
	reader++;
	while (!((*reader >= 'a' && *reader <= 'z') || (*reader >= 'A' && *reader <= 'Z') || (*reader == '\0')))
	{
		if ((*reader >= '0' && *reader <= '9') || (*reader == '-'))
		{
			numeral = true;
			*ptr_value = *reader;
			reader++;
			ptr_value++;
			continue;
		}
		if (*reader == '.' || *reader == ';' || *reader == ',')
		{
			separator = true;
			*boofer = atoi(value_in_str);
		}
		reader++;
	}
	value_in_str[0] = '\0';
	if (!numeral || !separator)
	{
		error_input = true;
		return reader;
	}
	else
	{
		return reader;
	}
}
/**
* Розрахунок , коли введено три сторони
* @param відсутній
* @return відсутній
**/
void three_sides()
{
	bool flag = false;
	if (a < b && a < c)
	{
		if (b < c)
		{
			if (a + b < c)
			{
				printf("Трикутника не iснує!!!\n");
				flag_trg_or_param = false;
				return;
			}
			else
			{
				flag = true;
			}
		}
	}
	if (!flag)
	{
		if (b < a && b < c)
		{
			if (c < a)
			{
				if (b + c < a)
				{
					printf("Трикутника не iснує!!!\n");
					return;
				}
				else
				{
					flag = true;
				}

			}
		}
	}
	if (!flag)
	{
		if (a + c < b)
		{
			printf("Трикутника не iснує!!!\n");
			return;
		}
		else
		{
			flag = true;
		}
	}
	p = (a + b + c) / 2;
	S = sqrt(p * (p - a) * (p - b) * (p - c));
	ha = (2 * S) / a;
	hb = (2 * S) / b;
	hc = (2 * S) / c;
	A = acos((b * b + c * c - a * a) / (2 * b * c));
	B = acos((a * a + c * c - b * b) / (2 * a * c));
	A = A * 180 / 3.14;
	B = B * 180 / 3.14;
	C = 180 - (A + B);

	double k = 0;
	k = 1.0 / 2.0;
	ma = (double)k * sqrt(b * b + c * c + 2.0 * c * b * cos(A * 3.14 / 180));
	mb = (double)k * sqrt(2.0 * a * a + 2.0 * c * c - b * b);
	mc = (double)k * sqrt(2.0 * b * b + 2.0 * a * a - c * c);
}

/**
* Розрахунок , коли введено дві сторони та кут
* @param відсутній
* @return відсутній
**/
void two_sides_and_angle()
{
	if (a != 0 && b != 0 && C != 0)
	{
		c = sqrt(((b * b) + (a * a)) - (2 * b * a * cos(C * 3.14 / 180)));
		three_sides();
	}
	else if (a != 0 && c != 0 && B != 0)
	{
		b = sqrt(c * c + a * a - 2 * c * a * cos(B * 3.14 / 180));
		three_sides();
	}
	else if (b != 0 && c != 0 && A != 0)
	{
		a = sqrt(((b * b) + (c * c)) - (2 * c * b * cos(A * 3.14 / 180)));
		three_sides();
	}
	else
	{
		printf("Мало параметрiв!!!\n");
		flag_trg_or_param = false;
	}

}

/**
* Перевірка на коректність даних
* @param відсутній
* @return відсутній
**/
bool triangle_exists()
{
	if (a < 0 || b < 0 || c < 0)
	{
		printf("Сторона не може бути вшд'ємна!!!\n");
		return false;
	}

	if ((A > 180 || A < 0) || (B > 180 || B < 0) || (C > 180 || C < 0))
	{
		printf("Кути не можуть бути бiльше 180 градусiв!!\n");
		return false;
	}

	if (ha < 0 || hb < 0 || hc < 0)
	{
		printf("Висота не може бути вiд'ємна!!!\n");
		return false;
	}

	if (ma < 0 || mb < 0 || mc < 0)
	{
		printf("Площа не може бути від'ємна!!!\n");
		return false;
	}

	if (S < 0)
	{
		printf("Площа не може бути від'ємна!!!\n");
		return false;
	}

	if (p < 0)
	{
		printf("Пiвпериметр не може бути від'ємним!!!\n");
		return false;
	}

	if ((a + b == c || b + c == a || a + c == b) && a != 0 && b != 0 && c != 0)
	{
		printf("Трикутнк не iснує!!!\n");
		return false;
	}


	return true;
}

/**
* Розрахунок , коли введено три висоти
* @param відсутній
* @return відсутній
**/
void tree_heights()
{
	S = (double)1 / (sqrt((1 / ha + 1 / hb + 1 / hc) * (1 / ha + 1 / hb - 1 / hc) * (1 / ha - 1
		/ hb + 1 / hc) * (1 / hb + 1 / hc - 1 / ha)));
	a = 2 * S / ha;
	b = 2 * S / hb;
	c = 2 * S / hc;
	three_sides();
}

/**
* Розрахунок , коли введено координати трьох вершин
* @param відсутній
* @return відсутній
**/
void three_coordinates()
{
	c = sqrt((xB - xA) * (xB - xA) + (yB - yA) * (yB - yA));
	b = sqrt((xC - xA) * (xC - xA) + (yC - yA) * (yC - yA));
	a = sqrt((xC - xB) * (xC - xB) + (yC - yB) * (yC - yB));
	tree_heights();
}

/**
* Виведення результатів
* @param відсутній
* @return відсутній
**/
void output_param()
{
	printf("Сторона а = %g\n", a);
	printf("Сторона b = %g\n", b);
	printf("Сторона c = %g\n", c);
	printf("Кут А = %g\n", A);
	printf("Кут B = %g\n", B);
	printf("Кут C = %g\n", C);
	printf(" Висота ha = %g\n", ha);
	printf(" Висота hb = %g\n", hb);
	printf(" Висота hc = %g\n", hc);
	printf(" Медiана ma = %g\n", ma);
	printf(" Медiана mb = %g\n", mb);
	printf(" Медiана mc = %g\n", mc);
	if (xA != 0 && yA != 0 && xB != 0 && yB != 0 && xC != 0 && yC != 0)
	{
		printf(" Координати точки A: x = %g, y = %g\n", xA, yA);
		printf(" Координати точки B: x = %g, y = %g\n", xB, yB);
		printf(" Координати точки C: x = %g, y = %g\n", xC, yC);
	}
	else
	{
		printf("Координати не можуть бути порахованi!!!\n");
	}
	printf(" Площа S = %g\n", S);
	printf(" Пiвпериметр p = %g\n", p);
}

/**
* Виведення інструкції
* @param відсутній
* @return відсутній
**/
void print_menu()
{
	printf("\t\t\tIнструкцiя по використанню калькулятора\n");
	printf("Сторони протилежнi будь-якому куту називаються так само лише маленькою лiтерою. Тобто навпроти кута А лежить сторона\nтрикутника а, сторонi c протистоiть кут С.\n");
	printf("Сума БУДЬ-ЯКИХ(!) двох сторiн має бути бiльшою за третю.\n");
	printf("Параметри записувати як (параметр = значення)\n");
	printf("Список параметрiв, якi можуть фiгурувати в розрахунках:\n");
	printf("Сторона a\nСторона b\nСторона c\nПiвпериметр p\nКут А\nКут B\nКут C\nПлоща трикутника S\nВисота ha на сторону a\nВисота hb на сторону b\nВисота hc на сторону c\n");
	printf("Медiана ma на сторону a\nМедiана mb на сторону b\nМедiана mc на сторону c\nКоординати вершин (xA,yA) (xB,yB) (xC,yC)\n");
	printf("Приклад введення параметрiв: а = 2; b = 5; C = 45;\n");
	printf("Строго дотримуйтесь синтаксису запису параметрiв!!!\n");
}
