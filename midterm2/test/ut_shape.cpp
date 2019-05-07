#include <gtest/gtest.h>
#include "../src/object.h"
#include "../src/empty_set.h"
#include "../src/object_set.h"
#include "../src/object_iterator.h"
#include "../src/number.h"
#include "../src/shape.h"
#include "../src/triangle.h"
#include "../src/triangle_factory.h"
#include <algorithm>
#include <vector>

int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(TriangleTest, CreateTriangleSuccess)
{
  Triangle * triangle = new Triangle(3,4,5);
  ASSERT_TRUE(triangle->isCreate());
  ASSERT_EQ(12, triangle->perimeter());
}

TEST(TraingleTest, CreateTriangleFalse)
{
  ASSERT_ANY_THROW(Triangle * faleTriangle = new Triangle(0,0,0));
}

TEST(TriangleTest, TriangleFactorySuccess)
{
  Triangle * triangle = new Triangle(3,4,5);
  TriangleFactory * triangleFactory = new TriangleFactory();
  ASSERT_TRUE(triangleFactory->create(3,4,5)->isCreate());
  ASSERT_EQ(12, triangleFactory->create(3,4,5)->perimeter());
}

TEST(TriangleTest, TriangleFactoryFalse)
{
  TriangleFactory * triangleFactory = new TriangleFactory();
  ASSERT_EQ(nullptr, triangleFactory->create(0,0,0));
}

TEST(ObjectTest, ObjectAdd)
{
  Object * result = new OjectSet();   //{}

  Object * integerOne = new Number(1);  //1
  result->add(integerOne);

  Object * integerTwo = new Number(2);  //{2}
  Object * objSet = new OjectSet();
  objSet->add(integerTwo);
  result->add(objSet);    //{1, {2}}

  Object * objSetTwo = new OjectSet();
  Object * integerThree = new Number(3);
  Object * integerFore = new Number(4);
  Object * objSetThree = new OjectSet();
  Object * integerFive = new Number(5);
  Object * emptySet = new EmptySet();
  objSetThree->add(integerFive);
  objSetThree->add(emptySet); // {5,{}}
  objSetTwo->add(integerThree);
  objSetTwo->add(integerFore);
  objSetTwo->add(objSetThree);//  {3,4,{5,{}}}
  result->add(objSetTwo);// {1,{2},{3,4,{5,{}}}}

  //std::unique_ptr<ObjectIterator> objIt(result->createIterator());
  //objIt->first();
  //ASSERT_EQ("1", it->currentItem()->getValueStr());
}
