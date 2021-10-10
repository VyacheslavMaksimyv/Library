#pragma warning(disable:4996)
#include "Biblio.h"
#include <iostream>
#include <Windows.h>
#include <tchar.h>
#include <iomanip>
#include <stdio.h>
int _tmain(int argc, _TCHAR* argv[])
{
	books b = books();
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int x, k = 0;
	while (1)
	{
		while (1)
		{
			std::cout << "Виберіть операцію яку ви хочете виконати з базою даних" << std::endl;
			std::cout << "1)-Записати базу даних\n2)-Дописати записи в базу даних(допис відбувається у уже існуючу базу)\n3)-Вивести усі дані з бази даних\n4)-Змінити записи в базі даних\n5)-Відібрати дані з бази даних (за критерієм)\n6)-Видалити дані з бази даних\n7)-Сортування даних(вивід в текстовий файл)\n0)-Вихід з програми" << std::endl;
			std::cin >> x;
			system("cls");
			switch (x)
			{
			case 1:
				std::cout << "Дана функція перестворює базу даних" << std::endl << "Ви дійсно бажаєте продовжити (1) чи можливо ви предумали(0)?" << std::endl;
				std::cin >> x;
				if (x == 1)
					b.Record();
				system("cls");
				break;
			case 2:
				b.Add_to_bin();
				break;
			case 3:
				b.Repeat();
				break;
			case 4:
				while (1)
				{
					b.Mod();
					std::cout << "Продовжити редагування записів даної бази даних(1) чи вийти до головного меню(0)?" << std::endl;
					std::cin >> x;
					if (x == 0)
						break;
				}
				break;
			case (5):
				while (1)
				{
					std::cout << "Ви бажаєте здійснити вибірку за певним значенням певного поля(0)? " << std::endl;
					std::cin >> x;
					if (x == 1)
					{
						k = 0;
					}
					else
					{
						while (1)
						{
							std::cout << "Виберіть поле за яким бажаєте здійснити вибірку:";
							std::cout << std::endl << "1)-Назва\n2)-Автор\n3)-Жанр\n4)-Рік випуску\n5)-Ціна\n6)-Дата інвентаризації\n7)-Наявність CD/DVD(так/ні)" << std::endl;
							std::cin >> k;
							if (k >= 1 && k <= 7)
								break;
							else
								std::cout << "Ви вибрали не існуючий варіант!!!" << std::endl;
						}
					}
					system("cls");
					b.Drop_to_txt(k);
					std::cout << "Продовжити вибірку записів даної бази даних(1) чи вийти до головного меню(0) ? " << std::endl;
					std::cin >> x;
					if (x == 0)
					{
						system("cls");
						break;
					}
					system("cls");
				}
				break;
			case 6:
				while (1)
				{
					b.Remove();
					std::cout << "Продовжити видалення записів даної бази даних(1) чи вийти до головного меню(0)?" << std::endl;
					std::cin >> x;
					if (x == 0)
						break;
				}
				break;
			case (7):
				while (1)
				{
					std::cout << "Ви бажаєте здійснити сортуваня за роком видання (1) чи певним значенням певного поля (0)? " << std::endl;
					std::cin >> x;
					if (x == 1)
					{
						k = 0;
					}
					else
					{
						while (1)
						{
							std::cout << "Виберіть поле за яким бажаєте здійснити сортуваня:";
							std::cout << std::endl << "1)-Назва\n2)-Автор\n3)-Жанр\n4)-Рік випуску\n5)-Ціна\n6)-Дата інвентаризації\n7)-Наявність CD/DVD(так/ні)" << std::endl;
							std::cin >> k;
							if (k >= 1 && k <= 7)
								break;
							else
								std::cout << "Ви вибрали не існуючий варіант!!!" << std::endl;
						}
					}
					system("cls");
					b.Sort_to_txt(k);
					system("cls");
					break;
				}
				break;
			case (0):
				std::cout << "Дякуємо за користування нашою програмою!\nПовертайтесь знову!!!" << std::endl;

				return 0;
			default:
				std::cout << "Ви вибрали не існуючий варіант!!!" << std::endl;
			}
			if (x <= 8 && x >= 1)
				break;
		}
		std::cout << "Бажаєте продовжити роботу з базою даних(1) чи завершити роботу(0)?" << std::endl;
		std::cin >> x;
		system("cls");
		if (x != 1)
			break;
	}
	std::cout << "Дякуємо за користування нашою програмою!\nПовертайтесь знову!!!" << std::endl;
	system("pause");
	return 0;
}