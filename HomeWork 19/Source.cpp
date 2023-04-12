#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>

int functionEx1(int num1,int num2);//Ex1
int mirror_number(int num);//Ex2
int arr_search(int arr[], const int length, int num);//Ex3
void arr_AB(int arr[], const int length, int num1, int num2);//Ex4
int main() {
	int n0, n, n1, n2, n3, n4;

		//Задача 1
		//Создайте функцию, которая принимает два числа и
		//возвращает их наибольший общий делитель.
	std::cin >> n >> n0;
	std::cout << functionEx1(n, n0);
	std::cout << std::endl;
		//Задача 2
		//Напишите функцию mirror_number, которая
		//принимает число и возвращает его в отражённом виде.
	std::cin>> n1;
	std::cout << mirror_number(n1);//(int)pow(10, k - 1);//v;//pow(10, k-1);
	std::cout << std::endl;
		//Задача 3
		//Создайте функцию, которая принимает массив, его
		//длину и число N.Функция возвращает первую позицию
		//числа N в массиве, а также сортирует все элементы,
		//которые находятся справа от N.
	const int size3 = 100;
	int arr3[size3];
	std::cin >> n2;
	std::cout << arr_search(arr3, size3, n2);
	std::cout << std::endl;
		//Задача 4
		//	Создайте функцию, которая принимает пустой
		//	массив, его длину и два числа A и B, которые являются
		//	началом и концом диапазона.Функция должна
		//	заполнять массив случайными числами из указанного
		//	диапазона.
	const int size4 = 100;
	int arr4[size4]{};
	return 0;
}

int functionEx1(int num1, int num2) { //Ex1
	if (num1 == num2)
		return num1;
	if (num2 > num1) {
		for (int i = num2 / 2; i > 0; i--)
			if (num2 % i == 0)
				if (num1 % i == 0)
					return i;
	}
	else {
		for (int i = num1 / 2; i > 0; i--)
			if (num1 % i == 0)
				if (num2 % i == 0)
		return i;
	}	
}


int mirror_number(int num) { //Ex2
	int v = 0;
	int m = num;
	int k = 0;
	do {
		m /= 10;
		k++;
	} while (m != 0);
	m = 0;
	int l = 1;
	int s;
	s = k;
	for (int i = 0; i < k; i++) {
		m = num % (int)pow(10, l);
		m = m / (int)pow(10, l - 1);
		v = v + m * (int)pow(10, s - 1);
		l++;
		s--;
	}
	return v;
}
int arr_search(int arr[], const int length, int num) { //Ex3
	int n = 0;
	srand(time(NULL));
	for (int i = 0; i < length; i++){
		arr[i] = rand() % (100 - 0 + 1) + 0;
	}
	if (num > -1 && num < 101) {
		for (int i = 0; i < length; i++)
			if (num == arr[i]) {
				n = i;
			}
		for (int i = n + 1 ; i < length; i++){
			for (int j = n + 1; j < length - 1; j++){
				if (arr[i] < arr[i + 1]) {
					int tmp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = tmp;
				}
			}
		}
	if (num > -1 && num < 101) 
		for (int i = 0; i < length; i++)
			if (num == arr[i]) 				
				return i;			
	}
	else return -1;
}
void arr_AB(int arr[], const int length, int num1, int num2) {//Ex4
		if (num1 < 0 || num2 < 0)
			std::cout << "Entor ERROR!!!";
		if (num1 > num2)
			std::swap(num1, num2);
		for (int i = 0; i < length; i++)	{
			if (arr[i] >= num1 && arr[i] <= num2) {
				srand(time(NULL));
					arr[i] = rand() % 11;
			}
		}
}
