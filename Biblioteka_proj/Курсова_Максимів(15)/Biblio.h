#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <iomanip>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <string>
FILE* filebin, * filetxt;
class books
{
public:
	int number;
	char name[20];
	char avtor[20];
	char genre[25];
	int yearr;
	int price;
	int date[3];
	char dvd[3];
	void Record()
	{
		int n, k = 1;
		if ((filebin = fopen("Bookshelf.bin", "wb")) == NULL)
		{
			std::cout << "На вашому присторої відсутня база даних з назвою\"Bookshelf.bin\"!" << std::endl;
			exit(1);

		}
		std::cout << "Введіть кількість записів яку хочете занести в базу даних: ";
		std::cin >> n;
		fwrite(&n, sizeof(int), 1, filebin);
		books book = books();
		for (int i = 0; i < n; i++)
		{
			book.number = k; k++;
			std::cout << "Введiть назву книги:";
			std::cin >> book.name;
			std::cout << "Введiть автора книги:";
			std::cin >> book.avtor;
			std::cout << "Введiть жанр книги:";
			std::cin >> book.genre;
			while (1)
			{
				std::cout << "Введiть рік видання:";
				std::cin >> book.yearr;
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
				}
				else
				{
					if (book.yearr > 1800 && book.yearr <= 2020)
						break;
				}
			}
			while (1)
			{
				std::cout << "Введiть ціну(ціна не може бути від'ємною):";
				std::cin >> book.price;
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
				}
				else
				{
					if (book.price > 0)
						break;
				}
			}
			std::cout << "Введiть дату інвентаризації відповідно наступних пунктів:" << std::endl;
			while (1)
			{
				std::cout << "Введiть день інвентаризації:";
				std::cin >> book.date[0];
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
				}
				else
				{
					if (book.date[0] > 0 && book.date[0] <= 30)
						break;
				}
			}
			while (1)
			{
				std::cout << "Введiть місяць інвентаризації:";
				std::cin >> book.date[1];
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
				}
				else
				{
					if (book.date[1] > 0 && book.date[1] <= 12)
						break;
				}
			}
			while (1)
			{
				std::cout << "Введiть рік інвентаризації:";
				std::cin >> book.date[2];
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
				}
				else
				{
					if (book.date[2] >= 1900 && book.date[2] <= 2020)
						break;
				}
			}
			while (1)
			{
				std::cout << "Введiть наявність місць(так/ні):";
				std::cin >> book.dvd;
				if (strcmp(book.dvd, "Так") == 0 || strcmp(book.dvd, "так") == 0 || strcmp(book.dvd, "Ні") == 0 || strcmp(book.dvd, "ні") == 0 || strcmp(book.dvd, "yes") == 0 || strcmp(book.dvd, "Yes") == 0 || strcmp(book.dvd, "no") == 0 || strcmp(book.dvd, "No") == 0)
					break;
			}
			fwrite(&book, sizeof(books), 1, filebin);
		}
		std::cout << "Ви успішно занесли дані в базу даних!!!" << std::endl;
		fclose(filebin);
		system("pause");
		system("cls");
	}
	void Add_to_bin()
	{
		int n1, n2, kil = 0, k = 1;
		if ((filebin = fopen("Bookshelf.bin", "r+b")) == NULL)
		{
			std::cout << "На вашому присторої відсутня база даних з назвою\"Bookshelf.bin\"!" << std::endl;
			exit(1);
		}
		fseek(filebin, 0, SEEK_SET);
		fread(&n1, sizeof(int), 1, filebin);
		std::cout << "Введіть кількість записів яку хочете дописати в базу даних: ";
		std::cin >> n2;
		kil = n1 + n2;
		k = n1 + 1;
		fseek(filebin, 0, SEEK_SET);
		fwrite(&kil, sizeof(int), 1, filebin);
		fseek(filebin, 0, SEEK_END);
		books book = books();
		for (int i = 0; i < n2; i++)
		{
			book.number = k; k++;
			std::cout << "Введiть назву книги:";

			std::cin>>book.name;
			std::cout << "Введiть автора книги:";

			std::cin>>book.avtor;
			std::cout << "Введiть жанр книги:";

			std::cin>>book.genre;
			while (1)
			{
				std::cout << "Введiть рік видання:";
				std::cin >> book.yearr;
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
				}
				else
				{
					if (book.yearr > 1800 && book.yearr <= 2020)
						break;
				}
			}
			while (1)
			{
				std::cout << "Введiть ціну(ціна не може бути від'ємною):";
				std::cin >> book.price;
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
				}
				else
				{
					if (book.price > 0)
						break;
				}
			}
			std::cout << "Введiть дату інвентаризації відповідно наступних пунктів:" << std::endl;
			while (1)
			{
				std::cout << "Введiть день інвентаризації:";
				std::cin >> book.date[0];
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
				}
				else
				{
					if (book.date[0] > 0 && book.date[0] <= 30)
						break;
				}
			}
			while (1)
			{
				std::cout << "Введiть місяць інвентаризації:";
				std::cin >> book.date[1];
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
				}
				else
				{
					if (book.date[1] > 0 && book.date[1] <= 12)
						break;
				}
			}
			while (1)
			{
				std::cout << "Введiть рік інвентаризації:";
				std::cin >> book.date[2];
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
				}
				else
				{
					if (book.date[2] >= 1900 && book.date[2] <= 2020)
						break;
				}
			}
			while (1)
			{
				std::cout << "Введiть наявність місць(так/ні):";
				std::cin >> book.dvd;
				if (strcmp(book.dvd, "Так") == 0 || strcmp(book.dvd, "так") == 0 || strcmp(book.dvd, "Ні") == 0 || strcmp(book.dvd, "ні") == 0 || strcmp(book.dvd, "yes") == 0 || strcmp(book.dvd, "Yes") == 0 || strcmp(book.dvd, "no") == 0 || strcmp(book.dvd, "No") == 0)
					break;
			}
			fwrite(&book, sizeof(books), 1, filebin);
		}
		std::cout << "Ви успішно додали дані в базу даних!!!" << std::endl;
		fclose(filebin);
		system("pause");
		system("cls");
	}
	void Repeat()
	{
		int n;
		if ((filebin = fopen("Bookshelf.bin", "rb")) == NULL)
		{
			std::cout << "На вашому присторої відсутня база даних з назвою\"Bookshelf.bin\"!" << std::endl;
			exit(1);
		}
		fseek(filebin, 0, SEEK_SET);
		fread(&n, sizeof(int), 1, filebin);
		std::cout << "+---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------+" << std::endl;
		std::cout << "|№  |Назва               |Автор               |Жанр                     |Рік        |Ціна    |Дата              | СD/DVD |" << std::endl;
		std::cout << "|   |                    |                    |                         |видання    |        |інвентаризації    |        |" << std::endl;
		std::cout << "|---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------|" << std::endl;
		books* book = new books[n];
		for (int i = 0; i < n; i++)
		{
			fread(&book[i], sizeof(books), 1, filebin);
			std::cout << "|" << std::left << std::setw(3) << i+1;
			std::cout << "|" << std::left << std::setw(20) << book[i].name;
			std::cout << "|" << std::left << std::setw(20) << book[i].avtor;
			std::cout << "|" << std::left << std::setw(25) << book[i].genre;
			std::cout << "|" << std::right << std::setw(11) << book[i].yearr;
			std::cout << "|" << std::right << std::setw(8) << book[i].price;
			std::cout << "|" << std::setw(2) << book[i].date[0] << "." << std::setw(2) << book[i].date[1] << "." << std::left << std::setw(12) << book[i].date[2];
			std::cout << "|" << std::left << std::setw(8) << book[i].dvd;
			std::cout << "|" << std::endl;
		}
		std::cout << "+---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------+" << std::endl;
		system("pause");
		fclose(filebin);
		system("cls");
	}
	void Mod()
	{
		int n, num, k = 1;
		if ((filebin = fopen("Bookshelf.bin", "r+b")) == NULL)
		{
			std::cout << "На вашому присторої відсутня база даних з назвою\"Bookshelf.bin\"!" << std::endl;
			exit(1);
		}
		fseek(filebin, 0, SEEK_SET);
		fread(&n, sizeof(int), 1, filebin);
		std::cout << "+---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------+" << std::endl;
		std::cout << "|№  |Назва               |Автор               |Жанр                     |Рік        |Ціна    |Дата              | СD/DVD |" << std::endl;
		std::cout << "|   |                    |                    |                         |видання    |        |інвентаризації    |        |" << std::endl;
		std::cout << "|---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------|" << std::endl;
		books book = books();
		for (int i = 0; i < n; i++)
		{
			fread(&book, sizeof(books), 1, filebin);
			std::cout << "|" << std::left << std::setw(3) << book.number;
			std::cout << "|" << std::left << std::setw(20) << book.name;
			std::cout << "|" << std::left << std::setw(20) << book.avtor;
			std::cout << "|" << std::left << std::setw(25) << book.genre;
			std::cout << "|" << std::right << std::setw(11) << book.yearr;
			std::cout << "|" << std::right << std::setw(8) << book.price;
			std::cout << "|" << std::setw(2) << book.date[0] << "." << std::setw(2) << book.date[1] << "." << std::left << std::setw(12) << book.date[2];
			std::cout << "|" << std::left << std::setw(8) << book.dvd;
			std::cout << "|" << std::endl;
		}
		std::cout << "+---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------+" << std::endl;
		while (1)
		{
			std::cout << "Введіть номер запису який хочете редагувати:\n";
			std::cin >> num;
			if (num > 0 && num <= n)
				break;
		}

		fseek(filebin, 4 + ((num - 1) * sizeof(books)), SEEK_SET);
		fread(&book, sizeof(books), 1, filebin);
		fseek(filebin, 4 + ((num - 1) * sizeof(books)), SEEK_SET);
		std::cout << "Введiть назву книги:";

		std::cin>>book.name, 20;
		std::cout << "Введiть автора книги:";

		std::cin>>book.avtor, 20;
		std::cout << "Введiть жанр книги:";

		std::cin>>book.genre;
		while (1)
		{
			std::cout << "Введiть рік видання:";
			std::cin >> book.yearr;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
			}
			else
			{
				if (book.yearr > 1800 && book.yearr <= 2020)
					break;
			}
		}
		while (1)
		{
			std::cout << "Введiть ціну(ціна не може бути від'ємною):";
			std::cin >> book.price;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
			}
			else
			{
				if (book.price > 0)
					break;
			}
		}
		std::cout << "Введiть дату інвентаризації відповідно наступних пунктів:" << std::endl;
		while (1)
		{
			std::cout << "Введiть день інвентаризації:";
			std::cin >> book.date[0];
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
			}
			else
			{
				if (book.date[0] > 0 && book.date[0] <= 30)
					break;
			}
		}
		while (1)
		{
			std::cout << "Введiть місяць інвентаризації:";
			std::cin >> book.date[1];
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
			}
			else
			{
				if (book.date[1] > 0 && book.date[1] <= 12)
					break;
			}
		}
		while (1)
		{
			std::cout << "Введiть рік інвентаризації:";
			std::cin >> book.date[2];
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
			}
			else
			{
				if (book.date[2] >= 1900 && book.date[2] <= 2020)
					break;
			}
		}
		while (1)
		{
			std::cout << "Введiть наявність місць(так/ні):";
			std::cin >> book.dvd;
			if (strcmp(book.dvd, "Так") == 0 || strcmp(book.dvd, "так") == 0 || strcmp(book.dvd, "Ні") == 0 || strcmp(book.dvd, "ні") == 0 || strcmp(book.dvd, "yes") == 0 || strcmp(book.dvd, "Yes") == 0 || strcmp(book.dvd, "no") == 0 || strcmp(book.dvd, "No") == 0)
				break;
		}
		fwrite(&book, sizeof(books), 1, filebin);
		std::cout << "Ви успішно змінили дані в базі даних" << std::endl;
		system("pause");
		fclose(filebin);
		system("cls");
	}
	void Remove()
{

	int n, num, k = 1;
	if ((filebin = fopen("Bookshelf.bin", "r+b")) == NULL)
	{
		std::cout << "На вашому присторої відсутня база даних з назвою\"Bookshelf.bin\"!" << std::endl;
		exit(1);
	}
	fseek(filebin, 0, SEEK_SET);
	fread(&n, sizeof(int), 1, filebin);
	books* book = new books[n];
	std::cout << "+---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------+" << std::endl;
	std::cout << "|№  |Назва               |Автор               |Жанр                     |Рік        |Ціна    |Дата              | СD/DVD |" << std::endl;
	std::cout << "|   |                    |                    |                         |видання    |        |інвентаризації    |        |" << std::endl;
	std::cout << "|---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------|" << std::endl;
	for (int i = 0; i < n; i++)
	{
		fread(&book[i], sizeof(books), 1, filebin);
		std::cout << "|" << std::left << std::setw(3) << i+1;
		std::cout << "|" << std::left << std::setw(20) << book[i].name;
		std::cout << "|" << std::left << std::setw(20) << book[i].avtor;
		std::cout << "|" << std::left << std::setw(25) << book[i].genre;
		std::cout << "|" << std::right << std::setw(11) << book[i].yearr;
		std::cout << "|" << std::right << std::setw(8) << book[i].price;
		std::cout << "|" << std::setw(2) << book[i].date[0] << "." << std::setw(2) << book[i].date[1] << "." << std::left  << std::setw(12) << book[i].date[2];
		std::cout << "|" << std::left << std::setw(8) << book[i].dvd;
		std::cout << "|" << std::endl;
	}
	std::cout << "+---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------+" << std::endl;
	while (1)
	{
		std::cout << "Введіть номер запису який хочете видалити:\n";
		std::cin >> num;
		if (num > 0 && num <= n)
			break;
	}
	fclose(filebin);
	filebin = fopen("Bookshelf.bin", "wb");
	fseek(filebin, 4, SEEK_SET);

	for (int i = 0; i < n; i++)
	{
		if ((i + 1) != num)
		{
			fwrite(&book[i], sizeof(books), 1, filebin);
		}
	}
	n -= 1;
	fseek(filebin, 0, SEEK_SET);
	fwrite(&n, sizeof(int), 1, filebin);
	delete[] book;
	fclose(filebin);
	system("cls");
}
	void Drop_to_txt(int x)
	{
		char kat_ch[20] = "";
		int n, kat_int = 0, k = 1, kat_date[3] = { 0 };
		bool much;
		time_t t;
		time(&t);
		int year = localtime(&t)->tm_year;
		if ((filebin = fopen("Bookshelf.bin", "r+b")) == NULL)
		{
			std::cout << "На вашому присторої відсутня база даних з назвою\"Bookshelf.bin\"!" << std::endl;
			exit(1);
		}
		if ((filetxt = fopen("BD_books.txt", "w+")) == NULL)
		{
			std::cout << "На вашому присторої відcутній текстовий файл\"BD_books.txt\"!" << std::endl;
			exit(1);
		}
		fseek(filebin, 0, SEEK_SET);
		fread(&n, sizeof(int), 1, filebin);
		books* book = new books[n];
		for (int i = 0; i < n; i++)
		{
			fread(&book[i], sizeof(books), 1, filebin);
		}

		if (x == 1 || x == 2 || x == 3 || x == 7)
		{
			std::cout << "Введіть значення по якому буде проводитись вибірка" << std::endl;

			std::cin.getline(kat_ch, 20);
		}
		if (x == 4 || x == 5)
		{
			while (1)
			{
				std::cout << "Введіть значення по якому буде проводитись вибірка" << std::endl;
				std::cin >> kat_int;
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
				}
				else
				{
					break;
				}
			}
		}
		if (x == 6)
		{
			std::cout << "Введiть дату відправки відповідно наступних пунктів:";
			while (1)
			{
				std::cout << "Введiть день відправки:";
				std::cin >> kat_date[0];
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
				}
				else
				{
					if (kat_date[0] > 0 && kat_date[0] <= 30)
						break;
				}
			}
			while (1)
			{
				std::cout << "Введiть місяць відправки:";
				std::cin >> kat_date[1];
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
				}
				else
				{
					if (kat_date[1] > 0 && kat_date[1] <= 12)
						break;
				}
			}
			while (1)
			{
				std::cout << "Введiть рік відправки:";
				std::cin >> kat_date[2];
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
				}
				else
				{
					if (kat_date[2] >= 1900 && kat_date[2] <= 2040)
						break;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (((book[i].date[2] == (year + 1900)) && x == 0) || ((strcmp(book[i].name, kat_ch) == 0) && x == 1) || ((strcmp(book[i].avtor, kat_ch) == 0) && x == 2) || ((strcmp(book[i].genre, kat_ch) == 0) && x == 3) || ((book[i].yearr == kat_int) && x == 4) || (book[i].price == kat_int && x == 5) || ((book[i].date[0] == kat_date[0] && book[i].date[1] == kat_date[1] && book[i].date[2] == kat_date[2]) && x == 6) || (strcmp(book[i].dvd, kat_ch) == 0 && x == 7))
			{
				much = true;
				break;
			}
			else
			{
				much = false;
			}
		}
		if (much == true)
		{
			fprintf(filetxt, "Вибірка згідно вибраних вами критеріїв:\n");
			std::cout << "Вибірка згідно вибраних вами критеріїв:\n";
			std::cout << "+---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------+" << std::endl;
			std::cout << "|№  |Назва               |Автор               |Жанр                     |Рік        |Ціна    |Дата              | СD/DVD |" << std::endl;
			std::cout << "|   |                    |                    |                         |видання    |        |інвентаризації    |        |" << std::endl;
			std::cout << "|---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------|" << std::endl;
			fprintf(filetxt, "+---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------+\n");
			fprintf(filetxt, "|№  |Назва               |Автор               |Жанр                     |Рік        |Ціна    |Дата              | СD/DVD |\n");
			fprintf(filetxt, "|   |                    |                    |                         |видання    |        |інвентаризації    |        |\n");
			fprintf(filetxt, "|---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------|\n");
			for (int i = 0; i < n; i++)
			{
				if (((book[i].date[2] == (year + 1900)) && x == 0) || ((strcmp(book[i].name, kat_ch) == 0) && x == 1) || ((strcmp(book[i].avtor, kat_ch) == 0) && x == 2) || ((strcmp(book[i].genre, kat_ch) == 0) && x == 3) || ((book[i].yearr == kat_int) && x == 4) || (book[i].price == kat_int && x == 5) || ((book[i].date[0] == kat_date[0] && book[i].date[1] == kat_date[1] && book[i].date[2] == kat_date[2]) && x == 6) || (strcmp(book[i].dvd, kat_ch) == 0 && x == 7))
				{
					fprintf(filetxt, "|%-3i|%-20s|%-20s|%-25s|%-11i|%-8i|%2i.%2i.%-12i|%-8s|\n", book[i].number, book[i].name, book[i].avtor, book[i].avtor, book[i].yearr, book[i].price, book[i].date[0], book[i].date[1], book[i].date[2], book[i].dvd);
					std::cout << "|" << std::left << std::setw(3) << book[i].number;
					std::cout << "|" << std::left << std::setw(20) << book[i].name;
					std::cout << "|" << std::left << std::setw(20) << book[i].avtor;
					std::cout << "|" << std::left << std::setw(25) << book[i].genre;
					std::cout << "|" << std::right << std::setw(11) << book[i].yearr;
					std::cout << "|" << std::right << std::setw(8) << book[i].price;
					std::cout << "|" << std::setw(2) << book[i].date[0] << "." << std::setw(2) << book[i].date[1] << "." << std::left << std::setw(12) << book[i].date[2];
					std::cout << "|" << std::left << std::setw(8) << book[i].dvd;
					std::cout << "|" << std::endl;
				}
			}
			std::cout << "+---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------+" << std::endl;
			fprintf(filetxt, "+---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------+\n");
		}
		else
			std::cout << "За даним критерієм не знайдено жодного значення!!!" << std::endl;
		delete[] book;
		fclose(filebin);
		fclose(filetxt);
		system("pause");
		system("cls");
	}
	void Drop(int x)
	{
		char kat_ch[20] = "";
		int n, kat_int = 0, k = 1, kat_date[3] = { 0 };
		bool much = false;
		if ((filebin = fopen("Bookshelf.bin", "r+b")) == NULL)
		{
			std::cout << "На вашому присторої відсутня база даних з назвою\"Bookshelf.bin\"!" << std::endl;
			exit(1);
		}
		if ((filetxt = fopen("BD_books.txt", "w+")) == NULL)
		{
			std::cout << "На вашому присторої відcутній текстовий файл\"BD_books.txt\"!" << std::endl;
			exit(1);
		}
		fseek(filebin, 0, SEEK_SET);
		fread(&n, sizeof(int), 1, filebin);
		books* book = new books[n];
		for (int i = 0; i < n; i++)
		{
			fread(&book[i], sizeof(books), 1, filebin);
		}

		if (x != 0)
		{
			if (x == 1 || x == 2 || x == 3 || x == 7)
			{
				std::cout << "Введіть значення по якому буде проводитись вибірка" << std::endl;

				std::cin.getline(kat_ch, 20);
			}
			if (x == 4 || x == 5)
			{
				while (1)
				{
					std::cout << "Введіть значення по якому буде проводитись вибірка" << std::endl;
					std::cin >> kat_int;
					if (std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(32767, '\n');
					}
					else
					{
						break;
					}
				}
			}
			if (x == 6)
			{
				std::cout << "Введiть дату відправки відповідно наступних пунктів:";
				while (1)
				{
					std::cout << "Введiть день відправки:";
					std::cin >> kat_date[0];
					if (std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(32767, '\n');
					}
					else
					{
						if (kat_date[0] > 0 && kat_date[0] <= 30)
							break;
					}
				}
				while (1)
				{
					std::cout << "Введiть місяць відправки:";
					std::cin >> kat_date[1];
					if (std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(32767, '\n');
					}
					else
					{
						if (kat_date[1] > 0 && kat_date[1] <= 12)
							break;
					}
				}
				while (1)
				{
					std::cout << "Введiть рік відправки:";
					std::cin >> kat_date[2];
					if (std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(32767, '\n');
					}
					else
					{
						if (kat_date[2] >= 1900 && kat_date[2] <= 2040)
							break;
					}
				}
			}
			for (int i = 0; i < n; i++)
			{
				if (((strcmp(book[i].name, kat_ch) == 0) && x == 1) || ((strcmp(book[i].avtor, kat_ch) == 0) && x == 2) || ((strcmp(book[i].genre, kat_ch) == 0) && x == 3) || ((book[i].yearr == kat_int) && x == 4) || (book[i].price == kat_int && x == 5) || ((book[i].date[0] == kat_date[0] && book[i].date[1] == kat_date[1] && book[i].date[2] == kat_date[2]) && x == 6) || (strcmp(book[i].dvd, kat_ch) == 0 && x == 7))
				{
					much = true;
					break;
				}
				else
				{
					much = false;
				}
			}
			if (much == true)
			{
				std::cout << "Вибірка згідно вибраних вами критеріїв:\n";
				std::cout << "+---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------+" << std::endl;
				std::cout << "|№  |Назва               |Автор               |Жанр                     |Рік        |Ціна    |Дата              | СD/DVD |" << std::endl;
				std::cout << "|   |                    |                    |                         |видання    |        |інвентаризації    |        |" << std::endl;
				std::cout << "|---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------|" << std::endl;
				for (int i = 0; i < n; i++)
				{
					if (((strcmp(book[i].name, kat_ch) == 0) && x == 1) || ((strcmp(book[i].avtor, kat_ch) == 0) && x == 2) || ((strcmp(book[i].genre, kat_ch) == 0) && x == 3) || ((book[i].yearr == kat_int) && x == 4) || (book[i].price == kat_int && x == 5) || ((book[i].date[0] == kat_date[0] && book[i].date[1] == kat_date[1] && book[i].date[2] == kat_date[2]) && x == 6) || (strcmp(book[i].dvd, kat_ch) == 0 && x == 7))
					{
						std::cout << "|" << std::left << std::setw(3) << book[i].number;
						std::cout << "|" << std::left << std::setw(20) << book[i].name;
						std::cout << "|" << std::left << std::setw(20) << book[i].avtor;
						std::cout << "|" << std::left << std::setw(25) << book[i].genre;
						std::cout << "|" << std::right << std::setw(11) << book[i].yearr;
						std::cout << "|" << std::right << std::setw(8) << book[i].price;
						std::cout << "|" << std::setw(2) << book[i].date[0] << "." << std::setw(2) << book[i].date[1] << "." << std::left << std::setw(12) << book[i].date[2];
						std::cout << "|" << std::left << std::setw(8) << book[i].dvd;
						std::cout << "|" << std::endl;
					}
				}
				std::cout << "+---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------+" << std::endl;
				fprintf(filetxt, "+---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------+\n");
			}
			else
				std::cout << "За даним критерієм не знайдено жодного значення!!!" << std::endl;
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < (strlen(book[i].name)); j++)
				{
					if (book[i].name[j] == 'C' || book[i].name[j] == 'С')
						if (book[i].name[j + 1] == '+' && book[i].name[j + 2] == '+')
						{
							/*	std::cout << "Вибірка згідно вибраних вами критеріїв:\n";
								std::cout << "+---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------+" << std::endl;
								std::cout << "|№  |Назва               |Автор               |Жанр                     |Рік        |Ціна    |Дата              | СD/DVD |" << std::endl;
								std::cout << "|   |                    |                    |                         |видання    |        |інвентаризації    |        |" << std::endl;
								std::cout << "|---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------|" << std::endl; */
							break;
						}
				}
			}
			std::cout << "Вибірка згідно вибраних вами критеріїв:\n";
			std::cout << "+---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------+" << std::endl;
			std::cout << "|№  |Назва               |Автор               |Жанр                     |Рік        |Ціна    |Дата              | СD/DVD |" << std::endl;
			std::cout << "|   |                    |                    |                         |видання    |        |інвентаризації    |        |" << std::endl;
			std::cout << "|---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------|" << std::endl;

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < (strlen(book[i].name)); j++)
				{
					if (book[i].name[j] == 'C' || book[i].name[j] == 'С')
						if (book[i].name[j + 1] == '+' && book[i].name[j + 2] == '+')
						{
							much = true;
							break;
						}
				}
			}
			if (much == true)
			{
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < (strlen(book[i].name)); j++)
					{
						if (book[i].name[j] == 'C' || book[i].name[j] == 'С')
							if (book[i].name[j + 1] == '+' && book[i].name[j + 2] == '+')
							{
								std::cout << "|" << std::left << std::setw(3) << book[i].number;
								std::cout << "|" << std::left << std::setw(20) << book[i].name;
								std::cout << "|" << std::left << std::setw(20) << book[i].avtor;
								std::cout << "|" << std::left << std::setw(25) << book[i].genre;
								std::cout << "|" << std::right << std::setw(11) << book[i].yearr;
								std::cout << "|" << std::right << std::setw(8) << book[i].price;
								std::cout << "|" << std::setw(2) << book[i].date[0] << "." << std::setw(2) << book[i].date[1] << "." << std::left << std::setw(12) << book[i].date[2];
								std::cout << "|" << std::left << std::setw(8) << book[i].dvd;
								std::cout << "|" << std::endl;
							}
					}
				}
				std::cout << "+---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------+" << std::endl;
				fprintf(filetxt, "+---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------+\n");
			}
			else
				std::cout << "За даним критерієм не знайдено жодного значення!!!" << std::endl;
		}
		fclose(filebin);
		fclose(filetxt);
		system("pause");
		system("cls");
		delete[] book;
	}
	void Remove_to_txt(int x)
	{
		char kat_ch[20] = "";
		int n, kat_int = 0, k = 1, kil = 0, kat_date[3] = { 0 };
		if ((filebin = fopen("Bookshelf.bin", "r+b")) == NULL)
		{
			std::cout << "На вашому присторої відсутня база даних з назвою\"Bookshelf.bin\"!" << std::endl << "Для її стоврення перейдіть в пункт головного меню\"1\"" << std::endl;
			exit(1);
		}
		if ((filetxt = fopen("BD_books.txt", "w+")) == NULL)
		{
			std::cout << "На вашому присторої відcутній текстовий файл\"BD_books.txt\"!" << std::endl << "Перед використанням даної функції, створіть його будь ласка!\n" << std::endl;
			exit(1);
		}
		fseek(filebin, 0, SEEK_SET);
		fread(&n, sizeof(int), 1, filebin);
		books* book = new books[n];
		for (int i = 0; i < n; i++)
		{
			fread(&book[i], sizeof(books), 1, filebin);
		}

		if (x == 1 || x == 2 || x == 6)
		{
			std::cout << "Введіть значення по якому буде проводитись вибірка" << std::endl;

			std::cin.getline(kat_ch, 20);
		}
		if (x == 5)
		{
			while (1)
			{
				std::cout << "Введіть значення по якому буде проводитись вибірка" << std::endl;
				std::cin >> kat_int;
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
				}
				else
				{
					break;
				}
			}
		}
		if (x == 3)
		{
			std::cout << "Введiть дату відправки відповідно наступних пунктів:";
			while (1)
			{
				std::cout << "Введiть день відправки:";
				std::cin >> kat_date[0];
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
				}
				else
				{
					if (kat_date[0] > 0 && kat_date[0] <= 30)
						break;
				}
			}
			while (1)
			{
				std::cout << "Введiть місяць відправки:";
				std::cin >> kat_date[1];
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
				}
				else
				{
					if (kat_date[1] > 0 && kat_date[1] <= 12)
						break;
				}
			}
			while (1)
			{
				std::cout << "Введiть рік відправки:";
				std::cin >> kat_date[2];
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
				}
				else
				{
					if (kat_date[2] >= 1900 && kat_date[2] <= 2040)
						break;
				}
			}
		}
		if (x == 4)
		{
			while (1)
			{
				std::cout << "Введiть годину відправки:";
				std::cin >> kat_date[0];
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
				}
				else
				{
					if (kat_date[0] <= 23 && kat_date[0] >= 0)
						break;
				}
			}
			while (1)
			{
				std::cout << "Введiть хвилину відправки:";
				std::cin >> kat_date[1];
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
				}
				else
				{
					if (kat_date[1] > 0 && kat_date[1] < 60)
						break;
				}
			}
		}
		fseek(filebin, 4, SEEK_SET);
		for (int i = 0; i < n; i++)
		{
			if (((book[i].yearr < 1950) && x == 0) || ((strcmp(book[i].name, kat_ch) == 0) && x == 1) || ((strcmp(book[i].avtor, kat_ch) == 0) && x == 2) || ((strcmp(book[i].genre, kat_ch) == 0) && x == 3) || ((book[i].yearr == kat_int) && x == 4) || (book[i].price == kat_int && x == 5) || ((book[i].date[0] == kat_date[0] && book[i].date[1] == kat_date[1] && book[i].date[2] == kat_date[2]) && x == 6) || (strcmp(book[i].dvd, kat_ch) == 0 && x == 7))
			{
				kil++;
			}
		}
		if (kil != 0)
		{
			fclose(filebin);
			filebin = fopen("Bookshelf.bin", "wb");
			fseek(filebin, 4, SEEK_SET);
			fprintf(filetxt, "База даних після видалення вибраних вами даних:\n");
			std::cout << "База даних після видалення вибраних вами даних:\n";
			std::cout << "+---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------+" << std::endl;
			std::cout << "|№  |Назва               |Автор               |Жанр                     |Рік        |Ціна    |Дата              | СD/DVD |" << std::endl;
			std::cout << "|   |                    |                    |                         |видання    |        |інвентаризації    |        |" << std::endl;
			std::cout << "|---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------|" << std::endl;
			fprintf(filetxt, "+---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------+\n");
			fprintf(filetxt, "|№  |Назва               |Автор               |Жанр                     |Рік        |Ціна    |Дата              | СD/DVD |\n");
			fprintf(filetxt, "|   |                    |                    |                         |видання    |        |інвентаризації    |        |\n");
			fprintf(filetxt, "|---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------|\n");
			for (int i = 0; i < n; i++)
			{
				book[i].number = i + 1;
				if (((book[i].yearr < 1950) && x == 0) || ((strcmp(book[i].name, kat_ch) == 0) && x == 1) || ((strcmp(book[i].avtor, kat_ch) == 0) && x == 2) || ((strcmp(book[i].genre, kat_ch) == 0) && x == 3) || ((book[i].yearr == kat_int) && x == 4) || (book[i].price == kat_int && x == 5) || ((book[i].date[0] == kat_date[0] && book[i].date[1] == kat_date[1] && book[i].date[2] == kat_date[2]) && x == 6) || (strcmp(book[i].dvd, kat_ch) == 0 && x == 7))
				{
					continue;
				}
				else
				{
					fprintf(filetxt, "|%-3i|%-20s|%-20s|%-25s|%-11i|%-8i|%2i.%2i.%-12i|%-8s|\n", book[i].number, book[i].name, book[i].avtor, book[i].avtor, book[i].yearr, book[i].price, book[i].date[0], book[i].date[1], book[i].date[2], book[i].dvd);
					book[i].number = k;
					std::cout << "|" << std::left << std::setw(3) << book[i].number;
					std::cout << "|" << std::left << std::setw(20) << book[i].name;
					std::cout << "|" << std::left << std::setw(20) << book[i].avtor;
					std::cout << "|" << std::left << std::setw(25) << book[i].genre;
					std::cout << "|" << std::right << std::setw(11) << book[i].yearr;
					std::cout << "|" << std::right << std::setw(8) << book[i].price;
					std::cout << "|" << std::setw(2) << book[i].date[0] << "." << std::setw(2) << book[i].date[1] << "." << std::left << std::setw(12) << book[i].date[2];
					std::cout << "|" << std::left << std::setw(8) << book[i].dvd;
					std::cout << "|" << std::endl;
					fwrite(&book[i], sizeof(books), 1, filebin);
				}
				std::cout << "+---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------+" << std::endl;
				fprintf(filetxt, "+---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------+\n");
			}
			n = n - kil;
			fseek(filebin, 0, SEEK_SET);
			fwrite(&n, sizeof(int), 1, filebin);
		}
		else
			std::cout << "За даним критерієм не знайдено жодного значення для видалення!!!" << std::endl;
		fclose(filebin);
		fclose(filetxt);
		system("pause");
		system("cls");
		delete[] book;
	}
	void Sort_to_txt(int x)
	{
		int n, mode, k = 1, kil = 0;
		if ((filebin = fopen("Bookshelf.bin", "r+b")) == NULL)
		{
			std::cout << "На вашому присторої відсутня база даних з назвою\"Bookshelf.bin\"!" << std::endl << "Для її стоврення перейдіть в пункт головного меню\"1\"" << std::endl;
			exit(1);
		}
		if ((filetxt = fopen("BD_books.txt", "w+")) == NULL)
		{
			std::cout << "На вашому присторої відcутній текстовий файл\"BD_books.txt\"!" << std::endl << "Перед використанням даної функції, створіть його будь ласка!\n" << std::endl;
			exit(1);
		}
		fseek(filebin, 0, SEEK_SET);
		fread(&n, sizeof(int), 1, filebin);
		books* book = new books[n];
		for (int i = 0; i < n; i++)
		{
			fread(&book[i], sizeof(books), 1, filebin);
		}
		if (x != 0)
		{
			while (1)
			{
				std::cout << "Ви бажаєте відсортувати за зростанням(1) чи за спаданням(0):" << std::endl;
				std::cin >> mode;
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
				}
				else
				{
					if (mode == 1 || mode == 0)
						break;
				}
			}
		}
		if (x == 0)
		{
			for (int i = 0; i < n - 1; i++)
				for (int j = 0; j < n - i - 1; j++)
					if (book[j + 1].yearr > book[j].yearr)
						std::swap(book[j + 1], book[j]);
		}
		else if (x == 5 || x == 4)
		{
			for (int i = 0; i < n - 1; i++)
				for (int j = 0; j < n - i - 1; j++)
					if (((book[j + 1].yearr > book[j].yearr) && x == 5 && mode == 0) || ((book[j + 1].yearr < book[j].yearr) && x == 5 && mode == 1) || ((book[j + 1].price > book[j].price) && x == 4 && mode == 0) || ((book[j + 1].price < book[j].price) && x == 4 && mode == 1))
						std::swap(book[j + 1], book[j]);
		}
		else if (x == 6)
		{
			for (int i = 0; i < n - 1; i++)
				for (int j = 0; j < n - i - 1; j++)
					if (((book[j].date[0] + (book[j].date[1] * 30) + (book[j].date[2] * 365)) > (book[j + 1].date[0] + (book[j + 1].date[1] * 30) + (book[j + 1].date[2] * 365)) && x == 6 && mode == 1) || ((book[j].date[0] + (book[j].date[1] * 30) + (book[j].date[2] * 365)) < (book[j + 1].date[0] + (book[j + 1].date[1] * 30) + (book[j + 1].date[2] * 365)) && x == 6 && mode == 0))
						std::swap(book[j + 1], book[j]);
		}
		else
		{
			for (int i = 0; i <= n; i++)
				for (int j = n - 1; j > i; j--)
					if ((strcmp(book[j].name, book[j - 1].name) < 0 && ((x == 1 && mode == 1))) || (strcmp(book[j].name, book[j - 1].name) > 0 && x == 1 && mode == 0) || (strcmp(book[j].avtor, book[j - 1].avtor) < 0 && x == 2 && mode == 1) || (strcmp(book[j].avtor, book[j - 1].avtor) > 0 && x == 2 && mode == 0) || (strcmp(book[j].genre, book[j - 1].genre) < 0 && x == 3 && mode == 1) || (strcmp(book[j].genre, book[j - 1].genre) > 0 && x == 3 && mode == 0) || (strcmp(book[j].dvd, book[j - 1].dvd) < 0 && x == 7 && mode == 1) || (strcmp(book[j].dvd, book[j - 1].dvd) > 0 && x == 7 && mode == 0))
						std::swap(book[j - 1], book[j]);
		}
		fprintf(filetxt, "База даних після сортування:\n");
		std::cout << "База даних після сортування:\n";
		fclose(filebin);
		filebin = fopen("Bookshelf.bin", "wb");
		fseek(filebin, 4, SEEK_SET);
		std::cout << "+---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------+" << std::endl;
		std::cout << "|№  |Назва               |Автор               |Жанр                     |Рік        |Ціна    |Дата              | СD/DVD |" << std::endl;
		std::cout << "|   |                    |                    |                         |видання    |        |інвентаризації    |        |" << std::endl;
		std::cout << "|---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------|" << std::endl;
		fprintf(filetxt, "+---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------+\n");
		fprintf(filetxt, "|№  |Назва               |Автор               |Жанр                     |Рік        |Ціна    |Дата              | СD/DVD |\n");
		fprintf(filetxt, "|   |                    |                    |                         |видання    |        |інвентаризації    |        |\n");
		fprintf(filetxt, "|---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------|\n");
		for (int i = 0; i < n; i++)
		{
			fprintf(filetxt, "|%-3i|%-20s|%-20s|%-25s|%-11i|%-8i|%2i.%2i.%-12i|%-8s|\n", book[i].number, book[i].name, book[i].avtor, book[i].avtor, book[i].yearr, book[i].price, book[i].date[0], book[i].date[1], book[i].date[2], book[i].dvd);

			book[i].number = k; k++;
			std::cout << "|" << std::left << std::setw(3) << book[i].number;
			std::cout << "|" << std::left << std::setw(20) << book[i].name;
			std::cout << "|" << std::left << std::setw(20) << book[i].avtor;
			std::cout << "|" << std::left << std::setw(25) << book[i].genre;
			std::cout << "|" << std::right << std::setw(11) << book[i].yearr;
			std::cout << "|" << std::right << std::setw(8) << book[i].price;
			std::cout << "|" << std::setw(2) << book[i].date[0] << "." << std::setw(2) << book[i].date[1] << "." << std::left << std::setw(12) << book[i].date[2];
			std::cout << "|" << std::left << std::setw(8) << book[i].dvd;
			std::cout << "|" << std::endl;
			fwrite(&book[i], sizeof(books), 1, filebin);
		}
		std::cout << "+---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------+" << std::endl;
		fprintf(filetxt, "+---+--------------------+--------------------+-------------------------+-----------+--------+------------------+--------+\n");
		fseek(filebin, 0, SEEK_SET);
		fwrite(&n, sizeof(int), 1, filebin);
		fclose(filebin);
		fclose(filetxt);
		system("pause");
		system("cls");
		delete[] book;
	}

};
