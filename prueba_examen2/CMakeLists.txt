cmake_minimum_required(VERSION 3.10)
project(TaskManager)

# Añadir soporte para Google Test
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Archivos fuente
set(SOURCE_FILES src/gestor_de_tareas.cpp)

# Ejecutable principal
add_executable(task_manager src/task_manager_app.cpp ${SOURCE_FILES})

# Ejecutable de pruebas
add_executable(gestor_de_tareas_test tests/gestor_de_tareas_test.cpp ${SOURCE_FILES})
target_link_libraries(gestor_de_tareas_test ${GTEST_LIBRARIES} pthread)

# Instrucción para ejecutar las pruebas
add_test(NAME GestorDeTareasTest COMMAND gestor_de_tareas_test)
