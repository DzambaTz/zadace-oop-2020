#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "MojNizInt.hpp"

#include <initializer_list>

TEST_CASE("Expects to construct empty array") {
  MojNizInt mojNiz;
  CHECK_EQ(mojNiz.size(), 0);
}

TEST_CASE("Expects method at to throw when element at 0 index does not exist") {
  MojNizInt mojNiz;
  CHECK_THROWS_AS(mojNiz.at(0), std::out_of_range);
}

TEST_CASE(
    "Expects method at to throw when element at -1 index does not exist") {
  MojNizInt mojNiz;
  CHECK_THROWS_AS(mojNiz.at(-1), std::out_of_range);
}

TEST_CASE("Expects to initialize MojNizInt using initializer_list") {
  MojNizInt mojNiz{1, 2, 3, 4, 5, 0, -1, -2, -3, -4, -5};
  CHECK_EQ(mojNiz.size(), 11);
  for (auto i = 1; i <= 5; ++i)
    CHECK_EQ(mojNiz.at(i - 1), i);
  for (auto i = 0; i >= -5; --i)
    CHECK_EQ(mojNiz.at(std::abs(i) + 5), i);
}

TEST_CASE("Expects to have const access to at and size method") {
  MojNizInt mojNiz{1, 2, 3, 4, 5};
  const auto &mojConstNiz = mojNiz;
  CHECK_EQ(mojConstNiz.size(), 5);
  for (auto i = 0; i < 5; ++i)
    CHECK_EQ(mojConstNiz.at(i), i + 1);
}

TEST_CASE(
    "Expects at method to be able to modify the object within MojNizInt") {
  MojNizInt mojNiz{1, 2, 3, 4, 5, 6};
  mojNiz.at(3) = 19;
  CHECK_EQ(mojNiz.size(), 6);
  CHECK_EQ(mojNiz.at(3), 19);
  for (auto i = 0; i < 3; ++i)
    CHECK_EQ(mojNiz.at(i), i + 1);
  for (auto i = 4; i < 6; ++i)
    CHECK_EQ(mojNiz.at(i), i + 1);
}

