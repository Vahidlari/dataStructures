#include "chapter3/animal_shelter.hpp"
#include <stdexcept>

CAnimal::CAnimal(EAnimalType type, order_t arrivalOrder, std::string name)
    : m_type(type), m_arrivalOrder(arrivalOrder), m_name(name) {}

CAnimal::EAnimalType CAnimal::getType() const {
    return m_type;
}

CAnimal::order_t CAnimal::getArrivalOrder() const {
    return m_arrivalOrder;
}

std::string CAnimal::getName() const {
    return m_name;
}

bool CAnimal::operator<(const CAnimal& other) const {
    return m_arrivalOrder < other.m_arrivalOrder;
}

CAnimal::CAnimal(const CAnimal& other)
    : m_type(other.m_type), m_arrivalOrder(other.m_arrivalOrder), m_name(other.m_name) {}

CAnimal& CAnimal::operator=(const CAnimal& other) {
    if (this != &other) {
        m_type = other.m_type;
        m_arrivalOrder = other.m_arrivalOrder;
        m_name = other.m_name;
    }

    return *this;
}

CAnimalShelter::CAnimalShelter()
    : m_lastArrivalOrder(0) 
{
}

void CAnimalShelter::enqueue(const std::string& name, animal_type_t type) {
    if (type == animal_type_t::Dog) {
	m_dogs.push(animal_t(type, m_lastArrivalOrder, name));
    } else {
	m_cats.push(animal_t(type, m_lastArrivalOrder, name));
    }

    ++m_lastArrivalOrder;
}

typename CAnimalShelter::animal_t CAnimalShelter::dequeueAny() {
    if (isEmpty()) {
        throw std::out_of_range("No animals in the shelter");
    }

    if (m_dogs.empty()) {
        auto cat = m_cats.front();
        m_cats.pop();
        return cat;
    }

    if (m_cats.empty()) {
        auto dog = m_dogs.front();
        m_dogs.pop();
        return dog;
    }

    if (m_dogs.front() < m_cats.front()) {
        auto dog = m_dogs.front();
        m_dogs.pop();
        return dog;
    } else {
        auto cat = m_cats.front();
        m_cats.pop();
        return cat;
    }
}

typename CAnimalShelter::animal_t CAnimalShelter::dequeueDog() {
    if (m_dogs.empty()) {
        throw std::out_of_range("No dogs in the shelter");
    }

    auto dog = m_dogs.front();
    m_dogs.pop();
    return dog;
}

typename CAnimalShelter::animal_t CAnimalShelter::dequeueCat() {
    if (m_cats.empty()) {
        throw std::out_of_range("No cats in the shelter");
    }

    auto cat = m_cats.front();
    m_cats.pop();
    return cat;
}

bool CAnimalShelter::isEmpty() const {
    return m_dogs.empty() && m_cats.empty();
}

typename CAnimalShelter::size_t CAnimalShelter::getDogCount() const {
    return m_dogs.size();
}

typename CAnimalShelter::size_t CAnimalShelter::getCatCount() const {
    return m_cats.size();
}

typename CAnimalShelter::size_t CAnimalShelter::getTotalCount() const {
    return m_dogs.size() + m_cats.size();
}
