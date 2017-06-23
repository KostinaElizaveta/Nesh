cmake_minimum_required(VERSION 2.8)
project(Nesh)
set(SOURCE_EXE src/main.cpp)		# Установка переменной со списком исходников для исполняемого файла
set(SOURCE_LIB src/matrix.cpp)			# То же самое, но для библиотеки
add_library(matrix STATIC ${SOURCE_LIB})	# Создание статической библиотеки
add_executable(main ${SOURCE_EXE})	# Создает исполняемый файл с именем main
target_link_libraries(main matrix)
