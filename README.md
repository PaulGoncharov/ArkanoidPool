# ArkanoidPool

Demo - https://www.youtube.com/watch?v=I1HOrgrt4xQ&feature=youtu.be

Для сборки  игры необходимы библиотеки glaux(загрузка текстур) и glut. Поскольку glaux библиотека старая (что является причиной к тому, чтобы её заменить), скачать её можно, например, здесь http://mycodelog.com/2010/05/15/gllibs/ 

Включение библиотек в Visual Studio:
1) Добавить заголовочные файлы к библиотекам Project->Properties->Configuration Properties->C/C++->Additional Include Directories
2) Добавить пути к библиотекам Project->Properties->Configuration Properties->Linker->General->Additional Library Directories
3) Добавить зависимости Glaux.lib, glut32.lib Project->Properties->Configuration Properties->Linker->General->Input->Additional Dependencies

Также необходимо добавить заголовочные файлы самой игры в проект  Project->Properties->Configuration Properties->C/C++->Additional Include Directories::$(ProjectDir)\include

Игра содержит несколько уровней, которые десериализуются из json формата. Добавление нового уровня требует создание его описания в формате json и добавление строкового идентификатора в assets_description. Переход к следующему уровню осуществляется по кнопке 'c'(cheat). Управление описано на первой странице игры.
