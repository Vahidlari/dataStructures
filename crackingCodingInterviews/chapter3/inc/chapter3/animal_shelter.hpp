#ifndef CHAPTER3_ANIMAL_SHELTER_HPP
#define CHAPTER3_ANIMAL_SHELTER_HPP

#include <queue>
#include <string>

/**
 * @file animal_shelter.hpp
 * @brief Solution for Cracking the Coding Interview 3.6: Animal Shelter
 * @problem
 * An animal shelter, which holds only dogs and cats, operates on a strictly "first in, first out" basis.
 * People must adopt either the "oldest" (based on arrival time) of all animals at the shelter, or they can select whether they would prefer a dog or a cat (and will receive the oldest animal of that type).
 * They cannot select which specific animal they would like.
 * @note The implementation is based on the std::queue class. We could also use the queue type from the problem 3.4., CQueueUsingStacks, but would result in higher time complexity.
 */

/**
 * @brief Base class for all animals
 * Animal type is defined by an enum class EAnimalType. The class holds the arrival order of the animal.
 * 
 */
class CAnimal {
public:
    using order_t = unsigned int;

    enum class EAnimalType {
        Dog,
        Cat
    };

    /**
     * @brief Constructor for the CAnimal class
     * @param type The type of the animal
     * @param arrivalOrder The arrival order of the animal
     * @param name The name of the animal
     */
    CAnimal(EAnimalType type, order_t arrivalOrder, std::string name);

    /**
     * @brief Destructor for the CAnimal class
     */
    ~CAnimal() = default;

    /** 
     * @brief Copy constructor for the CAnimal class
     * @param other The other animal
     */
    CAnimal(const CAnimal& other);

    /**
     * @brief Copy assignment operator for the CAnimal class
     */
    CAnimal& operator=(const CAnimal& other);

    /**
     * @brief Get the type of the animal
     * @return The type of the animal
     */
    EAnimalType getType() const;

    /**
     * @brief Get the arrival order of the animal
     * @return The arrival order of the animal
     */
    order_t getArrivalOrder() const;

    /**
     * @brief Get the name of the animal
     * @return The name of the animal
     */
    std::string getName() const;

    /**
     * @brief Comparison operator for the CAnimal class
     * @param other The other animal
     * @return true if the current animal is older than the other animal, false otherwise
     */
    bool operator<(const CAnimal& other) const;

private:
    EAnimalType m_type;
    order_t m_arrivalOrder;
    std::string m_name;
};

/**
 * @brief Class for the animal shelter
 * The class holds a queue of animals.
 * The class provides methods to enqueue and dequeue animals. 
 * Dequeueing an animal returns the oldest animal in the shelter, or the oldest animal of a given type.
 * @note The implementation is based on the std::queue class.
 */
class CAnimalShelter {
public:
    using animal_t = CAnimal;
    using queue_t = std::queue<animal_t>;
    using order_t = animal_t::order_t;
    using animal_type_t = animal_t::EAnimalType;
    using size_t = std::size_t;

    CAnimalShelter();

    ~CAnimalShelter() = default;

    /**
     * @brief Enqueues an animal into the shelter
     * @param name The name of the animal
     * @param type The type of the animal
     */
    void enqueue(const std::string& name, animal_type_t type);

    /**
     * @brief Dequeues any animal from the shelter
     * @return The oldest animal in the shelter
     */
    animal_t dequeueAny();

    /**
     * @brief Dequeues a dog from the shelter
     * @return The oldest dog in the shelter
     */
    animal_t dequeueDog();

    /**
     * @brief Dequeues a cat from the shelter
     * @return The oldest cat in the shelter
     */
    animal_t dequeueCat();

    /**
     * @brief Checks if the shelter is empty
     * @return true if the shelter is empty, false otherwise
     */
    bool isEmpty() const;

    /**
     * @brief Gets the number of dogs in the shelter
     * @return The number of dogs in the shelter
     */
    size_t getDogCount() const;

    /**
     * @brief Gets the number of cats in the shelter
     * @return The number of cats in the shelter
     */
    size_t getCatCount() const;

    /**
     * @brief Gets the total number of animals in the shelter
     * @return The total number of animals in the shelter
     */
    size_t getTotalCount() const;

private:
    queue_t m_dogs;
    queue_t m_cats;
    order_t m_lastArrivalOrder;
};

#endif // CHAPTER3_ANIMAL_SHELTER_HPP