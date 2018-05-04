#include <afxres.h>
#include <cstdio>

/**
 * Написать программу вывода списка файлов из указанного каталога с расширением bmp
 * с указанием их общего колличества
 **/


int main()
{
int COUNT = 0;
/**
 * WIN32_FIND_DATA -  структура, которая хранит информацию о файлах, найденных
 * с помощью FindFirstFile-функции
 * **/
WIN32_FIND_DATA f;
    /**
     * FindFirstFile - функция для поиска файлов в директории
     * **/
    HANDLE h = FindFirstFile("C:\\Sadov\\*.bmp", &f); //возвращает все файлы в указанной директории с расширением .bmp

    /**
     * Обработка ошибки(в случае, если указанной директории не существует)
     * **/
    if(h != INVALID_HANDLE_VALUE) //Если функция FindFirstFile не вернула в h флаг ошибки
    {
        do
        {
            puts(f.cFileName);
            COUNT++;
        } while(FindNextFile(h, &f));
    printf("Total: %i", COUNT);

    }

    else
    {
        fprintf(stderr, "Error opening directory\n"); //В терминале ошибка будет подсвечена красным
    }

return 0;
}
