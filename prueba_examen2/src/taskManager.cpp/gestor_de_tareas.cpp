#include "gestor_de_tareas.h"
#include <algorithm> // Para buscar tareas

// Implementación de Tarea
Tarea::Tarea(int id, const std::string& titulo, const std::string& descripcion,
             const std::string& fecha_vencimiento, const std::string& estado)
    : id(id), titulo(titulo), descripcion(descripcion),
      fecha_vencimiento(fecha_vencimiento), estado(estado) {}

int Tarea::getId() const { return id; }
const std::string& Tarea::getTitulo() const { return titulo; }
const std::string& Tarea::getDescripcion() const { return descripcion; }
const std::string& Tarea::getFechaVencimiento() const { return fecha_vencimiento; }
const std::string& Tarea::getEstado() const { return estado; }

void Tarea::setTitulo(const std::string& nuevo_titulo) { titulo = nuevo_titulo; }
void Tarea::setDescripcion(const std::string& nueva_descripcion) { descripcion = nueva_descripcion; }
void Tarea::setFechaVencimiento(const std::string& nueva_fecha) { fecha_vencimiento = nueva_fecha; }
void Tarea::setEstado(const std::string& nuevo_estado) { estado = nuevo_estado; }

std::string Tarea::imprimir() const {
    std::stringstream buffer;
    buffer << "ID: " << id << "\n"
           << "Título: " << titulo << "\n"
           << "Descripción: " << (descripcion.empty() ? "N/A" : descripcion) << "\n"
           << "Fecha de vencimiento: " << fecha_vencimiento << "\n"
           << "Estado: " << estado << "\n";
    return buffer.str();
}

// Implementación de GestorDeTareas
GestorDeTareas::GestorDeTareas() : siguiente_id(1) {}

void GestorDeTareas::crearTarea(const std::string& titulo, const std::string& descripcion,
                                const std::string& fecha_vencimiento, const std::string& estado) {
    if (titulo.empty()) {
        throw std::invalid_argument("El título de la tarea es obligatorio.");
    }
    Tarea nueva_tarea(siguiente_id++, titulo, descripcion, fecha_vencimiento, estado);
    tareas.push_back(nueva_tarea);
}

std::string GestorDeTareas::listarTareas() const {
    std::stringstream buffer;
    if (tareas.empty()) {
        buffer << "No hay tareas disponibles.\n";
    } else {
        for (const auto& tarea : tareas) {
            buffer << tarea.imprimir() << "--------------------------\n";
        }
    }
    return buffer.str();
}

void GestorDeTareas::actualizarTarea(int id, const std::string& titulo, const std::string& descripcion,
                                     const std::string& fecha_vencimiento, const std::string& estado) {
    auto it = std::find_if(tareas.begin(), tareas.end(), [id](const Tarea& tarea) {
        return tarea.getId() == id;
    });
    if (it == tareas.end()) {
        throw std::runtime_error("No se encontró la tarea con el ID especificado.");
    }
    if (!titulo.empty()) it->setTitulo(titulo);
    if (!descripcion.empty()) it->setDescripcion(descripcion);
    if (!fecha_vencimiento.empty()) it->setFechaVencimiento(fecha_vencimiento);
    if (!estado.empty()) it->setEstado(estado);
}

void GestorDeTareas::eliminarTarea(int id) {
    auto it = std::remove_if(tareas.begin(), tareas.end(), [id](const Tarea& tarea) {
        return tarea.getId() == id;
    });
    if (it == tareas.end()) {
        throw std::runtime_error("No se encontró la tarea con el ID especificado.");
    }
    tareas.erase(it, tareas.end());
}
