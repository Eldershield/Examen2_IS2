#include "gestor_de_tareas.h"

int main() {
    GestorDeTareas gestor;
    int opcion;

    do {
        std::cout << "1. Crear tarea\n"
                  << "2. Listar tareas\n"
                  << "3. Actualizar tarea\n"
                  << "4. Eliminar tarea\n"
                  << "5. Salir\n"
                  << "Seleccione una opción: ";
        std::cin >> opcion;

        try {
            switch (opcion) {
                case 1: {
                    std::string titulo, descripcion, fecha_vencimiento, estado;
                    std::cout << "Título: ";
                    std::cin.ignore();
                    std::getline(std::cin, titulo);
                    std::cout << "Descripción: ";
                    std::getline(std::cin, descripcion);
                    std::cout << "Fecha de vencimiento (YYYY-MM-DD): ";
                    std::getline(std::cin, fecha_vencimiento);
                    std::cout << "Estado (Pendiente/En progreso/Completada): ";
                    std::getline(std::cin, estado);
                    gestor.crearTarea(titulo, descripcion, fecha_vencimiento, estado);
                    break;
                }
                case 2:
                    std::cout << gestor.listarTareas();
                    break;
                case 3: {
                    int id;
                    std::string titulo, descripcion, fecha_vencimiento, estado;
                    std::cout << "ID de la tarea a actualizar: ";
                    std::cin >> id;
                    std::cin.ignore();
                    std::cout << "Nuevo título (dejar vacío para no cambiar): ";
                    std::getline(std::cin, titulo);
                    std::cout << "Nueva descripción (dejar vacío para no cambiar): ";
                    std::getline(std::cin, descripcion);
                    std::cout << "Nueva fecha de vencimiento (YYYY-MM-DD, dejar vacío para no cambiar): ";
                    std::getline(std::cin, fecha_vencimiento);
                    std::cout << "Nuevo estado (dejar vacío para no cambiar): ";
                    std::getline(std::cin, estado);
                    gestor.actualizarTarea(id, titulo, descripcion, fecha_vencimiento, estado);
                    break;
                }
                case 4: {
                    int id;
                    std::cout << "ID de la tarea a eliminar: ";
                    std::cin >> id;
                    gestor.eliminarTarea(id);
                    break;
                }
                case 5:
                    std::cout << "Saliendo del programa...\n";
                    break;
                default:
                    std::cout << "Opción no válida.\n";
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    } while (opcion != 5);

    return 0;
}
