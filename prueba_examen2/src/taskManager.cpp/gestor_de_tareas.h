#ifndef GESTOR_DE_TAREAS_H
#define GESTOR_DE_TAREAS_H

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <sstream> // Para generar cadenas en lugar de imprimir directamente

// Clase Tarea
class Tarea {
private:
    int id;
    std::string titulo;
    std::string descripcion;
    std::string fecha_vencimiento;
    std::string estado;

public:
    Tarea(int id, const std::string& titulo, const std::string& descripcion,
          const std::string& fecha_vencimiento, const std::string& estado);

    int getId() const;
    const std::string& getTitulo() const;
    const std::string& getDescripcion() const;
    const std::string& getFechaVencimiento() const;
    const std::string& getEstado() const;

    void setTitulo(const std::string& nuevo_titulo);
    void setDescripcion(const std::string& nueva_descripcion);
    void setFechaVencimiento(const std::string& nueva_fecha);
    void setEstado(const std::string& nuevo_estado);

    std::string imprimir() const;
};

// Clase GestorDeTareas
class GestorDeTareas {
private:
    std::vector<Tarea> tareas;
    int siguiente_id;

public:
    GestorDeTareas();

    void crearTarea(const std::string& titulo, const std::string& descripcion,
                    const std::string& fecha_vencimiento, const std::string& estado);

    std::string listarTareas() const;

    void actualizarTarea(int id, const std::string& titulo, const std::string& descripcion,
                         const std::string& fecha_vencimiento, const std::string& estado);

    void eliminarTarea(int id);
};

#endif // GESTOR_DE_TAREAS_H
