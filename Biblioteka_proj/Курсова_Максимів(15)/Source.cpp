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
			std::cout << "������� �������� ��� �� ������ �������� � ����� �����" << std::endl;
			std::cout << "1)-�������� ���� �����\n2)-�������� ������ � ���� �����(����� ���������� � ��� ������� ����)\n3)-������� �� ��� � ���� �����\n4)-������ ������ � ��� �����\n5)-³������ ��� � ���� ����� (�� �������)\n6)-�������� ��� � ���� �����\n7)-���������� �����(���� � ��������� ����)\n0)-����� � ��������" << std::endl;
			std::cin >> x;
			system("cls");
			switch (x)
			{
			case 1:
				std::cout << "���� ������� ����������� ���� �����" << std::endl << "�� ����� ������ ���������� (1) �� ������� �� ���������(0)?" << std::endl;
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
					std::cout << "���������� ����������� ������ ���� ���� �����(1) �� ����� �� ��������� ����(0)?" << std::endl;
					std::cin >> x;
					if (x == 0)
						break;
				}
				break;
			case (5):
				while (1)
				{
					std::cout << "�� ������ �������� ������ �� ������ ��������� ������� ����(0)? " << std::endl;
					std::cin >> x;
					if (x == 1)
					{
						k = 0;
					}
					else
					{
						while (1)
						{
							std::cout << "������� ���� �� ���� ������ �������� ������:";
							std::cout << std::endl << "1)-�����\n2)-�����\n3)-����\n4)-г� �������\n5)-ֳ��\n6)-���� ��������������\n7)-�������� CD/DVD(���/�)" << std::endl;
							std::cin >> k;
							if (k >= 1 && k <= 7)
								break;
							else
								std::cout << "�� ������� �� �������� ������!!!" << std::endl;
						}
					}
					system("cls");
					b.Drop_to_txt(k);
					std::cout << "���������� ������ ������ ���� ���� �����(1) �� ����� �� ��������� ����(0) ? " << std::endl;
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
					std::cout << "���������� ��������� ������ ���� ���� �����(1) �� ����� �� ��������� ����(0)?" << std::endl;
					std::cin >> x;
					if (x == 0)
						break;
				}
				break;
			case (7):
				while (1)
				{
					std::cout << "�� ������ �������� ��������� �� ����� ������� (1) �� ������ ��������� ������� ���� (0)? " << std::endl;
					std::cin >> x;
					if (x == 1)
					{
						k = 0;
					}
					else
					{
						while (1)
						{
							std::cout << "������� ���� �� ���� ������ �������� ���������:";
							std::cout << std::endl << "1)-�����\n2)-�����\n3)-����\n4)-г� �������\n5)-ֳ��\n6)-���� ��������������\n7)-�������� CD/DVD(���/�)" << std::endl;
							std::cin >> k;
							if (k >= 1 && k <= 7)
								break;
							else
								std::cout << "�� ������� �� �������� ������!!!" << std::endl;
						}
					}
					system("cls");
					b.Sort_to_txt(k);
					system("cls");
					break;
				}
				break;
			case (0):
				std::cout << "������ �� ������������ ����� ���������!\n������������ �����!!!" << std::endl;

				return 0;
			default:
				std::cout << "�� ������� �� �������� ������!!!" << std::endl;
			}
			if (x <= 8 && x >= 1)
				break;
		}
		std::cout << "������ ���������� ������ � ����� �����(1) �� ��������� ������(0)?" << std::endl;
		std::cin >> x;
		system("cls");
		if (x != 1)
			break;
	}
	std::cout << "������ �� ������������ ����� ���������!\n������������ �����!!!" << std::endl;
	system("pause");
	return 0;
}