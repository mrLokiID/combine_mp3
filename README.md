# combine_mp3
Приложение combine_mp3 предназначено для компилирования из нескольких mp3 файлов в один.
Это консольное приложение, написанное на С++ в visual studio 2019.
Порядок работы с приложением.
Приложение может работать с двумя ключами 
1)	–d для работы с директорией.
Пример   combine_mp3.exe –d указываем_директорию указываем_располжение_конечного_файла
combine_mp3.exe –d d:\test\ d:\123.mp3
Обратите внимание на то что при работе с директориями в рабочей папке программы создается файл list_mp3.txt в нем содержится перечень всех файлов, который находились в указанной директории. Вы можете удалить, поменять местами строки, после нажатия на клавишу y, компиляция выполнится в последовательности сверху в низ. 

2)	–f для работы с несколькими файлами
Пример combine_mp3.exe –f путь_к_фалйу_1 путь_к_файлу_2 путь_к_файлу_n конечный_файл
combine_mp3.exe –f d:\test\1.mp3 e:\test\2.mp3 f:\test\3.mp3 c:\123.mp3

