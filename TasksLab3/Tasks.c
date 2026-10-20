#include <stdio.h> 
#include <windows.h>
#include <math.h>

#define PI 3.141593f

//Завдання 4
static void Task4(int year0, int month0, int year1, int month1)
{
	if (year0 < 0 || year1 < 0 || month0 <= 0 || month1 <= 0 || month0 > 12 || month1 > 12) {
		printf("Рік і місяць не можуть бути від'ємними і місяців не може бути більше за 12\n");
		return;
	}
	int year = year1 - year0;

	if (month1 > month0) year++;
	else if (month1 < month0) year--;

	printf("Вік людини: %d\n", year);
	if (month1 == month0) {
		printf("Пройшов повний рік!\n");
	}
}

//Завдання 8
static void Task8(float areaCircle, float areaSquare)
{
	float radiusCircle = 0.0f, HalfSideSquare = 0.0f, radiusCircleSquare = 0.0f;

	radiusCircle = sqrtf(areaCircle / PI);
	HalfSideSquare = sqrtf(4 * areaSquare);
	radiusCircleSquare = sqrtf(areaSquare * 2) / 2;

	if (radiusCircle <= HalfSideSquare) {
		printf("а) Так, коло вміщується в квадрат\n");
	}
	else{
		printf("а) Ні, коло не вміщується в квадрат\n");
	}
	if (radiusCircleSquare <= radiusCircle) {
		printf("б) Так, квадрат вміщується в коло\n");
	}
	else {
		printf("б) Ні, квадрат не вміщується в коло\n");
	}
}
//Завдання 40
static void Task40(float temperature)
{
	if (temperature > 60) {
		printf("Пожежонебезпечна ситуація\n");
	}
	else {
		printf("Все безпечно\n");
	}
}
//Завдання 47
static void Task47(float radiusCircle, float sideSquare, float side1Rectangle, float side2Rectangle, float side1Triangle, float side2Triangle, float side3Triangle)
{
	float areaCircle = PI * radiusCircle * radiusCircle;
	float areaSquare = sideSquare * sideSquare;
	float areaRectangle = side1Rectangle * side2Rectangle;
	float p = (side1Triangle + side2Triangle + side3Triangle) / 2.0f;
	float areaTriangle = sqrtf(p * (p - side1Triangle) * (p - side2Triangle) * (p - side3Triangle));

	if (areaCircle == areaSquare && areaSquare == areaRectangle && areaRectangle == areaTriangle) {
		printf("Немає найбільшої площі, бо площі рівні\n");
		return;
	}

	float max = areaCircle;
	char* name = "кола";

	if (areaSquare > max) {
		max = areaSquare; name = "квадрата"; 
	}
	if (areaRectangle > max) {
		max = areaRectangle; name = "прямокутника";
	}
	if (areaTriangle > max) {
		max = areaTriangle; name = "трикутника";
	}
	printf("Найбільша площа -- площа %s (%.2f)\n", name, max);
	
}
//Завдання 58
static void Task58(float xa, float ya, float xb, float yb, float xc, float yc)
{
	float absBA = sqrtf((xb - xa) * (xb - xa) + (yb - ya) * (yb - ya));
	float absBC = sqrtf((xb - xc) * (xb - xc) + (yb - yc) * (yb - yc));


	if ((xb - xa) * (yc - ya) == (yb - ya) * (xc - xa)) {
		printf("Точки знаходяться на одній прямій.\n");
	}
	else {
		float cosB = (float)((xb - xa) * (xb - xc) + (yb - ya) * (yb - yc)) / (absBA * absBC);
		float radB = acosf(cosB);
		float angleB = radB * 180.0f / 3.14159265f;
		printf("Три точки не лежать на одній прямій, тому кут В в градусах дорівнює: %f\n", angleB);
	}
}

//Завдання 61
static void Task61(float a, float b, float c)
{
	if ((a + b > c) && (a + c > b) && (b + c > a)) {
		float p = (a + b + c) / 2;
		float areaTriangle = sqrtf(p * (p - a) * (p - b) * (p - c));

		printf("Числа є сторонами трикутника. Площа триктуника дорівнює: %f\n", areaTriangle);
	}
	else {
		printf("Числа НЕ є сторонами трикутника\n");
	}
}

