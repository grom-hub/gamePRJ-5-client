

cmake_minimum_required(VERSION 3.0)


# Задать характеристики проекта "MyProject":
project(PotaynoyLazPRJ VERSION 0.2 LANGUAGES C CXX)


# Скомпилировать исполняемый файл "MyExecutable" из
# исходников "ObjectHandler.c", "TimeManager.c" и "MessageGenerator.c":
add_executable(PotaynoyLazClient main.cpp connector.cpp ncScreen.cpp playerController.cpp)


# Скомпоновать исполняемый файл "MyExecutable" с
# библиотеками "JsonParser", "SocketFactory" и "BrowserInvoker":
target_link_libraries(PotaynoyLazClient ncurses)


# Установить свойству 'C_STANDARD' значение "11",
# а свойству 'C_STANDARD_REQUIRED' значение "ON":
set_target_properties(PotaynoyLazClient PROPERTIES C_STANDARD 11 C_STANDARD_REQUIRED ON)








