#define CATCH_CONFIG_MAIN
#include "../potokashi.cpp"
#include "catch2/catch.hpp"

Potokashi field_random;

const Potokashi field_correct(std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15});

TEST_CASE("Check the default constructor") {
  REQUIRE(field_random.getTiles().size() == 16);
}

TEST_CASE("Check the copying constructor") {
  Potokashi copied_random(field_random);
  REQUIRE(copied_random == field_random);
}

TEST_CASE("Check vector constructor") {

  REQUIRE(field_correct.getTiles() == std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7,
                                                       8, 9, 10, 11, 12, 13, 14,
                                                       15});
}

TEST_CASE("Check Tiles getter") {

  REQUIRE(field_correct.getTiles() == std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7,
                                                       8, 9, 10, 11, 12, 13, 14,
                                                       15});
  REQUIRE(field_random.getTiles().size() == 16);
}

TEST_CASE("Check 'checkCorrectness' method") {

  REQUIRE(field_correct.checkCorrectness() == true);
}

TEST_CASE("Check 'checkCorrectness' method (on incorrect value)") {

  Potokashi field(
      // incorrect field
      std::vector<int>{1, 0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15});
  REQUIRE(field.checkCorrectness() == false);
}

TEST_CASE("Check the moveTile() function (direction - left)") {
  Potokashi field(
      std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15});
  // move Tile on position 1 to the left
  REQUIRE(field.moveTile(1, 2));
  REQUIRE(field[1] == 0);
  REQUIRE(field[0] == 1);
}

TEST_CASE("Check the moveTile() function (direction - up)") {
  Potokashi field(
      std::vector<int>{1, 0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15});
  // move Tile on position 5 upstairs
  REQUIRE(field.moveTile(5, 0));
  REQUIRE(field[1] == 5);
  REQUIRE(field[5] == 0);
}

TEST_CASE("Check the moveTile() function (direction - right)") {
  Potokashi field(
      std::vector<int>{1, 5, 2, 3, 4, 0, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15});
  // move Til
  REQUIRE(field.moveTile(4, 3));
  REQUIRE(field[5] == 4);
  REQUIRE(field[4] == 0);
}

TEST_CASE("Check the moveTile() function (direction - down)") {
  Potokashi field(
      std::vector<int>{1, 5, 2, 3, 0, 4, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15});
  // move Til
  REQUIRE(field.moveTile(0, 1));
  REQUIRE(field[0] == 0);
  REQUIRE(field[4] == 1);
}

TEST_CASE("Check the [0] operator") { REQUIRE(field_correct[0] == 0); }

TEST_CASE("Check the [1] operator") { REQUIRE(field_correct[1] == 1); }
TEST_CASE("Check the [2] operator") { REQUIRE(field_correct[2] == 2); }
TEST_CASE("Check the [3] operator") { REQUIRE(field_correct[3] == 3); }
TEST_CASE("Check the [4] operator") { REQUIRE(field_correct[4] == 4); }
TEST_CASE("Check the [5] operator") { REQUIRE(field_correct[5] == 5); }
TEST_CASE("Check the [6] operator") { REQUIRE(field_correct[6] == 6); }
TEST_CASE("Check the [7] operator") { REQUIRE(field_correct[7] == 7); }
TEST_CASE("Check the [8] operator") { REQUIRE(field_correct[8] == 8); }
TEST_CASE("Check the [9] operator") { REQUIRE(field_correct[9] == 9); }
TEST_CASE("Check the [10] operator") { REQUIRE(field_correct[10] == 10); }
TEST_CASE("Check the [11] operator") { REQUIRE(field_correct[11] == 11); }
TEST_CASE("Check the [12] operator") { REQUIRE(field_correct[12] == 12); }
TEST_CASE("Check the [13] operator") { REQUIRE(field_correct[13] != 14); }
TEST_CASE("Check the [13] operator (incorrect)") {
  REQUIRE(field_correct[13] == 13);
}
TEST_CASE("Check the [14] operator") { REQUIRE(field_correct[14] == 14); }
TEST_CASE("Check the [15] operator") { REQUIRE(field_correct[15] == 15); }

TEST_CASE("Check output stream operator") {
  std::ostringstream out;
  out << field_correct;
  REQUIRE(out.str() == "0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 ");
}

TEST_CASE("Check input stream operator") {
  Potokashi field(
      std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15});

  std::istringstream("1 2") >> field;
  // input operator should accept two numbers (position and direction) and call
  // moveTile() with these arguments
  REQUIRE(field[1] == 0);
  REQUIRE(field[0] == 1);
}

TEST_CASE("Check 'not equals' operator") {
  Potokashi field(
      std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15});
  // move Tile on position 1 to the left
  field.moveTile(1, 2);
  REQUIRE(field != field_correct);
}

TEST_CASE("Check the 'equals' operator") {
  REQUIRE(field_correct == field_correct);
}
