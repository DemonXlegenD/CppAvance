#include "../GameObjectLib/includes/Vector2D.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Vector2dTest
{
	TEST_CLASS(Vector) {

		Vector2D<int> Vector1 = Vector2D<int>(5, 10);
		Vector2D<float> Vector2 = Vector2D<float>(2.f, 5.f);

		public:
		TEST_METHOD(addTrue)
		{
			Assert::IsTrue(Vector1.add(Vector1, Vector1) == Vector2D<int>(10,20));
		}TEST_METHOD(addFalse)
		{
			Assert::IsFalse(Vector1.add(Vector1, Vector1) == Vector2D<int>(0,10));
		}
		TEST_METHOD(magnitude)
		{
			Assert::IsTrue(Vector1.magnitude() ==  std::sqrt((5 * 5) + (10 * 10)));
		}
		TEST_METHOD(down)
		{
			Assert::IsTrue(Vector2.down() == Vector2D<float>(0.f,-1.f));
		}	
		TEST_METHOD(zero)
		{
			Assert::IsTrue(Vector2.zero() == Vector2D<float>(0.f,0.f));
		}	
		TEST_METHOD(normalized)
		{
			Assert::IsTrue(Vector2.normalized() == Vector2D<float>(2.f/Vector2.magnitude(), 5.f / Vector2.magnitude()));
		}	
	};
}