//Завдання 65
static void Task65(float x)
{
	float s = sin(x);
	float c = cos(x);

	if (c == 0) {
		printf("Вираз tan x не має сенсу при таких значеннях x\n");
		if (s < c) {
			printf("У порядку зростання: sin x, cos x\n");
		}
		else {
			printf("У порядку зростання: cos x, sin x\n");
		}
	}
	else {
		float t = tan(x);

		float arr[3] = { s,c ,t };
		char* names[3] = { "sin(x)", "cos(x)", "tan(x)" };

		for (int i = 0; i < 2; i++) {
			for (int j = i + 1; j < 3; j++) {
				if (arr[i] > arr[j]) {
					float temp_val = arr[i];
					arr[i] = arr[j];
					arr[j] = temp_val;

					char* temp_name = names[i];
					names[i] = names[j];
					names[j] = temp_name;
				}
			}
		}
		printf("У порядку зростання\n");
		for (int i = 0; i < 3; i++) {
			printf("%s = %0.4f\n", names[i], arr[i]);
		}
	}
}
//Завдання 69
static void Task69(int N, int M)
{
	if (M <= 0) {
		printf("Номер квартири має бути додатним числом!\n");
		return;
	}

	int floor = (M - 1) / 3 + 1;

	if (floor > N) {
		printf("Квартира з номером %d не може знаходитися в хмарочосі на %d поверхів (вона на %d поверсі).\n", M, N, floor);
		return;
	}

	printf("Розрахунковий поверх для квартири %d: %d\n", M, floor);

	if (floor % 2 != 0) {
		printf("Поверх непарний. Ліфт доставив пасажира на %d поверх. \n", floor);
	}
	else {
		int targetFloor = floor - 1;
		if (targetFloor < 1) {
			targetFloor = floor + 1;
		}
		printf("Ліфт зупиняється лише на непарних поверхах!\n");
		printf("Ліфт доправить пасажира на найближчий непарний поверх: %d (звідти потрібйно пройтися до квартири на %d поверсі).\n", targetFloor, floor);
	}
}
//Завдання 84
static void Task84(float a, float b, float c)
{
	if (a < 0 || b < 0 || c < 0) {
		printf("Довжина не може бути від'ємною!");
		return;
	}
	if ((a + b > c) && (a + c > b) && (b + c > a)) {
		if (a == b || a == c || b == c) {
			printf("Трикутник рівнобедренний!\n");
		}
		else {
			printf("Триктник не є рівнобедренним.\n");
		}
	}
	else {
		printf("Не існує трикутника зі сторонами %f, %f, %f \n", a, b, c);

	}
}
//Завдання 108
static void printQuadrant(float x, float y) {
	if (x > 0 && y > 0) printf("I квадрант (x > 0, y > 0)");
	else if (x < 0 && y > 0) printf("II квадрант (x < 0, y > 0)");
	else if (x < 0 && y < 0) printf("III квадрант (x < 0, y < 0)");
	else if (x > 0 && y < 0) printf("IV квадрант (x > 0, y < 0)");
	else if (x == 0 && y != 0) printf("лежить на осі Y");
	else if (y == 0 && x != 0) printf("лежить на осі X");
	else printf("початок координат (0, 0)");
}
static void Task108(float k, float b, float R)
{
	if (R < 0) {
		printf("Радіус кола R має бути додатним числом!\n");
		return;
	}

	float A = 1.0f + k * k;
	float B = 2.0f * k * b;
	float C = b * b - R * R;

	float D = B * B - 4.0f * A * C;

	if (D < 0) {
		printf("Точок перетину немає: пряма проходить поза колом\n");
	}
	else if (fabsf(D) < 1e-5) {
		float x = -B / (2.0f * A);
		float y = k * x * b;
		printf("Пряма стосується кола в одній точці:\n");
		printf("Координати: (%.4f, %.4f) - знаходиться у ", x, y);
		printQuadrant(x, y);
		printf("\n");
	}
	else {
		float sqrtD = sqrtf(D);
		float x1 = (-B + sqrtD) / (2.0f * A);
		float y1 = k * x1 + b;

		float x2 = (-B - sqrtD) / (2.0f * A);
		float y2 = k * x2 + b;

		printf("Пряма перетинає коло у двох точках:\n");

		printf("Точка 1: (%.4f, %.4f) - ", x1, y1);
		printQuadrant(x1, y1);
		printf("\n");

		printf("Точка 2: (%.4f, %.4f) - ", x2, y2);
		printQuadrant(x2, y2);
		printf("\n");
	}
}

