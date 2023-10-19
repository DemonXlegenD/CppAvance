#include "../GameObjectLib/includes/Container.h"
#include "../GameObjectLib/includes/Vector2D.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ContainerTest {


	TEST_CLASS(ContainerTest) {

		Container<int> containerA = Container<int>();
		Container<int> containerA1 = Container<int>();
		Container<float> containerB = Container<float>();
		Container<Vector2D<int>> containerC = Container<Vector2D<int>>();

public:
	TEST_METHOD(ContainerTestEmptyTrue)
	{
		Assert::IsTrue(containerA.empty() == true, L"Conteneur A n'est pas vide");
		if (containerB.empty() == false) {
			Logger::WriteMessage("Le conteneur B est vide");
		}
		Assert::IsTrue(containerB.empty() == true, L"Conteneur B n'est pas vide");
	}
	TEST_METHOD(ContainerTestEmptyFalse)
	{
		containerA.push_back(1);
		Assert::IsTrue(containerA.empty() == false, L"Conteneur A est vide");
		if (containerB.empty() == false) {
			Logger::WriteMessage("Le conteneur A n'est pas vide");
		}
		containerB.push_back(1.f);
		Assert::IsTrue(containerB.empty() == false, L"Conteneur B est vide");
		if (containerB.empty() == false) {
			Logger::WriteMessage("Le conteneur B n'est pas vide");
		}
	}
	TEST_METHOD(ContainerTestAreEqualTrue) {
		containerA.push_back(1);
		containerA1.push_back(1);
		Assert::IsTrue((containerA == containerA1), L"Les conteneurs ne sont pas égaux");
		if (containerA == containerA1) {
			Logger::WriteMessage("Les conteneurs sont égaux");
		}
		//Assert::AreEqual(containerA, containerA1, L"salut"); //C'est le test qui bug
	}
	TEST_METHOD(ContainerTestAreEqualFalse) {
		//Non égalité d'élément
		containerA.push_back(1);
		containerA1.push_back(2);
		Assert::IsFalse((containerA == containerA1), L"Les conteneurs sont égaux");
		if (containerA != containerA1) {
			Logger::WriteMessage("Les conteneurs ne sont pas égaux, les éléments sont différents");
		}
		//Non égalité de taille
		containerA.pop_back();
		Assert::IsFalse((containerA == containerA1), L"Les conteneurs sont égaux");
		if (containerA != containerA1) {
			Logger::WriteMessage("Les conteneurs ne sont pas égaux, taille différente");
		}
	}
	TEST_METHOD(ContainerTestFindIndexByElementTrue) {

		containerA.push_back(0);
		Assert::IsTrue(containerA.findIndexByElement(0) == 0, L"L'index est incorrecte");
	}
	TEST_METHOD(ContainerTestFindIndexByElementFalse) {

		containerA.push_back(1);
		Assert::IsFalse(containerA.findIndexByElement(2) == 0, L"L'index est correct");
		if (containerA.findIndexByElement(2) == 0) {
			Logger::WriteMessage("L'index est incorrecte");
		}
		Assert::IsTrue(containerA.findIndexByElement(2) == -1, L"L'index est correct");
		if (containerA.findIndexByElement(2) == -1) {
			Logger::WriteMessage("L'index est incorrecte, -1 par défaut pour dire qu'il n'est pas dans le tableau");
		}
	}
	/*TEST_METHOD(ContainerTestFindIndexByElementTrue) {
		for (int i = 0; i < 10; i++) {
			containerA.push_back(i);
		}
		Assert::IsTrue(containerA.findIndexByElement(0) == 0, L"L'index est incorrecte");
	}*/

	//TEST_METHOD(ContainerTestFindIndexByElementFalse) {
	//	for (int i = 0; i < 30; i++) {
	//		containerA.push_back(i);
	//	}
	//	Assert::IsFalse(containerA.findIndexByElement(29) == 28, L"L'index est incorrecte");
	//	if (containerA.findIndexByElement(29) == 28) {
	//		Logger::WriteMessage("L'index est correcte");
	//	}
	//}
	};
}