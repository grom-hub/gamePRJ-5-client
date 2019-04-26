

cmake_minimum_required(VERSION 3.0)

project(PotaynoyLazPRJ VERSION 0.2 LANGUAGES C CXX)

# Скомпилировать исполняемый файл из исходников
add_executable(PotaynoyLazClient main.cpp connector.cpp ncScreen.cpp playerController.cpp)

# Скомпоновать исполняемый файл с библиотеками
target_link_libraries(PotaynoyLazClient ncurses)

# Установить свойству 'CXX_STANDARD' значение "11",
# а свойству 'CXX_STANDARD_REQUIRED' значение "ON":
set_target_properties(PotaynoyLazClient PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED ON)








