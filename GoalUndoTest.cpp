/**
 * Unit Tests for GoalUndo class
**/

#include <gtest/gtest.h>
#include "GoalUndo.h"

class GoalUndoTest : public ::testing::Test
{
	protected:
		GoalUndoTest(){}
		virtual ~GoalUndoTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(GoalUndoTest, sanityCheck)
{
	ASSERT_TRUE(true);
}


TEST(GoalUndoTest, check_addition_of_goals){
  GoalUndo g;
  g.addOperation("Reach target","Complete Task 1");
  ASSERT_TRUE(g.getGoal()=="Reach target");
}

TEST(GoalUndoTest,check_addition_of_operations){
  GoalUndo g;
  g.addOperation("Reach target","Complete Task 1");
  g.addOperation("Complete Task 2");
  ASSERT_TRUE(g.getOperations()=="Complete Task 1 Complete Task 2");
}
