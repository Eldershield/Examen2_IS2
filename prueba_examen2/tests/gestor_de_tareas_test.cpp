#include "gestor_de_tareas.h"
#include <gtest/gtest.h>

TEST(GestorDeTareasTest, CrearTarea) {
    GestorDeTareas gestor;
    gestor.crearTarea("Estudiar", "Estudiar para el examen", "2024-12-15", "Pendiente");

    // Validar que la tarea se creó correctamente
    std::stringstream salida;
    gestor.listarTareas(); // Deberías ajustar listarTareas para devolver un string en lugar de imprimir
    EXPECT_TRUE(salida.str().find("Estudiar") != std::string::npos);
}

TEST(GestorDeTareasTest, ActualizarTarea) {
    GestorDeTareas gestor;
    gestor.crearTarea("Estudiar", "Estudiar para el examen", "2024-12-15", "Pendiente");

    gestor.actualizarTarea(1, "Repasar", "", "", "En progreso");
    EXPECT_EQ(gestor.getTarea(1).getTitulo(), "Repasar");
    EXPECT_EQ(gestor.getTarea(1).getEstado(), "En progreso");
}

TEST(GestorDeTareasTest, EliminarTarea) {
    GestorDeTareas gestor;
    gestor.crearTarea("Estudiar", "Estudiar para el examen", "2024-12-15", "Pendiente");

    gestor.eliminarTarea(1);
    EXPECT_THROW(gestor.eliminarTarea(1), std::runtime_error);
}

TEST(GestorDeTareasTest, ManejoDeErrores) {
    GestorDeTareas gestor;
    EXPECT_THROW(gestor.crearTarea("", "", "", ""), std::invalid_argument);
}
