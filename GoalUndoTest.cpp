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
  g.addOperation("Complete Task 3");
  ASSERT_TRUE(g.getOperations()=="Complete Task 1 Complete Task 2 Complete Task 3");
}


TEST(GoalUndoTest, check_undoOperation){
  GoalUndo g;
  g.addOperation("Reach target","Complete Task 1");
  g.addOperation("Complete Task 2");
  g.addOperation("Complete Task 3");
  g.undoOperation();
  ASSERT_TRUE(g.getOperations()=="Complete Task 1 Complete Task 2");

}

TEST(GoalUndoTest, check_undoOperation_parameter){
  GoalUndo g;
  g.addOperation("Reach target","Complete Task 1");
  g.addOperation("Complete Task 2");
  g.addOperation("Complete Task 3");
  g.undoOperation("Complete Task 3");
  ASSERT_TRUE(g.getOperations()=="Complete Task 1 Complete Task 2");

}


TEST(GoalUndoTest, check_undoGoal){
  GoalUndo g;
  g.addOperation("Reach target","Complete Task 1");
  g.addOperation("Complete Task 2");
  g.undoGoal();
  ASSERT_TRUE(g.getGoal()=="");
}

TEST(GoalUndoTest,check_getgoal){
  GoalUndo g;
  g.addOperation("Reach target","Complete Task 1");
  g.addOperation("Complete Task 2");
  g.addOperation("Assign Target","Assign Task 1");
  g.addOperation("Assign Task 2");
  ASSERT_TRUE(g.getGoal()=="Assign Target");
  g.undoGoal();
  g.undoGoal();
  ASSERT_TRUE(g.getGoal()=="");
}



TEST(GoalUndoTest, check_getOperation){
  GoalUndo g;
  g.addOperation("Reach target","Complete Task 1");
  g.addOperation("Complete Task 2");
  g.addOperation("Assign Target","Assign Task 1");
  g.addOperation("Assign Task 2");
  ASSERT_TRUE(g.getOperations()=="Assign Task 1 Assign Task 2");
}

TEST(GoalUndoTest, check_undoGoal_with_all_branch){
    GoalUndo g;
    g.undoGoal();
    ASSERT_TRUE(g.getGoal()=="");
}


TEST(GoalUndoTest, check_undoOperation_with_all_branch){
  GoalUndo g;
  g.undoOperation();
  ASSERT_TRUE(g.getGoal()=="");
  g.addOperation("Reach target","Complete Task 1");
  g.addOperation("Complete Task 2");
  // g.undoOperation();
  g.undoOperation();
  g.undoOperation();

  ASSERT_TRUE(g.getGoal()=="");
  ASSERT_TRUE(g.getOperations()=="");
}
