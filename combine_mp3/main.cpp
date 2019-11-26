#define  _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING 
#include <iostream>
#include <fstream>
#include <string>
#include <experimental/filesystem> 

//Метод создающий списко mp3 файлов из задонной папки 
void file_list(const std::string folder_name) //В качестве параметра надо указать путь к каталогу с файлами
{
	std::ofstream out;
	out.open("list_mp3.txt");

	for (auto& p : std::experimental::filesystem::v1::directory_iterator(folder_name))
	{
		out << p << std::endl;
	}
	out.close();
}

void combine(char input[], char output[]) // В качестве параметров указваем назане входного файла и название 
{
	std::fstream input_file; // Созадем объект класса для чтения из файла 
	std::ofstream output_file; // CСоздаем объект класса для записи в файл
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
		if (std::strcmp(argv[1], "-d") == 0) //Работа с директорией
		{
			std::cout << "Работа с директорией" << std::endl;
			std::cout << argv[2] << std::endl;
		}
		if (std::strcmp(argv[1], "-f") == 0) // Работа с двумя файлами
		{
			std::cout << "Работа с файлами" << std::endl;
			for (auto i = 2; i <= argc-2; i++)
			{
				try
				{
					std::ofstream out(argv[argc - 1], std::ios::out | std::ios::app | std::ios::binary);
					std::fstream in(argv[i], std::ios::in | std::ios::binary);
					std::cout << "Компилироване файла " << argv[i] << std::endl;
					out << in.rdbuf();
					in.close();
					out.close();
				}
				catch (const std::exception & error)
				{
					std::cout << error.what() << std::endl;
					std::cout << "Ощибка при компилции файлов " << std::endl;
				}
			}
			std::cout << "Конец компиляции!" <<std::endl;
		}
	}
	else
	{
		std::cout << "Вы не указали ключь для работы с программой" << std::endl;
		std::cout << "Укажите ключь -d для работы с каталогом" << std::endl;
		std::cout << "Укажите ключь -f для работы с двумя и более файлами" << std::endl;
	}

	return 0;
}