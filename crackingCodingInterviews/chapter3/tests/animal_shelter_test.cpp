#include <gtest/gtest.h>
#include "chapter3/animal_shelter.hpp"

class CAnimalShelterTest : public ::testing::Test {
protected:
    void SetUp() override {
        m_shelter = new CAnimalShelter();
    }

    void TearDown() override {
        delete m_shelter;
    }

    CAnimalShelter* m_shelter;
};

TEST_F(CAnimalShelterTest, TestEnqueue) {
    m_shelter->enqueue("Buddy", CAnimal::EAnimalType::Dog);
    m_shelter->enqueue("Whiskers", CAnimal::EAnimalType::Cat);
    m_shelter->enqueue("Max", CAnimal::EAnimalType::Dog);
    m_shelter->enqueue("Luna", CAnimal::EAnimalType::Cat);

    ASSERT_EQ(m_shelter->getDogCount(), 2);
    ASSERT_EQ(m_shelter->getCatCount(), 2);
    ASSERT_EQ(m_shelter->getTotalCount(), 4);

    auto animal = m_shelter->dequeueAny();
    ASSERT_EQ(animal.getName(), "Buddy");
    ASSERT_EQ(animal.getType(), CAnimal::EAnimalType::Dog);

    animal = m_shelter->dequeueAny();
    ASSERT_EQ(animal.getName(), "Whiskers");
    ASSERT_EQ(animal.getType(), CAnimal::EAnimalType::Cat);

    animal = m_shelter->dequeueAny();
    ASSERT_EQ(animal.getName(), "Max");
    ASSERT_EQ(animal.getType(), CAnimal::EAnimalType::Dog);

    animal = m_shelter->dequeueAny();
    ASSERT_EQ(animal.getName(), "Luna");
    ASSERT_EQ(animal.getType(), CAnimal::EAnimalType::Cat);

    ASSERT_THROW(m_shelter->dequeueAny(), std::out_of_range);
}

TEST_F(CAnimalShelterTest, TestDequeueDog) {
    m_shelter->enqueue("Buddy", CAnimal::EAnimalType::Dog);
    m_shelter->enqueue("Whiskers", CAnimal::EAnimalType::Cat);
    m_shelter->enqueue("Max", CAnimal::EAnimalType::Dog);
    m_shelter->enqueue("Luna", CAnimal::EAnimalType::Cat);

    auto animal = m_shelter->dequeueDog();
    ASSERT_EQ(animal.getName(), "Buddy");
}

TEST_F(CAnimalShelterTest, TestDequeueCat) {
    m_shelter->enqueue("Buddy", CAnimal::EAnimalType::Dog);
    m_shelter->enqueue("Whiskers", CAnimal::EAnimalType::Cat);
    m_shelter->enqueue("Max", CAnimal::EAnimalType::Dog);
    m_shelter->enqueue("Luna", CAnimal::EAnimalType::Cat);

    auto animal = m_shelter->dequeueCat();
    ASSERT_EQ(animal.getName(), "Whiskers");
}

TEST_F(CAnimalShelterTest, TestDequeueAny) {
    m_shelter->enqueue("Buddy", CAnimal::EAnimalType::Dog);
    m_shelter->enqueue("Whiskers", CAnimal::EAnimalType::Cat);
    m_shelter->enqueue("Max", CAnimal::EAnimalType::Dog);
    m_shelter->enqueue("Luna", CAnimal::EAnimalType::Cat);

    auto animal = m_shelter->dequeueDog();
    ASSERT_EQ(animal.getName(), "Buddy");

    animal = m_shelter->dequeueAny();
    ASSERT_EQ(animal.getName(), "Whiskers");

}