TEST_CASE("Expects to have a proper copy constructor") {
  MojNizInt mojNiz{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  MojNizInt mojNiz2 = mojNiz;
  CHECK_EQ(mojNiz.size(), 10);
  CHECK_EQ(mojNiz2.size(), 10);
  for (auto i = 9; i >= 0; --i) {
    CHECK_EQ(mojNiz.at(9 - i), i + 1);
    CHECK_EQ(mojNiz2.at(9 - i), i + 1);
  }
  // check that zero elements have different addresses, that's the only way we
  // know copy is done properly
  CHECK_NE(&mojNiz.at(0), &mojNiz2.at(0));
}

TEST_CASE("Expects to have a proper move constructor") {
  MojNizInt mojNiz1{1, 3, 5, 7, 9};
  MojNizInt mojNiz2 = std::move(mojNiz1);
  CHECK_EQ(mojNiz2.size(), 5);
  for (auto i = 0; i < 5; ++i) {
    CHECK_EQ(mojNiz2.at(i), 2 * i + 1);
  }
  CHECK_EQ(mojNiz1.size(), 0);
}

TEST_CASE("Expects not to reset dynamic array on destructor when moved") {
  MojNizInt *mojNiz;
  {
    MojNizInt mojNizScoped{1, 3, 5, 7, 9};
    mojNiz = new MojNizInt(std::move(mojNizScoped));
    CHECK_EQ(mojNizScoped.size(), 0);
  }
  for (auto i = 0; i < 5; ++i) {
    CHECK_EQ(mojNiz->at(i), 2 * i + 1);
  }
}

TEST_CASE("Expects to have an operator[]") {
  MojNizInt mojNiz{1, 3, 5, 7, 9};
  for (auto i = 0; i < 5; ++i) {
    CHECK_EQ(mojNiz[i], 2 * i + 1);
  }
}

TEST_CASE("Expects to be able to modify an element using operator[]") {
  MojNizInt mojNiz{1, 3, 5, 7, 9};
  mojNiz[4] = 12;
  for (auto i = 0; i < 4; ++i) {
    CHECK_EQ(mojNiz[i], 2 * i + 1);
  }
  CHECK_EQ(mojNiz[4], 12);
}

TEST_CASE("Expects to be able to use operator[] in const context") {
  MojNizInt mojNiz{1, 3, 5, 7, 9};
  const MojNizInt &mojNizConstRef = mojNiz;
  for (auto i = 0; i < 4; ++i) {
    CHECK_EQ(mojNizConstRef[i], 2 * i + 1);
  }
}

TEST_CASE("Expects to have a proper copy operator=") {
  MojNizInt mojNiz1{0, 2, 4, 6, 8};
  MojNizInt mojNiz2{1, 3, 5, 7, 9, 12, 15};
  mojNiz2 = mojNiz1;
  // Did you replace the size?
  CHECK_EQ(mojNiz2.size(), 5);
  for (auto i = 0; i < 5; ++i) {
    CHECK_EQ(mojNiz1[i], 2 * i);
    CHECK_EQ(mojNiz2[i], 2 * i);
  }
  // check that zero elements have different addresses, that's the only way we
  // know copy is done properly
  CHECK_NE(&mojNiz1[0], &mojNiz2[0]);
}

TEST_CASE("Expects to be able to append copy operator=") {
  MojNizInt mojNiz1{0, 2, 4, 6, 8};
  MojNizInt mojNiz2{1, 3, 5, 7, 9};
  MojNizInt mojNiz3{-5, -4, -3, -2, -1, 0};
  mojNiz1 = mojNiz2 = mojNiz3;
  CHECK_EQ(mojNiz1.size(), 6);
  CHECK_EQ(mojNiz2.size(), 6);
  for (auto i = 0; i < 6; ++i) {
    CHECK_EQ(mojNiz1[i], i - 5);
    CHECK_EQ(mojNiz2[i], i - 5);
    CHECK_EQ(mojNiz3[i], i - 5);
  }
}

TEST_CASE("Expects to have a proper move operator=") {
  MojNizInt mojNiz1{0, 2, 4, 6};
  MojNizInt mojNiz2{1, 3, 5, 7, 9};
  mojNiz2 = std::move(mojNiz1);
  CHECK_EQ(mojNiz1.size(), 0);
  for (auto i = 0; i < 4; ++i) {
    CHECK_EQ(mojNiz2[i], 2 * i);
  }
  CHECK_EQ(mojNiz2.size(), 4);
}

TEST_CASE("Expects not to reset dynamic array on destructor when moved=") {
  MojNizInt mojNiz1;
  {
    MojNizInt mojNiz2{1, 3, 5, 7, 9};
    mojNiz1 = std::move(mojNiz2);
    CHECK_EQ(mojNiz2.size(), 0);
  }
  for (auto i = 0; i < 5; ++i) {
    CHECK_EQ(mojNiz1[i], 2 * i + 1);
  }
}

TEST_CASE("Expects to be able to append move operator=") {
  MojNizInt mojNiz1{0, 2, 4, 6, 8};
  MojNizInt mojNiz2{1, 3, 5, 7, 9};
  MojNizInt mojNiz3{-5, -4, -3, -2, -1, 0};
  mojNiz1 = mojNiz2 = std::move(mojNiz3);
  CHECK_EQ(mojNiz1.size(), 6);
  CHECK_EQ(mojNiz2.size(), 6);
  CHECK_EQ(mojNiz3.size(), 0);
  for (auto i = 0; i < 6; ++i) {
    CHECK_EQ(mojNiz1[i], i - 5);
    CHECK_EQ(mojNiz2[i], i - 5);
  }
}

TEST_CASE("Expects to do a scalar multiplication with array in const context") {
  MojNizInt mojNiz{1, 3, 5, 7, 9, 11, 13, 15, 17};
  const auto &mojNizRef = mojNiz;
  auto noviMojNizInt = mojNizRef * 5;
  // Expects old array to remain unchanged
  CHECK_EQ(mojNiz.size(), 9);
  for (auto i = 0; i < 9; ++i) {
    CHECK_EQ(mojNiz[i], 2 * i + 1);
  }

  CHECK_EQ(noviMojNizInt.size(), 9);
  for (auto i = 0; i < 9; ++i) {
    CHECK_EQ(noviMojNizInt[i], 10 * i + 5);
  }
}

TEST_CASE("Expects to throw when attempting to add two vectors together with "
          "different lengths") {
  MojNizInt mojNiz1, mojNiz2{1};
  CHECK_THROWS_AS(mojNiz1 + mojNiz2, std::invalid_argument);
}

TEST_CASE("Expects to do addition of two vectors in const context") {
  MojNizInt mojNiz1{0, 2, 4, 6, 8}, mojNiz2{1, 3, 5, 7, 9};
  const auto &mojNiz1Cref = mojNiz1;
  const auto &mojNiz2Cref = mojNiz2;
  auto mojNizRes = mojNiz1Cref + mojNiz2Cref;
  CHECK_EQ(mojNizRes.size(), 5);
  for (auto i = 0; i < 5; ++i) {
    CHECK_EQ(mojNizRes[i], 4 * i + 1);
  }
}

TEST_CASE(
    "Expects suffix operator++ to increment every element by 1 and return old "
    "array") {
  MojNizInt mojNiz{0, 2, 4, 6, 8};
  auto oldNiz = mojNiz++;
  CHECK_EQ(mojNiz.size(), 5);
  CHECK_EQ(oldNiz.size(), 5);
  for (auto i = 0; i < 5; ++i) {
    CHECK_EQ(mojNiz[i], 2 * i + 1);
  }
  for (auto i = 0; i < 5; ++i) {
    CHECK_EQ(oldNiz[i], 2 * i);
  }
}

TEST_CASE(
    "Expects prefix operator++ to increment every element by 1 and return same "
    "array") {
  MojNizInt mojNiz{0, 2, 4, 6, 8};
  auto &sameNiz = ++mojNiz;
  CHECK_EQ(mojNiz.size(), 5);
  CHECK_EQ(sameNiz.size(), 5);
  for (auto i = 0; i < 5; ++i) {
    CHECK_EQ(mojNiz[i], 2 * i + 1);
    CHECK_EQ(sameNiz[i], 2 * i + 1);
  }
  CHECK_EQ(&sameNiz, &mojNiz);
}

TEST_CASE("Expects to combine multiple operators properly") {
  MojNizInt mojNiz1{0, 2, 4, 6, 8}, mojNiz2{1, 3, 5, 7, 9};
  auto noviNiz = mojNiz1++ + mojNiz2 * 2;
  for (auto i = 0; i < 5; ++i) {
    CHECK_EQ(mojNiz1.at(i), 2 * i + 1);
    CHECK_EQ(mojNiz2.at(i), 2 * i + 1);
  }
  CHECK_EQ(noviNiz.size(), 5);
  for (auto i = 0; i < 5; ++i) {
    CHECK_EQ(noviNiz.at(i), 6 * i + 2);
  }
}

TEST_CASE("FIRST_PUSH_BACK_Expects push_back to append element at the end of "
          " array") {
  MojNizInt mojNiz;
  mojNiz.push_back(5);
  CHECK_EQ(mojNiz.size(), 1);
  CHECK_EQ(mojNiz.at(0), 5);
  auto addr51 = &mojNiz[0]; // taking address of 5 just after first
  // push_back

  mojNiz.push_back(7);
  CHECK_EQ(mojNiz.size(), 2);
  CHECK_EQ(mojNiz.at(1), 7);
  auto addr52 = &mojNiz[0]; // taking address of 5 after push_back of 7
  CHECK_NE(addr52, addr51); // addresses should be different since
  // reallocation
  // should happen at this point

  mojNiz.push_back(9);
  CHECK_EQ(mojNiz.size(), 3);
  CHECK_EQ(mojNiz.at(2), 9);
  auto addr53 = &mojNiz[0]; // taking address of 5 after push_back of 9
  CHECK_NE(addr52, addr53); // addresses should be different since
  // reallocation
  // should happen at this point
  CHECK_NE(addr52, addr51); // addresses should be different since
  // reallocation
  // should happen at this point
}