int main() {
	SetConsoleOutputCP(65001);
	int n = 1;

	while (n) {
		//Вибираємо завдання
		int task = 0;
		printf("Оберіть завдання: (4, 8, 40, 47, 58, 61, 65, 69, 84, 108) або 0 для виходу:\n");
		if (scanf_s("%d", &task) != 1) break;
		if (task == 0) break;

		switch (task) {
		case 4: {
			  int y0, m0, y1, m1;
			  printf("Завдання 4: Відомі рік і номер місяця народження людини, а також рік і номер місяця сьогодення (січень—1 і т.д.). Визначити вік людини (кількість повних років). У разі збігу зазначених місяців вважати, що пройшов повний рік.\n");
			  printf("\nВведіть рік і місяць народження: ");
			  scanf_s("%d %d", &y0, &m0);
			  printf("Введіть рік і місяць сьогодення: ");
			  scanf_s("%d %d", &y1, &m1);

			  Task4(y0, m0, y1, m1);
			  break;
		}
		case 8: {
			float ac, as;
			printf("Завдання 8: Відомі площі кола та квадрата.\nВизначити:а) чи вміститься коло в квадраті;б) зміститься чи квадрат у колі.\n");
			printf("Введіть площу кола та площу квадрата: ");
			scanf_s("%f %f", &ac, &as);
			Task8(ac, as);
			break;
		}
		case 40: {
			float t;
			printf("Завдання 40: Написати програму — модель аналізу пожежного датчика у приміщенні, яка виводить повідомлення «Пожежонебезпечна ситуація», якщо температура в кімнаті перевищила 60С.\n");
			printf("Введіть температуру в приміщенні (°С): ");
			scanf_s("%f", &t);
			Task40(t);
			break;
		}

		case 47: {
			float rc, ss, s1r, s2r, s1t, s2t, s3t;
			printf("Завдання 47: Задані радіус кола, сторона квадрата, дві суміжні сторони прямокутника та три сторони трикутника.\nВизначити, яка фігура має найбільшу площу.\n");
			printf("%f %f %f %f %f %f %f", &rc, &ss, &s1r, &s2r, &s1t, &s2t, &s3t);
			Task47(rc, ss, s1r, s2r, s1t, s2t, s3t);
			break;
		}

		case 58: {
			float xa, ya, xb, yb, xc, yc;
			printf("Завдання 58: Дано три точки А(x1, y1), B(x2, y2) і C(x3, y3). \nВизначити, чи вони розташовані на одній прямій. Якщо ні, то обчислити кут B.\n");
			printf("Введіть координати точок А, B, C (x1, y1, x2, y2, x3, y3): ");
			scanf_s("%f %f %f %f %f %f", &xa, &ya, &xb, &yb, &xc, &yc);
			Task58(xa, ya, xb, yb, xc, yc);
			break;
		}

		case 61: {
			float a, b, c;
			printf("Завдання 61: Дано три позитивні числа a, b, с. Перевірити, чи вони сторонами трикутника. Якщо так, то обчислити площу цього трикутника.");
			printf("Введіть три сторони трикутника a, b, c: ");
			scanf_s("%f %f %f", &a, &b, &c);
			Task61(a, b, c);
			break;
		}

		case 65: {
			float x;
			printf("Завдання 65: Дано число x. Надрукувати в порядку зростання числа: sin x, cos x, tan x.\nЯкщо за будь-якого значення x деякі з виразів не мають сенсу, вивести повідомлення про це та порівнювати значення лише тих виразів, які мають сенс.\n");
			printf("Введіть значення числа x у радіанах: ");
			scanf_s("%f", &x);
			Task65(x);
			break;
		}
		case 69: {
			int N, M;
			printf("Завдання 69: У хмарочосі N поверхів та всього один під'їзд; на кожному поверсі по 3 квартири; ліфт може зупинятися лише на непарних поверхах.\nЛюдина сідає в ліфт і набирає номер потрібної йому квартири. М.\nНа який поверх має доставити ліфт пасажира? ");
			printf("Введіть загальну кількість поверхів у хмарочосі (N) та номер квартири (M): ");
			scanf_s("%d %d", &N, &M);
			Task69(N, M);
			break;
		}
		case 84: {
			float a, b, c;
			printf("Завдання 84: Визначити, чи є трикутник із сторонами a, b, c рівнобедреним.\n");
			printf("Введіть довжину сторін а, b, c: ");
			scanf_s("%f %f %f", &a, &b, &c);
			Task84(a, b, c);
			break;
		}
		case 108: {
			float k, b, R;
			printf("Завдання 108: Знайти координати точок перетину прямої y = kx + b та кола радіусу R з центром на початку координат.\nУ яких квадрантах є точки перетину? Якщо точок перетину немає, або пряма стосується кола, видати відповідне повідомлення.\n");
			printf("Введіть коефіцієнти k та b для прямої y = kx + b та радіус кола R: ");
			scanf_s("%f %f %f", &k, &b, &R);
			Task108(k, b, R);
			break;
		}
		default:
			printf("Такого номеру завдання немає, спробуй ще раз!\n\n");
			continue;
		}
		printf("\nЩоб завершити програму зараз введіть: 0\n");
		scanf_s("%d", &n);
	}
	return 0;
}