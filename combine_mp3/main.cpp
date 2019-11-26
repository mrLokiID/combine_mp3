#define  _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING 
#include <iostream>
#include <fstream>
#include <string>
#include <experimental/filesystem> 

//����� ��������� ������ mp3 ������ �� �������� ����� 
void file_list(const std::string folder_name) //� �������� ��������� ���� ������� ���� � �������� � �������
{
	std::ofstream out;
	out.open("list_mp3.txt");

	for (auto& p : std::experimental::filesystem::v1::directory_iterator(folder_name))
	{
		out << p << std::endl;
	}
	out.close();
}

void combine(char input[], char output[]) // � �������� ���������� �������� ������ �������� ����� � �������� 
{
	std::fstream input_file; // ������� ������ ������ ��� ������ �� ����� 
	std::ofstream output_file; // C������� ������ ������ ��� ������ � ����
	input_file.exceptions(std::fstream::badbit | std::fstream::failbit);
	output_file.exceptions(std::ofstream::badbit | std::ofstream::failbit);
	try
	{
		output_file.open(output, std::ios::out | std::ios::app | std::ios::binary);
		input_file.open(input, std::ios::in | std::ios::binary);
	}
	catch (const std::exception & error)
	{
		std::cout << error.what() << std::endl;
	}
	output_file << input_file.rdbuf();
	input_file.close();
	output_file.close();
}



int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	if (argc > 1)
	{
		if (std::strcmp(argv[1], "-d") == 0) //������ � �����������
		{
			std::cout << "������ � �����������" << std::endl;
			std::cout << argv[2] << std::endl;
		}
		if (std::strcmp(argv[1], "-f") == 0) // ������ � ����� �������
		{
			std::cout << "������ � �������" << std::endl;
			for (auto i = 2; i <= argc-2; i++)
			{
				try
				{
					std::ofstream out(argv[argc - 1], std::ios::out | std::ios::app | std::ios::binary);
					std::fstream in(argv[i], std::ios::in | std::ios::binary);
					std::cout << "������������� ����� " << argv[i] << std::endl;
					out << in.rdbuf();
					in.close();
					out.close();
				}
				catch (const std::exception & error)
				{
					std::cout << error.what() << std::endl;
					std::cout << "������ ��� ��������� ������ " << std::endl;
				}
			}
			std::cout << "����� ����������!" <<std::endl;
		}
	}
	else
	{
		std::cout << "�� �� ������� ����� ��� ������ � ����������" << std::endl;
		std::cout << "������� ����� -d ��� ������ � ���������" << std::endl;
		std::cout << "������� ����� -f ��� ������ � ����� � ����� �������" << std::endl;
	}

	return 0;
}