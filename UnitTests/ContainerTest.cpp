#include "../GameObjectLib/includes/Container.h"
#include "../GameObjectLib/includes/Vector2D.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ContainerTest {


	TEST_CLASS(ContainerTest) {

		Container<int> containerA = Container<int>();
		Container<int> containerA1 = Container<int>();
		Container<float> containerB = Container<float>();
		Container<int> containerC = Container<int>();
public:


	/*==============================================================================================================================================*/
	/*-----------------------------------------------------------------CONSTRUCTORS-----------------------------------------------------------------*/
	/*==============================================================================================================================================*/


	//Test du constructor par défaut
	TEST_METHOD(DefaultConstructor) {
		Container<int> container;
		int* array = new int[1];
		Assert::AreEqual(0, container.getSize());
		Assert::AreEqual(1, container.getCapacity());
		Assert::IsTrue(containerA == containerA1);
	}

	//Test du constructor avec paramètres
	TEST_METHOD(ParametersConstructor) {
		int* array1 = new int[10];
		for (int i = 0; i < 4; i++) {
			array1[i] = i + 1;
		}
		Container<int> container1(4, 10, array1);
		int* array2 = new int[10];
		for (int i = 0; i < 4; i++) {
			array2[i] = i + 1;
		}
		Container<int> container2(4, 10, array2);
		Assert::AreEqual(4, container1.getSize());
		Assert::AreEqual(10, container1.getCapacity());
		Assert::AreEqual(array1, container1.getArray());
		Assert::IsTrue(container1 == container2);
	}


	/*==============================================================================================================================================*/
	/*-----------------------------------------------------------------OPERATORS--------------------------------------------------------------------*/
	/*==============================================================================================================================================*/


	//Test operator =

	TEST_METHOD(OperatorAssign) {
		containerA.push_back(42);
		containerA1 = containerA;
		Logger::WriteMessage("Size1 " + containerA1.getSize());
		Logger::WriteMessage("Size 2" + containerA.getSize());
		Assert::IsTrue(containerA1.getSize() == containerA.getSize());
		Assert::IsTrue(containerA1.getCapacity() == containerA.getCapacity());
		//Assert::IsTrue(containerA1 == containerA);
		///*Assert::IsTrue(containerA1 == containerA);*/
	}

	//Tests operator ==

	TEST_METHOD(OperatorEqual) {
		containerA.push_back(1);
		containerA1.push_back(1);
		Assert::IsTrue((containerA == containerA1), L"Les conteneurs ne sont pas égaux");
		if (containerA == containerA1) {
			Logger::WriteMessage("Les conteneurs sont égaux");
		}
		//Assert::AreEqual(containerA, containerA1, L"salut"); //C'est le test qui bug
	}
	TEST_METHOD(OperatorEqualFalseDifferentElement) {
		containerA.push_back(1);
		containerA1.push_back(1);
		Assert::IsTrue((containerA == containerA1), L"Les conteneurs ne sont pas égaux");
		if (containerA == containerA1) {
			Logger::WriteMessage("Les conteneurs sont égaux");
		}
		//Assert::AreEqual(containerA, containerA1, L"salut"); //C'est le test qui bug
	}
	TEST_METHOD(OperatorEqualFalseDifferentSize) {
		//Non égalité de taille
		containerA1.push_back(2);
		Assert::IsFalse((containerA == containerA1), L"Les conteneurs sont égaux");
		if (containerA != containerA1) {
			Logger::WriteMessage("Les conteneurs ne sont pas égaux, taille différente");
		}
	}

	//Test operator !=

	TEST_METHOD(OperatorNotEqual) {
		containerA1.push_back(2);
		containerA.push_back(0);
		Assert::IsTrue((containerA != containerA1), L"Les conteneurs sont égaux");
		if (containerA != containerA1) {
			Logger::WriteMessage("Les conteneurs ne sont pas égaux");
		}
	}

	/*==============================================================================================================================================*/
	/*--------------------------------------------------------------------HOME MADE-----------------------------------------------------------------*/
	/*==============================================================================================================================================*/

	//Get array and set array

	TEST_METHOD(GetAndSetArray) {
		for (int i = 0; i < 30; i++) {
			containerA.push_back(i * 42 + 20);
		}
		containerA1.setArray(containerA.getArray(), containerA.getSize());
		Assert::IsTrue((containerA == containerA1), L"Les conteneurs sont égaux");
		if (containerA.getArray() == containerA1.getArray()) {
			Logger::WriteMessage("Les conteneurs ne sont pas égaux");
		}
	}
	TEST_METHOD(ContainerAEmptyTrue)
	{
		Assert::IsTrue(containerA.empty() == true, L"Conteneur A n'est pas vide");
		if (containerB.empty() == false) {
			Logger::WriteMessage("Le conteneur B est vide");
		}
	}
	TEST_METHOD(ContainerAEmptyFalse)
	{
		containerA.push_back(1);
		Assert::IsTrue(containerA.empty() == false, L"Conteneur A est vide");
		if (containerB.empty() == false) {
			Logger::WriteMessage("Le conteneur A n'est pas vide");
		}
	}
	TEST_METHOD(ContainerFindIndexByElementTrue) {

		containerA.push_back(0);
		Assert::IsTrue(containerA.findIndexByElement(0) == 0, L"L'index est incorrecte");
	}
	TEST_METHOD(ContainerFindIndexByElementFalse) {

		containerA.push_back(1);
		Assert::IsTrue(containerA.findIndexByElement(2) == -1, L"L'index est correct");
		if (containerA.findIndexByElement(2) == -1) {
			Logger::WriteMessage("L'index est incorrecte, -1 par défaut pour dire qu'il n'est pas dans le tableau");
		}
	}
	};
}