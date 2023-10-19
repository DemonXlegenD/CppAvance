//#include "CppUnitTest.h"
//
//using namespace Microsoft::VisualStudio::CppUnitTestFramework;
//
//namespace Collider2dTest {
//
//
//	TEST_CLASS(CollisionTrigger) {
//
//		Collider2D colA = Collider2D(0.f, 0.f, 5.f, 5.f);
//		Collider2D colB = Collider2D(4.f, 4.f, 5.f, 5.f);
//		Collider2D colC = Collider2D(-5.f, 5.f, 1.f, 1.f);
//
//public:
//	TEST_METHOD(CollisionTriggerTrue)
//	{
//		Assert::IsTrue(colA.collisionTrigger(colB) == true);
//	}
//	TEST_METHOD(CollisionTriggerFalse)
//	{
//		Assert::IsTrue(colA.collisionTrigger(colC) == false);
//	}
//	};
//}